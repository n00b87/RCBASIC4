#ifndef RC_POST_FX_H_INCLUDED
#define RC_POST_FX_H_INCLUDED

#include <irrlicht.h>
#include <cstdlib>

#include "rc_gfx_core.h"

using namespace std;
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


// DISTORTION

class PPE_Glass_callback: public video::IShaderConstantSetCallBack
{
    public:
        float strength;

        virtual void OnSetConstants(video::IMaterialRendererServices* services, s32 userData)
        {
            video::IVideoDriver* driver = services->getVideoDriver();
            services->setVertexShaderConstant("strength", reinterpret_cast<f32*>(&strength),1);
            int var0=0;
            services->setPixelShaderConstant("Texture1", (float*)(&var0), 1);
            int var1=1;
            services->setPixelShaderConstant("Texture2", (float*)(&var1), 1);
        }
};




class IPostProcessGlass : public scene::ISceneNode
{

    public:
        core::aabbox3d<f32> Box;
        video::S3DVertex Vertices[6];//the vertices for the onscreenquad
        video::SMaterial Material;//the material used with shader
        video::ITexture* rt0; //the rendertarget/normalmap
        video::ITexture* rt1; //the smgr->drawAll output
        int mat;
        PPE_Glass_callback* callback;

        IPostProcessGlass(scene::ISceneNode* parent, scene::ISceneManager* mgr, s32 id): scene::ISceneNode(parent, mgr, id)
        {
            Vertices[0] = video::S3DVertex(-1.0f, -1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 0.0f, 1.0f);
            Vertices[1] = video::S3DVertex(-1.0f,  1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 0.0f, 0.0f);
            Vertices[2] = video::S3DVertex( 1.0f,  1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 1.0f, 0.0f);
            Vertices[3] = video::S3DVertex( 1.0f, -1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 1.0f, 1.0f);
            Vertices[4] = video::S3DVertex(-1.0f, -1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 0.0f, 1.0f);
            Vertices[5] = video::S3DVertex( 1.0f,  1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 1.0f, 0.0f);

            callback = NULL;
            rt0 = NULL;
            rt1 = NULL;
        }


        void initiate(unsigned int sizeW,unsigned int sizeH,float strength,scene::ISceneManager* smgr)
        {
            static stringc vertShader =
            "varying vec2 vTexCoord;"
            "void main(void)"
            "{"
              " vec2 Position;"
              " Position.xy = sign(gl_Vertex.xy);"
              " gl_Position = vec4(Position.xy, 0.0, 1.0);"
               "vTexCoord =Position.xy *.5 + .5;"
            "}";

            static stringc fragShader =
            "uniform float strength;"
            "varying vec2 vTexCoord;"
            "uniform sampler2D Texture2; "
            "uniform sampler2D Texture1;"
            ""
            "void main(void)"
            "{"
            "   vec2 offset= texture2D( Texture2, vTexCoord).xy;"
            "   float d=length(offset);"
            "   if(d!=0.0){offset-=0.5*d;}"
            "   offset=offset*strength+vTexCoord;"
            "   gl_FragColor = texture2D( Texture1, offset );"
            //"gl_FragColor=texture2D( Texture1, vTexCoord )+texture2D( Texture2, vTexCoord );"
            "}";



            video::IVideoDriver* driver = smgr->getVideoDriver();
            video::IGPUProgrammingServices* gpu = driver->getGPUProgrammingServices();

                  callback= new PPE_Glass_callback();
                  callback->strength=strength;

                  Material.MaterialType=(E_MATERIAL_TYPE)gpu->addHighLevelShaderMaterial
                    (
                           vertShader.c_str(), "main", video::EVST_VS_1_1,
                           fragShader.c_str(), "main", video::EPST_PS_1_1,
                           callback, (video::EMT_SOLID)
                    );
                  rt0 = driver->addRenderTargetTexture(core::dimension2d<u32>(sizeW,sizeH));
                  rt1 = driver->addRenderTargetTexture(core::dimension2d<u32>(sizeW,sizeH));

                  Material.Wireframe = false;
                  Material.Lighting = false;
                  Material.setTexture(0, rt0);
                  Material.setTexture(1,rt1);
        }




        virtual void OnPreRender()
        {
        }

        virtual void render()
        {
            u16 indices[] = {0,1,2,3,4,5};
            video::IVideoDriver* driver = SceneManager->getVideoDriver();

            driver->setMaterial(Material);
            driver->setTransform(video::ETS_WORLD, AbsoluteTransformation);
            driver->drawIndexedTriangleList(&Vertices[0], 6, &indices[0], 2);
        }


        virtual u32 getMaterialCount(){return 1;}
        virtual video::SMaterial& getMaterial(s32 i){return (Material);}
        virtual const core::aabbox3d<f32>& getBoundingBox() const{return Box;}
};






// COLORIZE

struct PPE_Color_Setup
{
    float saturation;
    float coloringStrength;
    video::SColorf col;
};


class PPE_Color_callback: public video::IShaderConstantSetCallBack
{
public:
    float saturation;
    float coloringStrength;
    video::SColorf col;

    virtual void OnSetConstants(video::IMaterialRendererServices* services, s32 userData)
    {
        video::IVideoDriver* driver = services->getVideoDriver();

        services->setVertexShaderConstant("saturation", reinterpret_cast<f32*>(&saturation),1);
        services->setVertexShaderConstant("coloringStrength", reinterpret_cast<f32*>(&coloringStrength),1);
        services->setPixelShaderConstant("coloring", reinterpret_cast<f32*>(&col), 4);
    }
};




class IPostProcessColor : public scene::ISceneNode
{

    public:
    core::aabbox3d<f32> Box;
    video::S3DVertex Vertices[6];//the vertices for the onscreenquad
    video::SMaterial Material;
    video::ITexture* rt0; //the rendertarget
    int mat;
    PPE_Color_callback* callback;

    IPostProcessColor(scene::ISceneNode* parent, scene::ISceneManager* mgr, s32 id): scene::ISceneNode(parent, mgr, id)
    {
        Vertices[0] = video::S3DVertex(-1.0f, -1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 0.0f, 1.0f);
        Vertices[1] = video::S3DVertex(-1.0f,  1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 0.0f, 0.0f);
        Vertices[2] = video::S3DVertex( 1.0f,  1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 1.0f, 0.0f);
        Vertices[3] = video::S3DVertex( 1.0f, -1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 1.0f, 1.0f);
        Vertices[4] = video::S3DVertex(-1.0f, -1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 0.0f, 1.0f);
        Vertices[5] = video::S3DVertex( 1.0f,  1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 1.0f, 0.0f);
    }


