#ifndef RC_GFX3D_H_INCLUDED
#define RC_GFX3D_H_INCLUDED

#include <SDL2/SDL.h>
#include <irrlicht.h>
#include <iostream>
#include <sstream>
#include <string>
#include <locale>
#include <codecvt>
#include <cmath>
#include <set>

#include "camera.h"
#include "rc_gfx_core.h"
#include "rc_matrix.h"
#include "RealisticWater.h"

#include <bullet/btBulletDynamicsCommon.h>
#include <bullet/BulletCollision/CollisionDispatch/btGhostObject.h>

//load a mesh from a file
int rc_loadMesh(std::string mesh_file)
{
    int mesh_id = -1;

    rc_mesh_obj mesh_obj;
    mesh_obj.mesh_type = RC_MESH_TYPE_ANIMATED;

    irr::scene::IAnimatedMesh* mesh = SceneManager->getMesh(mesh_file.c_str());
    mesh_obj.mesh = mesh;

    if(!mesh)
        return -1;

    for(int i = 0; i < rc_mesh.size(); i++)
    {
        if(!rc_mesh[i].mesh)
        {
            mesh_id = i;
            break;
        }
    }

    if(mesh_id < 0)
    {
        mesh_id = rc_mesh.size();
        rc_mesh.push_back(mesh_obj);
    }
    else
    {
        rc_mesh[mesh_id] = mesh_obj;
    }

    return mesh_id;
}

//load a mesh from an archive
int rc_loadMeshFromArchive(std::string archive, std::string mesh_file)
{
	int mesh_id = -1;

	device->getFileSystem()->addFileArchive(archive.c_str());
	irr::scene::IAnimatedMesh *mesh = SceneManager->getMesh(mesh_file.c_str());
	device->getFileSystem()->removeFileArchive((irr::u32) 0);

	rc_mesh_obj mesh_obj;
    mesh_obj.mesh_type = RC_MESH_TYPE_ANIMATED;
    mesh_obj.mesh = mesh;

	if(!mesh)
        return -1;

    for(int i = 0; i < rc_mesh.size(); i++)
    {
        if(!rc_mesh[i].mesh)
        {
            mesh_id = i;
            break;
        }
    }

    if(mesh_id < 0)
    {
        mesh_id = rc_mesh.size();
        rc_mesh.push_back(mesh_obj);
    }
    else
    {
        rc_mesh[mesh_id] = mesh_obj;
    }

    return mesh_id;
}

//delete mesh
void rc_deleteMesh(int mesh_id)
{
    if(mesh_id < 0 || mesh_id >= rc_mesh.size())
        return;

    if(rc_mesh[mesh_id].mesh)
        rc_mesh[mesh_id].mesh->drop();

    rc_mesh[mesh_id].mesh = NULL;
    rc_mesh[mesh_id].mesh_type = 0;

}

//create mesh from geometry data [TODO]
int rc_createMesh()
{
    irr::scene::ISkinnedMesh * mesh = SceneManager->createSkinnedMesh();

    if(!mesh)
        return -1;

    int mesh_id = rc_mesh.size();
    rc_mesh_obj mesh_obj;
    mesh_obj.mesh = mesh;
    mesh_obj.mesh_type = RC_MESH_TYPE_ANIMATED;

    rc_mesh.push_back(mesh_obj);

    return mesh_id;
}

int rc_createPlaneMesh(double w, double h, double tileCount_w, double tileCount_h)
{
	irr::scene::IAnimatedMesh* mesh = SceneManager->addHillPlaneMesh( "plane",
																irr::core::dimension2d<irr::f32>(w/tileCount_w, h/tileCount_h),
																irr::core::dimension2d<irr::u32>(tileCount_w, tileCount_h));

    if(!mesh)
        return -1;

    int mesh_id = rc_mesh.size();
    rc_mesh_obj mesh_obj;
    mesh_obj.mesh = mesh;
    mesh_obj.mesh_type = RC_MESH_TYPE_ANIMATED;

    rc_mesh.push_back(mesh_obj);

    return mesh_id;
}


//create mesh from geometry data [TODO]
bool rc_addMeshBuffer(int mesh_id, int vertex_count, double* vertex_data, double* normal_data, double* uv_data, int index_count, double* index_data)
{
    irr::scene::ISkinnedMesh * mesh = (irr::scene::ISkinnedMesh*) rc_mesh[mesh_id].mesh;

    irr::scene::SSkinMeshBuffer* mbuf = mesh->addMeshBuffer();

    if(!mbuf)
    {
        mesh->drop();
        return false;
    }

    irr::core::array<irr::video::S3DVertex> vertices;
    irr::core::array<irr::u16> indices;

    for(int i = 0; i < vertex_count; i++)
    {
        irr::video::S3DVertex v;
        v.Pos = irr::core::vector3df( (irr::f32) vertex_data[i*3], (irr::f32) vertex_data[i*3+1], (irr::f32) vertex_data[i*3+2] );
        v.Normal = irr::core::vector3df( (irr::f32) normal_data[i*3], (irr::f32) normal_data[i*3+1], (irr::f32) normal_data[i*3+2] );
        v.TCoords = irr::core::vector2df( (irr::f32) uv_data[i*2], (irr::f32) uv_data[i*2+1] );
        vertices.push_back(v);
    }

    for(int i = 0; i < index_count; i++)
    {
        indices.push_back( (irr::u16) index_data[i] );
    }

    if(indices.size() > 0)
    {
        for(int i = 0; i < vertices.size(); i++)
            mbuf->Vertices_Standard.push_back(vertices[i]);

        for(int i = 0; i < indices.size(); i++)
            mbuf->Indices.push_back(indices[i]);

    }

    return true;
}



//Set Gravity
void rc_setGravity3D(double x, double y, double z)
{
	rc_physics3D.world->setGravity(irr::core::vector3d<f32>(x, y, z));
}

void rc_getGravity3D(double* x, double* y, double* z)
{
	btVector3 v = rc_physics3D.world->getPointer()->getGravity();
	*x = v.getX();
	*y = v.getY();
	*z = v.getZ();
}

void setSolidProperties(int actor)
{
	if(!rc_actor[actor].physics.isSolid)
	{
		rc_actor[actor].physics.gravity = rc_actor[actor].physics.rigid_body->getGravity();
		rc_actor[actor].physics.rigid_body->setGravity(irr::core::vector3df(0,0,0));
		rc_actor[actor].physics.rigid_body->setCollisionFlags( ECollisionFlag::ECF_NO_CONTACT_RESPONSE );
	}
	else
	{
		//rc_actor[actor].physics.rigid_body->setGravity(rc_actor[actor].physics.gravity);
	}
}

void rc_setActorCollisionShape(int actor_id, int shape_type, double mass)
{
	//std::cout << "Start ColShape" << std::endl;
	if(rc_actor[actor_id].physics.rigid_body)
	{
		rc_physics3D.world->removeCollisionObject(rc_actor[actor_id].physics.rigid_body, false);
		delete rc_actor[actor_id].physics.rigid_body;
	}

	rc_actor[actor_id].physics.rigid_body = NULL;
	rc_actor[actor_id].physics.mass = mass;

	if(!rc_actor[actor_id].physics.isSolid)
		mass = 1;

	//std::cout << "NEXT" << std::endl;

	switch(shape_type)
	{
		case RC_NODE_SHAPE_TYPE_NONE:
			break;

		case RC_NODE_SHAPE_TYPE_BOX:
			{
				rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_BOX;
				IBoxShape* shape = new IBoxShape(rc_actor[actor_id].mesh_node, mass, false);

				rc_actor[actor_id].physics.rigid_body = rc_physics3D.world->addRigidBody(shape);

				setSolidProperties(actor_id);
			}
			break;

		case RC_NODE_SHAPE_TYPE_SPHERE:
			{
				rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_SPHERE;
				ISphereShape* shape = new ISphereShape(rc_actor[actor_id].mesh_node, mass, false);

				rc_actor[actor_id].physics.rigid_body = rc_physics3D.world->addRigidBody(shape);

				setSolidProperties(actor_id);
			}
			break;

		case RC_NODE_SHAPE_TYPE_CYLINDER:
			{
				rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_CYLINDER;
				ICylinderShape* shape = new ICylinderShape(rc_actor[actor_id].mesh_node, mass, false);

				rc_actor[actor_id].physics.rigid_body = rc_physics3D.world->addRigidBody(shape);

				setSolidProperties(actor_id);
			}
			break;

		case RC_NODE_SHAPE_TYPE_CAPSULE:
			{
				//std::cout << "CAPSULE" << std::endl;
				rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_CAPSULE;
				ICapsuleShape* shape;

				if(rc_actor[actor_id].node_type == RC_NODE_TYPE_MESH)
				{
					irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor_id].mesh_node;
					shape = new ICapsuleShape(node, mass, false);
				}
				else if(rc_actor[actor_id].node_type == RC_NODE_TYPE_OTMESH)
				{
					irr::scene::IOctreeSceneNode* node = (irr::scene::IOctreeSceneNode*)rc_actor[actor_id].mesh_node;
					shape = new ICapsuleShape(node, mass, false);
				}
				else if(rc_actor[actor_id].node_type == RC_NODE_TYPE_TERRAIN)
				{
					irr::scene::ITerrainSceneNode* node = (irr::scene::ITerrainSceneNode*)rc_actor[actor_id].mesh_node;
					shape = new ICapsuleShape(node, mass, false);
				}

				rc_actor[actor_id].physics.rigid_body = rc_physics3D.world->addRigidBody(shape);

				setSolidProperties(actor_id);
			}
			break;

		case RC_NODE_SHAPE_TYPE_CONE:
			{
				rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_CONE;
				IConeShape* shape = new IConeShape(rc_actor[actor_id].mesh_node, mass, false);

				rc_actor[actor_id].physics.rigid_body = rc_physics3D.world->addRigidBody(shape);

				setSolidProperties(actor_id);
			}
			break;

		case RC_NODE_SHAPE_TYPE_TRIMESH:
			{
				rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_TRIMESH;
				IBvhTriangleMeshShape* shape;

				if(rc_actor[actor_id].node_type == RC_NODE_TYPE_MESH)
				{
					irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor_id].mesh_node;
					shape = new IBvhTriangleMeshShape(rc_actor[actor_id].mesh_node, node->getMesh(), mass);
				}
				else if(rc_actor[actor_id].node_type == RC_NODE_TYPE_OTMESH)
				{
					irr::scene::IOctreeSceneNode* node = (irr::scene::IOctreeSceneNode*)rc_actor[actor_id].mesh_node;
					shape = new IBvhTriangleMeshShape(rc_actor[actor_id].mesh_node, node->getMesh(), mass);
				}
				else if(rc_actor[actor_id].node_type == RC_NODE_TYPE_TERRAIN)
				{
					irr::scene::ITerrainSceneNode* node = (irr::scene::ITerrainSceneNode*)rc_actor[actor_id].mesh_node;
					shape = new IBvhTriangleMeshShape(rc_actor[actor_id].mesh_node, node->getMesh(), mass);
				}
				//else if(rc_actor[actor_id].node_type == RC_NODE_TYPE_WATER)
					//shape = new IBvhTriangleMeshShape(rc_actor[actor_id].mesh_node, (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor_id].mesh_node->getMesh(), mass);

				rc_actor[actor_id].physics.rigid_body = rc_physics3D.world->addRigidBody(shape);

				setSolidProperties(actor_id);
			}
			break;

		case RC_NODE_SHAPE_TYPE_CONVEXHULL:
			{
				rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_CONVEXHULL;
				IConvexHullShape* shape;

				if(rc_actor[actor_id].node_type == RC_NODE_TYPE_MESH)
				{
					irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor_id].mesh_node;
					shape = new IConvexHullShape(rc_actor[actor_id].mesh_node, node->getMesh(), mass);
				}
				else if(rc_actor[actor_id].node_type == RC_NODE_TYPE_OTMESH)
				{
					irr::scene::IOctreeSceneNode* node = (irr::scene::IOctreeSceneNode*)rc_actor[actor_id].mesh_node;
					shape = new IConvexHullShape(rc_actor[actor_id].mesh_node, node->getMesh(), mass);
				}
				else if(rc_actor[actor_id].node_type == RC_NODE_TYPE_TERRAIN)
				{
					irr::scene::ITerrainSceneNode* node = (irr::scene::ITerrainSceneNode*)rc_actor[actor_id].mesh_node;
					shape = new IConvexHullShape(rc_actor[actor_id].mesh_node, node->getMesh(), mass);
				}

				rc_actor[actor_id].physics.rigid_body = rc_physics3D.world->addRigidBody(shape);

				setSolidProperties(actor_id);
			}
			break;

		default:
			std::cout << "SetActorCollisionShape Error: Invalid shape_type parameter" << std::endl;
	}

	if(rc_actor[actor_id].physics.rigid_body)
	{
		rc_actor[actor_id].physics.rigid_body->getIdentification()->setId(actor_id);
		rc_actor[actor_id].physics.rigid_body->getPointer()->setActivationState(ACTIVE_TAG);
		rc_actor[actor_id].physics.rigid_body->getPointer()->setActivationState(DISABLE_DEACTIVATION);
		rc_actor[actor_id].physics.rigid_body->getPointer()->updateInertiaTensor();
	}
}

void rc_setActorSleepState(int actor, int state)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->getPointer()->forceActivationState(state);
	}
}

int rc_getActorCollisionShape(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(!rc_actor[actor].mesh_node)
        return 0;

	return rc_actor[actor].physics.shape_type;
}


void rc_setActorSolid(int actor_id, bool flag)
{
	if(actor_id < 0 || actor_id >= rc_actor.size())
        return;

    if(!rc_actor[actor_id].mesh_node)
        return;

	if(flag != rc_actor[actor_id].physics.isSolid)
	{
		rc_actor[actor_id].physics.isSolid = flag;
		rc_setActorCollisionShape(actor_id, rc_actor[actor_id].physics.shape_type, rc_actor[actor_id].physics.mass);
	}
}

bool rc_actorIsSolid(int actor_id)
{
	if(actor_id < 0 || actor_id >= rc_actor.size())
        return false;

    if(!rc_actor[actor_id].mesh_node)
        return false;

	return rc_actor[actor_id].physics.isSolid;
}

bool rc_actorExists(int actor_id)
{
	if(actor_id < 0 || actor_id >= rc_actor.size())
        return false;

    return (rc_actor[actor_id].node_type > 0);
}


