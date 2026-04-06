#ifndef RC_ACTOR_MATERIAL_H_INCLUDED
#define RC_ACTOR_MATERIAL_H_INCLUDED

#include "rc_fx_materials.h"

//Create FX Material in given material slot
// Return
bool createShaderMaterial(int material_id, int fx_material_type)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return false;

	if(!rc_material[material_id].isUsed)
		return false;

	if(fx_material_type < RC_FX_MATERIAL_BASE_INDEX || fx_material_type >= (RC_FX_MATERIAL_BASE_INDEX + rc_shader_materials.size()))
		return false;

	if(rc_material[material_id].shader)
	{
		delete rc_material[material_id].shader;
		rc_material[material_id].shader = NULL;
	}

	rc_material[material_id].isFX = false;

	int shader_index = fx_material_type - RC_FX_MATERIAL_BASE_INDEX;

	//std::cout << "Shader Index = " << shader_index << std::endl;

	rc_material[material_id].shader = NULL;

	if(device)
        rc_material[material_id].shader = new CShader(device, rc_shader_materials[shader_index]);

	if(rc_material[material_id].shader)
	{
		rc_material[material_id].fxMatType = fx_material_type;
		rc_material[material_id].isFX = true;
	}

	return rc_material[material_id].isFX;
}

//set actor texture
void rc_setActorTexture(int actor, int layer, int image_id)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(image_id < 0 || image_id >= rc_image.size())
        return;

    if(rc_image[image_id].image)
    {
        rc_actor[actor].mesh_node->setMaterialTexture(layer, rc_image[image_id].image);
    }
}

//get Material count
Uint32 rc_getActorMaterialCount(int actor)
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(!rc_actor[actor].mesh_node)
        return 0;

    return rc_actor[actor].mesh_node->getMaterialCount();
}

//set Actor Material Flag
void rc_setActorMaterialFlag(int actor, int flag, bool flag_value)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    rc_actor[actor].mesh_node->setMaterialFlag((irr::video::E_MATERIAL_FLAG)flag, flag_value);
}

//set Actor Material Flag
bool rc_getActorMaterialFlag(int actor, int material, int flag)
{
    if(actor < 0 || actor >= rc_actor.size())
        return false;

    if(!rc_actor[actor].mesh_node)
        return false;

    return rc_actor[actor].mesh_node->getMaterial(material).getFlag((irr::video::E_MATERIAL_FLAG)flag);
}

//Set Actor Material Type
void rc_setActorMaterialType(int actor, int material_type)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(material_type >= 0 && material_type < MAX_DEFAULT_MATERIALS)
    {
    	irr::video::E_MATERIAL_TYPE n = (irr::video::E_MATERIAL_TYPE) material_type;
		rc_actor[actor].mesh_node->setMaterialType(n);
    }
}

//Set Actor Material Type
int rc_getActorMaterialType(int actor, int material)
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(!rc_actor[actor].mesh_node)
        return 0;

    int material_type = (int)rc_actor[actor].mesh_node->getMaterial(material).MaterialType;

    if(material_type >= 0 && material_type < MAX_DEFAULT_MATERIALS)
		return material_type;
	else
	{
		//loop through all the fx materials on the actor
		for(int i = 0; i < rc_actor[actor].actor_fx_materials.size(); i++)
		{
			if(rc_actor[actor].actor_fx_materials[i].inUse && rc_actor[actor].actor_fx_materials[i].actor_material_index == material)
			{
				int material_id = rc_actor[actor].actor_fx_materials[i].material_id;
				return rc_material[material_id].fxMatType;
			}
		}
	}
	return -1;
}

int rc_createMaterial()
{
	int material_id = -1;

	for(int i = 0; i < rc_material.size(); i++)
	{
		if(!rc_material[i].isUsed)
		{
			material_id = i;
			rc_material[i].isFX = false;
			rc_material[i].mat = irr::video::SMaterial();
			rc_material[i].isReference = false;
			rc_material[i].refActor = -1;
			rc_material[i].refMatNum = -1;
			if(rc_material[i].shader)
			{
				delete rc_material[i].shader;
				rc_material[i].shader = NULL;
			}
			break;
		}
	}

	if(material_id < 0)
	{
		material_id = rc_material.size();
		rc_material_obj mat;
		mat.isUsed = true;
		mat.isReference = false;
		mat.isFX = false;
		mat.shader = NULL;
		rc_material.push_back(mat);
	}

	#if defined(__ANDROID__)
        rc_material[material_id].mat.UseMipMaps = false;
    #endif // defined

	return material_id;
}

