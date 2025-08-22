/**************************************************************
file: CShader.h
author: Stephan Gödecker (Masterhawk studios)
version: rev. 5

description: this file was created to achieve a dynamic
management for GLSL shaders with irrlicht. After implementing
this code-snippet the user is able to dynamically load GLSL-
shader in his irrlicht application. The shader just have to
be additionally defined by a special xml-file. You can get
further information at:

http://www.masterhawk.dyndns.org/wordpress?p=267

***************************************************************/

#include <irrlicht.h>
#include <iostream>
#include "CShader.h"

rc_shader_value_obj rc_shader_float(float n)
{
	rc_shader_value_obj v;
	v.type = RC_SHADER_VALUE_TYPE_FLOAT;
	v.fvalue = n;
	return v;
}

rc_shader_value_obj rc_shader_string(std::string s)
{
	rc_shader_value_obj v;
	v.type = RC_SHADER_VALUE_TYPE_STRING;
	v.svalue = s;
	return v;
}

CShader::CShader(IrrlichtDevice* device, rc_shader_material_obj shader_material)
{

	dev=device;

	f_old_cycle_time = dev->getTimer()->getRealTime();

	driver = device->getVideoDriver();

	//Missing xml-handling

	irr::video::IGPUProgrammingServices* gpu = driver->getGPUProgrammingServices();
	p_material = 0;

	obj_node = 0;

	if(gpu)
	{
		std::cout << "Compiling Shader" << std::endl;
		//std::cout << shader_material.vert_shader << std::endl << std::endl;
		//std::cout << shader_material.frag_shader << std::endl << std::endl;
		p_material = gpu->addHighLevelShaderMaterial(
			shader_material.vert_shader.c_str(), "vertexMain", video::EVST_VS_4_1,
			shader_material.frag_shader.c_str(), "pixelMain", video::EPST_PS_4_1,
			this, video::EMT_SOLID);

		std::cout << "Result: " << p_material << std::endl;
	}


	for(s32 i=0; i<shader_material.shader_object.size(); i++)
	{
		//create new uniform variable
		SShaderVariable* shader_var = new SShaderVariable();
		shader_var->predefinition = ESPV_NONE;

		irr::core::stringc type( shader_material.shader_object[i].type.c_str() );

		if(type.equals_ignore_case("float"))
			shader_var->type = ESVT_FLOAT;
		else if(type.equals_ignore_case("vec2"))
			shader_var->type = ESVT_VEC2;
		else if(type.equals_ignore_case("vec3"))
			shader_var->type = ESVT_VEC3;
		else if(type.equals_ignore_case("vec4"))
			shader_var->type = ESVT_VEC4;
		else if(type.equals_ignore_case("mat4"))
			shader_var->type = ESVT_MAT4;
		else if(type.equals_ignore_case("sampler2d"))
			shader_var->type = ESVT_SAMPLER2D;
		else if(type.equals_ignore_case("predefined"))
			shader_var->type = ESVT_PREDEFINED;

		shader_var->name = core::stringc( shader_material.shader_object[i].name.c_str() );


		shader_var->b_frag_var = shader_material.shader_object[i].fragVar;

		switch(shader_var->type)
		{
		case ESVT_SAMPLER2D:
		case ESVT_FLOAT:
		{
			float* vars = new float[1];
			vars[0] = shader_material.shader_object[i].value[0].fvalue;
			shader_var->value = vars;

		}break;

		/*case ESVT_SAMPLER2D:
		{
			int tex = 0;

			TiXmlNode* value = node->FirstChild("value");

			tex = ((TiXmlElement*)value)->FirstAttribute()->IntValue();

			float* vars = new float[1];
			vars = (float*)(&tex);
			shader_var->value = vars;
		}break;*/

		case ESVT_VEC2:
		{
			float* vars = new float[2];

			for(s32 j=0; j<2; j++)
			{
				vars[j] = shader_material.shader_object[i].value[j].fvalue;
			}
			shader_var->value = vars;
		}break;

		case ESVT_VEC3:
		{
			float* vars = new float[3];

			for(s32 j=0; j<3; j++)
			{
				vars[j] = shader_material.shader_object[i].value[j].fvalue;
			}
			shader_var->value = vars;
		}break;

		case ESVT_VEC4:
		{
			float* vars = new float[4];

			for(s32 j=0; j<4; j++)
			{
				vars[j] = shader_material.shader_object[i].value[j].fvalue;
			}
			shader_var->value = vars;
		}break;

		case ESVT_MAT4:
			break;

		case ESVT_PREDEFINED:
		{
			core::stringc str_val(shader_material.shader_object[i].value[0].svalue.c_str());

			shader_var->value = 0;

			if(str_val.equals_ignore_case("predefined_eye_position"))
				shader_var->predefinition = ESPV_EYEPOSITION;
			else if(str_val.equals_ignore_case("predefined_mat4_view_proj"))
			{
				shader_var->predefinition = ESPV_MAT4_VIEW_PROJ;
			}
			else if(str_val.equals_ignore_case("predefined_mat4_view"))
			{
				shader_var->predefinition = ESPV_MAT4_VIEW;
			}
			else if(str_val.equals_ignore_case("predefined_float_time0x"))
			{
				shader_var->predefinition = ESPV_FLOAT_TIME0X;
				shader_var->value = new float[1];
				shader_var->value[0] = 0.f;
			}
			else if(str_val.equals_ignore_case("predefined_rtt_view"))
			{
				shader_var->predefinition = ESPV_NONE;
				shader_var->type = ESVT_SAMPLER2D;

				float* vars = new float[1];

				vars[0] = (shader_material.shader_object[i].additional_value.size() > 0 ? shader_material.shader_object[i].additional_value[0].fvalue : 0);

				shader_var->value = vars;

				//registering for RTT_VIEW
				S_RTT_Info* rtt_info = new S_RTT_Info();
				rtt_info->type = ERT_VIEW;
				rtt_info->tex_channel = (int)vars[0];
				rtt_infos.push_back(rtt_info);

				rtt_info = 0;

			}
			else if(str_val.equals_ignore_case("predefined_toonLightPos_position"))
			{
				shader_var->predefinition = ESPV_RC_TOON_LIGHTPOS;
			}
			else
				printf("ERROR: Unknown predefinition: %s\n",str_val.c_str());


			break;
		}

		default:
///			printf("(XML PARSER) ERROR: No type for uniform shader variable specified: %s\n",shader_var->name);
			break;
		}//end switch

		uniform_variables.push_back(shader_var);
	}
	//printf("(MATERIAL PARSER) Initialized %i uniform variables\n",uniform_variables.size());
	for(s32 i=0; i<uniform_variables.size(); i++)
	{
		//printf("(MATERIAL PARSER) VAR%i: %s VALUE: ",i,uniform_variables[i]->name.c_str());
		if(uniform_variables[i]->type == ESVT_PREDEFINED)
		{
			continue;
		}
		s32 element_count = (uniform_variables[i]->type != ESVT_SAMPLER2D) ? (s32)uniform_variables[i]->type : 1;
		//for(s32 j=0; j<element_count; j++)
			//if(uniform_variables[i]->type != ESVT_SAMPLER2D)
				//printf("%f ",(uniform_variables[i]->value[j]));
			//else
				//printf("%i",*uniform_variables[i]->value);
		//printf("\n\n");
	}
}