bool rc_getActorCollision(int actor1, int actor2)
{
	for(int i = 0; i < rc_actor[actor1].physics.collisions.size(); i++)
	{
		int c_index = rc_actor[actor1].physics.collisions[i];

		int actorA = rc_collisions[c_index].actorA;
		int actorB = rc_collisions[c_index].actorB;

		if(actor2 == actorA || actor2 == actorB)
		{
			//std::cout << "Actor in Collide = " << (actor1 == actorA ? "A" : "B") << std::endl;
			return true;
		}
	}

    return false;
}


//add mesh actor to scene
int rc_createMeshActor(int mesh_id)
{
    if(mesh_id < 0 || mesh_id >= rc_mesh.size())
        return -1;

    irr::scene::IAnimatedMesh* mesh = rc_mesh[mesh_id].mesh;

    if(!mesh)
        return -1;

    int actor_id = -1;
    irr::scene::IAnimatedMeshSceneNode* node = SceneManager->addAnimatedMeshSceneNode(mesh);
    rc_scene_node actor;
    actor.node_type = RC_NODE_TYPE_MESH;
    actor.mesh_node = node;
    actor.shadow = NULL;
    actor.transition = false;
    actor.transition_time = 0;
    actor.material_ref_index = -1;

    if(!node)
        return -1;

    for(int i = 0; i < rc_actor.size(); i++)
    {
        if(!rc_actor[i].mesh_node)
        {
            actor_id = i;
            break;
        }
    }

    if(actor_id < 0)
    {
        actor_id = rc_actor.size();
        rc_actor.push_back(actor);
    }
    else
    {
        rc_actor[actor_id] = actor;
    }

    //Actor RigidBody
    rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_BOX;
    rc_actor[actor_id].physics.rigid_body = NULL;
    rc_actor[actor_id].physics.isSolid = false;

    rc_setActorCollisionShape(actor_id, RC_NODE_SHAPE_TYPE_BOX, 1);

    return actor_id;
}


//add mesh actor to scene
int rc_createMeshOctreeActor(int mesh_id)
{
    if(mesh_id < 0 || mesh_id >= rc_mesh.size())
        return -1;

    irr::scene::IAnimatedMesh* mesh = rc_mesh[mesh_id].mesh;

    if(!mesh)
        return -1;

    int actor_id = -1;
    //irr::scene::IAnimatedMeshSceneNode* node = SceneManager->addAnimatedMeshSceneNode(mesh);
    irr::scene::IOctreeSceneNode *node = SceneManager->addOctreeSceneNode(mesh);
    rc_scene_node actor;
    actor.node_type = RC_NODE_TYPE_OTMESH;
    actor.mesh_node = node;
    actor.shadow = NULL;
    actor.transition = false;
    actor.transition_time = 0;
    actor.material_ref_index = -1;

    if(!node)
        return -1;

    for(int i = 0; i < rc_actor.size(); i++)
    {
        if(!rc_actor[i].mesh_node)
        {
            actor_id = i;
            break;
        }
    }

    if(actor_id < 0)
    {
        actor_id = rc_actor.size();
        rc_actor.push_back(actor);
    }
    else
    {
        rc_actor[actor_id] = actor;
    }

    //Actor RigidBody
    rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_BOX;
    rc_actor[actor_id].physics.rigid_body = NULL;
    rc_actor[actor_id].physics.isSolid = false;

    rc_setActorCollisionShape(actor_id, RC_NODE_SHAPE_TYPE_BOX, 1);


    return actor_id;
}

//add mesh actor to scene
int rc_createTerrainActor( std::string height_map )
{

    int actor_id = -1;
    irr::scene::ITerrainSceneNode *node = SceneManager->addTerrainSceneNode(height_map.c_str());
    rc_scene_node actor;
    actor.node_type = RC_NODE_TYPE_TERRAIN;
    actor.mesh_node = node;
    actor.shadow = NULL;
    actor.transition = false;
    actor.transition_time = 0;
    actor.material_ref_index = -1;

    if(!node)
        return -1;

    for(int i = 0; i < rc_actor.size(); i++)
    {
        if(!rc_actor[i].mesh_node)
        {
            actor_id = i;
            break;
        }
    }

    if(actor_id < 0)
    {
        actor_id = rc_actor.size();
        rc_actor.push_back(actor);
    }
    else
    {
        rc_actor[actor_id] = actor;
    }

    //Actor RigidBody
    rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_BOX;
    rc_actor[actor_id].physics.rigid_body = NULL;
    rc_actor[actor_id].physics.isSolid = false;

    rc_setActorCollisionShape(actor_id, RC_NODE_SHAPE_TYPE_BOX, 0);


    return actor_id;
}

int rc_createParticleActor( int particle_type )
{
    int actor_id = -1;
    irr::scene::IParticleSystemSceneNode *node = SceneManager->addParticleSystemSceneNode( false );
    rc_scene_node actor;
    actor.node_type = RC_NODE_TYPE_PARTICLE;
    actor.particle_properties.particle_type = particle_type;
    actor.particle_properties.mesh_id = -1;
    actor.mesh_node = node;
    actor.shadow = NULL;
    actor.transition = false;
    actor.transition_time = 0;
    actor.material_ref_index = -1;

    if(!node)
        return -1;

    for(int i = 0; i < rc_actor.size(); i++)
    {
        if(!rc_actor[i].mesh_node)
        {
            actor_id = i;
            break;
        }
    }

    if(actor_id < 0)
    {
        actor_id = rc_actor.size();
        rc_actor.push_back(actor);
    }
    else
    {
        rc_actor[actor_id] = actor;
    }

    //Actor RigidBody
    rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_BOX;
    rc_actor[actor_id].physics.rigid_body = NULL;
    rc_actor[actor_id].physics.isSolid = false;

    rc_setActorCollisionShape(actor_id, RC_NODE_SHAPE_TYPE_BOX, 0);


    return actor_id;
}

//add mesh actor to scene
int rc_createCubeActor(double cube_size)
{
    int actor_id = -1;
    irr::scene::IMeshSceneNode* node = SceneManager->addCubeSceneNode(cube_size);
    rc_scene_node actor;
    actor.node_type = RC_NODE_TYPE_MESH;
    actor.mesh_node = node;
    actor.shadow = NULL;
    actor.transition = false;
    actor.transition_time = 0;
    actor.material_ref_index = -1;

    if(!node)
        return -1;

    for(int i = 0; i < rc_actor.size(); i++)
    {
        if(!rc_actor[i].mesh_node)
        {
            actor_id = i;
            break;
        }
    }

    if(actor_id < 0)
    {
        actor_id = rc_actor.size();
        rc_actor.push_back(actor);
    }
    else
    {
        rc_actor[actor_id] = actor;
    }

    //Actor RigidBody
    rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_BOX;
    rc_actor[actor_id].physics.rigid_body = NULL;
    rc_actor[actor_id].physics.isSolid = false;

    rc_setActorCollisionShape(actor_id, RC_NODE_SHAPE_TYPE_BOX, 1);

    return actor_id;
}

//add mesh actor to scene
int rc_createSphereActor(double radius)
{
    int actor_id = -1;
    irr::scene::IMeshSceneNode* node = SceneManager->addSphereSceneNode(radius);
    rc_scene_node actor;
    actor.node_type = RC_NODE_TYPE_MESH;
    actor.mesh_node = node;
    actor.shadow = NULL;
    actor.transition = false;
    actor.transition_time = 0;
    actor.material_ref_index = -1;

    if(!node)
        return -1;

    for(int i = 0; i < rc_actor.size(); i++)
    {
        if(!rc_actor[i].mesh_node)
        {
            actor_id = i;
            break;
        }
    }

    if(actor_id < 0)
    {
        actor_id = rc_actor.size();
        rc_actor.push_back(actor);
    }
    else
    {
        rc_actor[actor_id] = actor;
    }

    //Actor RigidBody
    rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_SPHERE;
    rc_actor[actor_id].physics.rigid_body = NULL;
    rc_actor[actor_id].physics.isSolid = false;

    rc_setActorCollisionShape(actor_id, RC_NODE_SHAPE_TYPE_SPHERE, 1);

    return actor_id;
}

//add mesh actor to scene
int rc_createWaterActor(int mesh_id, double waveHeight, double waveSpeed, double waveLength)
{
    int actor_id = -1;

    if(mesh_id < 0 || mesh_id >= rc_mesh.size())
		return -1;

	if(!rc_mesh[mesh_id].mesh)
		return -1;

    irr::scene::ISceneNode* node = SceneManager->addWaterSurfaceSceneNode(rc_mesh[mesh_id].mesh, waveHeight, waveSpeed, waveLength);

    rc_scene_node actor;
    actor.node_type = RC_NODE_TYPE_WATER;
    actor.mesh_node = node;
    actor.shadow = NULL;
    actor.transition = false;
    actor.transition_time = 0;
    actor.material_ref_index = -1;

    if(!node)
        return -1;

    for(int i = 0; i < rc_actor.size(); i++)
    {
        if(!rc_actor[i].mesh_node)
        {
            actor_id = i;
            break;
        }
    }

    if(actor_id < 0)
    {
        actor_id = rc_actor.size();
        rc_actor.push_back(actor);
    }
    else
    {
        rc_actor[actor_id] = actor;
    }

    //Actor RigidBody
    rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_BOX;
    rc_actor[actor_id].physics.rigid_body = NULL;
    rc_actor[actor_id].physics.isSolid = false;

    rc_setActorCollisionShape(actor_id, RC_NODE_SHAPE_TYPE_BOX, 1);

    return actor_id;
}

int rc_createBillboardActor()
{
    int actor_id = -1;
    irr::scene::IBillboardSceneNode* node = SceneManager->addBillboardSceneNode();
    rc_scene_node actor;
    actor.node_type = RC_NODE_TYPE_BILLBOARD;
    actor.mesh_node = node;
    actor.shadow = NULL;
    actor.transition = false;
    actor.transition_time = 0;
    actor.material_ref_index = -1;

    if(!node)
        return -1;

    for(int i = 0; i < rc_actor.size(); i++)
    {
        if(!rc_actor[i].mesh_node)
        {
            actor_id = i;
            break;
        }
    }

    if(actor_id < 0)
    {
        actor_id = rc_actor.size();
        rc_actor.push_back(actor);
    }
    else
    {
        rc_actor[actor_id] = actor;
    }

    //Actor RigidBody
    rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_BOX;
    rc_actor[actor_id].physics.rigid_body = NULL;
    rc_actor[actor_id].physics.isSolid = false;

    rc_setActorCollisionShape(actor_id, RC_NODE_SHAPE_TYPE_BOX, 1);

    return actor_id;
}

int rc_createLightActor()
{
    int actor_id = -1;
    irr::scene::ILightSceneNode* node = SceneManager->addLightSceneNode();
    rc_scene_node actor;
    actor.node_type = RC_NODE_TYPE_LIGHT;
    actor.mesh_node = node;
    actor.shadow = NULL;
    actor.transition = false;
    actor.transition_time = 0;
    actor.material_ref_index = -1;

    if(!node)
        return -1;

    for(int i = 0; i < rc_actor.size(); i++)
    {
        if(!rc_actor[i].mesh_node)
        {
            actor_id = i;
            break;
        }
    }

    if(actor_id < 0)
    {
        actor_id = rc_actor.size();
        rc_actor.push_back(actor);
    }
    else
    {
        rc_actor[actor_id] = actor;
    }

    //Actor RigidBody
    rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_BOX;
    rc_actor[actor_id].physics.rigid_body = NULL;
    rc_actor[actor_id].physics.isSolid = false;

    rc_setActorCollisionShape(actor_id, RC_NODE_SHAPE_TYPE_BOX, 1);

    return actor_id;
}

//delete actor
void rc_deleteActor(int actor_id)
{
    if(actor_id < 0 || actor_id >= rc_actor.size())
        return;

    if(!rc_actor[actor_id].mesh_node)
        return;

	rc_physics3D.world->removeCollisionObject(rc_actor[actor_id].physics.rigid_body, false);
	rc_actor[actor_id].physics.collisions.clear();

    rc_actor[actor_id].mesh_node->remove();
    rc_actor[actor_id].mesh_node = NULL;
    rc_actor[actor_id].shadow = NULL;
    rc_actor[actor_id].node_type = 0;
    rc_actor[actor_id].transition = false;
    rc_actor[actor_id].transition_time = 0;
    rc_actor[actor_id].material_ref_index = -1;
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

    irr::video::E_MATERIAL_TYPE n = (irr::video::E_MATERIAL_TYPE) material_type;
    rc_actor[actor].mesh_node->setMaterialType(n);
}

//Set Actor Material Type
int rc_getActorMaterialType(int actor, int material)
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(!rc_actor[actor].mesh_node)
        return 0;

    return (int)rc_actor[actor].mesh_node->getMaterial(material).MaterialType;
}

struct rc_material_obj
{
    irr::video::SMaterial mat;
    bool isUsed = false;
    bool isReference = false;
    int refActor = -1;
    int refMatNum = 0;
};

irr::core::array<rc_material_obj> rc_material;

int rc_createMaterial()
{
	int material_id = -1;

	for(int i = 0; i < rc_material.size(); i++)
	{
		if(!rc_material[i].isUsed)
		{
			material_id = i;
			break;
		}
	}

	if(material_id < 0)
	{
		material_id = rc_material.size();
		rc_material_obj mat;
		mat.isUsed = true;
		mat.isReference = false;
		rc_material.push_back(mat);
	}

	return material_id;
}

void rc_deleteMaterial(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return;

	rc_material[material_id].isUsed = false;
	rc_material[material_id].mat = irr::video::SMaterial();
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
		if(rc_material[material_id].isReference)
		{
			int refActor = rc_material[material_id].refActor;
			int refMatNum = rc_material[material_id].refMatNum;
			rc_actor[actor].mesh_node->getMaterial(material_num) = rc_actor[ refActor ].mesh_node->getMaterial( refMatNum );
		}
		else
			rc_actor[actor].mesh_node->getMaterial(material_num) = rc_material[material_id].mat;
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

    return material_id;
}

int rc_copyMaterial(int src_material_id)
{
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

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		rc_actor[refActor].mesh_node->getMaterial(refMatNum).MaterialType = (irr::video::E_MATERIAL_TYPE)mat_type;
	}
	else
		rc_material[material_id].mat.MaterialType = (irr::video::E_MATERIAL_TYPE)mat_type;
}