void rc_deleteMaterial(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(rc_material[material_id].isFX)
	{
		//loop through the FX materials in every actor to remove this material
		for(int i = 0; i < rc_actor.size(); i++)
		{
			if(!rc_actor[i].mesh_node)
				continue;

			for(int fx_mat = 0; fx_mat < rc_actor[i].actor_fx_materials.size(); fx_mat++)
			{
				int m_id = rc_actor[i].actor_fx_materials[fx_mat].material_id;

				if(m_id < 0 || m_id >= rc_actor[i].mesh_node->getMaterialCount())
					continue;

				if(m_id == material_id && rc_actor[i].actor_fx_materials[fx_mat].inUse)
				{
					int actor_mat_index = rc_actor[i].actor_fx_materials[fx_mat].actor_material_index;
					irr::video::SMaterial m;
					m.MaterialType = irr::video::EMT_SOLID;
					rc_actor[i].mesh_node->getMaterial(actor_mat_index) = m;
					rc_actor[i].actor_fx_materials[fx_mat].inUse = false;
					rc_actor[i].actor_fx_materials[fx_mat].material_id = -1;
					rc_actor[i].actor_fx_materials[fx_mat].actor_material_index = -1;
				}
			}
		}

		if(rc_material[material_id].shader)
			delete rc_material[material_id].shader;
		rc_material[material_id].shader = NULL;
	}

	rc_material[material_id].isUsed = false;
	rc_material[material_id].mat = irr::video::SMaterial();
	rc_material[material_id].isFX = false;
	rc_material[material_id].fxMatType = -1;
}

//Set Actor Material Type
void rc_setActorMaterial(int actor, int material_num, int material_id)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(material_id < 0 || material_id >= rc_material.size())
        return;

    if(rc_material[material_id].isUsed)
	{
		if(rc_material[material_id].isFX)
		{
			if(rc_material[material_id].shader)
			{
			    rc_actor[actor].mesh_node->getMaterial(material_num) = rc_material[material_id].mat;
				rc_actor[actor].mesh_node->getMaterial(material_num).MaterialType = (video::E_MATERIAL_TYPE)rc_material[material_id].shader->getMaterial();
				rc_material[material_id].shader->setObjectNode(rc_actor[actor].mesh_node);

				registerSceneNodeForRTT(VideoDriver, rc_actor[actor].mesh_node, rc_material[material_id].shader->getRTTInfo(ERT_VIEW));

				int fx_index = -1;
				int vacant_index = -1;
				for(int i = 0; i < rc_actor[actor].actor_fx_materials.size(); i++)
				{
					if(rc_actor[actor].actor_fx_materials[i].actor_material_index == material_num &&
						rc_actor[actor].actor_fx_materials[i].inUse)
					{
						fx_index = i;
						break;
					}

					if(!rc_actor[actor].actor_fx_materials[i].inUse)
						vacant_index = i;
				}

				if(fx_index < 0)
					fx_index = vacant_index;

				if(fx_index < 0)
				{
					rc_actor_fx_material_obj actor_fx_mat;
					actor_fx_mat.actor_material_index = material_num;
					actor_fx_mat.inUse = true;
					actor_fx_mat.material_id = material_id;
					rc_actor[actor].actor_fx_materials.push_back(actor_fx_mat);
				}
				else
				{
					rc_actor[actor].actor_fx_materials[fx_index].actor_material_index = material_num;
					rc_actor[actor].actor_fx_materials[fx_index].inUse = true;
					rc_actor[actor].actor_fx_materials[fx_index].material_id = material_id;
				}
			}
			else
			{
				//shader is null then I might as well make sure this material is vacant
				rc_material[material_id].isFX = false;
				rc_material[material_id].isUsed = false;
			}
		}
		else if(rc_material[material_id].isReference)
		{
			int refActor = rc_material[material_id].refActor;
			int refMatNum = rc_material[material_id].refMatNum;
			rc_actor[actor].mesh_node->getMaterial(material_num) = rc_actor[ refActor ].mesh_node->getMaterial( refMatNum );
		}
		else
		{
			rc_actor[actor].mesh_node->getMaterial(material_num) = rc_material[material_id].mat;
		}
	}
}

