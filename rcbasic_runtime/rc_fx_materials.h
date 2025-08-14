#ifndef RC_FX_MATERIALS_H_INCLUDED
#define RC_FX_MATERIALS_H_INCLUDED

#include <irrlicht.h>
//don't forget to include the CShader source
#include "CShader.h"
#include "rc_fx_shaders.h"
#include "rc_stdlib.h"

#define RC_FX_MATERIAL_BASE_INDEX	128

irr::core::array<rc_shader_material_obj> rc_shader_materials;


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
void registerSceneNodeForRTT(irr::video::IVideoDriver* rtt_driver, irr::scene::ISceneNode* node, S_RTT_Info* rtt_info)
{
	if(node && rtt_info)
	{
		switch(rtt_info->type)
		{
			case ERT_VIEW:
			{
				if(scenenodes_for_rtt_view.size() <= 0)
					tex_rtt_view = rtt_driver->addRenderTargetTexture( core::dimension2d<u32>(256,256) );

				scenenodes_for_rtt_view.push_back(node);
				node->setMaterialTexture(rtt_info->tex_channel,tex_rtt_view);
			}
		}
	}
}

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



void init_refraction2()
{
	rc_shader_material_obj shader_material;

	shader_material.frag_shader = refraction2_frag;
	shader_material.vert_shader = refraction2_vert;

	rc_shader_materials.push_back(shader_material);
}