void CShader::OnSetConstants(video::IMaterialRendererServices* services, s32 userData)
{
	for(s32 i=0; i<uniform_variables.size(); i++)
	{
		int element_count = 0;
		switch(uniform_variables[i]->type)
		{
		case ESVT_SAMPLER2D:
			element_count = 1;
			break;
		case ESVT_PREDEFINED:
		{
			switch(uniform_variables[i]->predefinition)
			{
				case ESPV_EYEPOSITION:
				{
					if(uniform_variables[i]->value)
					{
						delete[] uniform_variables[i]->value;
						uniform_variables[i]->value = 0;
					}

					uniform_variables[i]->value = new float[3];
					core::vector3df cam_pos = dev->getSceneManager()->getActiveCamera()->getAbsolutePosition();
					uniform_variables[i]->value[0] = cam_pos.X;
					uniform_variables[i]->value[1] = cam_pos.Y;
					uniform_variables[i]->value[2] = cam_pos.Z;

					element_count = 3;
				}
				break;

				case ESPV_MAT4_VIEW:
				{
					core::matrix4 mat_view = dev->getVideoDriver()->getTransform(video::ETS_VIEW);

					uniform_variables[i]->value = mat_view.pointer();

					element_count = 16;
				}
				break;

				case ESPV_MAT4_VIEW_PROJ:
				{
					core::matrix4 mat_view_proj =  dev->getVideoDriver()->getTransform(video::ETS_PROJECTION);

					mat_view_proj *= dev->getVideoDriver()->getTransform(video::ETS_VIEW);

					uniform_variables[i]->value = mat_view_proj.pointer();

					element_count = 16;

					/*printf("VIEW_PROJECTION_MATRIX\n");
					for(int k=0; k<16; k++)
					{
						printf("%f ",uniform_variables[i]->value[k]);
						if(k==3 || k==7 || k==11 || k==15) printf("\n");
					}*/
				}
				break;

				case ESPV_FLOAT_TIME0X:
				{

					f32 f_time_diff = dev->getTimer()->getRealTime() - f_old_cycle_time;

					uniform_variables[i]->value[0] += f_time_diff / 1000;

					s32 i_tmp = uniform_variables[i]->value[0] / 120;

					uniform_variables[i]->value[0] = uniform_variables[i]->value[0] - (i_tmp*120);

					f_old_cycle_time = dev->getTimer()->getRealTime();

					element_count = 1;

					//printf("FLOAT_TIME0X = %f\n",uniform_variables[i]->value[0]);
				}
				break;

				case ESPV_RC_TOON_LIGHTPOS:
				{
					if(this->obj_node != NULL)
					{
						core::vector3df pos_in_world_space = dev->getSceneManager()->getActiveCamera()->getAbsolutePosition();
						core::vector3df pos_in_node_space(pos_in_world_space);

						core::matrix4 world_to_local = this->obj_node->getAbsoluteTransformation();
						world_to_local.makeInverse();

						world_to_local.transformVect(pos_in_world_space);
						f32 lightPos[3] = { pos_in_world_space.X, pos_in_world_space.Y, pos_in_world_space.Z };
						services->setVertexShaderConstant("lightPos", lightPos, 3);
					}
				}
				break;
			}
		}
		default:
			element_count = (s32)uniform_variables[i]->type;
		}
		if(uniform_variables[i]->b_frag_var)
			if(uniform_variables[i]->type != ESVT_SAMPLER2D)
				services->setPixelShaderConstant(uniform_variables[i]->name.c_str(),uniform_variables[i]->value,element_count);
			else
			{
				int tex = *uniform_variables[i]->value;
				services->setPixelShaderConstant(uniform_variables[i]->name.c_str(),(float*)(&tex),element_count);
			}

		else
			if(uniform_variables[i]->type != ESVT_SAMPLER2D)
				services->setVertexShaderConstant(uniform_variables[i]->name.c_str(),uniform_variables[i]->value,element_count);
			else
			{
				int tex = *uniform_variables[i]->value;
				services->setVertexShaderConstant(uniform_variables[i]->name.c_str(),(int*)(&tex),element_count);
			}

	}

}

void CShader::setObjectNode(irr::scene::ISceneNode* node)
{
	this->obj_node = node;
}

s32 CShader::getMaterial()
{
	return p_material;
}

int CShader::getUniformVariableCount()
{
	return uniform_variables.size();
}

SShaderVariable* CShader::getUniformVariable(int i)
{
	if(i < 0 || i >= uniform_variables.size())
		return NULL;

	return uniform_variables[i];
}

S_RTT_Info* CShader::getRTTInfo(E_RTT_TEXTURE rtt)
{
	for(s32 i=0; i<rtt_infos.size(); i++)
	{
		if(rtt == rtt_infos[i]->type)
			return rtt_infos[i];
	}
	return 0;
}

CShader::~CShader()
{
	for(s32 i=0; i<uniform_variables.size(); i++)
	{
		if(uniform_variables[i]->predefinition != ESPV_MAT4_VIEW_PROJ && uniform_variables[i]->predefinition != ESPV_MAT4_VIEW)
			delete[] uniform_variables[i]->value;

		delete uniform_variables[i];
		uniform_variables[i] = 0;
	}
	uniform_variables.clear();
}