//Set Actor Material Type
int rc_copyActorMaterial(int actor, int material_num)
{
    if(actor < 0 || actor >= rc_actor.size())
        return -1;

    if(!rc_actor[actor].mesh_node)
        return -1;

    int material_id = -1;

    for(int i = 0; i < rc_material.size(); i++)
    {
        if(!rc_material[i].isUsed)
        {
            rc_material[i].isUsed = true;
            material_id = i;
            break;
        }
    }

    if(material_id < 0)
    {
        material_id = rc_material.size();
        rc_material_obj nmat;
        nmat.isUsed = true;
        nmat.mat = rc_actor[actor].mesh_node->getMaterial(material_num);
        rc_material.push_back(nmat);
    }
    else
        rc_material[material_id].mat = rc_actor[actor].mesh_node->getMaterial(material_num);

	//Check if material is fx
	for(int i = 0; i < rc_actor[actor].actor_fx_materials.size(); i++)
	{
		if(!rc_actor[actor].actor_fx_materials[i].inUse)
			continue;

		if(rc_actor[actor].actor_fx_materials[i].actor_material_index == material_num)
		{
			int fx_mat_id = rc_actor[actor].actor_fx_materials[i].material_id;

			if(fx_mat_id >= 0 && fx_mat_id < rc_material.size())
			{
				rc_material[material_id].fxMatType = rc_material[fx_mat_id].fxMatType;
				rc_material[material_id].isFX = true;
				rc_material[material_id].shader = rc_material[fx_mat_id].shader;
			}
		}
	}

    return material_id;
}

int rc_copyMaterial(int src_material_id)
{
    int material_id = -1;

    if(!rc_material[src_material_id].isUsed)
		return -1;

    for(int i = 0; i < rc_material.size(); i++)
    {
        if(!rc_material[i].isUsed)
        {
            rc_material[i].isUsed = true;
            material_id = i;
            break;
        }
    }

    rc_material_obj nmat;
	nmat.isUsed = true;
	nmat.mat = rc_material[src_material_id].mat;
	nmat.isReference = false;
	nmat.refActor = -1;
	nmat.refMatNum = 0;

    if(material_id < 0)
    {
        material_id = rc_material.size();
        rc_material.push_back(nmat);
    }
    else
        rc_material[material_id] = nmat;

	if(rc_material[src_material_id].isFX)
	{
		if(!rc_material[src_material_id].shader)
		{
			rc_material[material_id].isUsed = false;
			rc_material[material_id].isReference = false;
			rc_material[material_id].isFX = false;
			rc_material[material_id].shader = NULL;
			return -1;
		}

		if(!createShaderMaterial(material_id, rc_material[src_material_id].fxMatType))
		{
			rc_material[material_id].isUsed = false;
			rc_material[material_id].isReference = false;
			rc_material[material_id].isFX = false;
			rc_material[material_id].shader = NULL;
			return -1;
		}

		//Copy all the uniforms
		for(int i = 0; i < rc_material[src_material_id].shader->getUniformVariableCount(); i++)
		{
			rc_material[material_id].shader->getUniformVariable(i)->b_frag_var = rc_material[src_material_id].shader->getUniformVariable(i)->b_frag_var;
			rc_material[material_id].shader->getUniformVariable(i)->name = rc_material[src_material_id].shader->getUniformVariable(i)->name;
			rc_material[material_id].shader->getUniformVariable(i)->predefinition = rc_material[src_material_id].shader->getUniformVariable(i)->predefinition;
			rc_material[material_id].shader->getUniformVariable(i)->type = rc_material[src_material_id].shader->getUniformVariable(i)->type;

			switch(rc_material[material_id].shader->getUniformVariable(i)->type)
			{
				case ESVT_SAMPLER2D:
				case ESVT_FLOAT:
					rc_material[material_id].shader->getUniformVariable(i)->value[0] = rc_material[src_material_id].shader->getUniformVariable(i)->value[0];
					break;
				case ESVT_VEC2:
					rc_material[material_id].shader->getUniformVariable(i)->value[0] = rc_material[src_material_id].shader->getUniformVariable(i)->value[0];
					rc_material[material_id].shader->getUniformVariable(i)->value[1] = rc_material[src_material_id].shader->getUniformVariable(i)->value[1];
					break;
				case ESVT_VEC3:
					rc_material[material_id].shader->getUniformVariable(i)->value[0] = rc_material[src_material_id].shader->getUniformVariable(i)->value[0];
					rc_material[material_id].shader->getUniformVariable(i)->value[1] = rc_material[src_material_id].shader->getUniformVariable(i)->value[1];
					rc_material[material_id].shader->getUniformVariable(i)->value[2] = rc_material[src_material_id].shader->getUniformVariable(i)->value[2];
					break;
				case ESVT_VEC4:
					rc_material[material_id].shader->getUniformVariable(i)->value[0] = rc_material[src_material_id].shader->getUniformVariable(i)->value[0];
					rc_material[material_id].shader->getUniformVariable(i)->value[1] = rc_material[src_material_id].shader->getUniformVariable(i)->value[1];
					rc_material[material_id].shader->getUniformVariable(i)->value[2] = rc_material[src_material_id].shader->getUniformVariable(i)->value[2];
					rc_material[material_id].shader->getUniformVariable(i)->value[3] = rc_material[src_material_id].shader->getUniformVariable(i)->value[3];
					break;
			}
		}
	}

    return material_id;
}