int rc_getMaterialType(int material_id)
{
	if(material_id < 0 || material_id >= rc_material.size())
		return 0;

	if(rc_material[material_id].isReference)
	{
		int refActor = rc_material[material_id].refActor;
		int refMatNum = rc_material[material_id].refMatNum;
		return (int)rc_actor[refActor].mesh_node->getMaterial(refMatNum).MaterialType;
	}
	else
		return (int)rc_material[material_id].mat.MaterialType;
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



bool rc_getActorTransform(int actor, int t_mat)
{
	if(actor < 0 || actor >= rc_actor.size())
        return false;

	if(t_mat < 0 || t_mat >= rc_matrix.size())
		return false;

	if(!rc_matrix[t_mat].active)
		return false;

	irr::core::matrix4 m = rc_actor[actor].mesh_node->getAbsoluteTransformation();
	rc_convertFromIrrMatrix(m, t_mat);

	return true;
}

//set actor position
void rc_setActorPosition(int actor, double x, double y, double z)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		//std::cout << "Set POS" << std::endl;
		irr::core::matrix4 actor_transform = rc_actor[actor].physics.rigid_body->getWorldTransform();
		rc_physics3D.world->removeCollisionObject(rc_actor[actor].physics.rigid_body, false);
		actor_transform.setTranslation( irr::core::vector3df(x, y, z) );
		rc_actor[actor].physics.rigid_body->clearForces();
		//rc_actor[actor].physics.rigid_body->
		rc_actor[actor].physics.rigid_body->setWorldTransform(actor_transform);

		rc_actor[actor].physics.rigid_body->setMassProps(rc_actor[actor].physics.mass, irr::core::vector3df(0,0,0));
		rc_physics3D.world->addRigidBody(rc_actor[actor].physics.rigid_body);

		rc_actor[actor].mesh_node->setPosition(actor_transform.getTranslation());

	}
}

//translate actor from local orientation
void rc_translateActorLocal(int actor, double x, double y, double z)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		//std::cout << "Set POS" << std::endl;
		irr::core::matrix4 actor_transform = rc_actor[actor].physics.rigid_body->getWorldTransform();
		irr::core::matrix4 m;
		m.setRotationDegrees(actor_transform.getRotationDegrees());
		irr::core::vector3df v(x, y, z);
		m.transformVect(v);

		actor_transform.setTranslation( actor_transform.getTranslation() + v );
		rc_actor[actor].physics.rigid_body->clearForces();
		rc_actor[actor].physics.rigid_body->setWorldTransform(actor_transform);
		rc_actor[actor].mesh_node->setPosition(actor_transform.getTranslation());
		rc_actor[actor].mesh_node->updateAbsolutePosition();
	}
}

//translate actor from world orientation
void rc_translateActorWorld(int actor, double x, double y, double z)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		//std::cout << "Set POS" << std::endl;
		irr::core::matrix4 actor_transform = rc_actor[actor].physics.rigid_body->getWorldTransform();
		actor_transform.setTranslation( actor_transform.getTranslation() + irr::core::vector3df(x, y, z) );
		rc_actor[actor].physics.rigid_body->clearForces();
		rc_actor[actor].physics.rigid_body->setWorldTransform(actor_transform);
		rc_actor[actor].mesh_node->setPosition(actor_transform.getTranslation());
		rc_actor[actor].mesh_node->updateAbsolutePosition();
	}
}

//get actor position
void rc_getActorPosition(int actor, double* x, double* y, double* z)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		//std::cout << "Set POS" << std::endl;
		irr::core::matrix4 actor_transform = rc_actor[actor].physics.rigid_body->getWorldTransform();
		*x = actor_transform.getTranslation().X;
		*y = actor_transform.getTranslation().Y;
		*z = actor_transform.getTranslation().Z;
	}
}

//set actor scale
void rc_setActorScale(int actor, double x, double y, double z)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		//std::cout << "Set POS" << std::endl;
		irr::core::matrix4 actor_transform = rc_actor[actor].physics.rigid_body->getWorldTransform();
		actor_transform.setScale( irr::core::vector3df(x, y, z) );
		rc_actor[actor].physics.rigid_body->clearForces();
		rc_actor[actor].physics.rigid_body->setWorldTransform(actor_transform);
		rc_actor[actor].mesh_node->setScale(actor_transform.getScale());
		rc_actor[actor].mesh_node->updateAbsolutePosition();
	}

}

//scale actor
void rc_scaleActor(int actor, double x, double y, double z)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		//std::cout << "Set POS" << std::endl;
		irr::core::matrix4 actor_transform = rc_actor[actor].physics.rigid_body->getWorldTransform();
		actor_transform.setScale( actor_transform.getScale() * irr::core::vector3df(x, y, z) );
		rc_actor[actor].physics.rigid_body->clearForces();
		rc_actor[actor].physics.rigid_body->setWorldTransform(actor_transform);
		rc_actor[actor].mesh_node->setScale(actor_transform.getScale());
		rc_actor[actor].mesh_node->updateAbsolutePosition();
	}
}

//get actor scale
void rc_getActorScale(int actor, double* x, double* y, double* z)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		//std::cout << "Set POS" << std::endl;
		irr::core::matrix4 actor_transform = rc_actor[actor].physics.rigid_body->getWorldTransform();
		*x = actor_transform.getScale().X;
		*y = actor_transform.getScale().Y;
		*z = actor_transform.getScale().Z;
	}
}


//set actor rotation
void rc_setActorRotation(int actor, double x, double y, double z)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		//std::cout << "Set POS" << std::endl;
		irr::core::matrix4 actor_transform = rc_actor[actor].physics.rigid_body->getWorldTransform();
		actor_transform.setRotationDegrees( irr::core::vector3df(x, y, z) );
		rc_actor[actor].physics.rigid_body->clearForces();
		rc_actor[actor].physics.rigid_body->setWorldTransform(actor_transform);
		rc_actor[actor].mesh_node->setRotation( actor_transform.getRotationDegrees() );
		rc_actor[actor].mesh_node->updateAbsolutePosition();
	}
}

//rotate actor
void rc_rotateActor(int actor, double x, double y, double z)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		//std::cout << "Set POS" << std::endl;
		irr::core::matrix4 actor_transform = rc_actor[actor].physics.rigid_body->getWorldTransform();

		irr::core::matrix4 n;
		irr::core::vector3df rot(x, y, z);
		n.setRotationDegrees(rot);
		actor_transform *= n;

		rc_actor[actor].physics.rigid_body->clearForces();
		rc_actor[actor].physics.rigid_body->setWorldTransform(actor_transform);
		rc_actor[actor].mesh_node->setRotation( actor_transform.getRotationDegrees() );
		rc_actor[actor].mesh_node->updateAbsolutePosition();
	}
}

//get actor position
void rc_getActorRotation(int actor, double* x, double* y, double* z)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		//std::cout << "Set POS" << std::endl;
		irr::core::matrix4 actor_transform = rc_actor[actor].physics.rigid_body->getWorldTransform();
		*x = actor_transform.getRotationDegrees().X;
		*y = actor_transform.getRotationDegrees().Y;
		*z = actor_transform.getRotationDegrees().Z;
	}
}

void rc_setActorGravity(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->setGravity(irr::core::vector3df(x, y, z));
	}
}

void rc_getActorGravity(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df gvec = rc_actor[actor].physics.rigid_body->getGravity();
		*x = gvec.X;
		*y = gvec.Y;
		*z = gvec.Z;
	}
}

void rc_setActorDamping(int actor, double lin_damping, double ang_damping)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->setDamping(lin_damping, ang_damping);
	}
}

double rc_getActorLinearDamping(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		return rc_actor[actor].physics.rigid_body->getLinearDamping();
	}
	return 0;
}

double rc_getActorAngularDamping(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		return rc_actor[actor].physics.rigid_body->getAngularDamping();
	}
	return 0;
}

double rc_getActorLinearSleepThreshold(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		return rc_actor[actor].physics.rigid_body->getLinearSleepingThreshold();
	}
	return 0;
}

double rc_getActorAngularSleepThreshold(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		return rc_actor[actor].physics.rigid_body->getAngularSleepingThreshold();
	}
	return 0;
}

void rc_applyActorDamping(int actor, double timeStep)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyDamping(timeStep);
	}
}

void rc_setActorMassProperties(int actor, double mass, double inertia_x, double inertia_y, double inertia_z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_physics3D.world->removeCollisionObject(rc_actor[actor].physics.rigid_body, false);
		rc_actor[actor].physics.rigid_body->setMassProps(mass, irr::core::vector3df(inertia_x, inertia_y, inertia_z));
		rc_physics3D.world->addRigidBody(rc_actor[actor].physics.rigid_body);
	}
	rc_actor[actor].physics.mass = mass;
}

void rc_getActorLinearFactor(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df lf = rc_actor[actor].physics.rigid_body->getLinearFactor();
		*x = lf.X;
		*y = lf.Y;
		*z = lf.Z;
	}
}

void rc_setActorLinearFactor(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->setLinearFactor(irr::core::vector3df(x, y, z));
	}
}

double rc_getActorInverseMass(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		return rc_actor[actor].physics.rigid_body->getInvMass();
	}
	return 0;
}

void rc_integrateActorVelocities(int actor, double step)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->integrateVelocities(step);
	}
}

void rc_applyActorCentralForceLocal(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyCentralForce(irr::core::vector3df(x,y,z), ERBTransformSpace::ERBTS_LOCAL);
	}
}

void rc_applyActorCentralForceWorld(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyCentralForce(irr::core::vector3df(x,y,z), ERBTransformSpace::ERBTS_WORLD);
	}
}

void rc_getActorTotalForce(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df f = rc_actor[actor].physics.rigid_body->getTotalForce();
		*x = f.X;
		*y = f.Y;
		*z = f.Z;
	}
}

void rc_getActorTotalTorque(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df f = rc_actor[actor].physics.rigid_body->getTotalTorque();
		*x = f.X;
		*y = f.Y;
		*z = f.Z;
	}
}

void rc_getActorInverseInertiaDiagLocal(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df f = rc_actor[actor].physics.rigid_body->getInvInertiaDiagLocal();
		*x = f.X;
		*y = f.Y;
		*z = f.Z;
	}
}

void rc_setActorInverseInertiaDiagLocal(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->setInvInertiaDiagLocal(irr::core::vector3df(x,y,z));
	}
}

void rc_setActorSleepThresholds(int actor, double linear, double angular)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->setSleepingThresholds(linear, angular);
	}
}

void rc_applyActorTorqueLocal(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyTorque(irr::core::vector3df(x,y,z), ERBTransformSpace::ERBTS_LOCAL);
	}
}

void rc_applyActorTorqueWorld(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyTorque(irr::core::vector3df(x,y,z), ERBTransformSpace::ERBTS_WORLD);
	}
}

void rc_applyActorForceLocal(int actor, double x, double y, double z, double rel_x, double rel_y, double rel_z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyForce(irr::core::vector3df(x,y,z), irr::core::vector3df(rel_x, rel_y, rel_z), ERBTransformSpace::ERBTS_LOCAL);
	}
}

void rc_applyActorForceWorld(int actor, double x, double y, double z, double rel_x, double rel_y, double rel_z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyForce(irr::core::vector3df(x,y,z), irr::core::vector3df(rel_x, rel_y, rel_z), ERBTransformSpace::ERBTS_WORLD);
	}
}

void rc_applyActorCentralImpulseLocal(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyCentralImpulse(irr::core::vector3df(x,y,z), ERBTransformSpace::ERBTS_LOCAL);
	}
}

void rc_applyActorCentralImpulseWorld(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyCentralImpulse(irr::core::vector3df(x,y,z), ERBTransformSpace::ERBTS_WORLD);
	}
}

void rc_applyActorTorqueImpulseLocal(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyTorqueImpulse(irr::core::vector3df(x,y,z), ERBTransformSpace::ERBTS_LOCAL);
	}
}

void rc_applyActorTorqueImpulseWorld(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyTorqueImpulse(irr::core::vector3df(x,y,z), ERBTransformSpace::ERBTS_WORLD);
	}
}

void rc_applyActorImpulseLocal(int actor, double x, double y, double z, double rel_x, double rel_y, double rel_z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyImpulse(irr::core::vector3df(x,y,z), irr::core::vector3df(rel_x, rel_y, rel_z), ERBTransformSpace::ERBTS_LOCAL);
	}
}

void rc_applyActorImpulseWorld(int actor, double x, double y, double z, double rel_x, double rel_y, double rel_z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyImpulse(irr::core::vector3df(x,y,z), irr::core::vector3df(rel_x, rel_y, rel_z), ERBTransformSpace::ERBTS_WORLD);
	}
}

void rc_clearActorForces(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->clearForces();
	}
}

void rc_updateActorInertiaTensor(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->updateInertiaTensor();
	}
}

void rc_getActorCOMPosition(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df pos = rc_actor[actor].physics.rigid_body->getCenterOfMassPosition();
		*x = pos.X;
		*y = pos.Y;
		*z = pos.Z;
	}
}

void rc_getActorRotationQ(int actor, double* x, double* y, double* z, double* w)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;
    *w = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::quaternion q = rc_actor[actor].physics.rigid_body->getOrientation();
		*x = q.X;
		*y = q.Y;
		*z = q.Z;
		*w = q.W;
	}
}

void rc_getActorLinearVelocityWorld(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df pos = rc_actor[actor].physics.rigid_body->getLinearVelocity();
		*x = pos.X;
		*y = pos.Y;
		*z = pos.Z;
	}
}

void rc_getActorAngularVelocityWorld(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df pos = rc_actor[actor].physics.rigid_body->getAngularVelocity();
		*x = pos.X;
		*y = pos.Y;
		*z = pos.Z;
	}
}

void rc_setActorLinearVelocityLocal(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->setLinearVelocity(irr::core::vector3df(x, y, z), ERBTransformSpace::ERBTS_LOCAL);
	}
}

void rc_setActorLinearVelocityWorld(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->setLinearVelocity(irr::core::vector3df(x, y, z), ERBTransformSpace::ERBTS_WORLD);
	}
}

void rc_setActorAngularVelocityLocal(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->setAngularVelocity(irr::core::vector3df(x, y, z), ERBTransformSpace::ERBTS_LOCAL);
	}
}

void rc_setActorAngularVelocityWorld(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->setAngularVelocity(irr::core::vector3df(x, y, z), ERBTransformSpace::ERBTS_WORLD);
	}
}

void rc_getActorLocalPointVelocity(int actor, double rel_x, double rel_y, double rel_z, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df pos = rc_actor[actor].physics.rigid_body->getVelocityInLocalPoint(irr::core::vector3df(rel_x, rel_y, rel_z));
		*x = pos.X;
		*y = pos.Y;
		*z = pos.Z;
	}
}

void rc_getActorLinearVelocityLocal(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		btVector3 v = rc_actor[actor].physics.rigid_body->getPointer()->getWorldTransform().getBasis().transpose() * rc_actor[actor].physics.rigid_body->getPointer()->getLinearVelocity();
		*x = v.getX();
		*y = v.getY();
		*z = v.getZ();
	}
}

