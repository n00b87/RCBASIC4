/*	DynamicShaderExample
*	Masterhawk studios 2011 - http://masterhawk.dyndns.org/wordpress
*
*	Description:
*	This is a simple example how to use the "Dynamic Shaders for Irrlicht"
*	by Masterhawk studios in your own application. This example shows how
*	to use all provided features, especially the glass refraction, since
*	it needs your application to support RTTs
*/

//////////////////////////////////
// DON'T FORGET TO LINK 		//
//								//
// IRRLICHT.LIB					//
// IRRLICHT-INCLUDE-DIRECTORY	//
// TINYXML.LIB					//
// TINYXML-INCLUDE-DIRECTORY	//
//								//
// TO YOUR PROJECT				//
//////////////////////////////////

//stdafx inlcudes the irrlicht.h inclusion
//#include "stdafx.h"
#include <irrlicht.h>
//don't forget to include the CShader source
#include "CShader.h"


//simple Irrlicht setup stuff
using namespace irr;

IrrlichtDevice* device = 0;
video::IVideoDriver* driver = 0;
scene::ISceneManager* smgr = 0;
scene::ICameraSceneNode* cam = 0;

std::string refraction1_vert =
"varying vec3  Normal; \n"
"varying vec3  EyeDir; \n"
"varying vec4  EyePos; \n"
"varying float LightIntensity; \n"
"\n"
"void main(void) \n"
"{ \n"
"    gl_Position    = ftransform(); \n"
"    Normal         = normalize(gl_NormalMatrix * gl_Normal); \n"
"    vec4 pos       = gl_ModelViewMatrix * gl_Vertex; \n"
"    EyeDir         = pos.xyz; \n"
"    EyePos         = gl_ModelViewProjectionMatrix * gl_Vertex; \n"
"    LightIntensity = max(dot(normalize(gl_LightSource[0].position.xyz - EyeDir), Normal), 0.0); \n"
"}";