int rc_getActorMaterial(int actor, int material_num)
{
    if(actor < 0 || actor >= rc_actor.size())
        return -1;

    if(!rc_actor[actor].mesh_node)
        return -1;

	if(rc_actor[actor].material_ref_index >= 0)
		return rc_actor[actor].material_ref_index;

    int material_id = -1;

    for(int i = 0; i < rc_material.size(); i++)
    {
        if(!rc_material[i].isUsed)
        {
            rc_material[i].isUsed = true;
            material_id = i;
            break;
        }
    }

    if(material_id < 0)
    {
        material_id = rc_material.size();
        rc_material_obj nmat;
        nmat.isUsed = true;
        nmat.isReference = true;
        nmat.refActor = actor;
        nmat.refMatNum = material_num;

        //Check if this material number is FX
        for(int i = 0; i < rc_actor[actor].actor_fx_materials.size(); i++)
		{
			if(!rc_actor[actor].actor_fx_materials[i].inUse)
				continue;

			int actor_material_index = rc_actor[actor].actor_fx_materials[i].actor_material_index;

			if(actor_material_index == material_num)
			{
				int fx_mat_id = rc_actor[actor].actor_fx_materials[i].material_id;

				if(fx_mat_id >= 0 && fx_mat_id < rc_material.size())
				{
					if(rc_material[fx_mat_id].isUsed && rc_material[fx_mat_id].isFX)
					{
						nmat.isFX = true;
						nmat.fxMatType = rc_material[fx_mat_id].fxMatType;
						nmat.shader = rc_material[fx_mat_id].shader;
					}
				}
			}
		}

        rc_material.push_back(nmat);
    }
    else
    {
    	rc_material_obj nmat;
        nmat.isUsed = true;
        nmat.isReference = true;
        nmat.refActor = actor;
        nmat.refMatNum = material_num;
        rc_material[material_id] = nmat;

        //Check if this material number is FX
        for(int i = 0; i < rc_actor[actor].actor_fx_materials.size(); i++)
		{
			if(!rc_actor[actor].actor_fx_materials[i].inUse)
				continue;

			int actor_material_index = rc_actor[actor].actor_fx_materials[i].actor_material_index;

			if(actor_material_index == material_num)
			{
				int fx_mat_id = rc_actor[actor].actor_fx_materials[i].material_id;

				if(fx_mat_id >= 0 && fx_mat_id < rc_material.size())
				{
					if(rc_material[fx_mat_id].isUsed && rc_material[fx_mat_id].isFX)
					{
						rc_material[material_id].isFX = true;
						rc_material[material_id].fxMatType = rc_material[fx_mat_id].fxMatType;
						rc_material[material_id].shader = rc_material[fx_mat_id].shader;
					}
				}
			}
		}
    }

    return material_id;
}

bool rc_materialExists(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return false;

	return rc_material[material_id].isUsed;
}

void rc_setMaterialAmbientColor(int material_id, Uint32 color)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).AmbientColor = irr::video::SColor(color);
	}
	else
		rc_material[material_id].mat.AmbientColor = irr::video::SColor(color);
}