void rc_getActorAngularVelocityLocal(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		btVector3 v = rc_actor[actor].physics.rigid_body->getPointer()->getWorldTransform().getBasis().transpose() * rc_actor[actor].physics.rigid_body->getPointer()->getAngularVelocity();
		*x = v.getX();
		*y = v.getY();
		*z = v.getZ();
	}
}

void rc_getActorAABB(int actor, double* min_x, double* min_y, double* min_z, double* max_x, double* max_y, double* max_z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *min_x = 0;
	*min_y = 0;
	*min_z = 0;
	*max_x = 0;
	*max_y = 0;
	*max_z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df min_aabb;
		irr::core::vector3df max_aabb;
		rc_actor[actor].physics.rigid_body->getAabb(min_aabb, max_aabb);
		*min_x = min_aabb.X;
		*min_y = min_aabb.Y;
		*min_z = min_aabb.Z;
		*max_x = max_aabb.X;
		*max_y = max_aabb.Y;
		*max_z = max_aabb.Z;
	}
}

double rc_computeActorImpulseDenominator(int actor, double pos_x, double pos_y, double pos_z, double normal_x, double normal_y, double normal_z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		return rc_actor[actor].physics.rigid_body->computeImpulseDenominator(irr::core::vector3df(pos_x, pos_y, pos_z), irr::core::vector3df(normal_x, normal_y, normal_z));
	}
}

double rc_computeActorAngularImpulseDenominator(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		return rc_actor[actor].physics.rigid_body->computeAngularImpulseDenominator(irr::core::vector3df(x, y, z));
	}
}

void rc_setActorAngularFactor(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->setAngularFactor(irr::core::vector3df(x, y, z));
	}
}

void rc_getActorAngularFactor(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df af = rc_actor[actor].physics.rigid_body->getAngularFactor();
		*x = af.X;
		*y = af.Y;
		*z = af.Z;
	}
}

void rc_computeActorGyroImpulseLocal(int actor, double step, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		btVector3 v = rc_actor[actor].physics.rigid_body->getPointer()->computeGyroscopicImpulseImplicit_Body(step);
		*x = v.getX();
		*y = v.getY();
		*z = v.getZ();
	}
}

void rc_computeActorGyroImpulseWorld(int actor, double dt, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		btVector3 v = rc_actor[actor].physics.rigid_body->getPointer()->computeGyroscopicImpulseImplicit_World(dt);
		*x = v.getX();
		*y = v.getY();
		*z = v.getZ();
	}
}

void rc_getActorLocalInertia(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		btVector3 v = rc_actor[actor].physics.rigid_body->getPointer()->getLocalInertia();
		*x = v.getX();
		*y = v.getY();
		*z = v.getZ();
	}
}

int getConstraintId()
{
	int cid = -1;
	for(int i = 0; i < rc_physics3D.constraints.size(); i++)
	{
		if(rc_physics3D.constraints[i].type <= 0)
		{
			cid = i;
			break;
		}
	}

	if(cid >= 0)
		return cid;

	rc_constraint_obj constraint;
	cid = rc_physics3D.constraints.size();
	rc_physics3D.constraints.push_back(constraint);
	return cid;
}

int rc_createPointConstraint(int actorA, double pxA, double pyA, double pzA)
{
	if(actorA < 0 || actorA >= rc_actor.size())
        return -1;

    if(rc_actor[actorA].physics.rigid_body)
	{
		rc_constraint_obj p2p;
		p2p.type = RC_CONSTRAINT_TYPE_POINT;
		btVector3 pvtA(pxA, pyA, pzA);
		p2p.constraint = new btPoint2PointConstraint(*rc_actor[actorA].physics.rigid_body->getPointer(), pvtA);
		rc_physics3D.world->getPointer()->addConstraint(p2p.constraint);
		int constraint_id = getConstraintId();
		rc_physics3D.constraints[constraint_id] = p2p;
		return constraint_id;
	}

	return -1;
}

int rc_createPointConstraintEx(int actorA, int actorB, double pxA, double pyA, double pzA, double pxB, double pyB, double pzB)
{
	if(actorA < 0 || actorA >= rc_actor.size() || actorB < 0 || actorB >= rc_actor.size())
        return -1;

    if(rc_actor[actorA].physics.rigid_body && rc_actor[actorB].physics.rigid_body)
	{
		rc_constraint_obj p2p;
		p2p.type = RC_CONSTRAINT_TYPE_POINT;
		btVector3 pvtA(pxA, pyA, pzA);
		btVector3 pvtB(pxB, pyB, pzB);
		p2p.constraint = new btPoint2PointConstraint(*rc_actor[actorA].physics.rigid_body->getPointer(), *rc_actor[actorB].physics.rigid_body->getPointer(),
														pvtA, pvtB);
		rc_physics3D.world->getPointer()->addConstraint(p2p.constraint);
		int constraint_id = getConstraintId();
		rc_physics3D.constraints[constraint_id] = p2p;
		return constraint_id;
	}
}

void rc_setPointPivotA(int constraint_id, double x, double y, double z)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

    if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* c = (btPoint2PointConstraint*)rc_physics3D.constraints[constraint_id].constraint;
		c->setPivotA(btVector3(x, y, z));
	}
}

void rc_setPointPivotB(int constraint_id, double x, double y, double z)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

    if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* c = (btPoint2PointConstraint*)rc_physics3D.constraints[constraint_id].constraint;
		c->setPivotB(btVector3(x, y, z));
	}
}

int rc_createHingeConstraint(int actorA, int frameInA_matrix, bool useReferenceFrameA)
{
	if(actorA < 0 || actorA >= rc_actor.size())
        return -1;

    if(rc_actor[actorA].physics.rigid_body)
	{
		rc_constraint_obj hinge;
		hinge.type = RC_CONSTRAINT_TYPE_HINGE;

		irr::core::matrix4 irr_matA = rc_convertToIrrMatrix(frameInA_matrix);
		btTransform frameInA;
		btTransformFromIrrlichtMatrix(irr_matA, frameInA);

		hinge.constraint = new btHingeConstraint(*rc_actor[actorA].physics.rigid_body->getPointer(), frameInA, useReferenceFrameA);
		rc_physics3D.world->getPointer()->addConstraint(hinge.constraint);
		int constraint_id = getConstraintId();
		rc_physics3D.constraints[constraint_id] = hinge;
		return constraint_id;
	}
}


int rc_createHingeConstraintEx(int actorA, int actorB, int frameInA_matrix, int frameInB_matrix, bool useReferenceFrameA)
{
	if(actorA < 0 || actorA >= rc_actor.size() || actorB < 0 || actorB >= rc_actor.size())
        return -1;

    if(rc_actor[actorA].physics.rigid_body && rc_actor[actorB].physics.rigid_body)
	{
		rc_constraint_obj hinge;
		hinge.type = RC_CONSTRAINT_TYPE_HINGE;

		irr::core::matrix4 irr_matA = rc_convertToIrrMatrix(frameInA_matrix);
		irr::core::matrix4 irr_matB = rc_convertToIrrMatrix(frameInB_matrix);

		btTransform frameInA, frameInB;
		btTransformFromIrrlichtMatrix(irr_matA, frameInA);
		btTransformFromIrrlichtMatrix(irr_matB, frameInB);

		hinge.constraint = new btHingeConstraint(*rc_actor[actorA].physics.rigid_body->getPointer(), *rc_actor[actorB].physics.rigid_body->getPointer(), frameInA, frameInB, useReferenceFrameA);
		rc_physics3D.world->getPointer()->addConstraint(hinge.constraint);
		int constraint_id = getConstraintId();
		rc_physics3D.constraints[constraint_id] = hinge;
		return constraint_id;
	}
}

int rc_createSlideConstraint(int actorA, int frameInB_matrix, bool useLinearReferenceFrameA)
{
	if(actorA < 0 || actorA >= rc_actor.size())
        return -1;

    if(rc_actor[actorA].physics.rigid_body)
	{
		rc_constraint_obj slide;
		slide.type = RC_CONSTRAINT_TYPE_SLIDER;

		irr::core::matrix4 irr_mat = rc_convertToIrrMatrix(frameInB_matrix);
		btTransform frameInB;
		btTransformFromIrrlichtMatrix(irr_mat, frameInB);

		slide.constraint = new btSliderConstraint(*rc_actor[actorA].physics.rigid_body->getPointer(), frameInB, useLinearReferenceFrameA);
		rc_physics3D.world->getPointer()->addConstraint(slide.constraint);
		int constraint_id = getConstraintId();
		rc_physics3D.constraints[constraint_id] = slide;
		return constraint_id;
	}
}

int rc_createSlideConstraintEx(int actorA, int actorB, int frameInA_matrix, int frameInB_matrix, bool useLinearReferenceFrameA)
{
	if(actorA < 0 || actorA >= rc_actor.size() || actorB < 0 || actorB >= rc_actor.size())
        return -1;

    if(rc_actor[actorA].physics.rigid_body && rc_actor[actorB].physics.rigid_body)
	{
		rc_constraint_obj slide;
		slide.type = RC_CONSTRAINT_TYPE_SLIDER;

		irr::core::matrix4 irr_matA = rc_convertToIrrMatrix(frameInA_matrix);
		irr::core::matrix4 irr_matB = rc_convertToIrrMatrix(frameInB_matrix);

		btTransform frameInA, frameInB;
		btTransformFromIrrlichtMatrix(irr_matA, frameInA);
		btTransformFromIrrlichtMatrix(irr_matB, frameInB);

		slide.constraint = new btSliderConstraint(*rc_actor[actorA].physics.rigid_body->getPointer(), *rc_actor[actorB].physics.rigid_body->getPointer(), frameInA, frameInB, useLinearReferenceFrameA);
		rc_physics3D.world->getPointer()->addConstraint(slide.constraint);
		int constraint_id = getConstraintId();
		rc_physics3D.constraints[constraint_id] = slide;
		return constraint_id;
	}
}


int rc_createConeConstraint(int actorA, int rbAFrame_matrix)
{
	if(actorA < 0 || actorA >= rc_actor.size())
        return -1;

    if(rc_actor[actorA].physics.rigid_body)
	{
		rc_constraint_obj cone;
		cone.type = RC_CONSTRAINT_TYPE_CONE;

		irr::core::matrix4 irr_matA = rc_convertToIrrMatrix(rbAFrame_matrix);

		btTransform rba;
		btTransformFromIrrlichtMatrix(irr_matA, rba);

		cone.constraint = new btConeTwistConstraint(*rc_actor[actorA].physics.rigid_body->getPointer(), rba);
		rc_physics3D.world->getPointer()->addConstraint(cone.constraint);
		int constraint_id = getConstraintId();
		rc_physics3D.constraints[constraint_id] = cone;
		return constraint_id;
	}
}

int rc_createConeConstraintEx(int actorA, int actorB, int rbAFrame_matrix, int rbBFrame_matrix)
{
	if(actorA < 0 || actorA >= rc_actor.size() || actorB < 0 || actorB >= rc_actor.size())
        return -1;

    if(rc_actor[actorA].physics.rigid_body && rc_actor[actorB].physics.rigid_body)
	{
		rc_constraint_obj cone;
		cone.type = RC_CONSTRAINT_TYPE_CONE;

		irr::core::matrix4 irr_matA = rc_convertToIrrMatrix(rbAFrame_matrix);
		irr::core::matrix4 irr_matB = rc_convertToIrrMatrix(rbBFrame_matrix);

		btTransform rba, rbb;
		btTransformFromIrrlichtMatrix(irr_matA, rba);
		btTransformFromIrrlichtMatrix(irr_matB, rbb);

		cone.constraint = new btConeTwistConstraint(*rc_actor[actorA].physics.rigid_body->getPointer(), *rc_actor[actorB].physics.rigid_body->getPointer(), rba, rbb);
		rc_physics3D.world->getPointer()->addConstraint(cone.constraint);
		int constraint_id = getConstraintId();
		rc_physics3D.constraints[constraint_id] = cone;
		return constraint_id;
	}
}

void rc_deleteConstraint(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

    if(rc_physics3D.constraints[constraint_id].constraint)
	{
		rc_physics3D.world->getPointer()->removeConstraint(rc_physics3D.constraints[constraint_id].constraint);
		rc_physics3D.constraints[constraint_id].constraint = NULL;
		rc_physics3D.constraints[constraint_id].type = 0;
	}
}

bool rc_constraintExists(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return false;

    if(rc_physics3D.constraints[constraint_id].constraint)
		return true;

	return false;
}


void rc_getConstraintFrameOffsetA(int constraint_id, double* x, double* y, double* z, double* rx, double* ry, double* rz)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

	*rx = 0;
	*ry = 0;
	*rz = 0;

    if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*)rc_physics3D.constraints[constraint_id].constraint;
		//btTransform t = hinge->getFrameOffsetA();
		//t.getBasis().getEulerZYX()
		*x = hinge->getFrameOffsetA().getOrigin().getX();
		*y = hinge->getFrameOffsetA().getOrigin().getY();
		*z = hinge->getFrameOffsetA().getOrigin().getZ();

		btScalar yaw, pitch, roll;
		hinge->getFrameOffsetA().getBasis().getEulerZYX(yaw, pitch, roll);
		*rx = roll;
		*ry = pitch;
		*rz = yaw;
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*)rc_physics3D.constraints[constraint_id].constraint;
		*x = cone->getFrameOffsetA().getOrigin().getX();
		*y = cone->getFrameOffsetA().getOrigin().getY();
		*z = cone->getFrameOffsetA().getOrigin().getZ();

		btScalar yaw, pitch, roll;
		cone->getFrameOffsetA().getBasis().getEulerZYX(yaw, pitch, roll);
		*rx = roll;
		*ry = pitch;
		*rz = yaw;
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*)rc_physics3D.constraints[constraint_id].constraint;
		*x = slide->getFrameOffsetA().getOrigin().getX();
		*y = slide->getFrameOffsetA().getOrigin().getY();
		*z = slide->getFrameOffsetA().getOrigin().getZ();

		btScalar yaw, pitch, roll;
		slide->getFrameOffsetA().getBasis().getEulerZYX(yaw, pitch, roll);
		*rx = roll;
		*ry = pitch;
		*rz = yaw;
	}
}