    void initiate(unsigned int sizeW,unsigned int sizeH,PPE_Color_Setup data,scene::ISceneManager* smgr)
    {
        static stringc vertToonShader =
        "varying vec2 vTexCoord;"
        "void main(void)"
        "{"

        " vec2 Position;"
        " Position.xy = sign(gl_Vertex.xy);"
        " gl_Position = vec4(Position.xy, 0.0, 1.0);"
        "vTexCoord =Position.xy *.5 + .5;"
        "}";
        static stringc fragToonShader =
        "uniform sampler2D texture[2];"
        "varying vec2 vTexCoord;"
        "uniform float saturation;"
        "uniform float coloringStrength;"
        "uniform vec4  coloring;"

        "void main()"
        "{"
        "   vec4 sample = texture2D(texture[0], vTexCoord);"
        "   float sat=saturation/10.0;"
        "   float hue=coloringStrength/10.0;"
        "   float greyscale=sample.r*0.3+sample.g*0.49+sample.b*0.11;"
        "   vec4 cGreyScale;"
        "   cGreyScale.r=greyscale;"
        "   cGreyScale.g=greyscale;"
        "   cGreyScale.b=greyscale;"

        "   sample=(sample*(1.0-hue))+coloring/255.0*greyscale*(hue);"
        "   gl_FragColor = (cGreyScale*sat)+sample*(1.0-sat);"
        "}";

        video::IVideoDriver* driver = smgr->getVideoDriver();
        video::IGPUProgrammingServices* gpu = driver->getGPUProgrammingServices();

        callback= new PPE_Color_callback;
        callback->saturation=data.saturation;
        callback->coloringStrength=data.coloringStrength;
        callback->col=data.col;

        Material.MaterialType=(E_MATERIAL_TYPE)gpu->addHighLevelShaderMaterial
        (
               vertToonShader.c_str(), "main", video::EVST_VS_1_1,
               fragToonShader.c_str(), "main", video::EPST_PS_1_1,
               callback, (video::EMT_SOLID)
        );


        rt0 = driver->addRenderTargetTexture(core::dimension2d<u32>(sizeW,sizeH));
        Material.Wireframe = false;
        Material.Lighting = false;
        Material.setTexture(0,rt0);
    }




    virtual void OnPreRender(){}

    virtual void render()
    {
        u16 indices[] = {0,1,2,3,4,5};
        video::IVideoDriver* driver = SceneManager->getVideoDriver();

        driver->setMaterial(Material);
        driver->setTransform(video::ETS_WORLD, AbsoluteTransformation);
        driver->drawIndexedTriangleList(&Vertices[0], 6, &indices[0], 2);
    }
    //Renders the Post-Process Effect

    virtual u32 getMaterialCount(){return 1;}
    virtual video::SMaterial& getMaterial(s32 i){return (Material);}
    virtual const core::aabbox3d<f32>& getBoundingBox() const{return Box;}
};







// RADIAL BLUR

class PPE_RadialBlur_callback: public video::IShaderConstantSetCallBack
{
    public:
        float sampleDist;
        float sampleStrength;
        virtual void OnSetConstants(video::IMaterialRendererServices* services, s32 userData)
        {
            video::IVideoDriver* driver = services->getVideoDriver();
            services->setVertexShaderConstant("sampleDist", reinterpret_cast<f32*>(&sampleDist),1);
            services->setVertexShaderConstant("sampleStrength", reinterpret_cast<f32*>(&sampleStrength),1);
        }
};




class IPostProcessRadialBlur : public scene::ISceneNode
{
    public:
    core::aabbox3d<f32> Box;
    video::S3DVertex Vertices[6];//the vertices for the onscreenquad
    video::SMaterial Material;
    video::ITexture* rt0; //the rendertarget
    int mat;
    PPE_RadialBlur_callback* callback;

    IPostProcessRadialBlur(scene::ISceneNode* parent, scene::ISceneManager* mgr, s32 id): scene::ISceneNode(parent, mgr, id)
    {
        Vertices[0] = video::S3DVertex(-1.0f, -1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 0.0f, 1.0f);
        Vertices[1] = video::S3DVertex(-1.0f,  1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 0.0f, 0.0f);
        Vertices[2] = video::S3DVertex( 1.0f,  1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 1.0f, 0.0f);
        Vertices[3] = video::S3DVertex( 1.0f, -1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 1.0f, 1.0f);
        Vertices[4] = video::S3DVertex(-1.0f, -1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 0.0f, 1.0f);
        Vertices[5] = video::S3DVertex( 1.0f,  1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 1.0f, 0.0f);
    }


    void initiate(int sizeW,int sizeH,float sampleDist,float sampleStrength,scene::ISceneManager* smgr)
    {
        static stringc vertToonShader =
        "varying vec2 vTexCoord;"
        "void main(void)"
        "{"

        " vec2 Position;"
        " Position.xy = sign(gl_Vertex.xy);"
        " gl_Position = vec4(Position.xy, 0.0, 1.0);"
        "vTexCoord =Position.xy *.5 + .5;"
        "}";
        static stringc fragToonShader =
        "uniform sampler2D texture[2];"
        "varying vec2 vTexCoord;"
        "uniform float sampleDist;"
        "uniform float sampleStrength;"

        "void main()"
        "{"
        "vec2 dir=vec2(0.5,0.5)-vTexCoord;"
        "float dist=sqrt(dir.x*dir.x+dir.y*dir.y);"
        "dir=normalize(dir);"
        "   float samples [10];"
        "   samples [0]=-0.08;"
        "   samples [1]=-0.05;"
        "   samples [2]=-0.03;"
        "   samples [3]=-0.02;"
        "   samples [4]=-0.01;"
        "   samples [5]=0.01;"
        "   samples [6]=0.02;"
        "   samples [7]=0.03;"
        "   samples [8]=0.05;"
        "   samples [9]=0.08;"
        "   vec4 sample = texture2D(texture[0], vTexCoord);"
        "   vec4 avg=sample;"
        "   vec4 col;"
        "   for (int i = 0; i < 10; i++)"
        "   {"
        "      vec2 tC=min(vec2(0.999,0.999),max(vec2(0.001,0.001),vTexCoord+dir*samples[i]*sampleDist));"

        "      col=texture2D(texture[0],tC);"
        "      float intensity=col.r+col.g+col.b;"
        "      avg += col;  "
        "   }"
        "   avg /= 11.0;"
        " float t=dist*sampleStrength;"
        "t=clamp(t,0.0,1.0);"
        "   gl_FragColor = mix(sample,avg,t);"
        "}";
        video::IVideoDriver* driver = smgr->getVideoDriver();
        video::IGPUProgrammingServices* gpu = driver->getGPUProgrammingServices();

        callback= new PPE_RadialBlur_callback;
        callback->sampleDist=sampleDist;
        callback->sampleStrength=sampleStrength;
        Material.MaterialType=(E_MATERIAL_TYPE)gpu->addHighLevelShaderMaterial
        (
               vertToonShader.c_str(), "main", video::EVST_VS_1_1,
               fragToonShader.c_str(), "main", video::EPST_PS_1_1,
               callback, (video::EMT_SOLID)
        );


        rt0 = driver->addRenderTargetTexture(core::dimension2d<u32>(sizeW,sizeH));
        Material.Wireframe = false;
        Material.Lighting = false;
        Material.setTexture(0, rt0);
    }