void init_gooch()
{
	rc_shader_material_obj shader_material;

	rc_shader_obj obj;

	obj.name = "SurfaceColor";
	obj.type = "vec3";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(0.75000));
	obj.value.push_back(rc_shader_float(0.75000));
	obj.value.push_back(rc_shader_float(0.75000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "WarmColor";
	obj.type = "vec3";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(0.60000));
	obj.value.push_back(rc_shader_float(0.60000));
	obj.value.push_back(rc_shader_float(0.00000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "CoolColor";
	obj.type = "vec3";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(0.00000));
	obj.value.push_back(rc_shader_float(0.00000));
	obj.value.push_back(rc_shader_float(0.60000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "DiffuseWarm";
	obj.type = "float";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(0.45000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "DiffuseCool";
	obj.type = "float";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(0.45000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();


	shader_material.frag_shader = gooch_frag;
	shader_material.vert_shader = gooch_vert;

	rc_shader_materials.push_back(shader_material);
}




void init_style()
{
	rc_shader_material_obj shader_material;

	rc_shader_obj obj;

	obj.name = "lightPos";
	obj.type = "predefined";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_string("predefined_toonLightPos_position"));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();


	shader_material.frag_shader = style_frag;
	shader_material.vert_shader = style_vert;

	rc_shader_materials.push_back(shader_material);
}




void init_normalShade()
{
	rc_shader_material_obj shader_material;

	rc_shader_obj obj;

	obj.name = "Alpha";
	obj.type = "float";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(1.0));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	shader_material.frag_shader = glass_frag;
	shader_material.vert_shader = glass_vert;

	rc_shader_materials.push_back(shader_material);
}





void init_outline()
{
	rc_shader_material_obj shader_material;

	rc_shader_obj obj;

	obj.name = "SurfaceColor";
	obj.type = "vec3";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(0.75000));
	obj.value.push_back(rc_shader_float(0.75000));
	obj.value.push_back(rc_shader_float(0.75000));
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


	shader_material.frag_shader = outline_frag;
	shader_material.vert_shader = outline_vert;

	rc_shader_materials.push_back(shader_material);
}




void init_plastic()
{
	rc_shader_material_obj shader_material;

	rc_shader_obj obj;

	obj.name = "Color";
	obj.type = "vec4";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(0.80000));
	obj.value.push_back(rc_shader_float(0.00000));
	obj.value.push_back(rc_shader_float(0.00000));
	obj.value.push_back(rc_shader_float(1.00000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "intensity";
	obj.type = "float";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(1.0));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();


	shader_material.frag_shader = plastic_frag;
	shader_material.vert_shader = plastic_vert;

	rc_shader_materials.push_back(shader_material);
}




void init_tangent()
{
	rc_shader_material_obj shader_material;

	rc_shader_obj obj;

	obj.name = "matView";
	obj.type = "predefined";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_string("predefined_mat4_view"));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "bViewSpace";
	obj.type = "float";
	obj.fragVar = false;
	obj.artistVar = true;
	obj.value.push_back(rc_shader_float(1.0));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	shader_material.frag_shader = tangent_frag;
	shader_material.vert_shader = tangent_vert;

	rc_shader_materials.push_back(shader_material);
}




void init_speaker()
{
	rc_shader_material_obj shader_material;

	rc_shader_obj obj;

	obj.name = "view_proj_matrix";
	obj.type = "predefined";
	obj.fragVar = false;
	obj.artistVar = true;
	obj.value.push_back(rc_shader_string("predefined_mat4_view_proj"));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "view_matrix";
	obj.type = "predefined";
	obj.fragVar = false;
	obj.artistVar = true;
	obj.value.push_back(rc_shader_string("predefined_mat4_view"));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "time_0_X";
	obj.type = "predefined";
	obj.fragVar = false;
	obj.artistVar = true;
	obj.value.push_back(rc_shader_string("predefined_float_time0x"));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "pulseSharpness";
	obj.type = "float";
	obj.fragVar = false;
	obj.artistVar = true;
	obj.value.push_back(rc_shader_float(14.00000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "beat";
	obj.type = "float";
	obj.fragVar = false;
	obj.artistVar = true;
	obj.value.push_back(rc_shader_float(2.2500));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "amplitude";
	obj.type = "float";
	obj.fragVar = false;
	obj.artistVar = true;
	obj.value.push_back(rc_shader_float(2.4000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "bassFrequency";
	obj.type = "float";
	obj.fragVar = false;
	obj.artistVar = true;
	obj.value.push_back(rc_shader_float(44.0000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "base";
	obj.type = "sampler2d";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(0));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	shader_material.frag_shader = speaker_frag;
	shader_material.vert_shader = speaker_vert;

	rc_shader_materials.push_back(shader_material);
}




void init_phong()
{
	rc_shader_material_obj shader_material;

	rc_shader_obj obj;

	obj.name = "fvAmbient";
	obj.type = "vec4";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(0.3686));
	obj.value.push_back(rc_shader_float(0.3684));
	obj.value.push_back(rc_shader_float(0.3684));
	obj.value.push_back(rc_shader_float(1.0000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "fvSpecular";
	obj.type = "vec4";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(0.4902));
	obj.value.push_back(rc_shader_float(0.4887));
	obj.value.push_back(rc_shader_float(0.4887));
	obj.value.push_back(rc_shader_float(1.0000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "fvDiffuse";
	obj.type = "vec4";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(0.8863));
	obj.value.push_back(rc_shader_float(0.8850));
	obj.value.push_back(rc_shader_float(0.8850));
	obj.value.push_back(rc_shader_float(1.0000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "fSpecularPower";
	obj.type = "float";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(25.0000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "baseMap";
	obj.type = "sampler2d";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(0.0000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "fvEyePosition";
	obj.type = "predefined";
	obj.fragVar = false;
	obj.artistVar = true;
	obj.value.push_back(rc_shader_string("predefined_eye_position"));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	shader_material.frag_shader = tx_phong_frag;
	shader_material.vert_shader = tx_phong_vert;

	rc_shader_materials.push_back(shader_material);
}




void init_style2()
{
	rc_shader_material_obj shader_material;

	rc_shader_obj obj;

	obj.name = "baseMap";
	obj.type = "sampler2d";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(0.0000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	shader_material.frag_shader = style2_frag;
	shader_material.vert_shader = style2_vert;

	rc_shader_materials.push_back(shader_material);
}




void init_style3()
{
	rc_shader_material_obj shader_material;

	rc_shader_obj obj;

	shader_material.frag_shader = style3_frag;
	shader_material.vert_shader = style3_vert;

	rc_shader_materials.push_back(shader_material);
}




void init_style4()
{
	rc_shader_material_obj shader_material;

	rc_shader_obj obj;

	obj.name = "silhouetteThreshold";
	obj.type = "float";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(0.2000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "silhouetteColor";
	obj.type = "vec4";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(1.0000));
	obj.value.push_back(rc_shader_float(1.0000));
	obj.value.push_back(rc_shader_float(1.0000));
	obj.value.push_back(rc_shader_float(1.0000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "enableLighting";
	obj.type = "float";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(1.0000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	obj.name = "tex";
	obj.type = "sampler2d";
	obj.fragVar = true;
	obj.artistVar = false;
	obj.value.push_back(rc_shader_float(0.0000));
	shader_material.shader_object.push_back(obj);
	obj.value.clear();
	obj.additional_value.clear();

	shader_material.frag_shader = style4_frag;
	shader_material.vert_shader = style4_vert;

	rc_shader_materials.push_back(shader_material);
}


void initFXMaterials()
{
	//IMPORTANT NOTE: THESE HAVE TO BE ADDED IN THIS ORDER SO THEY MATCH THE ORDER I SPECIFIED FOR THE CONSTANTS IN THE TOKENIZER

	init_normalShade();	//FX_MATERIAL_TYPE_NORMAL_BLEND
	init_refraction1();	//FX_MATERIAL_TYPE_REFRACTION
	init_refraction2();	//FX_MATERIAL_TYPE_REFRACTION2
	init_gooch();	//FX_MATERIAL_TYPE_GOOCH
	init_plastic();	//FX_MATERIAL_TYPE_PLASTIC
	init_tangent();	//FX_MATERIAL_TYPE_TANGENT
	init_speaker();	//FX_MATERIAL_TYPE_SPEAKER
	init_phong();	//FX_MATERIAL_TYPE_PHONG_TEXTURE
	init_style();	//FX_MATERIAL_TYPE_STYLE
	init_style2();	//FX_MATERIAL_TYPE_STYLE2
	init_style3();	//FX_MATERIAL_TYPE_STYLE3
	init_style4();	//FX_MATERIAL_TYPE_STYLE4
}


int rc_numMaterialConstants(int material_type)
{
	if(material_type < RC_FX_MATERIAL_BASE_INDEX || material_type >= (RC_FX_MATERIAL_BASE_INDEX + rc_shader_materials.size()))
		return 0;

	int shader_m_id = material_type - RC_FX_MATERIAL_BASE_INDEX;
	return rc_shader_materials[shader_m_id].shader_object.size();
}

std::string rc_getMaterialConstantName(int material_type, int index)
{
	if(material_type < RC_FX_MATERIAL_BASE_INDEX || material_type >= (RC_FX_MATERIAL_BASE_INDEX + rc_shader_materials.size()))
		return "";

	int shader_m_id = material_type - RC_FX_MATERIAL_BASE_INDEX;
	if(index < 0 || index >= rc_shader_materials[shader_m_id].shader_object.size())
		return "";

	return rc_intern_ucase(rc_shader_materials[shader_m_id].shader_object[index].name);
}

void rc_setMaterialConstant(int material_id, std::string m_constant, double n1, double n2, double n3, double n4)
{
    if(material_id < 0 || material_id >= rc_material.size())
		return;

    if(!rc_material[material_id].isFX)
        return;

    float m_constant_value[] = {n1, n2, n3, n4};

    m_constant = rc_intern_trim(rc_intern_lcase(m_constant));

    for(int i = 0; i < rc_material[material_id].shader->getUniformVariableCount(); i++)
    {
        std::string u_var(rc_material[material_id].shader->getUniformVariable(i)->name.c_str());
        u_var = rc_intern_trim(rc_intern_lcase(u_var));
        if(u_var.compare(m_constant)==0)
        {
            rc_material[material_id].shader->getUniformVariable(i)->value = m_constant_value;
            break;
        }
    }
}

void rc_getMaterialConstant(int material_id, std::string m_constant, double* n1, double* n2, double* n3, double* n4)
{
    if(material_id < 0 || material_id >= rc_material.size())
		return;

    if(!rc_material[material_id].isFX)
        return;

    *n1 = 0;
    *n2 = 0;
    *n3 = 0;
    *n4 = 0;

    m_constant = rc_intern_trim(rc_intern_lcase(m_constant));

    for(int i = 0; i < rc_material[material_id].shader->getUniformVariableCount(); i++)
    {
        std::string u_var(rc_material[material_id].shader->getUniformVariable(i)->name.c_str());
        u_var = rc_intern_trim(rc_intern_lcase(u_var));
        if(u_var.compare(m_constant)==0)
        {
            switch(rc_material[material_id].shader->getUniformVariable(i)->type)
            {
                case ESVT_FLOAT:
                {
                    *n1 = rc_material[material_id].shader->getUniformVariable(i)->value[0];
                }
                break;
                ESVT_VEC2:
                {
                    *n1 = rc_material[material_id].shader->getUniformVariable(i)->value[0];
                    *n2 = rc_material[material_id].shader->getUniformVariable(i)->value[1];
                }
                break;
                ESVT_VEC3:
                {
                    *n1 = rc_material[material_id].shader->getUniformVariable(i)->value[0];
                    *n2 = rc_material[material_id].shader->getUniformVariable(i)->value[1];
                    *n3 = rc_material[material_id].shader->getUniformVariable(i)->value[2];
                }
                break;
                ESVT_VEC4:
                {
                    *n1 = rc_material[material_id].shader->getUniformVariable(i)->value[0];
                    *n2 = rc_material[material_id].shader->getUniformVariable(i)->value[1];
                    *n3 = rc_material[material_id].shader->getUniformVariable(i)->value[2];
                    *n4 = rc_material[material_id].shader->getUniformVariable(i)->value[3];
                }
                break;
            }
            break;
        }
    }
}



#endif // RC_FX_MATERIALS_H_INCLUDED