void rc_getConstraintFrameOffsetB(int constraint_id, double* x, double* y, double* z, double* rx, double* ry, double* rz)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

	*rx = 0;
	*ry = 0;
	*rz = 0;

    if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*)rc_physics3D.constraints[constraint_id].constraint;
		*x = hinge->getFrameOffsetB().getOrigin().getX();
		*y = hinge->getFrameOffsetB().getOrigin().getY(); btTransform:
		*z = hinge->getFrameOffsetB().getOrigin().getZ();

		btScalar yaw, pitch, roll;
		hinge->getFrameOffsetB().getBasis().getEulerZYX(yaw, pitch, roll);
		*rx = roll;
		*ry = pitch;
		*rz = yaw;
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*)rc_physics3D.constraints[constraint_id].constraint;
		*x = cone->getFrameOffsetB().getOrigin().getX();
		*y = cone->getFrameOffsetB().getOrigin().getY();
		*z = cone->getFrameOffsetB().getOrigin().getZ();

		btScalar yaw, pitch, roll;
		cone->getFrameOffsetB().getBasis().getEulerZYX(yaw, pitch, roll);
		*rx = roll;
		*ry = pitch;
		*rz = yaw;
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*)rc_physics3D.constraints[constraint_id].constraint;
		*x = slide->getFrameOffsetB().getOrigin().getX();
		*y = slide->getFrameOffsetB().getOrigin().getY();
		*z = slide->getFrameOffsetB().getOrigin().getZ();

		btScalar yaw, pitch, roll;
		slide->getFrameOffsetB().getBasis().getEulerZYX(yaw, pitch, roll);
		*rx = roll;
		*ry = pitch;
		*rz = yaw;
	}
}


void rc_useConstraintFrameOffset(int constraint_id, bool flag)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		hinge->setUseFrameOffset(flag);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setUseFrameOffset(flag);
	}
}

//btHingeConstraint::getHingeAngle()
double rc_getHingeAngle(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return hinge->getHingeAngle();
	}

	return 0;
}

double rc_getHingeAngleEx(int constraint_id, int t_matrixA, int t_matrixB)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btTransform transformA, transformB;
		irr::core::matrix4 irr_matA = rc_convertToIrrMatrix(t_matrixA);
		irr::core::matrix4 irr_matB = rc_convertToIrrMatrix(t_matrixB);
		btTransformFromIrrlichtMatrix(irr_matA, transformA);
		btTransformFromIrrlichtMatrix(irr_matB, transformB);
		return hinge->getHingeAngle(transformA, transformB);
	}

	return 0;
}

//btHingeConstraint::getBreakingImpulseThreshold()
double rc_getConstraintBreakingImpulseThreshold(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return hinge->getBreakingImpulseThreshold();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* p2p = (btPoint2PointConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return p2p->getBreakingImpulseThreshold();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getBreakingImpulseThreshold();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getBreakingImpulseThreshold();
	}

	return 0;
}

//btHingeConstraint::getAFrame()
int rc_getConstraintAFrame(int constraint_id, int mA)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return -1;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btTransform aframe = hinge->getAFrame();
		irr::core::matrix4 irr_mat;
		btTransformToIrrlichtMatrix(aframe, irr_mat);
		mA = rc_convertFromIrrMatrix(irr_mat, mA);
		return mA;
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btTransform aframe = cone->getAFrame();
		irr::core::matrix4 irr_mat;
		btTransformToIrrlichtMatrix(aframe, irr_mat);
		mA = rc_convertFromIrrMatrix(irr_mat, mA);
		return mA;
	}

	return -1;
}

//btHingeConstraint::getBFrame()
int rc_getConstraintBFrame(int constraint_id, int mA)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return -1;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btTransform bframe = hinge->getBFrame();
		irr::core::matrix4 irr_mat;
		btTransformToIrrlichtMatrix(bframe, irr_mat);
		mA = rc_convertFromIrrMatrix(irr_mat, mA);
		return mA;
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btTransform bframe = cone->getBFrame();
		irr::core::matrix4 irr_mat;
		btTransformToIrrlichtMatrix(bframe, irr_mat);
		mA = rc_convertFromIrrMatrix(irr_mat, mA);
		return mA;
	}

	return -1;
}

//btHingeConstraint::setAxis()
void rc_setHingeAxis(int constraint_id, double x, double y, double z)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btVector3 axis(x,y,z);
		hinge->setAxis(axis);
	}
}

//btHingeConstraint::setBreakingImpulseThreshold()
void rc_setConstraintBreakingImpulseThreshold(int constraint_id, double threshold)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		hinge->setBreakingImpulseThreshold(threshold);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* p2p = (btPoint2PointConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		p2p->setBreakingImpulseThreshold(threshold);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		cone->setBreakingImpulseThreshold(threshold);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setBreakingImpulseThreshold(threshold);
	}
}

//btHingeConstraint::setFrames()
void rc_setConstraintFrames(int constraint_id, int frameA_matrix, int frameB_matrix)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btTransform frameA, frameB;
		irr::core::matrix4 irr_matA, irr_matB;
		irr_matA = rc_convertToIrrMatrix(frameA_matrix);
		irr_matB = rc_convertToIrrMatrix(frameB_matrix);
		btTransformFromIrrlichtMatrix(irr_matA, frameA);
		btTransformFromIrrlichtMatrix(irr_matB, frameB);
		hinge->setFrames(frameA, frameB);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btTransform frameA, frameB;
		irr::core::matrix4 irr_matA, irr_matB;
		irr_matA = rc_convertToIrrMatrix(frameA_matrix);
		irr_matB = rc_convertToIrrMatrix(frameB_matrix);
		btTransformFromIrrlichtMatrix(irr_matA, frameA);
		btTransformFromIrrlichtMatrix(irr_matB, frameB);
		cone->setFrames(frameA, frameB);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btTransform frameA, frameB;
		irr::core::matrix4 irr_matA, irr_matB;
		irr_matA = rc_convertToIrrMatrix(frameA_matrix);
		irr_matB = rc_convertToIrrMatrix(frameB_matrix);
		btTransformFromIrrlichtMatrix(irr_matA, frameA);
		btTransformFromIrrlichtMatrix(irr_matB, frameB);
		slide->setFrames(frameA, frameB);
	}
}

//btHingeConstraint::setLimit();
void rc_setHingeLimit(int constraint_id, double low, double high, double softness, double bias_factor, double relaxation_factor)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		hinge->setLimit(low, high, softness, bias_factor, relaxation_factor);
	}
}

void rc_setConeLimit(int constraint_id, double swingSpan1, double swingSpan2, double twistSpan, double softness, double bias_factor, double relaxation_factor)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		cone->setLimit(swingSpan1, swingSpan2, twistSpan, softness, bias_factor, relaxation_factor);
	}
}

//btHingeConstraint::getLimitBiasFactor()
double rc_getHingeLimitBiasFactor(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return hinge->getLimitBiasFactor();
	}

	return 0;
}

//btHingeConstraint::getLimitRelaxationFactor()
double rc_getHingeLimitRelaxationFactor(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return hinge->getLimitRelaxationFactor();
	}

	return 0;
}

//btHingeConstraint::getLimitSign()
double rc_getHingeLimitSign(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return hinge->getLimitSign();
	}

	return 0;
}

//btHingeConstraint::getSolveLimit()
int rc_getHingeSolveLimit(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return hinge->getSolveLimit();
	}

	return 0;
}

//btHingeConstraint::setUseReferenceFrameA()
void rc_useHingeReferenceFrameA(int constraint_id, bool flag)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		hinge->setUseReferenceFrameA(flag);
	}
}


//
//btPoint2PointConstraint::getAppliedImpulse()
double rc_getConstraintAppliedImpulse(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return hinge->getAppliedImpulse();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* p2p = (btPoint2PointConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return p2p->getAppliedImpulse();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getAppliedImpulse();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getAppliedImpulse();
	}

	return 0;
}


//btPoint2PointConstraint::getFixedBody()
int rc_getConstraintFixedActor(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return -1;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = hinge->getFixedBody();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* p2p = (btPoint2PointConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = p2p->getFixedBody();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = cone->getFixedBody();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = slide->getFixedBody();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}

	return -1;
}

//btPoint2PointConstraint::getPivotInA()
void rc_getPointPivotA(int constraint_id, double* x, double* y, double* z)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* p2p = (btPoint2PointConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btVector3 pivot = p2p->getPivotInA();
		*x = pivot.getX();
		*y = pivot.getY();
		*z = pivot.getZ();
	}
}

//btPoint2PointConstraint::getPivotInB()
void rc_getPointPivotB(int constraint_id, double* x, double* y, double* z)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* p2p = (btPoint2PointConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btVector3 pivot = p2p->getPivotInB();
		*x = pivot.getX();
		*y = pivot.getY();
		*z = pivot.getZ();
	}
}

//btPoint2PointConstraint::getRigidBodyA()
int rc_getConstraintActorA(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return -1;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = hinge->getRigidBodyA();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* p2p = (btPoint2PointConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = p2p->getRigidBodyA();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = cone->getRigidBodyA();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = slide->getRigidBodyA();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}

	return -1;
}

//btPoint2PointConstraint::getRigidBodyB()
int rc_getConstraintActorB(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return -1;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = hinge->getRigidBodyB();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* p2p = (btPoint2PointConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = p2p->getRigidBodyB();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = cone->getRigidBodyB();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = slide->getRigidBodyB();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}

	return -1;
}

//btPoint2PointConstraint::setOverrideNumSolverIterations()
void rc_setConstraintSolverIterations(int constraint_id, int num)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		hinge->setOverrideNumSolverIterations(num);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* p2p = (btPoint2PointConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		p2p->setOverrideNumSolverIterations(num);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		cone->setOverrideNumSolverIterations(num);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setOverrideNumSolverIterations(num);
	}
}

//
//btConeTwistConstraint::getBiasFactor()
double rc_getConeBiasFactor(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getBiasFactor();
	}

	return 0;
}

//btConeTwistConstraint::getDamping()
double rc_getConeDamping(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getDamping();
	}

	return 0;
}

//btConeTwistConstraint::getFixThresh()
double rc_getConeFixThresh(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getFixThresh();
	}

	return 0;
}

//btConeTwistConstraint::getLimit()
double rc_getConeLimit(int constraint_id, int limit_index)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getLimit(limit_index);
	}

	return 0;
}

//btConeTwistConstraint::getLimitSoftness()
double rc_getConstraintLimitSoftness(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return hinge->getLimitSoftness();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getLimitSoftness();
	}

	return 0;
}

//btConeTwistConstraint::getOverrideNumSolverIterations()
double rc_getConstraintSolverIterations(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return hinge->getOverrideNumSolverIterations();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* p2p = (btPoint2PointConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return p2p->getOverrideNumSolverIterations();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getOverrideNumSolverIterations();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getOverrideNumSolverIterations();
	}

	return 0;
}

//btConeTwistConstraint::GetPointForAngle()
void rc_getConeAnglePoint(int constraint_id, double angle, double len, double* x, double* y, double* z)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btVector3 v = cone->GetPointForAngle( radians(angle), len);
		*x = v.getX();
		*y = v.getY();
		*z = v.getZ();
	}
}

//btConeTwistConstraint::getAngularOnly()
bool rc_getConstraintAngularOnly(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return false;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return hinge->getAngularOnly();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getAngularOnly();
	}

	return false;
}

//btConeTwistConstraint::getSolveSwingLimit()
int rc_getConeSolveSwingLimit(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getSolveSwingLimit();
	}

	return 0;
}

int rc_getConeSolveTwistLimit(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getSolveTwistLimit();
	}

	return 0;
}

//btConeTwistConstraint::getSwingSpan1()
double rc_getConeSwingSpan1(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getSwingSpan1();
	}

	return 0;
}

//btConeTwistConstraint::getSwingSpan2()
int rc_getConeSwingSpan2(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getSwingSpan2();
	}

	return 0;
}

//btConeTwistConstraint::getTwistAngle()
double rc_getConeTwistAngle(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getTwistAngle();
	}

	return 0;
}


//btConeTwistConstraint::getTwistLimitSign()
double rc_getConeTwistLimitSign(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getTwistLimitSign();
	}

	return 0;
}

//btConeTwistConstraint::getTwistSpan()
int rc_getConeTwistSpan(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getTwistSpan();
	}

	return 0;
}

//btConeTwistConstraint::setAngularOnly()
void rc_setConstraintAngularOnly(int constraint_id, bool flag)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		hinge->setAngularOnly(flag);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		cone->setAngularOnly(flag);
	}
}

//btConeTwistConstraint::setDamping()
void rc_setConeDamping(int constraint_id, double damping)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		cone->setDamping(damping);
	}
}

//btConeTwistConstraint::setFixThresh()
void rc_setConeFixThresh(int constraint_id, double fixThresh)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		cone->setFixThresh(fixThresh);
	}
}


//btSliderConstraint::getAncorInA()
void rc_getSlideAnchorA(int constraint_id, double* x, double* y, double* z)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btVector3 v = slide->getAncorInA();
		*x = v.getX();
		*y = v.getY();
		*z = v.getZ();
	}
}

//btSliderConstraint::getAncorInB()
void rc_getSlideAnchorB(int constraint_id, double* x, double* y, double* z)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btVector3 v = slide->getAncorInB();
		*x = v.getX();
		*y = v.getY();
		*z = v.getZ();
	}
}

//btSliderConstraint::getAngDepth()
double rc_getSlideAngDepth(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getAngDepth();
	}

	return 0;
}

//btSliderConstraint::getAngularPos()
double rc_getSlideAngularPos(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getAngularPos();
	}

	return 0;
}

//btSliderConstraint::getDampingDirAng()
double rc_getSlideDampingDirAng(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getDampingDirAng();
	}

	return 0;
}

//btSliderConstraint::getDampingDirLin()
double rc_getSlideDampingDirLin(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getDampingDirLin();
	}

	return 0;
}

//btSliderConstraint::getDampingLimAng()
double rc_getSlideDampingLimAng(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getDampingLimAng();
	}

	return 0;
}

//btSliderConstraint::getDampingLimLin()
double rc_getSlideDampingLimLin(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getDampingLimLin();
	}

	return 0;
}

//btSliderConstraint::getDampingOrthoAng()
double rc_getSlideDampingOrthoAng(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getDampingOrthoAng();
	}

	return 0;
}

//btSliderConstraint::getDampingOrthoLin()
double rc_getSlideDampingOrthoLin(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getDampingOrthoLin();
	}

	return 0;
}

//btSliderConstraint::getLinearPos()
double rc_getSlideLinearPos(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getLinearPos();
	}

	return 0;
}

//btSliderConstraint::getLinDepth()
double rc_getSlideLinDepth(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getLinDepth();
	}

	return 0;
}

//btSliderConstraint::getLowerAngLimit()
double rc_getSlideLowerAngLimit(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getLowerAngLimit();
	}

	return 0;
}