    virtual void OnPreRender(){}

    virtual void render()
    {
        u16 indices[] = {0,1,2,3,4,5};
        video::IVideoDriver* driver = SceneManager->getVideoDriver();

        driver->setMaterial(Material);
        driver->setTransform(video::ETS_WORLD, AbsoluteTransformation);
        driver->drawIndexedTriangleList(&Vertices[0], 6, &indices[0], 2);
    }
    //Renders the Post-Process Effect

    virtual u32 getMaterialCount(){return 1;}
    virtual video::SMaterial& getMaterial(s32 i){return (Material);}
    virtual const core::aabbox3d<f32>& getBoundingBox() const{return Box;}
};






// BLOOM

struct PPE_Bloom_Setup
{
    float sampleDist;
    float strength;
    float multiplier;
};


class PPE_Bloom_callback: public video::IShaderConstantSetCallBack
{
public:
    float sampleDist;
    float strength;
    float multiplier;

    virtual void OnSetConstants(video::IMaterialRendererServices* services, s32 userData)
    {
        video::IVideoDriver* driver = services->getVideoDriver();
        services->setVertexShaderConstant("sampleDist", reinterpret_cast<f32*>(&sampleDist),1);
        services->setVertexShaderConstant("strength", reinterpret_cast<f32*>(&strength),1);
        services->setVertexShaderConstant("multiplier", reinterpret_cast<f32*>(&multiplier),1);
    }
};




class IPostProcessBloom : public scene::ISceneNode
{

public:
    core::aabbox3d<f32> Box;
    video::S3DVertex Vertices[6];//the vertices for the onscreenquad
    video::SMaterial Material;
    video::ITexture* rt0; //the rendertarget
    int mat;
    PPE_Bloom_callback* callback;

    IPostProcessBloom(scene::ISceneNode* parent, scene::ISceneManager* mgr, s32 id): scene::ISceneNode(parent, mgr, id)
    {
        Vertices[0] = video::S3DVertex(-1.0f, -1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 0.0f, 1.0f);
        Vertices[1] = video::S3DVertex(-1.0f,  1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 0.0f, 0.0f);
        Vertices[2] = video::S3DVertex( 1.0f,  1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 1.0f, 0.0f);
        Vertices[3] = video::S3DVertex( 1.0f, -1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 1.0f, 1.0f);
        Vertices[4] = video::S3DVertex(-1.0f, -1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 0.0f, 1.0f);
        Vertices[5] = video::S3DVertex( 1.0f,  1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 1.0f, 0.0f);
    }


    void initiate(unsigned int sizeW,unsigned int sizeH,PPE_Bloom_Setup data,scene::ISceneManager* smgr)
    {
        static stringc vertShader =
        "varying vec2 vTexCoord;"
        "void main(void)"
        "{"
        " vec2 Position;"
        " Position.xy = sign(gl_Vertex.xy);"
        " gl_Position = vec4(Position.xy, 0.0, 1.0);"
        "vTexCoord =Position.xy *.5 + .5;"
        "}";

        static stringc fragShader =
        "uniform sampler2D texture[2];"
        "varying vec2 vTexCoord;"
        "uniform float sampleDist;"
        "uniform float strength;"
        "uniform float multiplier;"
        "void main()"
        "{"
        "   vec2 samples[12]; "
        "   samples[0]  = vTexCoord + sampleDist * vec2(-0.326212, -0.405805);"
        "   samples[1]  = vTexCoord + sampleDist * vec2(-0.840144, -0.073580);"
        "   samples[2]  = vTexCoord + sampleDist * vec2(-0.695914,  0.457137);"
        "   samples[3]  = vTexCoord + sampleDist * vec2(-0.203345,  0.620716);"
        "   samples[4]  = vTexCoord + sampleDist * vec2(0.962340, -0.194983);"
        "   samples[5]  = vTexCoord + sampleDist * vec2(0.473434, -0.480026);"
        "   samples[6]  = vTexCoord + sampleDist * vec2(0.519456,  0.767022);"
        "   samples[7]  = vTexCoord + sampleDist * vec2(0.185461, -0.893124);"
        "   samples[8]  = vTexCoord + sampleDist * vec2(0.507431,  0.064425);"
        "   samples[9]  = vTexCoord + sampleDist * vec2(0.896420,  0.412458);"
        "   samples[10]  = vTexCoord + sampleDist * vec2(-0.321940, -0.932615);"
        "   samples[11]  = vTexCoord + sampleDist * vec2(-0.791559, -0.597705);"
        "   vec4 sample = texture2D(texture[0], vTexCoord);"
        "   vec4 avg = sample;"
        "   vec4 col;"
        "   for (int i = 0; i < 12; i++)"
        "   {"
        "      vec2 tC=min(vec2(0.999,0.999),max(vec2(0.001,0.001),samples[i]));"
        "      avg +=texture2D(texture[0],tC);"
        "   }"
        "   avg /= 13.0;"
        "   avg.r=pow(avg.r,strength);"
        "   avg.g=pow(avg.g,strength);"
        "   avg.b=pow(avg.b,strength);"
        "   gl_FragColor = sample+avg*multiplier;"
        "}";

        video::IVideoDriver* driver = smgr->getVideoDriver();
        video::IGPUProgrammingServices* gpu = driver->getGPUProgrammingServices();

        callback= new PPE_Bloom_callback();
        callback->sampleDist=data.sampleDist;
        callback->strength=data.strength;
        callback->multiplier=data.multiplier;

        Material.MaterialType=(E_MATERIAL_TYPE)gpu->addHighLevelShaderMaterial
        (
               vertShader.c_str(), "main", video::EVST_VS_1_1,
               fragShader.c_str(), "main", video::EPST_PS_1_1,
               callback, (video::EMT_SOLID)
        );
        rt0 = driver->addRenderTargetTexture(core::dimension2d<u32>(sizeW,sizeH));
        Material.Wireframe = false;
        Material.Lighting = false;
        Material.setTexture(0, rt0);
    }




    virtual void OnPreRender(){}