std::string refraction1_frag =
"const vec3 Xunitvec = vec3 (1.0, 0.0, 0.0); \n"
"const vec3 Yunitvec = vec3 (0.0, 1.0, 0.0); \n"
" \n"
"uniform vec3  BaseColor; \n"
"uniform float Depth; \n"
"uniform float MixRatio; \n"
" \n"
"// need to scale our framebuffer - it has a fixed width/height of 2048 \n"
"uniform float FrameWidth; \n"
"uniform float FrameHeight; \n"
" \n"
"uniform sampler2D EnvMap; \n"
"uniform sampler2D RefractionMap; \n"
" \n"
"varying vec3  Normal; \n"
"varying vec3  EyeDir; \n"
"varying vec4  EyePos; \n"
"varying float LightIntensity; \n"
" \n"
"void main (void) \n"
"{ \n"
"    // Compute reflection vector \n"
"    vec3 reflectDir = reflect(EyeDir, Normal); \n"
" \n"
"    // Compute altitude and azimuth angles \n"
" \n"
"    vec2 index; \n"
" \n"
"    index.y = dot(normalize(reflectDir), Yunitvec); \n"
"    reflectDir.y = 0.0; \n"
"    index.x = dot(normalize(reflectDir), Xunitvec) * 0.5; \n"
" \n"
"    // Translate index values into proper range \n"
" \n"
"    if (reflectDir.z >= 0.0) \n"
"        index = (index + 1.0) * 0.5; \n"
"    else \n"
"    { \n"
"        index.t = (index.t + 1.0) * 0.5; \n"
"        index.s = (-index.s) * 0.5 + 1.0; \n"
"    } \n"
"    \n"
"    // if reflectDir.z >= 0.0, s will go from 0.25 to 0.75 \n"
"    // if reflectDir.z <  0.0, s will go from 0.75 to 1.25, and \n"
"    // that's OK, because we've set the texture to wrap. \n"
"  \n"
"    // Do a lookup into the environment map. \n"
" \n"
"    vec3 envColor = vec3 (texture2D(EnvMap, index)); \n"
"    \n"
"    // calc fresnels term.  This allows a view dependant blend of reflection/refraction \n"
"    float fresnel = abs(dot(normalize(EyeDir), Normal)); \n"
"    fresnel *= MixRatio; \n"
"    fresnel = clamp(fresnel, 0.1, 0.9); \n"
" \n"
"   // calc refraction \n"
"   vec3 refractionDir = normalize(EyeDir) - normalize(Normal); \n"
" \n"
"   // Scale the refraction so the z element is equal to depth \n"
"   float depthVal = Depth / -refractionDir.z; \n"
"    \n"
"   // perform the div by w \n"
"   float recipW = 1.0 / EyePos.w; \n"
"   vec2 eye = EyePos.xy * vec2(recipW); \n"
" \n"
"   // calc the refraction lookup \n"
"   index.s = (eye.x + refractionDir.x * depthVal); \n"
"   index.t = (eye.y + refractionDir.y * depthVal); \n"
"    \n"
"   // scale and shift so we're in the range 0-1 \n"
"   index.s = index.s / 2.0 + 0.5; \n"
"   index.t = index.t / 2.0 + 0.5; \n"
"    \n"
"   // as we're looking at the framebuffer, we want it clamping at the edge of the rendered scene, not the edge of the texture, \n"
"   // so we clamp before scaling to fit \n"
"   float recip1k = 1.0 / 255.0; \n"
"   index.s = clamp(index.s, 0.0, 1.0 - recip1k); \n"
"   index.t = clamp(index.t, 0.0, 1.0 - recip1k); \n"
"    \n"
"   // scale the texture so we just see the rendered framebuffer \n"
"   index.s = index.s * FrameWidth * recip1k; \n"
"   index.t = index.t * FrameHeight * recip1k; \n"
"    \n"
"    vec3 RefractionColor = vec3 (texture2D(RefractionMap, index)); \n"
"    \n"
"    // Add lighting to base color and mix \n"
"    vec3 base = LightIntensity * BaseColor; \n"
"    envColor = mix(envColor, RefractionColor, fresnel); \n"
"    envColor = mix(envColor, base, 0.2); \n"
" \n"
"    gl_FragColor = vec4 (envColor, 1.0); \n"
"}";

irr::core::array<rc_shader_material_obj> rc_shader_materials;