//btSliderConstraint::getLowerLinLimit()
double rc_getSlideLowerLinLimit(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getLowerLinLimit();
	}

	return 0;
}

//btSliderConstraint::getRestitutionDirAng()
double rc_getSlideRestitutionDirAng(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getRestitutionDirAng();
	}

	return 0;
}

//btSliderConstraint::getRestitutionDirLin()
double rc_getSlideRestitutionDirLin(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getRestitutionDirLin();
	}

	return 0;
}

//btSliderConstraint::getRestitutionLimAng()
double rc_getSlideRestitutionLimAng(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getRestitutionLimAng();
	}

	return 0;
}

//btSliderConstraint::getRestitutionLimLin()
double rc_getSlideRestitutionLimLin(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getRestitutionLimLin();
	}

	return 0;
}

//btSliderConstraint::getRestitutionOrthoAng()
double rc_getSlideRestitutionOrthoAng(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getRestitutionOrthoAng();
	}

	return 0;
}

//btSliderConstraint::getRestitutionOrthoLin()
double rc_getSlideRestitutionOrthoLin(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getRestitutionOrthoLin();
	}

	return 0;
}

//btSliderConstraint::getSoftnessDirAng()
double rc_getSlideSoftnessDirAng(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getSoftnessDirAng();
	}

	return 0;
}

//btSliderConstraint::getSoftnessDirLin()
double rc_getSlideSoftnessDirLin(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getSoftnessDirLin();
	}

	return 0;
}

//btSliderConstraint::getSoftnessLimAng()
double rc_getSlideSoftnessLimAng(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getSoftnessLimAng();
	}

	return 0;
}

//btSliderConstraint::getSoftnessLimLin()
double rc_getSlideSoftnessLimLin(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getSoftnessLimLin();
	}

	return 0;
}

//btSliderConstraint::getSoftnessOrthoAng()
double rc_getSlideSoftnessOrthoAng(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getSoftnessOrthoAng();
	}

	return 0;
}

//btSliderConstraint::getSoftnessOrthoLin()
double rc_getSlideSoftnessOrthoLin(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getSoftnessOrthoLin();
	}

	return 0;
}

//btSliderConstraint::getSolveAngLimit()
bool rc_getSlideSolveAngLimit(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getSolveAngLimit();
	}

	return 0;
}

//btSliderConstraint::getSolveLinLimit()
bool rc_getSlideSolveLinLimit(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getSolveLinLimit();
	}

	return 0;
}

//btSliderConstraint::getUpperAngLimit()
double rc_getSlideUpperAngLimit(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getUpperAngLimit();
	}

	return 0;
}

//btSliderConstraint::getUpperLinLimit()
double rc_getSlideUpperLinLimit(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getUpperLinLimit();
	}

	return 0;
}

//btSliderConstraint::getUseFrameOffset()
bool rc_getSlideUseFrameOffset(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getUseFrameOffset();
	}

	return 0;
}

//btSliderConstraint::setDampingDirAng()
void rc_setSlideDampingDirAng(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setDampingDirAng(n);
	}
}

//btSliderConstraint::setDampingDirLin()
void rc_setSlideDampingDirLin(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setDampingDirLin(n);
	}
}

//btSliderConstraint::setDampingLimAng()
void rc_setSlideDampingLimAng(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setDampingLimAng(n);
	}
}

//btSliderConstraint::setDampingLimLin()
void rc_setSlideDampingLimLin(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setDampingLimLin(n);
	}
}

//btSliderConstraint::setDampingOrthoAng()
void rc_setSlideDampingOrthoAng(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setDampingOrthoAng(n);
	}
}

//btSliderConstraint::setDampingOrthoLin()
void rc_setSlideDampingOrthoLin(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setDampingOrthoLin(n);
	}
}

//btSliderConstraint::setLowerAngLimit()
void rc_setSlideLowerAngLimit(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setLowerAngLimit(n);
	}
}

//btSliderConstraint::setLowerLinLimit()
void rc_setSlideLowerLinLimit(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setLowerLinLimit(n);
	}
}

//btSliderConstraint::setRestitutionDirAng()
void rc_setSlideRestitutionDirAng(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setRestitutionDirAng(n);
	}
}

//btSliderConstraint::setRestitutionDirLin()
void rc_setSlideRestitutionDirLin(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setRestitutionDirLin(n);
	}
}

//btSliderConstraint::setRestitutionLimAng()
void rc_setSlideRestitutionLimAng(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setRestitutionLimAng(n);
	}
}

//btSliderConstraint::setRestitutionLimLin()
void rc_setSlideRestitutionLimLin(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setRestitutionLimLin(n);
	}
}

//btSliderConstraint::setRestitutionOrthoAng()
void rc_setSlideRestitutionOrthoAng(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setRestitutionOrthoAng(n);
	}
}

//btSliderConstraint::setRestitutionOrthoLin()
void rc_setSlideRestitutionOrthoLin(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setRestitutionOrthoLin(n);
	}
}

//btSliderConstraint::setSoftnessDirAng()
void rc_setSlideSoftnessDirAng(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setSoftnessDirAng(n);
	}
}

//btSliderConstraint::setSoftnessDirLin()
void rc_setSlideSoftnessDirLin(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setSoftnessDirLin(n);
	}
}

//btSliderConstraint::setSoftnessLimAng()
void rc_setSlideSoftnessLimAng(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setSoftnessLimAng(n);
	}
}

//btSliderConstraint::setSoftnessLimLin()
void rc_setSlideSoftnessLimLin(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setSoftnessLimLin(n);
	}
}

//btSliderConstraint::setSoftnessOrthoAng()
void rc_setSlideSoftnessOrthoAng(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setSoftnessOrthoAng(n);
	}
}

//btSliderConstraint::setSoftnessOrthoLin()
void rc_setSlideSoftnessOrthoLin(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setSoftnessOrthoLin(n);
	}
}

//btSliderConstraint::setUpperAngLimit()
void rc_setSlideUpperAngLimit(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setUpperAngLimit(n);
	}
}

//btSliderConstraint::setUpperLinLimit()
void rc_setSlideUpperLinLimit(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setUpperLinLimit(n);
	}
}





void rc_setWorld3DDeltaTime(double dt)
{
	rc_physics3D.DeltaTime = dt;
}

void rc_setWorld3DMaxSubSteps(double steps)
{
	rc_physics3D.maxSubSteps = steps;
}

void rc_setWorld3DTimeStep(double ts)
{
	rc_physics3D.fixedTimeStep = ts;
}


//set actor animation [TODO]
void rc_setActorAnimation(int actor, int start_frame, int end_frame)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            node->setFrameLoop((irr::s32)start_frame, (irr::s32)end_frame );
            break;
    }
}

void rc_setActorMD2Animation(int actor, int md2_animation)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            node->setMD2Animation( (irr::scene::EMD2_ANIMATION_TYPE) md2_animation );
            break;
    }
}

void rc_setActorMD2AnimationByName(int actor, std::string animation_name)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            node->setMD2Animation( animation_name.c_str() );
            break;
    }
}

int rc_getActorStartFrame(int actor)
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            return node->getStartFrame();
    }

    return 0;
}

int rc_getActorEndFrame(int actor)
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            return node->getEndFrame();
    }

    return 0;
}

int rc_getActorCurrentFrame(int actor)
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            return node->getFrameNr();
    }

    return 0;
}

//set actor animation speed
void rc_setActorAnimationSpeed(int actor, double speed)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            node->setAnimationSpeed( (irr::f32)speed );
            break;
    }
}

double rc_getActorAnimationSpeed(int actor)
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            return node->getAnimationSpeed();
    }

    return 0;
}

void rc_setActorFrame(int actor, int frame)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            node->setCurrentFrame(frame);
            break;
    }
}

//set actor animation speed
void rc_setActorAutoCulling(int actor, int cull_type)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

	rc_actor[actor].mesh_node->setAutomaticCulling((irr::scene::E_CULLING_TYPE) cull_type);
}

int rc_getActorAutoCulling(int actor)
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(rc_actor[actor].mesh_node)
		return rc_actor[actor].mesh_node->getAutomaticCulling();

	return 0;
}


void rc_addActorShadow(int actor)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].shadow)
		return;

    switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_TERRAIN:
        case RC_NODE_TYPE_OTMESH:
        case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            rc_actor[actor].shadow = node->addShadowVolumeSceneNode();
            break;
    }
}

void rc_removeActorShadow(int actor)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

	if(!rc_actor[actor].shadow)
		return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_TERRAIN:
        case RC_NODE_TYPE_OTMESH:
        case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            node->removeChild(rc_actor[actor].shadow);
            break;
    }
}

bool rc_lightIsCastingShadow(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return false;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_LIGHT:
            irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)rc_actor[actor].mesh_node;
            return node->getCastShadow();
    }

    return false;
}

int rc_getLightType(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return -1;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_LIGHT:
            irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)rc_actor[actor].mesh_node;
            return (int)node->getLightType();
    }

    return -1;
}

double rc_getLightRadius(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_LIGHT:
            irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)rc_actor[actor].mesh_node;
            return node->getRadius();
    }

    return 0;
}

void rc_setLightType(int actor, int light_type)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_LIGHT:
            irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)rc_actor[actor].mesh_node;
            node->setLightType((irr::video::E_LIGHT_TYPE)light_type);
    }
}

void rc_setLightRadius(int actor, double radius)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_LIGHT:
            irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)rc_actor[actor].mesh_node;
            node->setRadius(radius);
    }
}


void rc_setLightShadowCast(int actor, bool flag)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_LIGHT:
            irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)rc_actor[actor].mesh_node;
            node->enableCastShadow(flag);
    }
}

void rc_setLightAmbientColor(int actor, Uint32 color)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_LIGHT:
            irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)rc_actor[actor].mesh_node;
            irr::video::SColor c;
            c.set(color);
            irr::video::SColorf cf(c);
            irr::video::SLight light_data = node->getLightData();
            light_data.AmbientColor = cf;
            node->setLightData(light_data);
    }
}

Uint32 rc_getLightAmbientColor(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_LIGHT:
            irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)rc_actor[actor].mesh_node;
            irr::video::SLight light_data = node->getLightData();
            return light_data.AmbientColor.toSColor().color;
    }

    return 0;
}

void rc_setLightAttenuation(int actor, double l_constant, double l_linear, double l_quadratic)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_LIGHT:
            irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)rc_actor[actor].mesh_node;
            irr::video::SLight light_data = node->getLightData();
            light_data.Attenuation.set(l_constant, l_linear, l_quadratic);
            node->setLightData(light_data);
    }
}

void rc_getLightAttenuation(int actor, double* l_constant, double* l_linear, double* l_quadratic)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	*l_constant = 0;
	*l_linear = 0;
	*l_quadratic = 0;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_LIGHT:
            irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)rc_actor[actor].mesh_node;
            irr::video::SLight light_data = node->getLightData();
           *l_constant = light_data.Attenuation.X;
           *l_linear = light_data.Attenuation.Y;
           *l_quadratic = light_data.Attenuation.Z;
    }
}

void rc_setLightDiffuseColor(int actor, Uint32 color)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_LIGHT:
            irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)rc_actor[actor].mesh_node;
            irr::video::SColor c;
            c.set(color);
            irr::video::SColorf cf(c);
            irr::video::SLight light_data = node->getLightData();
            light_data.DiffuseColor = cf;
            node->setLightData(light_data);
    }
}

Uint32 rc_getLightDiffuseColor(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_LIGHT:
            irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)rc_actor[actor].mesh_node;
            irr::video::SLight light_data = node->getLightData();
            return light_data.DiffuseColor.toSColor().color;
    }

    return 0;
}

void rc_setLightFalloff(int actor, double falloff)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_LIGHT:
            irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)rc_actor[actor].mesh_node;
            irr::video::SLight light_data = node->getLightData();
            light_data.Falloff = falloff;
            node->setLightData(light_data);
    }
}

double rc_getLightFalloff(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_LIGHT:
            irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)rc_actor[actor].mesh_node;
            irr::video::SLight light_data = node->getLightData();
            return light_data.Falloff;
    }

    return 0;
}

void rc_setLightInnerCone(int actor, double angle)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_LIGHT:
            irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)rc_actor[actor].mesh_node;
            irr::video::SLight light_data = node->getLightData();
            light_data.InnerCone = angle;
            node->setLightData(light_data);
    }
}

double rc_getLightInnerCone(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_LIGHT:
            irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)rc_actor[actor].mesh_node;
            irr::video::SLight light_data = node->getLightData();
            return light_data.InnerCone;
    }

    return 0;
}

void rc_setLightOuterCone(int actor, double angle)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_LIGHT:
            irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)rc_actor[actor].mesh_node;
            irr::video::SLight light_data = node->getLightData();
            light_data.OuterCone = angle;
            node->setLightData(light_data);
    }
}

double rc_getLightOuterCone(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_LIGHT:
            irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)rc_actor[actor].mesh_node;
            irr::video::SLight light_data = node->getLightData();
            return light_data.OuterCone;
    }

    return 0;
}

void rc_setLightSpecularColor(int actor, Uint32 color)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_LIGHT:
            irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)rc_actor[actor].mesh_node;
            irr::video::SColor c;
            c.set(color);
            irr::video::SColorf cf(c);
            irr::video::SLight light_data = node->getLightData();
            light_data.SpecularColor = cf;
            node->setLightData(light_data);
    }
}

Uint32 rc_getLightSpecularColor(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_LIGHT:
            irr::scene::ILightSceneNode* node = (irr::scene::ILightSceneNode*)rc_actor[actor].mesh_node;
            irr::video::SLight light_data = node->getLightData();
            return light_data.SpecularColor.toSColor().color;
    }

    return 0;
}


void rc_loopActorAnimation(int actor, bool flag)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            node->setLoopMode(flag);
            break;
    }
}

bool rc_actorAnimationIsLooped(int actor)
{
    if(actor < 0 || actor >= rc_actor.size())
        return false;

    switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            return node->getLoopMode();
    }

    return false;
}

//set actor animation speed
void rc_setActorVisible(int actor, bool flag)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    irr::scene::ISceneNode* node = rc_actor[actor].mesh_node;
	node->setVisible(flag);
}

bool rc_actorIsVisible(int actor)
{
    if(actor < 0 || actor >= rc_actor.size())
        return false;

    return rc_actor[actor].mesh_node->isVisible();
}