    virtual void render()
    {

        u16 indices[] = {0,1,2,3,4,5};
        video::IVideoDriver* driver = SceneManager->getVideoDriver();

        driver->setMaterial(Material);
        driver->setTransform(video::ETS_WORLD, AbsoluteTransformation);
        driver->drawIndexedTriangleList(&Vertices[0], 6, &indices[0], 2);
    }
    //Renders the Post-Process Effect

    virtual u32 getMaterialCount(){return 1;}
    virtual video::SMaterial& getMaterial(s32 i){return (Material);}
    virtual const core::aabbox3d<f32>& getBoundingBox() const{return Box;}
};







// BLUR

class PPE_Blur_callback: public video::IShaderConstantSetCallBack
{
public:
    float sampleDist;
    virtual void OnSetConstants(video::IMaterialRendererServices* services, s32 userData)
    {
        video::IVideoDriver* driver = services->getVideoDriver();
        services->setVertexShaderConstant("sampleDist", reinterpret_cast<f32*>(&sampleDist),1);
    }
};




class IPostProcessBlur : public scene::ISceneNode
{
public:
    core::aabbox3d<f32> Box;
    video::S3DVertex Vertices[6];//the vertices for the onscreenquad
    video::SMaterial Material;
    video::ITexture* rt0; //the rendertarget
    int mat;
    PPE_Blur_callback* callback;

    IPostProcessBlur(scene::ISceneNode* parent, scene::ISceneManager* mgr, s32 id): scene::ISceneNode(parent, mgr, id)
    {
        Vertices[0] = video::S3DVertex(-1.0f, -1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 0.0f, 1.0f);
        Vertices[1] = video::S3DVertex(-1.0f,  1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 0.0f, 0.0f);
        Vertices[2] = video::S3DVertex( 1.0f,  1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 1.0f, 0.0f);
        Vertices[3] = video::S3DVertex( 1.0f, -1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 1.0f, 1.0f);
        Vertices[4] = video::S3DVertex(-1.0f, -1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 0.0f, 1.0f);
        Vertices[5] = video::S3DVertex( 1.0f,  1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 1.0f, 0.0f);
    }


    void initiate(int sizeW,int sizeH,float sampleDist,scene::ISceneManager* smgr)
    {
        static stringc vertToonShader =
        "varying vec2 vTexCoord;"
        "void main(void)"
        "{"

        " vec2 Position;"
        " Position.xy = sign(gl_Vertex.xy);"
        " gl_Position = vec4(Position.xy, 0.0, 1.0);"
        "vTexCoord =Position.xy *.5 + .5;"
        "}";
        static stringc fragToonShader =
        "uniform sampler2D texture[2];"
        "varying vec2 vTexCoord;"
        "uniform float sampleDist;"

        "void main()"
        "{"
        "   vec2 samples[12]; "
        "   samples[0]  = vTexCoord + sampleDist * vec2(-0.326212, -0.405805);"
        "   samples[1]  = vTexCoord + sampleDist * vec2(-0.840144, -0.073580);"
        "   samples[2]  = vTexCoord + sampleDist * vec2(-0.695914,  0.457137);"
        "   samples[3]  = vTexCoord + sampleDist * vec2(-0.203345,  0.620716);"
        "   samples[4]  = vTexCoord + sampleDist * vec2(0.962340, -0.194983);"
        "   samples[5]  = vTexCoord + sampleDist * vec2(0.473434, -0.480026);"
        "   samples[6]  = vTexCoord + sampleDist * vec2(0.519456,  0.767022);"
        "   samples[7]  = vTexCoord + sampleDist * vec2(0.185461, -0.893124);"
        "   samples[8]  = vTexCoord + sampleDist * vec2(0.507431,  0.064425);"
        "   samples[9]  = vTexCoord + sampleDist * vec2(0.896420,  0.412458);"
        "   samples[10]  = vTexCoord + sampleDist * vec2(-0.321940, -0.932615);"
        "   samples[11]  = vTexCoord + sampleDist * vec2(-0.791559, -0.597705);"
        "   vec4 sample = texture2D(texture[0], vTexCoord);"
        "   vec4 avg = sample;"
        "   vec4 col;"
        "   for (int i = 0; i < 12; i++)"
        "   {"
        "      vec2 tC=min(vec2(0.999,0.999),max(vec2(0.001,0.001),samples[i]));"
        "      col=texture2D(texture[0],tC );"
        "      float intensity=col.r+col.g+col.b;"
        "      avg += col;  "
        "   }"
        "   avg /= 13.0;"
        "   gl_FragColor = avg;"
        "}";
        video::IVideoDriver* driver = smgr->getVideoDriver();
        video::IGPUProgrammingServices* gpu = driver->getGPUProgrammingServices();

        callback= new PPE_Blur_callback;
        callback->sampleDist=sampleDist;
        Material.MaterialType=(E_MATERIAL_TYPE)gpu->addHighLevelShaderMaterial
        (
               vertToonShader.c_str(), "main", video::EVST_VS_1_1,
               fragToonShader.c_str(), "main", video::EPST_PS_1_1,
               callback, (video::EMT_SOLID)
        );


        rt0 = driver->addRenderTargetTexture(core::dimension2d<u32>(sizeW,sizeH));
        Material.Wireframe = false;
        Material.Lighting = false;
        Material.setTexture(0, rt0);
    }




    virtual void OnPreRender(){}

    virtual void render()
    {
        u16 indices[] = {0,1,2,3,4,5};
        video::IVideoDriver* driver = SceneManager->getVideoDriver();

        driver->setMaterial(Material);
        driver->setTransform(video::ETS_WORLD, AbsoluteTransformation);
        driver->drawIndexedTriangleList(&Vertices[0], 6, &indices[0], 2);
    }
    //Renders the Post-Process Effect

    virtual u32 getMaterialCount(){return 1;}
    virtual video::SMaterial& getMaterial(s32 i){return (Material);}
    virtual const core::aabbox3d<f32>& getBoundingBox() const{return Box;}
};





// INVERT

class IPostProcessInvert : public scene::ISceneNode
{
public:
    core::aabbox3d<f32> Box;
    video::S3DVertex Vertices[6];//the vertices for the onscreenquad
    video::SMaterial Material;
    video::ITexture* rt0; //the rendertarget
    int mat;

    IPostProcessInvert(scene::ISceneNode* parent, scene::ISceneManager* mgr, s32 id): scene::ISceneNode(parent, mgr, id)
    {
        Vertices[0] = video::S3DVertex(-1.0f, -1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 0.0f, 1.0f);
        Vertices[1] = video::S3DVertex(-1.0f,  1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 0.0f, 0.0f);
        Vertices[2] = video::S3DVertex( 1.0f,  1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 1.0f, 0.0f);
        Vertices[3] = video::S3DVertex( 1.0f, -1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 1.0f, 1.0f);
        Vertices[4] = video::S3DVertex(-1.0f, -1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 0.0f, 1.0f);
        Vertices[5] = video::S3DVertex( 1.0f,  1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 1.0f, 0.0f);
    }