void rc_setMaterialTextureCanvas(int material_id, int level, int canvas_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(canvas_id < 0 || canvas_id >= rc_canvas.size())
		return;

	if(!rc_canvas[canvas_id].texture)
		return;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).setTexture(level, rc_canvas[canvas_id].texture);
	}
	else
		rc_material[material_id].mat.setTexture(level, rc_canvas[canvas_id].texture);
}

Uint32 rc_getMaterialAmbientColor(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return 0;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return rc_actor[refActor].mesh_node->getMaterial(refMatNum).AmbientColor.color;
	}
	else
		return rc_material[material_id].mat.AmbientColor.color;
}

void rc_setMaterialAntiAliasing(int material_id, int aa)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).AntiAliasing = aa;
	}
	else
		rc_material[material_id].mat.AntiAliasing = aa;
}

int rc_getMaterialAntiAliasing(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return 0;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return rc_actor[refActor].mesh_node->getMaterial(refMatNum).AntiAliasing;
	}
	else
		return rc_material[material_id].mat.AntiAliasing;
}

void rc_setMaterialBackfaceCulling(int material_id, bool flag)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).BackfaceCulling = flag;
	}
	else
		rc_material[material_id].mat.BackfaceCulling = flag;
}

bool rc_getMaterialBackfaceCulling(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return false;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return rc_actor[refActor].mesh_node->getMaterial(refMatNum).BackfaceCulling;
	}
	else
		return rc_material[material_id].mat.BackfaceCulling;
}

void rc_setMaterialBlendFactor(int material_id, double bf)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).BlendFactor = bf;
	}
	else
		rc_material[material_id].mat.BlendFactor = bf;
}

double rc_getMaterialBlendFactor(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return 0;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return rc_actor[refActor].mesh_node->getMaterial(refMatNum).BlendFactor;
	}
	else
		return rc_material[material_id].mat.BlendFactor;
}

void rc_setMaterialBlendMode(int material_id, int blend_mode)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).BlendOperation = (irr::video::E_BLEND_OPERATION)blend_mode;
	}
	else
		rc_material[material_id].mat.BlendOperation = (irr::video::E_BLEND_OPERATION)blend_mode;
}

int rc_getMaterialBlendMode(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return 0;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return (int)rc_actor[refActor].mesh_node->getMaterial(refMatNum).BlendOperation;
	}
	else
		return (int)rc_material[material_id].mat.BlendOperation;
}

void rc_setMaterialColorMask(int material_id, int color_mask)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).ColorMask = color_mask;
	}
	else
		rc_material[material_id].mat.ColorMask = color_mask;
}

int rc_getMaterialColorMask(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return 0;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return rc_actor[refActor].mesh_node->getMaterial(refMatNum).ColorMask;
	}
	else
		return rc_material[material_id].mat.ColorMask;
}

void rc_setMaterialColorMode(int material_id, int color_mode)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).ColorMaterial = (irr::video::E_COLOR_MATERIAL)color_mode;
	}
	else
		rc_material[material_id].mat.ColorMaterial = (irr::video::E_COLOR_MATERIAL)color_mode;
}

int rc_getMaterialColorMode(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return 0;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return (int)rc_actor[refActor].mesh_node->getMaterial(refMatNum).ColorMaterial;
	}
	else
		return (int)rc_material[material_id].mat.ColorMaterial;
}

void rc_setMaterialDiffuseColor(int material_id, Uint32 color)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).DiffuseColor.set(color);
	}
	else
		rc_material[material_id].mat.DiffuseColor = irr::video::SColor(color);
}

Uint32 rc_getMaterialDiffuseColor(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return 0;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return rc_actor[refActor].mesh_node->getMaterial(refMatNum).DiffuseColor.color;
	}
	else
		return rc_material[material_id].mat.DiffuseColor.color;
}

void rc_setMaterialEmissiveColor(int material_id, Uint32 color)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).EmissiveColor.set(color);
	}
	else
		rc_material[material_id].mat.EmissiveColor = irr::video::SColor(color);
}

Uint32 rc_getMaterialEmissiveColor(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return 0;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return rc_actor[refActor].mesh_node->getMaterial(refMatNum).EmissiveColor.color;
	}
	else
		return rc_material[material_id].mat.EmissiveColor.color;
}