void rc_startActorTransition(int actor, double frame, double transition_time)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].transition)
		return;

    switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            node->setTransitionTime(transition_time);
            node->setJointMode(irr::scene::EJUOR_CONTROL);
            node->setCurrentFrame(frame);
            rc_actor[actor].transition = true;
            rc_actor[actor].transition_time = transition_time;
            rc_actor[actor].transition_start_time = ((double)SDL_GetTicks())/1000.0d;
            rc_transition_actor.push_back(actor);
    }
}

double rc_getActorTransitionTime(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

	if(rc_actor[actor].transition)
		return rc_actor[actor].transition_time;

    return 0;
}


void rc_stopActorTransition(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;


    switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            node->setTransitionTime(0);
            node->setJointMode(irr::scene::EJUOR_NONE);
            rc_actor[actor].transition = false;
            rc_actor[actor].transition_time = 0;

            for(int i = 0; i < rc_transition_actor.size();)
			{
				if(rc_transition_actor[i] == actor)
				{
					rc_transition_actor.erase(i);
				}
				else
					i++;
			}
    }
}

bool rc_actorIsInTransition(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return false;

	return rc_actor[actor].transition;
}


void rc_getTerrainPatchAABB(int actor, double patch_x, double patch_z, double* min_x, double* min_y, double* min_z, double* max_x, double* max_y, double* max_z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	*min_x = 0;
	*min_y = 0;
	*min_z = 0;

	*max_x = 0;
	*max_y = 0;
    *max_z = 0;


    switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_TERRAIN:
            irr::scene::ITerrainSceneNode* node = (irr::scene::ITerrainSceneNode*)rc_actor[actor].mesh_node;
            irr::core::aabbox3d bbox = node->getBoundingBox(patch_x, patch_z);

            *min_x = bbox.MinEdge.X;
            *min_y = bbox.MinEdge.Y;
            *min_z = bbox.MinEdge.Z;

            *max_x = bbox.MaxEdge.X;
            *max_y = bbox.MaxEdge.Y;
            *max_z = bbox.MaxEdge.Z;
    }
}


int rc_getTerrainPatchLOD(int actor, int patchX, int patchZ)
{
	if(actor < 0 || actor >= rc_actor.size())
        return -1;

	switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_TERRAIN:
			irr::scene::ITerrainSceneNode* terrain = (irr::scene::ITerrainSceneNode*) rc_actor[actor].mesh_node;

			irr::core::array<irr::s32> lod;
			int lodp_size = terrain->getCurrentLODOfPatches(lod);
			irr::s32 dim_size = irr::core::squareroot(lodp_size);
			return lod[patchX * dim_size + patchZ];
    }

	return -1;
}

double rc_getTerrainHeight(int actor, int patchX, int patchZ )
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

	switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_TERRAIN:
			irr::scene::ITerrainSceneNode* terrain = (irr::scene::ITerrainSceneNode*) rc_actor[actor].mesh_node;
			return terrain->getHeight(patchX, patchZ);
    }

	return 0;
}

void rc_getTerrainCenter(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

	switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_TERRAIN:
			irr::scene::ITerrainSceneNode* terrain = (irr::scene::ITerrainSceneNode*) rc_actor[actor].mesh_node;
			irr::core::vector3df v = terrain->getTerrainCenter();
			*x = v.X;
			*y = v.Y;
			*z = v.Z;
    }
}

void rc_setTerrainLODDistance(int actor, int lod, double distance)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_TERRAIN:
			irr::scene::ITerrainSceneNode* terrain = (irr::scene::ITerrainSceneNode*) rc_actor[actor].mesh_node;
			terrain->overrideLODDistance(lod, distance);
    }
}

void rc_scaleTerrainTexture(int actor, double scale1, double scale2)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_TERRAIN:
			irr::scene::ITerrainSceneNode* terrain = (irr::scene::ITerrainSceneNode*) rc_actor[actor].mesh_node;
			terrain->scaleTexture(scale1, scale2);
    }
}

void rc_setTerrainCameraMovementDelta(int actor, double delta)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_TERRAIN:
			irr::scene::ITerrainSceneNode* terrain = (irr::scene::ITerrainSceneNode*) rc_actor[actor].mesh_node;
			terrain->setCameraMovementDelta(delta);
    }
}

void rc_setTerrainCameraRotationDelta(int actor, double delta)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_TERRAIN:
			irr::scene::ITerrainSceneNode* terrain = (irr::scene::ITerrainSceneNode*) rc_actor[actor].mesh_node;
			terrain->setCameraRotationDelta(delta);
    }
}

void rc_setTerrainPatchLOD(int actor, int patchX, int patchZ, int lod)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_TERRAIN:
			irr::scene::ITerrainSceneNode* terrain = (irr::scene::ITerrainSceneNode*) rc_actor[actor].mesh_node;
			terrain->setLODOfPatch(patchX, patchZ, lod);
    }
}

int rc_getParticleType(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return 0;

	return rc_actor[actor].particle_properties.particle_type;
}

void rc_startParticleEmitter(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;


	bool everyMeshVertex = rc_actor[actor].particle_properties.everyMeshVertex;
	irr::s32 mbNumber = rc_actor[actor].particle_properties.mbNumber;
	irr::f32 normalDirectionModifier = rc_actor[actor].particle_properties.normalDirectionModifier;
	bool useNormalDirection = rc_actor[actor].particle_properties.useNormalDirection;
	irr::s32 mesh_id = rc_actor[actor].particle_properties.mesh_id;
	irr::core::vector3df direction = rc_actor[actor].particle_properties.direction;
	irr::u32 minParticlesPerSecond = rc_actor[actor].particle_properties.minParticlesPerSecond;
	irr::u32 maxParticlesPerSecond = rc_actor[actor].particle_properties.maxParticlesPerSecond;
	irr::video::SColor minStartColor = rc_actor[actor].particle_properties.minStartColor;
	irr::video::SColor maxStartColor = rc_actor[actor].particle_properties.maxStartColor;
	irr::u32 lifeTimeMin = rc_actor[actor].particle_properties.lifeTimeMin;
	irr::u32 lifeTimeMax = rc_actor[actor].particle_properties.lifeTimeMax;
	irr::s32 maxAngleDegrees = rc_actor[actor].particle_properties.maxAngleDegrees;
	irr::core::dimension2df minStartSize = rc_actor[actor].particle_properties.minStartSize;
	irr::core::dimension2df maxStartSize = rc_actor[actor].particle_properties.maxStartSize;
	irr::core::vector3df center = rc_actor[actor].particle_properties.center;
	irr::f32 radius = rc_actor[actor].particle_properties.radius;
	irr::f32 ringThickness = rc_actor[actor].particle_properties.ringThickness;
	irr::core::aabbox3df box = rc_actor[actor].particle_properties.box;
	irr::core::vector3df normal = rc_actor[actor].particle_properties.normal;
	irr::f32 length = rc_actor[actor].particle_properties.length;
	bool outlineOnly = rc_actor[actor].particle_properties.outlineOnly;

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*) rc_actor[actor].mesh_node;

	irr::scene::IParticleEmitter* em = NULL;

	switch(rc_actor[actor].particle_properties.particle_type)
    {
    	case RC_PARTICLE_TYPE_POINT:
			em = node->createPointEmitter(direction, minParticlesPerSecond, maxParticlesPerSecond,
										minStartColor, maxStartColor, lifeTimeMin, lifeTimeMax,
										maxAngleDegrees, minStartSize, maxStartSize);
			node->setEmitter(em);
			em->drop();
			break;

		case RC_PARTICLE_TYPE_BOX:
			em = node->createBoxEmitter(box, direction, minParticlesPerSecond, maxParticlesPerSecond,
										minStartColor, maxStartColor, lifeTimeMin, lifeTimeMax,
										maxAngleDegrees, minStartSize, maxStartSize);
			node->setEmitter(em);
			em->drop();
			break;

		case RC_PARTICLE_TYPE_SPHERE:
			em = node->createSphereEmitter(center, radius, direction,
											minParticlesPerSecond, maxParticlesPerSecond,
											minStartColor, maxStartColor, lifeTimeMin, lifeTimeMax,
											maxAngleDegrees, minStartSize, maxStartSize);
			node->setEmitter(em);
			em->drop();
			break;

		case RC_PARTICLE_TYPE_CYLINDER:
			em = node->createCylinderEmitter(center, radius, normal, length, outlineOnly,
											direction, minParticlesPerSecond, maxParticlesPerSecond,
											minStartColor, maxStartColor, lifeTimeMin, lifeTimeMax,
											maxAngleDegrees, minStartSize, maxStartSize);
			node->setEmitter(em);
			em->drop();
			break;

		case RC_PARTICLE_TYPE_MESH:
			if(mesh_id < 0 || mesh_id >= rc_mesh.size())
				return;

			if(!rc_mesh[mesh_id].mesh)
				return;

			em = node->createMeshEmitter(rc_mesh[mesh_id].mesh, useNormalDirection,
										direction, normalDirectionModifier, mbNumber, everyMeshVertex,
										minParticlesPerSecond, maxParticlesPerSecond,
										minStartColor, maxStartColor, lifeTimeMin, lifeTimeMax,
										maxAngleDegrees, minStartSize, maxStartSize);
			node->setEmitter(em);
			em->drop();
			break;

		case RC_PARTICLE_TYPE_RING:
			em = node->createRingEmitter(center, radius, ringThickness,
											direction, minParticlesPerSecond, maxParticlesPerSecond,
											minStartColor, maxStartColor, lifeTimeMin, lifeTimeMax,
											maxAngleDegrees, minStartSize, maxStartSize);
			node->setEmitter(em);
			em->drop();
			break;
    }
}

void rc_stopParticleEmitter(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*) rc_actor[actor].mesh_node;
	node->setEmitter(0);
}

void rc_setParticleDirection(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	rc_actor[actor].particle_properties.direction.set(x, y, z);

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*)rc_actor[actor].mesh_node;

	if(node->getEmitter())
		node->getEmitter()->setDirection( rc_actor[actor].particle_properties.direction );
}

void rc_getParticleDirection(int actor, double* x, double* y, double* z)
{
	*x = 0;
	*y = 0;
	*z = 0;

	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	*x = rc_actor[actor].particle_properties.direction.X;
	*y = rc_actor[actor].particle_properties.direction.Y;
	*z = rc_actor[actor].particle_properties.direction.Z;
}

void rc_useParticleEveryMeshVertex(int actor, bool flag)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	if(rc_actor[actor].particle_properties.particle_type != RC_PARTICLE_TYPE_MESH)
		return;

	rc_actor[actor].particle_properties.everyMeshVertex = flag;

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*)rc_actor[actor].mesh_node;

	if(node->getEmitter())
	{
		irr::scene::IParticleMeshEmitter* em = (irr::scene::IParticleMeshEmitter*)node->getEmitter();
		em->setEveryMeshVertex(rc_actor[actor].particle_properties.everyMeshVertex);
	}
}

bool rc_particleIsUsingEveryMeshVertex(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return false;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return false;

	if(rc_actor[actor].particle_properties.particle_type != RC_PARTICLE_TYPE_MESH)
		return false;

	return rc_actor[actor].particle_properties.everyMeshVertex;

}

void rc_setParticleNormalDirectionMod(int actor, double mod)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	if(rc_actor[actor].particle_properties.particle_type != RC_PARTICLE_TYPE_MESH)
		return;

	rc_actor[actor].particle_properties.normalDirectionModifier = mod;

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*)rc_actor[actor].mesh_node;

	if(node->getEmitter())
	{
		irr::scene::IParticleMeshEmitter* em = (irr::scene::IParticleMeshEmitter*)node->getEmitter();
		em->setNormalDirectionModifier(rc_actor[actor].particle_properties.normalDirectionModifier);
	}
}

double rc_getParticleNormalDirectionMod(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return 0;

	if(rc_actor[actor].particle_properties.particle_type != RC_PARTICLE_TYPE_MESH)
		return 0;

	return rc_actor[actor].particle_properties.normalDirectionModifier;
}

void rc_useParticleNormalDirection(int actor, bool flag)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	if(rc_actor[actor].particle_properties.particle_type != RC_PARTICLE_TYPE_MESH)
		return;

	rc_actor[actor].particle_properties.useNormalDirection = flag;

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*)rc_actor[actor].mesh_node;

	if(node->getEmitter())
	{
		irr::scene::IParticleMeshEmitter* em = (irr::scene::IParticleMeshEmitter*)node->getEmitter();
		em->setUseNormalDirection(rc_actor[actor].particle_properties.useNormalDirection);
	}
}

bool rc_particleIsUsingNormalDirection(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return false;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return false;

	if(rc_actor[actor].particle_properties.particle_type != RC_PARTICLE_TYPE_MESH)
		return false;

	return rc_actor[actor].particle_properties.useNormalDirection;
}

void rc_setParticleMesh(int actor, int mesh)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	if(rc_actor[actor].particle_properties.particle_type != RC_PARTICLE_TYPE_MESH)
		return;

	rc_actor[actor].particle_properties.mesh_id = mesh;

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*)rc_actor[actor].mesh_node;

	if(node->getEmitter())
	{
		if(mesh < 0 || mesh >= rc_mesh.size())
			return;

		if(!rc_mesh[mesh].mesh)
			return;

		irr::scene::IParticleMeshEmitter* em = (irr::scene::IParticleMeshEmitter*)node->getEmitter();
		em->setMesh(rc_mesh[mesh].mesh);
	}
}

void rc_setMinParticlesPerSecond(int actor, Uint32 minParticlesPerSecond)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	rc_actor[actor].particle_properties.minParticlesPerSecond = minParticlesPerSecond;

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*)rc_actor[actor].mesh_node;

	if(node->getEmitter())
		node->getEmitter()->setMinParticlesPerSecond(minParticlesPerSecond);
}

Uint32 rc_getMinParticlesPerSecond(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return 0;

	return rc_actor[actor].particle_properties.minParticlesPerSecond;
}

void rc_setMaxParticlesPerSecond(int actor, Uint32 maxParticlesPerSecond)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	rc_actor[actor].particle_properties.maxParticlesPerSecond = maxParticlesPerSecond;

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*)rc_actor[actor].mesh_node;

	if(node->getEmitter())
		node->getEmitter()->setMaxParticlesPerSecond(maxParticlesPerSecond);
}

Uint32 rc_getMaxParticlesPerSecond(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return 0;

	return rc_actor[actor].particle_properties.maxParticlesPerSecond;
}

void rc_setParticleMinStartColor(int actor, Uint32 color)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	rc_actor[actor].particle_properties.minStartColor = irr::video::SColor(color);

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*)rc_actor[actor].mesh_node;

	if(node->getEmitter())
		node->getEmitter()->setMinStartColor(rc_actor[actor].particle_properties.minStartColor);
}