    void initiate(int sizeW,int sizeH,scene::ISceneManager* smgr)
    {
        static stringc vertToonShader =
        "varying vec2 vTexCoord;"
        "void main(void)"
        "{"

        " vec2 Position;"
        " Position.xy = sign(gl_Vertex.xy);"
        " gl_Position = vec4(Position.xy, 0.0, 1.0);"
        "vTexCoord =Position.xy *.5 + .5;"
        "}";
        static stringc fragToonShader =
        "uniform sampler2D texture[2];"
        "varying vec2 vTexCoord;"
        ""
        "void main()"
        "{"
        "  vec4 col=texture2D(texture[0],vTexCoord);"
        "   gl_FragColor =vec4(1.0,1.0,1.0,1.0)-col;"
        "}";
        video::IVideoDriver* driver = smgr->getVideoDriver();
        video::IGPUProgrammingServices* gpu = driver->getGPUProgrammingServices();

        Material.MaterialType=(E_MATERIAL_TYPE)gpu->addHighLevelShaderMaterial
        (
               vertToonShader.c_str(), "main", video::EVST_VS_1_1,
               fragToonShader.c_str(), "main", video::EPST_PS_1_1,
               NULL, (video::EMT_SOLID)
        );


        rt0 = driver->addRenderTargetTexture(core::dimension2d<u32>(sizeW,sizeH));
        Material.Wireframe = false;
        Material.Lighting = false;
        Material.setTexture(0, rt0);
    }




    virtual void OnPreRender(){}

    virtual void render()
    {
        u16 indices[] = {0,1,2,3,4,5};
        video::IVideoDriver* driver = SceneManager->getVideoDriver();

        driver->setMaterial(Material);
        driver->setTransform(video::ETS_WORLD, AbsoluteTransformation);
        driver->drawIndexedTriangleList(&Vertices[0], 6, &indices[0], 2);
    }
    //Renders the Post-Process Effect

    virtual u32 getMaterialCount(){return 1;}
    virtual video::SMaterial& getMaterial(s32 i){return (Material);}
    virtual const core::aabbox3d<f32>& getBoundingBox() const{return Box;}
};




// MOTION BLUR

class PPE_MotionBlur_callback: public video::IShaderConstantSetCallBack
{
public:
    float strength;
    virtual void OnSetConstants(video::IMaterialRendererServices* services, s32 userData)
    {
        video::IVideoDriver* driver = services->getVideoDriver();
        services->setVertexShaderConstant("strength", reinterpret_cast<f32*>(&strength),1);
        int var0=0;
        services->setPixelShaderConstant("texture1", (float*)(&var0), 1);
        int var1=1;
        services->setPixelShaderConstant("texture2", (float*)(&var1), 1);
    }
};




class IPostProcessMotionBlur : public scene::ISceneNode
{

public:
    core::aabbox3d<f32> Box;
    video::S3DVertex Vertices[6];//the vertices for the onscreenquad
    video::SMaterial Material;//the material used with shader
    video::SMaterial Accum;//a simple diffuse material..
    video::ITexture* next; //the rendertarget
    video::ITexture* prev; //the rendertarget
    video::ITexture* accum; //the rendertarget
    int mat;
    PPE_MotionBlur_callback* callback;

    IPostProcessMotionBlur(scene::ISceneNode* parent, scene::ISceneManager* mgr, s32 id): scene::ISceneNode(parent, mgr, id)
    {
        Vertices[0] = video::S3DVertex(-1.0f, -1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 0.0f, 1.0f);
        Vertices[1] = video::S3DVertex(-1.0f,  1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 0.0f, 0.0f);
        Vertices[2] = video::S3DVertex( 1.0f,  1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 1.0f, 0.0f);
        Vertices[3] = video::S3DVertex( 1.0f, -1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 1.0f, 1.0f);
        Vertices[4] = video::S3DVertex(-1.0f, -1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 0.0f, 1.0f);
        Vertices[5] = video::S3DVertex( 1.0f,  1.0f, 0.0f,1,1,0, video::SColor(255,0,255,255), 1.0f, 0.0f);
    }


    void initiate(unsigned int sizeW,unsigned int sizeH,float strength,scene::ISceneManager* smgr)
    {
        static stringc vertShader =
        "varying vec2 vTexCoord;"
        "void main(void)"
        "{"
        " vec2 Position;"
        " Position.xy = sign(gl_Vertex.xy);"
        " gl_Position = vec4(Position.xy, 0.0, 1.0);"
        "vTexCoord =Position.xy *.5 + .5;"
        "}";

        static stringc fragShader =
        "uniform sampler2D texture1;"
        "uniform sampler2D texture2;"
        "varying vec2 vTexCoord;"
        "uniform float strength;"
        "void main()"
        "{"
        "  gl_FragColor = mix( texture2D( texture1, vTexCoord ), texture2D( texture2, vTexCoord ), vec4( strength,strength,strength,strength) );"
        "}";


        static stringc fragShader2 =
        "uniform sampler2D texture1;"
        "varying vec2 vTexCoord;"
        "void main()"
        "{"
        "  gl_FragColor =texture2D( texture1, vTexCoord );"
        "}";


        video::IVideoDriver* driver = smgr->getVideoDriver();
        video::IGPUProgrammingServices* gpu = driver->getGPUProgrammingServices();

        callback= new PPE_MotionBlur_callback();
        callback->strength=strength;

        Material.MaterialType=(E_MATERIAL_TYPE)gpu->addHighLevelShaderMaterial
        (
               vertShader.c_str(), "main", video::EVST_VS_1_1,
               fragShader.c_str(), "main", video::EPST_PS_1_1,
               callback, (video::EMT_SOLID)
        );
        Accum.MaterialType=(E_MATERIAL_TYPE)gpu->addHighLevelShaderMaterial
        (
               vertShader.c_str(), "main", video::EVST_VS_1_1,
               fragShader2.c_str(), "main", video::EPST_PS_1_1,
               NULL, (video::EMT_SOLID)
        );
        next = driver->addRenderTargetTexture(core::dimension2d<u32>(sizeW,sizeH));
        prev = driver->addRenderTargetTexture(core::dimension2d<u32>(sizeW,sizeH));
        accum = driver->addRenderTargetTexture(core::dimension2d<u32>(sizeW,sizeH));

        Material.Wireframe = false;
        Material.Lighting = false;
        Material.setTexture(0, next);
        Material.setTexture(1,prev);


        Accum.Wireframe = false;
        Accum.Lighting = false;
        Accum.setTexture(0, accum);
    }