void init_refraction1()
{
	rc_shader_material_obj shader_material;

	rc_shader_obj obj;

	obj.name = "BaseColor";
	obj.type = "vec3";
	obj.fragVar = true;
	obj.artistVar = true;
	obj.value.push_back(rc_shader_float(0.40000));
	obj.value.push_back(rc_shader_float(0.40000));
	obj.value.push_back(rc_shader_float(0.10000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "Depth";
	obj.type = "float";
	obj.fragVar = true;
	obj.artistVar = true;
	obj.value.push_back(rc_shader_float(0.10000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "MixRatio";
	obj.type = "float";
	obj.fragVar = true;
	obj.artistVar = true;
	obj.value.push_back(rc_shader_float(1.0000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "FrameHeight";
	obj.type = "float";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(255.0000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "FrameWidth";
	obj.type = "float";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(255.0000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "EnvMap";
	obj.type = "sampler2d";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(0));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "RefractionMap";
	obj.type = "predefined";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_string("predefined_rtt_view"));
	obj.additional_value.push_back(rc_shader_float(1));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	shader_material.frag_shader = refraction1_frag;
	shader_material.vert_shader = refraction1_vert;

	rc_shader_materials.push_back(shader_material);
}

std::string refraction2_frag;
std::string refraction2_vert;

void init_refraction2()
{
	rc_shader_material_obj shader_material;

	shader_material.frag_shader = refraction2_frag;
	shader_material.vert_shader = refraction2_vert;

	rc_shader_materials.push_back(shader_material);
}


//Now we have to set up a simple Render-To-Texture management
//-----------------------------------------------------------
//scenenode_for_rtt_view:
//Here all scenenodes get stored which use a shader with RTT requirement.
//This is currently just the glass refraction shader
core::array<scene::ISceneNode*> scenenodes_for_rtt_view;

//tex_rtt_view:
//The texture which holds the texture render from the view position.
//There's currently no other RTT-type supported. Each type would need
//its own texture.
video::ITexture* tex_rtt_view = 0;


//Adds a scenenode to the RTT-queue if it has a RTT-requirement
//These information are all provided and handled by the DynamicShader files.
void registerSceneNodeForRTT(scene::ISceneNode* node, S_RTT_Info* rtt_info)
{
	if(node && rtt_info)
	{
		switch(rtt_info->type)
		{
		case ERT_VIEW:
		{
			if(scenenodes_for_rtt_view.size() <= 0)
				tex_rtt_view = driver->addRenderTargetTexture( core::dimension2d<u32>(256,256) );

			scenenodes_for_rtt_view.push_back(node);
			node->setMaterialTexture(rtt_info->tex_channel,tex_rtt_view);
		}
		}
	}
}

int main()
{
	//again simple Irrlicht setup/loading stuff
	device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(800,600));
	if(!device) return -1;

	driver = device->getVideoDriver();
	if(!driver) return -2;

	smgr = device->getSceneManager();
	if(!smgr) return -3;

	cam = smgr->addCameraSceneNodeMaya();

	device->setWindowCaption(L"Dynamic Shader Example - Masterhawk studios 2011");


	//loading the angel model
	scene::ISceneNode* glass_angel = smgr->addMeshSceneNode(smgr->getMesh("./meshes/statue_angel.obj"));
	//setting up the environment texture for the simulated reflection.
	//In IrrShaderViewer this is achieved by the settings xml files.
	glass_angel->setMaterialTexture(0,driver->getTexture("./media/House.jpg"));

	//disable lighting. This shader doesn't need a light source
	glass_angel->setMaterialFlag(video::EMF_LIGHTING,false);

	//loading the shader-defintion and create a shader. Don't forget to delete
	//the pointer!
	init_refraction1();
	CShader* glass_shader = new CShader(device, rc_shader_materials[0]);

	//assigning the shader to the scenenode
	if(glass_shader)
		glass_angel->setMaterialType((video::E_MATERIAL_TYPE)glass_shader->getMaterial());

	//register the scenenode for RTT handling. This is made for every scenenode, no
	//matter if its shader requires RTT support or not. The registerSceneNodeForRTT()
	//takes care of this
	registerSceneNodeForRTT(glass_angel,glass_shader->getRTTInfo(ERT_VIEW));

	//adding a skybox so you can see a transparency effect
	smgr->addSkyBoxSceneNode(
		driver->getTexture("./media/irrlicht2_up.jpg"),
		driver->getTexture("./media/irrlicht2_dn.jpg"),
		driver->getTexture("./media/irrlicht2_lf.jpg"),
		driver->getTexture("./media/irrlicht2_rt.jpg"),
		driver->getTexture("./media/irrlicht2_ft.jpg"),
		driver->getTexture("./media/irrlicht2_bk.jpg"));

	while(device->run())
	{
		driver->beginScene(true, true, video::SColor(255,100,100,100));

		//creating the RTT-VIEW texture for every frame
		if(scenenodes_for_rtt_view.size() > 0)
		{
			for(s32 i=0; i<scenenodes_for_rtt_view.size(); i++)
				scenenodes_for_rtt_view[i]->setVisible(false);

			driver->setRenderTarget(tex_rtt_view);
			smgr->drawAll();
			driver->setRenderTarget(0);

			for(s32 i=0; i<scenenodes_for_rtt_view.size(); i++)
				scenenodes_for_rtt_view[i]->setVisible(true);
		}

		//just the normal rendering
		smgr->drawAll();
		driver->endScene();
	}

	device->drop();

	//deleting the shader
	delete glass_shader;

	return 0;
}