Uint32 rc_getParticleMinStartColor(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return 0;

	return rc_actor[actor].particle_properties.minStartColor.color;
}

void rc_setParticleMaxStartColor(int actor, Uint32 color)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	rc_actor[actor].particle_properties.maxStartColor = irr::video::SColor(color);

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*)rc_actor[actor].mesh_node;

	if(node->getEmitter())
		node->getEmitter()->setMaxStartColor(rc_actor[actor].particle_properties.maxStartColor);
}

Uint32 rc_getParticleMaxStartColor(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return 0;

	return rc_actor[actor].particle_properties.maxStartColor.color;
}

void rc_setParticleMinLife(int actor, Uint32 minLife)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	rc_actor[actor].particle_properties.lifeTimeMin = minLife;

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*)rc_actor[actor].mesh_node;

	if(node->getEmitter())
		node->getEmitter()->setMinLifeTime(rc_actor[actor].particle_properties.lifeTimeMin);
}

Uint32 rc_getParticleMinLife(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return 0;

	return rc_actor[actor].particle_properties.lifeTimeMin;
}

void rc_setParticleMaxLife(int actor, Uint32 maxLife)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	rc_actor[actor].particle_properties.lifeTimeMax = maxLife;

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*)rc_actor[actor].mesh_node;

	if(node->getEmitter())
		node->getEmitter()->setMaxLifeTime(rc_actor[actor].particle_properties.lifeTimeMax);
}

Uint32 rc_getParticleMaxLife(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return 0;

	return rc_actor[actor].particle_properties.lifeTimeMax;
}

void rc_setParticleMaxAngle(int actor, int maxAngle)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	rc_actor[actor].particle_properties.maxAngleDegrees = maxAngle;

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*)rc_actor[actor].mesh_node;

	if(node->getEmitter())
		node->getEmitter()->setMaxAngleDegrees(rc_actor[actor].particle_properties.maxAngleDegrees);
}

int rc_getParticleMaxAngle(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return 0;

	return rc_actor[actor].particle_properties.maxAngleDegrees;
}

void rc_setParticleMinStartSize(int actor, double w, double h)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	rc_actor[actor].particle_properties.minStartSize = irr::core::dimension2df(w, h);

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*)rc_actor[actor].mesh_node;

	if(node->getEmitter())
		node->getEmitter()->setMinStartSize(rc_actor[actor].particle_properties.minStartSize);
}

void rc_getParticleMinStartSize(int actor, double* w, double* h)
{
	*w = 0;
	*h = 0;

	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	*w = rc_actor[actor].particle_properties.minStartSize.Width;
	*h = rc_actor[actor].particle_properties.minStartSize.Height;
}

void rc_setParticleMaxStartSize(int actor, double w, double h)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	rc_actor[actor].particle_properties.maxStartSize = irr::core::dimension2df(w, h);

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*)rc_actor[actor].mesh_node;

	if(node->getEmitter())
		node->getEmitter()->setMaxStartSize(rc_actor[actor].particle_properties.maxStartSize);
}

void rc_getParticleMaxStartSize(int actor, double* w, double* h)
{
	*w = 0;
	*h = 0;

	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	*w = rc_actor[actor].particle_properties.maxStartSize.Width;
	*h = rc_actor[actor].particle_properties.maxStartSize.Height;
}

void rc_setParticleCenter(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	rc_actor[actor].particle_properties.center = irr::core::vector3df(x, y, z);

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*)rc_actor[actor].mesh_node;

	if(!node->getEmitter())
		return;


	switch(rc_actor[actor].particle_properties.particle_type)
	{
		case RC_PARTICLE_TYPE_SPHERE:
		{
			irr::scene::IParticleSphereEmitter* em = (irr::scene::IParticleSphereEmitter*)node->getEmitter();
			em->setCenter(rc_actor[actor].particle_properties.center);
		}
		break;
		case RC_PARTICLE_TYPE_CYLINDER:
		{
			irr::scene::IParticleCylinderEmitter* em = (irr::scene::IParticleCylinderEmitter*)node->getEmitter();
			em->setCenter(rc_actor[actor].particle_properties.center);
		}
		break;
		case RC_PARTICLE_TYPE_RING:
			{
			irr::scene::IParticleRingEmitter* em = (irr::scene::IParticleRingEmitter*)node->getEmitter();
			em->setCenter(rc_actor[actor].particle_properties.center);
		}
		break;
	}
}

void rc_getParticleCenter(int actor, double* x, double* y, double* z)
{
	*x = 0;
	*y = 0;
	*z = 0;

	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	*x = rc_actor[actor].particle_properties.center.X;
	*y = rc_actor[actor].particle_properties.center.Y;
	*z = rc_actor[actor].particle_properties.center.Z;
}

void rc_setParticleRadius(int actor, double radius)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	rc_actor[actor].particle_properties.radius = radius;

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*)rc_actor[actor].mesh_node;

	if(!node->getEmitter())
		return;


	switch(rc_actor[actor].particle_properties.particle_type)
	{
		case RC_PARTICLE_TYPE_SPHERE:
		{
			irr::scene::IParticleSphereEmitter* em = (irr::scene::IParticleSphereEmitter*)node->getEmitter();
			em->setRadius(rc_actor[actor].particle_properties.radius);
		}
		break;
		case RC_PARTICLE_TYPE_CYLINDER:
		{
			irr::scene::IParticleCylinderEmitter* em = (irr::scene::IParticleCylinderEmitter*)node->getEmitter();
			em->setRadius(rc_actor[actor].particle_properties.radius);
		}
		break;
		case RC_PARTICLE_TYPE_RING:
			{
			irr::scene::IParticleRingEmitter* em = (irr::scene::IParticleRingEmitter*)node->getEmitter();
			em->setRadius(rc_actor[actor].particle_properties.radius);
		}
		break;
	}
}

double rc_getParticleRadius(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return 0;

	return rc_actor[actor].particle_properties.radius;
}

void rc_setParticleRingThickness(int actor, double ringThickness)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	rc_actor[actor].particle_properties.ringThickness = ringThickness;

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*)rc_actor[actor].mesh_node;

	if(!node->getEmitter())
		return;


	switch(rc_actor[actor].particle_properties.particle_type)
	{
		case RC_PARTICLE_TYPE_RING:
		{
			irr::scene::IParticleRingEmitter* em = (irr::scene::IParticleRingEmitter*)node->getEmitter();
			em->setRingThickness(rc_actor[actor].particle_properties.ringThickness);
		}
		break;
	}
}

double rc_getParticleRingThickness(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return 0;

	return rc_actor[actor].particle_properties.ringThickness;
}

void rc_setParticleBox(int actor, double min_x, double min_y, double min_z, double max_x, double max_y, double max_z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	rc_actor[actor].particle_properties.box = irr::core::aabbox3df(min_x, min_y, min_z, max_x, max_y, max_z);

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*)rc_actor[actor].mesh_node;

	if(!node->getEmitter())
		return;


	switch(rc_actor[actor].particle_properties.particle_type)
	{
		case RC_PARTICLE_TYPE_BOX:
		{
			irr::scene::IParticleBoxEmitter* em = (irr::scene::IParticleBoxEmitter*)node->getEmitter();
			em->setBox(rc_actor[actor].particle_properties.box);
		}
		break;
	}
}

void rc_getParticleBox(int actor, double* min_x, double* min_y, double* min_z, double* max_x, double* max_y, double* max_z)
{
	*min_x = 0;
	*min_y = 0;
	*min_z = 0;

	*max_x = 0;
	*max_y = 0;
	*max_z = 0;

	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	*min_x = rc_actor[actor].particle_properties.box.MinEdge.X;
	*min_y = rc_actor[actor].particle_properties.box.MinEdge.Y;
	*min_z = rc_actor[actor].particle_properties.box.MinEdge.Z;

	*max_x = rc_actor[actor].particle_properties.box.MaxEdge.X;
	*max_y = rc_actor[actor].particle_properties.box.MaxEdge.Y;
	*max_z = rc_actor[actor].particle_properties.box.MaxEdge.Z;
}

void rc_setParticleNormal(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	rc_actor[actor].particle_properties.normal.set(x, y, z);

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*)rc_actor[actor].mesh_node;

	if(!node->getEmitter())
		return;


	switch(rc_actor[actor].particle_properties.particle_type)
	{
		case RC_PARTICLE_TYPE_CYLINDER:
		{
			irr::scene::IParticleCylinderEmitter* em = (irr::scene::IParticleCylinderEmitter*)node->getEmitter();
			em->setNormal(rc_actor[actor].particle_properties.normal);
		}
		break;
	}
}

void rc_getParticleNormal(int actor, double* x, double* y, double* z)
{
	*x = 0;
	*y = 0;
	*z = 0;

	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	*x = rc_actor[actor].particle_properties.normal.X;
	*y = rc_actor[actor].particle_properties.normal.Y;
	*z = rc_actor[actor].particle_properties.normal.Z;
}

void rc_setParticleLength(int actor, double length)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	rc_actor[actor].particle_properties.length = length;

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*)rc_actor[actor].mesh_node;

	if(!node->getEmitter())
		return;


	switch(rc_actor[actor].particle_properties.particle_type)
	{
		case RC_PARTICLE_TYPE_CYLINDER:
		{
			irr::scene::IParticleCylinderEmitter* em = (irr::scene::IParticleCylinderEmitter*)node->getEmitter();
			em->setLength(rc_actor[actor].particle_properties.length);
		}
		break;
	}
}

double rc_getParticleLength(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return 0;

	return rc_actor[actor].particle_properties.length;
}

void rc_useParticleOutlineOnly(int actor, bool flag)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return;

	rc_actor[actor].particle_properties.outlineOnly = flag;

	irr::scene::IParticleSystemSceneNode* node = (irr::scene::IParticleSystemSceneNode*)rc_actor[actor].mesh_node;

	if(!node->getEmitter())
		return;


	switch(rc_actor[actor].particle_properties.particle_type)
	{
		case RC_PARTICLE_TYPE_CYLINDER:
		{
			irr::scene::IParticleCylinderEmitter* em = (irr::scene::IParticleCylinderEmitter*)node->getEmitter();
			em->setOutlineOnly(flag);
		}
		break;
	}
}

bool rc_particleIsUsingOutlineOnly(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return false;

	if(rc_actor[actor].node_type != RC_NODE_TYPE_PARTICLE)
		return false;

	return rc_actor[actor].particle_properties.outlineOnly;
}



void rc_setCameraPosition(double x, double y, double z)
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

    rc_canvas[rc_active_canvas].camera.setPosition(x, y, z);
}

void rc_getCameraPosition(double* x, double* y, double* z)
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

    irr::f32 fx, fy, fz;

    rc_canvas[rc_active_canvas].camera.getPosition(fx, fy, fz);

    *x = fx;
    *y = fy;
    *z = fz;
}

void rc_translateCamera(double x, double y, double z)
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

    rc_canvas[rc_active_canvas].camera.translate(x, y, z);
}

void rc_translateCameraW(double x, double y, double z)
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

    rc_canvas[rc_active_canvas].camera.translateW(x, y, z);
}


void rc_setCameraRotation(double x, double y, double z)
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

    rc_canvas[rc_active_canvas].camera.setRotation(x, y, z);
}

void rc_getCameraRotation(double* x, double* y, double* z)
{
    if(rc_active_canvas <= 0 || rc_active_canvas >= rc_canvas.size())
        return;

    *x = rc_canvas[rc_active_canvas].camera.rx;
    *y = rc_canvas[rc_active_canvas].camera.ry;
    *z = rc_canvas[rc_active_canvas].camera.rz;

    //std::cout << "Get Rotation: " << x[0] << ", " << y[0] << ", " << z[0] << std::endl;
}

void rc_rotateCamera(double x, double y, double z)
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

    rc_canvas[rc_active_canvas].camera.rotate(x, y, z);
}

void rc_setCameraFOV(double fov)
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

    rc_canvas[rc_active_canvas].camera.camera->setFOV(fov);
}

double rc_getCameraFOV()
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return 0;

    return rc_canvas[rc_active_canvas].camera.camera->getFOV();
}

void rc_setCameraAspectRatio(double aspect)
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

    rc_canvas[rc_active_canvas].camera.camera->setAspectRatio(aspect);
}

double rc_getCameraAspectRatio()
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return 0;

    return rc_canvas[rc_active_canvas].camera.camera->getAspectRatio();
}

void rc_setCameraFarValue(double zf)
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

    rc_canvas[rc_active_canvas].camera.camera->setFarValue(zf);
}

double rc_getCameraFarValue()
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return 0;

    return rc_canvas[rc_active_canvas].camera.camera->getFarValue();
}

void rc_setCameraNearValue(double zn)
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

    rc_canvas[rc_active_canvas].camera.camera->setNearValue(zn);
}

double rc_getCameraNearValue()
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return 0;

    return rc_canvas[rc_active_canvas].camera.camera->getNearValue();
}


void rc_addSceneSkyBox(int img_top, int img_bottom, int img_left, int img_right, int img_front, int img_back)
{
	if(!SceneManager)
		return;

	if(rc_scene_properties.sky)
		return;

	irr::video::ITexture* tp = rc_image[img_top].image;
	irr::video::ITexture* bt = rc_image[img_bottom].image;
	irr::video::ITexture* lf = rc_image[img_left].image;
	irr::video::ITexture* rt = rc_image[img_right].image;
	irr::video::ITexture* ft = rc_image[img_front].image;
	irr::video::ITexture* bk = rc_image[img_back].image;
	rc_scene_properties.sky = SceneManager->addSkyBoxSceneNode(tp, bt, lf, rt, ft, bk);
}

void rc_addSceneSkyDome(int img)
{
	if(!SceneManager)
		return;

	if(rc_scene_properties.sky)
		return;

	irr::video::ITexture* texture = rc_image[img].image;
	rc_scene_properties.sky = SceneManager->addSkyDomeSceneNode(texture);
}

void rc_addSceneSkyDomeEx(int img, Uint32 horiRes, Uint32 vertRes, double txPercentage, double spherePercentage, double radius)
{
	if(!SceneManager)
		return;

	if(rc_scene_properties.sky)
		return;

	irr::video::ITexture* texture = rc_image[img].image;
	rc_scene_properties.sky = SceneManager->addSkyDomeSceneNode(texture, horiRes, vertRes, txPercentage, spherePercentage, radius);
}

void rc_removeSceneSky()
{
	if(rc_scene_properties.sky)
		rc_scene_properties.sky->remove();

	rc_scene_properties.sky = NULL;
}



#endif // RC_GFX3D_H_INCLUDED