    virtual void OnPreRender(){}

    virtual void render()
    {
        u16 indices[] = {0,1,2,3,4,5};
        video::IVideoDriver* driver = SceneManager->getVideoDriver();             //Fills Next
        driver->setRenderTarget(next, true, true, video::SColor(0,0,0,0));
        SceneManager->drawAll();

        driver->setRenderTarget(accum, true, true, video::SColor(0,0,0,0));     //Combine Next&prev in accum
        driver->setMaterial(Material);
        driver->setTransform(video::ETS_WORLD, AbsoluteTransformation);
        driver->drawIndexedTriangleList(&Vertices[0], 6, &indices[0], 2);

        driver->setRenderTarget(prev, true, true, video::SColor(0,0,0,0));        //Write back accum into prev
        driver->setMaterial(Accum);
        driver->setTransform(video::ETS_WORLD, AbsoluteTransformation);
        driver->drawIndexedTriangleList(&Vertices[0], 6, &indices[0], 2);
    }

    virtual void renderFinal()
    {
        video::IVideoDriver* driver = SceneManager->getVideoDriver();
        u16 indices[] = {0,1,2,3,4,5};
        driver->setMaterial(Accum);
        driver->setTransform(video::ETS_WORLD, AbsoluteTransformation);
        driver->drawIndexedTriangleList(&Vertices[0], 6, &indices[0], 2);
    }


    virtual u32 getMaterialCount(){return 1;}
    virtual video::SMaterial& getMaterial(s32 i){return (Material);}
    virtual const core::aabbox3d<f32>& getBoundingBox() const{return Box;}
};




void rc_clearPostEffect(int canvas_id)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size())
        return;

    rc_canvas[canvas_id].post_effect.is_active = false;

    if(rc_canvas[canvas_id].post_effect.object)
    {
        switch(rc_canvas[canvas_id].post_effect.type)
        {
            case RC_POST_PROCESS_BLOOM:
            {
                IPostProcessBloom* post_process = (IPostProcessBloom*)rc_canvas[canvas_id].post_effect.object;
                post_process->remove();
            }
            break;

            case RC_POST_PROCESS_BLUR:
            {
                IPostProcessBlur* post_process = (IPostProcessBlur*)rc_canvas[canvas_id].post_effect.object;
                post_process->remove();
            }
            break;

            case RC_POST_PROCESS_COLORIZE:
            {
                IPostProcessColor* post_process = (IPostProcessColor*)rc_canvas[canvas_id].post_effect.object;
                post_process->remove();
            }
            break;

            case RC_POST_PROCESS_MINERAL:
            {
                IPostProcessGlass* post_process = (IPostProcessGlass*)rc_canvas[canvas_id].post_effect.object;
                post_process->remove();
            }
            break;

            case RC_POST_PROCESS_INVERT:
            {
                IPostProcessInvert* post_process = (IPostProcessInvert*)rc_canvas[canvas_id].post_effect.object;
                post_process->remove();
            }
            break;

            case RC_POST_PROCESS_MOTION_BLUR:
            {
                IPostProcessMotionBlur* post_process = (IPostProcessMotionBlur*)rc_canvas[canvas_id].post_effect.object;
                post_process->remove();
            }
            break;

            case RC_POST_PROCESS_RADIAL_BLUR:
            {
                IPostProcessRadialBlur* post_process = (IPostProcessRadialBlur*)rc_canvas[canvas_id].post_effect.object;
                post_process->remove();
            }
            break;
        }
    }

    rc_canvas[canvas_id].post_effect.object = NULL;
    rc_canvas[canvas_id].post_effect.type = -1;
}


bool rc_setPostEffect(int canvas_id, int effect_type)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size())
        return false;

    rc_clearPostEffect(canvas_id);

    rc_canvas[canvas_id].post_effect.type = effect_type;
    rc_canvas[canvas_id].post_effect.object = NULL;
    rc_canvas[canvas_id].post_effect.is_active = true;


    switch(effect_type)
    {
        case RC_POST_PROCESS_BLOOM:
        {
            IPostProcessBloom *Bloom = new IPostProcessBloom(SceneManager->getRootSceneNode(), SceneManager, -1);

            PPE_Bloom_Setup setup;
            setup.sampleDist=0.01;
            setup.strength=1;
            setup.multiplier=1;

            Bloom->initiate(rc_canvas[canvas_id].viewport.dimension.Width, rc_canvas[canvas_id].viewport.dimension.Height, setup, SceneManager);

            rc_canvas[canvas_id].post_effect.object = Bloom;
        }
        break;

        case RC_POST_PROCESS_BLUR:
        {
            IPostProcessBlur *Blur = new IPostProcessBlur(SceneManager->getRootSceneNode(), SceneManager, -1);

            float sampleDist = 0.001;
            Blur->initiate(rc_canvas[canvas_id].viewport.dimension.Width, rc_canvas[canvas_id].viewport.dimension.Height, sampleDist, SceneManager);

            rc_canvas[canvas_id].post_effect.object = Blur;
        }
        break;

        case RC_POST_PROCESS_COLORIZE:
        {
            IPostProcessColor * PPE_Color = new IPostProcessColor(SceneManager->getRootSceneNode(), SceneManager, -1);
            PPE_Color_Setup setup;
            setup.saturation=1;  //
            setup.coloringStrength=1;
            setup.col=video::SColorf(0,0,0,0);
            PPE_Color->initiate(rc_canvas[canvas_id].viewport.dimension.Width, rc_canvas[canvas_id].viewport.dimension.Height, setup, SceneManager);

            rc_canvas[canvas_id].post_effect.object = PPE_Color;
        }
        break;

        case RC_POST_PROCESS_INVERT:
        {
            IPostProcessInvert *Invert = new IPostProcessInvert(SceneManager->getRootSceneNode(), SceneManager, -1);
            Invert->initiate(rc_canvas[canvas_id].viewport.dimension.Width, rc_canvas[canvas_id].viewport.dimension.Height, SceneManager);

            rc_canvas[canvas_id].post_effect.object = Invert;
        }
        break;

        case RC_POST_PROCESS_MOTION_BLUR:
        {
            IPostProcessMotionBlur *Blur = new IPostProcessMotionBlur(SceneManager->getRootSceneNode(), SceneManager, -1);
            float strength = 0.1;
            Blur->initiate(rc_canvas[canvas_id].viewport.dimension.Width, rc_canvas[canvas_id].viewport.dimension.Height, strength, SceneManager);

            rc_canvas[canvas_id].post_effect.object = Blur;
        }
        break;

        case RC_POST_PROCESS_RADIAL_BLUR:
        {
            IPostProcessRadialBlur *Blur = new IPostProcessRadialBlur(SceneManager->getRootSceneNode(), SceneManager, -1);
            float dist = 0.1;
            float strength = 1;
            Blur->initiate(rc_canvas[canvas_id].viewport.dimension.Width, rc_canvas[canvas_id].viewport.dimension.Height, dist, strength, SceneManager);

            rc_canvas[canvas_id].post_effect.object = Blur;
        }
        break;

        case RC_POST_PROCESS_MINERAL:
        {
            IPostProcessGlass *Glass = new IPostProcessGlass(SceneManager->getRootSceneNode(), SceneManager, -1);
            float strength = 0.1;
            Glass->initiate(rc_canvas[canvas_id].viewport.dimension.Width, rc_canvas[canvas_id].viewport.dimension.Height, strength, SceneManager);

            rc_canvas[canvas_id].post_effect.object = Glass;
        }
        break;
    }

    if(!rc_canvas[canvas_id].post_effect.object)
    {
        rc_canvas[canvas_id].post_effect.is_active = false;
        rc_canvas[canvas_id].post_effect.type = -1;
        return false;
    }


    return true;
}