void rc_setMaterialFog(int material_id, bool flag)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).FogEnable = flag;
	}
	else
		rc_material[material_id].mat.FogEnable = flag;
}

bool rc_getMaterialFog(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return false;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return rc_actor[refActor].mesh_node->getMaterial(refMatNum).FogEnable;
	}
	else
		return rc_material[material_id].mat.FogEnable;
}

void rc_setMaterialFrontfaceCulling(int material_id, bool flag)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).FrontfaceCulling = flag;
	}
	else
		rc_material[material_id].mat.FrontfaceCulling = flag;
}

bool rc_getMaterialFrontfaceCulling(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return false;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return rc_actor[refActor].mesh_node->getMaterial(refMatNum).FrontfaceCulling;
	}
	else
		return rc_material[material_id].mat.FrontfaceCulling;
}

void rc_setMaterialGouraudShading(int material_id, bool flag)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).GouraudShading = flag;
	}
	else
		rc_material[material_id].mat.GouraudShading = flag;
}

bool rc_materialIsGouraudShaded(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return false;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return rc_actor[refActor].mesh_node->getMaterial(refMatNum).GouraudShading;
	}
	else
		return rc_material[material_id].mat.GouraudShading;
}

bool rc_materialIsAplhaBlend(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return false;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return rc_actor[refActor].mesh_node->getMaterial(refMatNum).isAlphaBlendOperation();
	}
	else
		return rc_material[material_id].mat.isAlphaBlendOperation();
}

bool rc_materialIsTransparent(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return false;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return rc_actor[refActor].mesh_node->getMaterial(refMatNum).isTransparent();
	}
	else
		return rc_material[material_id].mat.isTransparent();
}

void rc_setMaterialLighting(int material_id, bool flag)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).Lighting = flag;
	}
	else
		rc_material[material_id].mat.Lighting = flag;
}

bool rc_materialIsLit(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return false;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return rc_actor[refActor].mesh_node->getMaterial(refMatNum).Lighting;
	}
	else
		return rc_material[material_id].mat.Lighting;
}

void rc_setMaterialType(int material_id, int mat_type)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(!rc_material[material_id].isUsed)
		return;

	if(mat_type >= RC_FX_MATERIAL_BASE_INDEX && mat_type < (RC_FX_MATERIAL_BASE_INDEX + rc_shader_materials.size()))
	{
		if(rc_material[material_id].isReference)
		{
			return;
		}
		else
		{
			createShaderMaterial(material_id, mat_type);
		}
	}
	else
	{
		if(rc_material[material_id].isReference)
		{
			int refActor = rc_material[material_id].refActor;
			int refMatNum = rc_material[material_id].refMatNum;
			rc_actor[refActor].mesh_node->getMaterial(refMatNum).MaterialType = (irr::video::E_MATERIAL_TYPE)mat_type;
		}
		else
			rc_material[material_id].mat.MaterialType = (irr::video::E_MATERIAL_TYPE)mat_type;
	}
}

int rc_getMaterialType(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return 0;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;

		//Check if material is an fx material
		for(int i = 0; i < rc_actor[refActor].actor_fx_materials.size(); i++)
		{
			if(!rc_actor[refActor].actor_fx_materials[i].inUse)
				continue;

			if(rc_actor[refActor].actor_fx_materials[i].material_id == material_id)
			{
				if(material_id >= 0 && material_id < rc_material.size())
				{
					if(rc_material[material_id].isFX)
						return rc_material[material_id].fxMatType;
				}
			}
		}

		if(rc_material[material_id].isFX)
		{
			int n = rc_actor[refActor].actor_fx_materials[0].material_id;
			if(n >= 0 && n < rc_material.size())
			{
				if(rc_material[n].isUsed)
					return rc_material[n].fxMatType;
			}

			//std::cout << "yolo: " << rc_material[n].fxMatType << " ~ " << material_id << std::endl;
		}

		return (int)rc_actor[refActor].mesh_node->getMaterial(refMatNum).MaterialType;
	}
	else
	{
		if(rc_material[material_id].isFX)
		{
			return rc_material[material_id].fxMatType;
		}
		else
			return (int)rc_material[material_id].mat.MaterialType;
	}
}

