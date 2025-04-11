#ifndef CSHADER_H_INCLUDED
#define CSHADER_H_INCLUDED

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

//#include "stdafx.h"
#include <irrlicht.h>
#include <string>

using namespace irr;

#define RC_SHADER_VALUE_TYPE_FLOAT	0
#define RC_SHADER_VALUE_TYPE_STRING	1

struct rc_shader_value_obj
{
	int type;
	float fvalue;
	std::string svalue;
};

rc_shader_value_obj rc_shader_float(float n);
rc_shader_value_obj rc_shader_string(std::string s);

struct rc_shader_obj
{
	std::string name;
	std::string type;
	bool fragVar;
	bool artistVar;
	irr::core::array<rc_shader_value_obj> value;
	irr::core::array<rc_shader_value_obj> additional_value;
};

struct rc_shader_material_obj
{
	std::string frag_shader;
	std::string vert_shader;
	irr::core::array<rc_shader_obj> shader_object;
};

enum E_SHADER_VAR_TYPE
{
	ESVT_FLOAT = 1,
	ESVT_VEC2 = 2,
	ESVT_VEC3 = 3,
	ESVT_VEC4 = 4,
	ESVT_MAT4 = 16,
	ESVT_SAMPLER2D,
	ESVT_PREDEFINED
};
enum E_SHADER_PREDEFINED_VARS
{
	ESPV_NONE,
	ESPV_FLOAT_TIME0X,
	ESPV_EYEPOSITION,
	ESPV_MAT4_VIEW,
	ESPV_MAT4_VIEW_PROJ,
	ESPV_RTT_VIEW,
	ESPV_RC_TOON_LIGHTPOS
};

enum E_RTT_TEXTURE
{
	ERT_VIEW = 0x0001
};

struct S_RTT_Info
{
	E_RTT_TEXTURE type;
	s32 tex_channel;
};

struct SShaderVariable
{
	core::stringc name;
	E_SHADER_VAR_TYPE type;
	E_SHADER_PREDEFINED_VARS predefinition;
	bool b_frag_var;
	float* value;
};

class CShader : public video::IShaderConstantSetCallBack
{
private:
	s32 p_material; //material which has to be applied to a scene_node
	IrrlichtDevice* dev;
	video::IVideoDriver* driver;

	//temporarily
	core::array<SShaderVariable*> uniform_variables;

	core::array<S_RTT_Info*> rtt_infos;

	f32 f_old_cycle_time;

	irr::scene::ISceneNode* obj_node;

public:
	CShader(IrrlichtDevice* device, rc_shader_material_obj shader_material);
	~CShader();

	virtual void OnSetConstants(video::IMaterialRendererServices* services, s32 userData);

	void setObjectNode(irr::scene::ISceneNode* node);

	s32 getMaterial();
	int getUniformVariableCount();
	SShaderVariable* getUniformVariable(int i);

	S_RTT_Info* getRTTInfo(E_RTT_TEXTURE rtt);
};

#endif // CSHADER_H_INCLUDED