void rc_setPostEffectStrength(int canvas_id, double strength)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size())
        return;

    int effect_type = rc_canvas[canvas_id].post_effect.type; //type will be -1 if effect has been removed

    switch(effect_type)
    {
        case RC_POST_PROCESS_BLOOM:
        {
            IPostProcessBloom *Bloom = (IPostProcessBloom*) rc_canvas[canvas_id].post_effect.object;
            Bloom->callback->strength = (float)strength;
        }
        break;

        case RC_POST_PROCESS_COLORIZE:
        {
            IPostProcessColor * PPE_Color = (IPostProcessColor*) rc_canvas[canvas_id].post_effect.object;
            PPE_Color->callback->coloringStrength = (float)strength;
        }
        break;

        case RC_POST_PROCESS_MOTION_BLUR:
        {
            IPostProcessMotionBlur *Blur = (IPostProcessMotionBlur*) rc_canvas[canvas_id].post_effect.object;
            Blur->callback->strength = (float)strength;
        }
        break;

        case RC_POST_PROCESS_RADIAL_BLUR:
        {
            IPostProcessRadialBlur *Blur = (IPostProcessRadialBlur*) rc_canvas[canvas_id].post_effect.object;
            Blur->callback->sampleStrength = (float)strength;
        }
        break;

        case RC_POST_PROCESS_MINERAL:
        {
            IPostProcessGlass *Glass = (IPostProcessGlass*) rc_canvas[canvas_id].post_effect.object;
            Glass->callback->strength = (float)strength;
        }
        break;
    }
}


void rc_setPostEffectDistance(int canvas_id, double dist)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size())
        return;

    int effect_type = rc_canvas[canvas_id].post_effect.type; //type will be -1 if effect has been removed

    switch(effect_type)
    {
        case RC_POST_PROCESS_BLOOM:
        {
            IPostProcessBloom *Bloom = (IPostProcessBloom*) rc_canvas[canvas_id].post_effect.object;
            Bloom->callback->sampleDist = (float)dist;
        }
        break;

        case RC_POST_PROCESS_BLUR:
        {
            IPostProcessBlur *Blur = (IPostProcessBlur*) rc_canvas[canvas_id].post_effect.object;
            Blur->callback->sampleDist = (float)dist;
        }
        break;

        case RC_POST_PROCESS_RADIAL_BLUR:
        {
            IPostProcessRadialBlur *Blur = (IPostProcessRadialBlur*) rc_canvas[canvas_id].post_effect.object;
            Blur->callback->sampleDist = (float)dist;
        }
        break;
    }
}



void rc_setPostEffectMultiplier(int canvas_id, double multiplier)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size())
        return;

    int effect_type = rc_canvas[canvas_id].post_effect.type; //type will be -1 if effect has been removed

    switch(effect_type)
    {
        case RC_POST_PROCESS_BLOOM:
        {
            IPostProcessBloom *Bloom = (IPostProcessBloom*) rc_canvas[canvas_id].post_effect.object;
            Bloom->callback->multiplier = (float)multiplier;
        }
        break;
    }
}


void rc_setPostEffectSaturation(int canvas_id, double saturation)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size())
        return;

    int effect_type = rc_canvas[canvas_id].post_effect.type; //type will be -1 if effect has been removed

    switch(effect_type)
    {
        case RC_POST_PROCESS_COLORIZE:
        {
            IPostProcessColor * PPE_Color = (IPostProcessColor*) rc_canvas[canvas_id].post_effect.object;
            PPE_Color->callback->saturation = (float)saturation;
        }
        break;
    }
}


void rc_setPostEffectColor(int canvas_id, double c_color)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size())
        return;

    int effect_type = rc_canvas[canvas_id].post_effect.type; //type will be -1 if effect has been removed

    switch(effect_type)
    {
        case RC_POST_PROCESS_COLORIZE:
        {
            IPostProcessColor * PPE_Color = (IPostProcessColor*) rc_canvas[canvas_id].post_effect.object;
            PPE_Color->callback->col = irr::video::SColorf( irr::video::SColor((irr::u32) c_color) );
        }
        break;
    }
}


void rc_setPostEffectProperty(int canvas_id, int effect_property, double effect_value)
{
    switch(effect_property)
    {
        case RC_PP_PROPERTY_STRENGTH:
        {
            rc_setPostEffectStrength(canvas_id, effect_value);
        }
        break;

        case RC_PP_PROPERTY_DISTANCE:
        {
            rc_setPostEffectDistance(canvas_id, effect_value);
        }
        break;

        case RC_PP_PROPERTY_MULTIPLIER:
        {
            rc_setPostEffectMultiplier(canvas_id, effect_value);
        }
        break;

        case RC_PP_PROPERTY_SATURATION:
        {
            rc_setPostEffectSaturation(canvas_id, effect_value);
        }
        break;

        case RC_PP_PROPERTY_COLOR:
        {
            rc_setPostEffectColor(canvas_id, effect_value);
        }
        break;
    }
}