void rc_setMaterialNormalize(int material_id, bool flag)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).NormalizeNormals = flag;
	}
	else
		rc_material[material_id].mat.NormalizeNormals = flag;
}

bool rc_materialIsNormalized(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return false;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return rc_actor[refActor].mesh_node->getMaterial(refMatNum).NormalizeNormals;
	}
	else
		return rc_material[material_id].mat.NormalizeNormals;
}

void rc_setMaterialPointCloud(int material_id, bool flag)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).PointCloud = flag;
	}
	else
		rc_material[material_id].mat.PointCloud = flag;
}

bool rc_materialIsPointCloud(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return 0;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return rc_actor[refActor].mesh_node->getMaterial(refMatNum).PointCloud;
	}
	else
		return rc_material[material_id].mat.PointCloud;
}

void rc_setMaterialFlag(int material_id, int material_flag, bool f_value)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).setFlag((irr::video::E_MATERIAL_FLAG)material_flag, f_value);
	}
	else
		rc_material[material_id].mat.setFlag((irr::video::E_MATERIAL_FLAG)material_flag, f_value);
}

bool rc_getMaterialFlag(int material_id, int material_flag)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return false;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return rc_actor[refActor].mesh_node->getMaterial(refMatNum).getFlag((irr::video::E_MATERIAL_FLAG) material_flag);
	}
	else
		return rc_material[material_id].mat.getFlag((irr::video::E_MATERIAL_FLAG) material_flag);
}

void rc_setMaterialTexture(int material_id, int level, int img_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(level < 0 || level >= irr::video::MATERIAL_MAX_TEXTURES)
		return;

	if(img_id < 0 || img_id >= rc_image.size())
		return;

	if(!rc_image[img_id].image)
		return;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).setTexture(level, rc_image[img_id].image);
	}
	else
		rc_material[material_id].mat.setTexture(level, rc_image[img_id].image);
}

void rc_setMaterialShininess(int material_id, double shininess)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;


	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).Shininess = shininess;
	}
	else
		rc_material[material_id].mat.Shininess = shininess;
}

double rc_getMaterialShininess(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return 0;


	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return rc_actor[refActor].mesh_node->getMaterial(refMatNum).Shininess;
	}
	else
		return rc_material[material_id].mat.Shininess;
}

void rc_setMaterialSpecularColor(int material_id, Uint32 color)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).SpecularColor.set(color);
	}
	else
		rc_material[material_id].mat.SpecularColor = irr::video::SColor(color);
}

Uint32 rc_getMaterialSpecularColor(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return 0;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return rc_actor[refActor].mesh_node->getMaterial(refMatNum).SpecularColor.color;
	}
	else
		return rc_material[material_id].mat.SpecularColor.color;
}

void rc_setMaterialThickness(int material_id, double thickness)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).Thickness = thickness;
	}
	else
		rc_material[material_id].mat.Thickness = thickness;
}

double rc_getMaterialThickness(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return 0;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return rc_actor[refActor].mesh_node->getMaterial(refMatNum).Thickness;
	}
	else
		return rc_material[material_id].mat.Thickness;
}

void rc_setMaterialWireframe(int material_id, bool flag)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).Wireframe = flag;
	}
	else
		rc_material[material_id].mat.Wireframe = flag;
}

bool rc_materialIsWireframe(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return false;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return rc_actor[refActor].mesh_node->getMaterial(refMatNum).Wireframe;
	}
	else
		return rc_material[material_id].mat.Wireframe;
}




//get Actor Texture
int rc_getActorTexture(int actor, int material, int layer)
{
    if(actor < 0 || actor >= rc_actor.size())
        return -1;

    if(!rc_actor[actor].mesh_node)
        return -1;

    rc_image_obj img;
    img.image = rc_actor[actor].mesh_node->getMaterial(material).getTexture(layer);

    if(img.image == NULL)
        return -1;

    int img_id = -1;

    for(int i = 0; i < rc_image.size(); i++)
    {
        if(rc_image[i].image == NULL)
        {
            img_id = i;
            break;
        }
    }

    if(img_id < 0)
    {
        img_id = rc_image.size();
        rc_image.push_back(img);
    }
    else
    {
        rc_image[img_id] = img;
    }

    return img_id;
}

#endif // RC_ACTOR_MATERIAL_H_INCLUDED