double rc_getPostEffectStrength(int canvas_id)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size())
        return 0;

    int effect_type = rc_canvas[canvas_id].post_effect.type; //type will be -1 if effect has been removed

    switch(effect_type)
    {
        case RC_POST_PROCESS_BLOOM:
        {
            IPostProcessBloom *Bloom = (IPostProcessBloom*) rc_canvas[canvas_id].post_effect.object;
            return (double)Bloom->callback->strength;
        }
        break;

        case RC_POST_PROCESS_COLORIZE:
        {
            IPostProcessColor * PPE_Color = (IPostProcessColor*) rc_canvas[canvas_id].post_effect.object;
            return (double)PPE_Color->callback->coloringStrength;
        }
        break;

        case RC_POST_PROCESS_MOTION_BLUR:
        {
            IPostProcessMotionBlur *Blur = (IPostProcessMotionBlur*) rc_canvas[canvas_id].post_effect.object;
            return (double)Blur->callback->strength;
        }
        break;

        case RC_POST_PROCESS_RADIAL_BLUR:
        {
            IPostProcessRadialBlur *Blur = (IPostProcessRadialBlur*) rc_canvas[canvas_id].post_effect.object;
            return (double)Blur->callback->sampleStrength;
        }
        break;

        case RC_POST_PROCESS_MINERAL:
        {
            IPostProcessGlass *Glass = (IPostProcessGlass*) rc_canvas[canvas_id].post_effect.object;
            return (double)Glass->callback->strength;
        }
        break;
    }

    return 0;
}


double rc_getPostEffectDistance(int canvas_id)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size())
        return 0;

    int effect_type = rc_canvas[canvas_id].post_effect.type; //type will be -1 if effect has been removed

    switch(effect_type)
    {
        case RC_POST_PROCESS_BLOOM:
        {
            IPostProcessBloom *Bloom = (IPostProcessBloom*) rc_canvas[canvas_id].post_effect.object;
            return (double)Bloom->callback->sampleDist;
        }
        break;

        case RC_POST_PROCESS_BLUR:
        {
            IPostProcessBlur *Blur = (IPostProcessBlur*) rc_canvas[canvas_id].post_effect.object;
            return (double)Blur->callback->sampleDist;
        }
        break;

        case RC_POST_PROCESS_RADIAL_BLUR:
        {
            IPostProcessRadialBlur *Blur = (IPostProcessRadialBlur*) rc_canvas[canvas_id].post_effect.object;
            return (double)Blur->callback->sampleDist;
        }
        break;
    }

    return 0;
}



double rc_getPostEffectMultiplier(int canvas_id)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size())
        return 0;

    int effect_type = rc_canvas[canvas_id].post_effect.type; //type will be -1 if effect has been removed

    switch(effect_type)
    {
        case RC_POST_PROCESS_BLOOM:
        {
            IPostProcessBloom *Bloom = (IPostProcessBloom*) rc_canvas[canvas_id].post_effect.object;
            return (double)Bloom->callback->multiplier;
        }
        break;
    }

    return 0;
}


double rc_getPostEffectSaturation(int canvas_id)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size())
        return 0;

    int effect_type = rc_canvas[canvas_id].post_effect.type; //type will be -1 if effect has been removed

    switch(effect_type)
    {
        case RC_POST_PROCESS_COLORIZE:
        {
            IPostProcessColor * PPE_Color = (IPostProcessColor*) rc_canvas[canvas_id].post_effect.object;
            return (double)PPE_Color->callback->saturation;
        }
        break;
    }

    return 0;
}


double rc_getPostEffectColor(int canvas_id)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size())
        return 0;

    int effect_type = rc_canvas[canvas_id].post_effect.type; //type will be -1 if effect has been removed

    switch(effect_type)
    {
        case RC_POST_PROCESS_COLORIZE:
        {
            IPostProcessColor * PPE_Color = (IPostProcessColor*) rc_canvas[canvas_id].post_effect.object;
            return (double)PPE_Color->callback->col.toSColor().color;
        }
        break;
    }

    return 0;
}


double rc_getPostEffectProperty(int canvas_id, int effect_property)
{
    switch(effect_property)
    {
        case RC_PP_PROPERTY_STRENGTH:
        {
            return rc_getPostEffectStrength(canvas_id);
        }
        break;

        case RC_PP_PROPERTY_DISTANCE:
        {
            return rc_getPostEffectDistance(canvas_id);
        }
        break;

        case RC_PP_PROPERTY_MULTIPLIER:
        {
            return rc_getPostEffectMultiplier(canvas_id);
        }
        break;

        case RC_PP_PROPERTY_SATURATION:
        {
            return rc_getPostEffectSaturation(canvas_id);
        }
        break;

        case RC_PP_PROPERTY_COLOR:
        {
            return rc_getPostEffectColor(canvas_id);
        }
        break;
    }

    return 0;
}


void rc_setPostEffectActive(int canvas_id, bool flag)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size())
        return;

    rc_canvas[canvas_id].post_effect.is_active = flag;
}

bool rc_postEffectIsActive(int canvas_id)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size())
        return false;

    return rc_canvas[canvas_id].post_effect.is_active;
}



void rc_renderPostEffect(int canvas_id)
{
    if(!rc_canvas[canvas_id].post_effect.is_active)
        return;

    int effect_type = rc_canvas[canvas_id].post_effect.type; //type will be -1 if effect has been removed

    switch(effect_type)
    {
        case RC_POST_PROCESS_BLOOM:
        {
            IPostProcessBloom *Bloom = (IPostProcessBloom*) rc_canvas[canvas_id].post_effect.object;
            Bloom->render();
        }
        break;

        case RC_POST_PROCESS_BLUR:
        {
            IPostProcessBlur *Blur = (IPostProcessBlur*) rc_canvas[canvas_id].post_effect.object;
            Blur->render();
        }
        break;

        case RC_POST_PROCESS_COLORIZE:
        {
            IPostProcessColor * PPE_Color = (IPostProcessColor*) rc_canvas[canvas_id].post_effect.object;
            PPE_Color->render();
        }
        break;

        case RC_POST_PROCESS_INVERT:
        {
            IPostProcessInvert *Invert = (IPostProcessInvert*) rc_canvas[canvas_id].post_effect.object;
            Invert->render();
        }
        break;

        case RC_POST_PROCESS_MOTION_BLUR:
        {
            IPostProcessMotionBlur *Blur = (IPostProcessMotionBlur*) rc_canvas[canvas_id].post_effect.object;
            Blur->renderFinal();
        }
        break;

        case RC_POST_PROCESS_RADIAL_BLUR:
        {
            IPostProcessRadialBlur *Blur = (IPostProcessRadialBlur*) rc_canvas[canvas_id].post_effect.object;
            Blur->render();
        }
        break;

        case RC_POST_PROCESS_MINERAL:
        {
            IPostProcessGlass *Glass = (IPostProcessGlass*) rc_canvas[canvas_id].post_effect.object;
            Glass->render();
        }
        break;
    }

}


int rc_getPostEffectType(int canvas_id)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size())
        return -1;

    if(!rc_canvas[canvas_id].post_effect.is_active)
        return -1;

    return rc_canvas[canvas_id].post_effect.type; //type will be -1 if effect has been removed
}

#endif // RC_POST_FX_H_INCLUDED
