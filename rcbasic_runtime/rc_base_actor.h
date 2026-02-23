#ifndef RC_BASE_ACTOR_H_INCLUDED
#define RC_BASE_ACTOR_H_INCLUDED

#include "ProjectiveTextures.h"
#include "rc_matrix.h"

void setSolidProperties(int actor)
{
    if(rc_actor[actor].node_type == RC_NODE_TYPE_VEHICLE)
    {
        int chassis_actor = rc_actor[actor].vehicle_properties.chassis_actor_id;

        if(chassis_actor >= 0 && chassis_actor < rc_actor.size())
        {
            if(rc_actor[chassis_actor].physics.rigid_body)
            {
                if(!rc_actor[chassis_actor].physics.isSolid)
                {
                    rc_actor[chassis_actor].physics.gravity = rc_actor[chassis_actor].physics.rigid_body->getGravity();
                    rc_actor[chassis_actor].physics.rigid_body->setGravity(irr::core::vector3df(0,0,0));
                    rc_actor[chassis_actor].physics.rigid_body->setCollisionFlags( ECollisionFlag::ECF_NO_CONTACT_RESPONSE );
                }
            }
        }

        for(int i = 0; i < rc_actor[actor].vehicle_properties.wheels.size(); i++)
        {
            int wheel_actor = rc_actor[actor].vehicle_properties.wheels[i].actor_id;

            if(wheel_actor < 0 || wheel_actor >= rc_actor.size())
                continue;

            if(!rc_actor[wheel_actor].physics.rigid_body)
                continue;

            if(!rc_actor[wheel_actor].physics.isSolid)
            {
                rc_actor[wheel_actor].physics.gravity = rc_actor[wheel_actor].physics.rigid_body->getGravity();
                rc_actor[wheel_actor].physics.rigid_body->setGravity(irr::core::vector3df(0,0,0));
                rc_actor[wheel_actor].physics.rigid_body->setCollisionFlags( ECollisionFlag::ECF_NO_CONTACT_RESPONSE );
            }
        }
    }
    else
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
}

void rc_setActorCollisionShape(int actor_id, int shape_type, double mass, double radius=-1.0)
{
    if(actor_id < 0 || actor_id >= rc_actor.size())
        return;

    if(rc_actor[actor_id].node_type == RC_NODE_TYPE_VEHICLE)
        return;

    if(rc_actor[actor_id].node_type == RC_NODE_TYPE_COMPOSITE && shape_type != RC_NODE_SHAPE_TYPE_COMPOSITE)
        return;

    if(shape_type == RC_NODE_SHAPE_TYPE_IMPACT_MESH)
    {
        rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_IMPACT_MESH;

        if(rc_actor[actor_id].physics.impact_mesh_id < 0)
        {
            return;
        }
    }

	//std::cout << "Start ColShape" << std::endl;
	if(rc_actor[actor_id].physics.rigid_body)
	{
	    if(rc_actor[actor_id].physics.rigid_body->getCollisionShape()->getShapeType() == ECollisionShapeType::ECST_COMPOUND)
        {
            ICompoundShape* shape = (ICompoundShape*)rc_actor[actor_id].physics.rigid_body->getCollisionShape();

            //std::cout << "Child Actors: " << rc_actor[actor_id].child_actors.size() << std::endl;

            int num_shapes = shape->getNumChildShapes();
            for(int i = 0; i < num_shapes; i++)
            {
                ICollisionShape* child_shape = rc_actor[actor_id].child_actors[i].shape; //shape->getChildShape(0);
                shape->removeChildShape(child_shape);
            }

            irr::scene::ISceneNode* empty_node = SceneManager->addEmptySceneNode();
            IBoxShape* new_child_shape = new IBoxShape(empty_node, 0, false);
            rc_actor[actor_id].physics.rigid_body->setCollisionShape(new_child_shape);

            rc_physics3D.world->removeCollisionObject(rc_actor[actor_id].physics.rigid_body, false);
            delete rc_actor[actor_id].physics.rigid_body;

            empty_node->remove();
        }
        else
		{
		    rc_physics3D.world->removeCollisionObject(rc_actor[actor_id].physics.rigid_body, false);
            delete rc_actor[actor_id].physics.rigid_body;
		}
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
				ISphereShape* shape = new ISphereShape(rc_actor[actor_id].mesh_node, mass, false, radius);

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
					shape = new ICapsuleShape(node, mass, false, radius);
				}
				else if(rc_actor[actor_id].node_type == RC_NODE_TYPE_STMESH)
				{
					irr::scene::IMeshSceneNode* node = (irr::scene::IMeshSceneNode*)rc_actor[actor_id].mesh_node;
					shape = new ICapsuleShape(node, mass, false, radius);
				}
				else if(rc_actor[actor_id].node_type == RC_NODE_TYPE_OTMESH)
				{
					irr::scene::IOctreeSceneNode* node = (irr::scene::IOctreeSceneNode*)rc_actor[actor_id].mesh_node;
					shape = new ICapsuleShape(node, mass, false, radius);
				}
				else if(rc_actor[actor_id].node_type == RC_NODE_TYPE_TERRAIN)
				{
					irr::scene::ITerrainSceneNode* node = (irr::scene::ITerrainSceneNode*)rc_actor[actor_id].mesh_node;
					shape = new ICapsuleShape(node, mass, false, radius);
				}
				else
                {
                    shape = new ICapsuleShape(rc_actor[actor_id].mesh_node, mass, false, radius);
                }

				rc_actor[actor_id].physics.rigid_body = rc_physics3D.world->addRigidBody(shape);

				setSolidProperties(actor_id);
			}
			break;

		case RC_NODE_SHAPE_TYPE_CONE:
			{
				rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_CONE;
				IConeShape* shape = new IConeShape(rc_actor[actor_id].mesh_node, mass, false, radius);

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
				else if(rc_actor[actor_id].node_type == RC_NODE_TYPE_STMESH)
                {
					irr::scene::IMeshSceneNode* node = (irr::scene::IMeshSceneNode*)rc_actor[actor_id].mesh_node;
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
				else if(rc_actor[actor_id].node_type == RC_NODE_TYPE_STMESH)
				{
					irr::scene::IMeshSceneNode* node = (irr::scene::IMeshSceneNode*)rc_actor[actor_id].mesh_node;
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

        case RC_NODE_SHAPE_TYPE_COMPOSITE:
			if(rc_actor[actor_id].node_type == RC_NODE_TYPE_COMPOSITE)
			{
				rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_COMPOSITE;

				ICompoundShape* shape = new ICompoundShape(rc_actor[actor_id].mesh_node, mass, false);

				for(int i = 0; i < rc_actor[actor_id].child_actors.size(); i++)
                {
                    int child_id = rc_actor[actor_id].child_actors[i].id;

                    if(child_id < 0 || child_id >= rc_actor.size())
                        continue;

                    if(!rc_actor[actor_id].child_actors[i].shape)
                        continue;

                    shape->addChildShape(rc_actor[actor_id].child_actors[i].child_transform, rc_actor[actor_id].child_actors[i].shape);
                }

                rc_actor[actor_id].physics.rigid_body = rc_physics3D.world->addRigidBody(shape);

				setSolidProperties(actor_id);
			}
			else
            {
                std::cout << "SetActorShape Error: Composite Shapes can only be set on Composite Actors" << std::endl;
            }
			break;

        case RC_NODE_SHAPE_TYPE_IMPACT_MESH:
			{
				rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_IMPACT_MESH;
				int mesh_id = rc_actor[actor_id].physics.impact_mesh_id;
				irr::scene::IMesh* mesh = rc_mesh[mesh_id].mesh;
				IGImpactMeshShape* shape = new IGImpactMeshShape(rc_actor[actor_id].mesh_node, mesh, mass);

				rc_actor[actor_id].physics.rigid_body = rc_physics3D.world->addRigidBody(shape);

				setSolidProperties(actor_id);
			}
			break;

		default:
			std::cout << "SetActorShape Error: Invalid shape_type parameter" << std::endl;
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

	if(rc_actor[actor].node_type == RC_NODE_TYPE_VEHICLE)
    {
        int chassis_id = rc_actor[actor].vehicle_properties.chassis_actor_id;

        if(chassis_id >= 0 && chassis_id < rc_actor.size())
        {
            if(rc_actor[chassis_id].physics.rigid_body)
            {
                rc_actor[chassis_id].physics.rigid_body->getPointer()->forceActivationState(state);
            }
        }

        for(int i = 0; i < rc_actor[actor].vehicle_properties.wheels.size(); i++)
        {
            int wheel_id = rc_actor[actor].vehicle_properties.wheels[i].actor_id;

            if(wheel_id < 0 || wheel_id >= rc_actor.size())
                continue;

            if(rc_actor[wheel_id].physics.rigid_body)
            {
                rc_actor[wheel_id].physics.rigid_body->getPointer()->forceActivationState(state);
            }
        }
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
	    if(rc_actor[actor_id].node_type == RC_NODE_TYPE_VEHICLE)
        {
            int chassis_id = rc_actor[actor_id].vehicle_properties.chassis_actor_id;

            if(chassis_id >= 0 && chassis_id < rc_actor.size())
            {
                if(rc_actor[chassis_id].physics.rigid_body)
                {
                    rc_actor[chassis_id].physics.isSolid = flag;
                    rc_setActorCollisionShape(chassis_id, rc_actor[chassis_id].physics.shape_type, rc_actor[chassis_id].physics.mass);
                }
            }

            for(int i = 0; i < rc_actor[actor_id].vehicle_properties.wheels.size(); i++)
            {
                int wheel_id = rc_actor[actor_id].vehicle_properties.wheels[i].actor_id;

                if(wheel_id < 0 || wheel_id >= rc_actor.size())
                    continue;

                if(rc_actor[wheel_id].physics.rigid_body)
                {
                    //rc_actor[wheel_id].physics.isSolid = flag;
                    //rc_setActorCollisionShape(wheel_id, rc_actor[wheel_id].physics.shape_type, rc_actor[wheel_id].physics.mass);
                }
            }
        }
		else
		{
		    rc_actor[actor_id].physics.isSolid = flag;
            rc_setActorCollisionShape(actor_id, rc_actor[actor_id].physics.shape_type, rc_actor[actor_id].physics.mass);
		}
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
    if(actor1 < 0 || actor1 >= rc_actor.size())
        return false;

    if(actor2 < 0 || actor2 >= rc_actor.size())
        return false;

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

	if(rc_actor[actor1].node_type == RC_NODE_TYPE_VEHICLE)
    {
        if(rc_actor[actor2].node_type == RC_NODE_TYPE_VEHICLE)
        {
            int chassis_id1 = rc_actor[actor1].vehicle_properties.chassis_actor_id;
            int chassis_id2 = rc_actor[actor2].vehicle_properties.chassis_actor_id;

            if(rc_getActorCollision(chassis_id1, chassis_id2))
                return true;

            for(int i1 = 0; i1 < rc_actor[actor1].vehicle_properties.wheels.size(); i1++)
            {
                int wheel_id1 = rc_actor[actor1].vehicle_properties.wheels[i1].actor_id;

                if(rc_getActorCollision(wheel_id1, chassis_id2))
                    return true;

                for(int i2 = 0; i2 < rc_actor[actor2].vehicle_properties.wheels.size(); i2++)
                {
                    int wheel_id2 = rc_actor[actor2].vehicle_properties.wheels[i2].actor_id;

                    if(i1 == 0)
                    {
                        if(rc_getActorCollision(wheel_id2, chassis_id1))
                            return true;
                    }

                    if(rc_getActorCollision(wheel_id2, wheel_id1))
                        return true;
                }
            }
        }
        else
        {
            int chassis_id = rc_actor[actor1].vehicle_properties.chassis_actor_id;

            if(rc_getActorCollision(chassis_id, actor2))
                return true;

            for(int i = 0; i < rc_actor[actor1].vehicle_properties.wheels.size(); i++)
            {
                int wheel_id = rc_actor[actor1].vehicle_properties.wheels[i].actor_id;

                if(rc_getActorCollision(wheel_id, actor2))
                    return true;
            }
        }
    }

    return false;
}

int rc_getActorType(int actor_id)
{
    if(actor_id < 0 || actor_id >= rc_actor.size())
        return -1;

    if(!rc_actor[actor_id].mesh_node)
        return -1;

    return rc_actor[actor_id].node_type;
}

void rc_setActorImpactMesh(int actor_id, int mesh_id, double mass)
{
    if(actor_id < 0 || actor_id >= rc_actor.size())
        return;

    if(!rc_actor[actor_id].mesh_node)
        return;

    if(mesh_id < 0 || mesh_id >= rc_mesh.size())
        return;

    rc_actor[actor_id].physics.impact_mesh_id = mesh_id;
    rc_actor[actor_id].physics.mass = mass;

    if(rc_actor[actor_id].physics.shape_type == RC_NODE_SHAPE_TYPE_IMPACT_MESH)
        rc_setActorCollisionShape(actor_id, RC_NODE_SHAPE_TYPE_IMPACT_MESH, rc_actor[actor_id].physics.mass);
}


//add mesh actor to scene
int rc_createAnimatedActor(int mesh_id)
{
    if(mesh_id < 0 || mesh_id >= rc_mesh.size())
        return -1;

    irr::scene::IMesh* mesh = rc_mesh[mesh_id].mesh;

    if(!mesh)
        return -1;

    int actor_id = -1;

    irr::scene::ISceneNode* node;

    rc_scene_node actor;

    if(rc_mesh[mesh_id].mesh_type == RC_MESH_TYPE_ANIMATED)
	{
		actor.node_type = RC_NODE_TYPE_MESH;
		node = SceneManager->addAnimatedMeshSceneNode((irr::scene::IAnimatedMesh*)mesh);
	}
	else
	{
		actor.node_type = RC_NODE_TYPE_STMESH; //STATIC MESH NODE
		node = SceneManager->addMeshSceneNode(mesh);
	}

    actor.mesh_node = node;

    #if defined(__ANDROID__)
        actor.mesh_node->setMaterialFlag(irr::video::EMF_USE_MIP_MAPS, false);
    #endif // defined

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

    //animation
    rc_actor_animation_obj animation;
    animation.start_frame = 0;
    animation.end_frame = 0;
    animation.fps = 60.0;
    animation.frame_start_time = SDL_GetTicks();
    animation.frame_swap_time = 1000/60;
    rc_actor[actor_id].animation.push_back(animation);

    if(rc_mesh[mesh_id].mesh_type == RC_MESH_TYPE_ANIMATED)
    {
    	rc_actor[actor_id].current_animation = 0;
		rc_actor[actor_id].current_animation_loop = 0;
		rc_actor[actor_id].num_animation_loops = 0;
		rc_animEndCallBack* anim_callback = new rc_animEndCallBack();
		anim_callback->ref_id = actor_id;
		anim_callback->OnAnimationEnd((irr::scene::IAnimatedMeshSceneNode*)node);
		((irr::scene::IAnimatedMeshSceneNode*)node)->setAnimationEndCallback(anim_callback);
		((irr::scene::IAnimatedMeshSceneNode*)node)->setLoopMode(false);
		((irr::scene::IAnimatedMeshSceneNode*)node)->setFrameLoop(0, 0);
		anim_callback->drop();
    }


    //Actor RigidBody
    rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_BOX;
    rc_actor[actor_id].physics.rigid_body = NULL;
    rc_actor[actor_id].physics.isSolid = false;
    rc_actor[actor_id].physics.impact_mesh_id = -1;

    rc_actor[actor_id].parent_id = -1;
    rc_actor[actor_id].isWheel = false;

    rc_setActorCollisionShape(actor_id, RC_NODE_SHAPE_TYPE_BOX, 1);

    return actor_id;
}


//add mesh actor to scene
int rc_createCompositeActor()
{
    int actor_id = -1;

    irr::scene::ISceneNode* node;

    rc_scene_node actor;

    actor.node_type = RC_NODE_TYPE_COMPOSITE; //STATIC MESH NODE

    node = SceneManager->addEmptySceneNode();

    actor.mesh_node = node;

    actor.shadow = NULL;
    actor.transition = false;
    actor.transition_time = 0;
    actor.material_ref_index = -1;

    if(!node)
    {
        //std::cout << "Composite DBG: NO NODE" << std::endl;
        return -1;
    }

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
    rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_COMPOSITE;
    rc_actor[actor_id].physics.rigid_body = NULL;
    rc_actor[actor_id].physics.isSolid = false;
    rc_actor[actor_id].physics.impact_mesh_id = -1;

    rc_actor[actor_id].parent_id = -1;
    rc_actor[actor_id].isWheel = false;

    rc_setActorCollisionShape(actor_id, RC_NODE_SHAPE_TYPE_COMPOSITE, 1);

    return actor_id;
}


int rc_createVehicleActor(int chassis_actor)
{
    int actor_id = -1;

    if(chassis_actor < 0 || chassis_actor >= rc_actor.size())
        return -1;

    if(!rc_actor[chassis_actor].mesh_node)
        return -1;

    irr::scene::ISceneNode* node;

    rc_scene_node actor;

    actor.node_type = RC_NODE_TYPE_VEHICLE;

    node = rc_actor[chassis_actor].mesh_node;

    actor.mesh_node = node;

    actor.shadow = NULL;
    actor.transition = false;
    actor.transition_time = 0;
    actor.material_ref_index = -1;

    if(!node)
    {
        //std::cout << "Composite DBG: NO NODE" << std::endl;
        return -1;
    }

    if(!rc_actor[chassis_actor].physics.rigid_body)
        return -1;

    //Create RayCast Vehicle
    actor.vehicle_properties.vehicle = rc_physics3D.world->addRaycastVehicle(rc_actor[chassis_actor].physics.rigid_body);
    actor.vehicle_properties.vehicle->getVehicleRaycaster()->setUseFilter(false);

    actor.vehicle_properties.chassis_actor_id = chassis_actor;

    irr::core::matrix4 t_mat = actor.vehicle_properties.vehicle->getChassisWorldTransform();
    rc_actor[chassis_actor].mesh_node->setPosition(t_mat.getTranslation());
    rc_actor[chassis_actor].mesh_node->setRotation(t_mat.getRotationDegrees());
    rc_actor[chassis_actor].mesh_node->setScale(t_mat.getScale());
    rc_actor[chassis_actor].mesh_node->updateAbsolutePosition();


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
    rc_actor[actor_id].physics = rc_actor[chassis_actor].physics;

    rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_NONE;
    rc_actor[actor_id].physics.collisions.clear();

    rc_actor[actor_id].parent_id = -1;
    rc_actor[actor_id].isWheel = false;

    rc_vehicle_actors.push_back(actor_id);

    //setSolidProperties(actor_id);

    return actor_id;
}


//add mesh actor to scene
int rc_createOctreeActor(int mesh_id)
{
    if(mesh_id < 0 || mesh_id >= rc_mesh.size())
        return -1;

    irr::scene::IMesh* mesh = rc_mesh[mesh_id].mesh;

    if(!mesh)
        return -1;

    int actor_id = -1;
    //irr::scene::IAnimatedMeshSceneNode* node = SceneManager->addAnimatedMeshSceneNode(mesh);
    irr::scene::IOctreeSceneNode *node = SceneManager->addOctreeSceneNode(mesh);
    rc_scene_node actor;
    actor.node_type = RC_NODE_TYPE_OTMESH;
    actor.mesh_node = node;

    #if defined(__ANDROID__)
        actor.mesh_node->setMaterialFlag(irr::video::EMF_USE_MIP_MAPS, false);
    #endif // defined

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
    rc_actor[actor_id].physics.impact_mesh_id = -1;

    rc_actor[actor_id].parent_id = -1;
    rc_actor[actor_id].isWheel = false;

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

    #if defined(__ANDROID__)
        actor.mesh_node->setMaterialFlag(irr::video::EMF_USE_MIP_MAPS, false);
    #endif // defined

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
    rc_actor[actor_id].physics.impact_mesh_id = -1;

    rc_actor[actor_id].parent_id = -1;
    rc_actor[actor_id].isWheel = false;

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

    #if defined(__ANDROID__)
        actor.mesh_node->setMaterialFlag(irr::video::EMF_USE_MIP_MAPS, false);
    #endif // defined

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
    rc_actor[actor_id].physics.impact_mesh_id = -1;

    rc_actor[actor_id].parent_id = -1;
    rc_actor[actor_id].isWheel = false;

    rc_setActorCollisionShape(actor_id, RC_NODE_SHAPE_TYPE_BOX, 0);


    return actor_id;
}

//add mesh actor to scene
int rc_createCubeActor(double cube_size)
{
    int actor_id = -1;
    irr::scene::IMeshSceneNode* node = SceneManager->addCubeSceneNode(cube_size);
    rc_scene_node actor;
    actor.node_type = RC_NODE_TYPE_STMESH;
    actor.mesh_node = node;

    #if defined(__ANDROID__)
        actor.mesh_node->setMaterialFlag(irr::video::EMF_USE_MIP_MAPS, false);
    #endif // defined

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
    rc_actor[actor_id].physics.impact_mesh_id = -1;

    rc_actor[actor_id].parent_id = -1;
    rc_actor[actor_id].isWheel = false;

    rc_setActorCollisionShape(actor_id, RC_NODE_SHAPE_TYPE_BOX, 1);

    return actor_id;
}

//add mesh actor to scene
int rc_createSphereActor(double radius)
{
    int actor_id = -1;
    irr::scene::IMeshSceneNode* node = SceneManager->addSphereSceneNode(radius);
    rc_scene_node actor;
    actor.node_type = RC_NODE_TYPE_STMESH;
    actor.mesh_node = node;

    #if defined(__ANDROID__)
        actor.mesh_node->setMaterialFlag(irr::video::EMF_USE_MIP_MAPS, false);
    #endif // defined

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
    rc_actor[actor_id].physics.impact_mesh_id = -1;

    rc_actor[actor_id].parent_id = -1;
    rc_actor[actor_id].isWheel = false;

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

    #if defined(__ANDROID__)
        actor.mesh_node->setMaterialFlag(irr::video::EMF_USE_MIP_MAPS, false);
    #endif // defined

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
    rc_actor[actor_id].physics.impact_mesh_id = -1;

    rc_actor[actor_id].parent_id = -1;
    rc_actor[actor_id].isWheel = false;

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

    #if defined(__ANDROID__)
        actor.mesh_node->setMaterialFlag(irr::video::EMF_USE_MIP_MAPS, false);
    #endif // defined

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
    rc_actor[actor_id].physics.impact_mesh_id = -1;

    rc_actor[actor_id].parent_id = -1;
    rc_actor[actor_id].isWheel = false;

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

    #if defined(__ANDROID__)
        actor.mesh_node->setMaterialFlag(irr::video::EMF_USE_MIP_MAPS, false);
    #endif // defined

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
    rc_actor[actor_id].physics.impact_mesh_id = -1;

    rc_actor[actor_id].parent_id = -1;
    rc_actor[actor_id].isWheel = false;

    rc_setActorCollisionShape(actor_id, RC_NODE_SHAPE_TYPE_BOX, 1);

    return actor_id;
}

int rc_createProjectorActor()
{
	int actor_id = -1;
	CProjectiveTextures* node = new CProjectiveTextures(device, 0, SceneManager, -1);
    rc_scene_node actor;
    actor.node_type = RC_NODE_TYPE_PROJECTOR;
    actor.mesh_node = node;

    #if defined(__ANDROID__)
        actor.mesh_node->setMaterialFlag(irr::video::EMF_USE_MIP_MAPS, false);
    #endif // defined

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
    rc_actor[actor_id].physics.impact_mesh_id = -1;

    rc_actor[actor_id].parent_id = -1;
    rc_actor[actor_id].isWheel = false;

    rc_actor[actor_id].projector_properties.project_texture_id = -1;
    rc_actor[actor_id].projector_properties.effect_actors.clear();

    rc_setActorCollisionShape(actor_id, RC_NODE_SHAPE_TYPE_BOX, 1);

    rc_projector_actors.push_back(actor_id);

    return actor_id;
}


void removeProjectorParent(int projector_actor, int tgt_actor)
{
    if(projector_actor < 0 || projector_actor >= rc_actor.size())
        return;

    if(tgt_actor < 0 || tgt_actor >= rc_actor.size())
        return;

    for(int i = 0; i < rc_actor[tgt_actor].projector_parent.size(); i++)
    {
        if(rc_actor[tgt_actor].projector_parent[i] == projector_actor)
        {
            rc_actor[tgt_actor].projector_parent.erase(i);
            break;
        }
    }
}


//delete actor
void rc_deleteActor(int actor_id)
{
    if(actor_id < 0 || actor_id >= rc_actor.size())
        return;

    if(!rc_actor[actor_id].mesh_node)
        return;

    // This is to prevent deleting wheels attached to vehicles
    if(rc_actor[actor_id].isWheel && rc_actor[actor_id].parent_id >= 0)
        return;

    if(rc_actor[actor_id].node_type == RC_NODE_TYPE_PROJECTOR)
    {
        for(int i = 0; i < rc_projector_actors.size(); i++)
        {
            if(rc_projector_actors[i] == actor_id)
            {
                rc_projector_actors.erase(i);
                break;
            }
        }

        for(int i = 0; i < rc_actor[actor_id].projector_properties.effect_actors.size(); i++)
        {
            int tgt_id = rc_actor[actor_id].projector_properties.effect_actors[i];
            removeProjectorParent(actor_id, tgt_id);
        }
    }

    //Remove actor from any projectors it may be added to
    for(int i = 0; i < rc_actor[actor_id].projector_parent.size(); i++)
    {
        int parent_id = rc_actor[actor_id].projector_parent[i];

        if(parent_id < 0 || parent_id >= rc_actor.size())
            continue;

        for(int e_index = 0; e_index < rc_actor[parent_id].projector_properties.effect_actors.size(); e_index++)
        {
            if(rc_actor[parent_id].projector_properties.effect_actors[e_index] == actor_id)
            {
                rc_actor[parent_id].projector_properties.effect_actors.erase(e_index);
                break;
            }
        }

        if(rc_actor[parent_id].mesh_node)
        {
            CProjectiveTextures* parent_node = (CProjectiveTextures*)rc_actor[parent_id].mesh_node;
            for(int node_index = 0; node_index < parent_node->nodeArray.size(); node_index++)
            {
                if(parent_node->nodeArray[node_index] == rc_actor[actor_id].mesh_node)
                {
                    parent_node->nodeArray.erase(node_index);
                    break;
                }
            }
        }
    }


    for(int i = 0; i < rc_actor[actor_id].child_actors.size(); i++)
    {
        int child_id = rc_actor[actor_id].child_actors[i].id;

        if(child_id < 0 || child_id >= rc_actor.size())
            continue;

        if(rc_actor[child_id].mesh_node == NULL)
            continue;

        rc_deleteActor(child_id);
    }

    rc_actor[actor_id].child_actors.clear();


	if(rc_actor[actor_id].physics.rigid_body && rc_actor[actor_id].node_type != RC_NODE_TYPE_VEHICLE)
    {
        rc_physics3D.world->removeCollisionObject(rc_actor[actor_id].physics.rigid_body, false);
        delete rc_actor[actor_id].physics.rigid_body;
    }

    if(rc_actor[actor_id].node_type == RC_NODE_TYPE_VEHICLE)
    {
        for(int i = 0; i < rc_actor[actor_id].vehicle_properties.wheels.size(); i++)
        {
            int wheel_actor = rc_actor[actor_id].vehicle_properties.wheels[i].actor_id;

            if(wheel_actor < 0 || wheel_actor >= rc_actor.size())
                continue;

            rc_actor[wheel_actor].parent_id = -1;

            rc_deleteActor(wheel_actor); //This should never happen but you can never be too careful with pointers
        }

        rc_deleteActor(rc_actor[actor_id].vehicle_properties.chassis_actor_id);

        if(rc_actor[actor_id].vehicle_properties.vehicle)
        {
            rc_physics3D.world->removeRaycastVehicle(rc_actor[actor_id].vehicle_properties.vehicle);
        }

        for(int i = 0; i < rc_vehicle_actors.size(); i++)
        {
            if(rc_vehicle_actors[i] == actor_id)
            {
                rc_vehicle_actors.erase(i);
                break;
            }
        }
    }

    rc_actor[actor_id].projector_parent.clear();
    rc_actor[actor_id].projector_properties.effect_actors.clear();
    rc_actor[actor_id].projector_properties.project_texture_id = -1;

	rc_actor[actor_id].physics.rigid_body = NULL;
	rc_actor[actor_id].vehicle_properties.vehicle = NULL;
	rc_actor[actor_id].vehicle_properties.wheels.clear();
	rc_actor[actor_id].physics.impact_mesh_id = -1;

	rc_actor[actor_id].physics.collisions.clear();

    // Vehicles use the same mesh_node as there chassis which is deleted above
    if(rc_actor[actor_id].node_type != RC_NODE_TYPE_VEHICLE)
        rc_actor[actor_id].mesh_node->remove();

    rc_actor[actor_id].mesh_node = NULL;
    rc_actor[actor_id].shadow = NULL;
    rc_actor[actor_id].node_type = 0;
    rc_actor[actor_id].transition = false;
    rc_actor[actor_id].transition_time = 0;
    rc_actor[actor_id].material_ref_index = -1;
    rc_actor[actor_id].parent_id = -1;
}







//-------------------Actor Transforms-------------------------------

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
		//rc_physics3D.world->removeCollisionObject(rc_actor[actor].physics.rigid_body, false);
		actor_transform.setTranslation( irr::core::vector3df(x, y, z) );
		rc_actor[actor].physics.rigid_body->clearForces();
		//rc_actor[actor].physics.rigid_body->
		rc_actor[actor].physics.rigid_body->setWorldTransform(actor_transform);

		//rc_actor[actor].physics.rigid_body->setMassProps(rc_actor[actor].physics.mass, irr::core::vector3df(0,0,0));
		//rc_physics3D.world->addRigidBody(rc_actor[actor].physics.rigid_body);

		rc_actor[actor].mesh_node->setPosition(actor_transform.getTranslation());
		rc_actor[actor].mesh_node->updateAbsolutePosition();

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

// --------------COMPOSITE STUFF-------------------
//Function AddCompositeChild(actor, child_actor, t_matrix)
int rc_addCompositeChild(int actor, int child_actor, int t_matrix)
{
    //std::cout << "AddChild DBG: " << actor << ", " << child_actor << ", " << t_matrix << std::endl;

	if(actor < 0 || actor >= rc_actor.size())
        return -1;

    if(child_actor < 0 || child_actor >= rc_actor.size())
        return -1;

    if(t_matrix < 0 || t_matrix >= rc_matrix.size())
        return -1;

    int index = -1;
    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_COMPOSITE:
            {
                ICompoundShape* parent_shape = (ICompoundShape*)rc_actor[actor].physics.rigid_body->getCollisionShape();
                ICollisionShape* child_shape = rc_actor[child_actor].physics.rigid_body->getCollisionShape();

                irr::core::matrix4 irr_mat = rc_convertToIrrMatrix(t_matrix);

                index = parent_shape->addChildShape(irr_mat, child_shape);

                rc_actor[actor].mesh_node->addChild(rc_actor[child_actor].mesh_node);

                irr::core::matrix4 irr_mat_t = irr_mat * rc_actor[actor].mesh_node->getAbsoluteTransformation();

                irr::core::vector3df pos = irr_mat_t.getTranslation();
                irr::core::vector3df rot = irr_mat_t.getRotationDegrees();
                irr::core::vector3df scale = irr_mat_t.getScale();

                rc_actor[child_actor].mesh_node->setPosition(pos);
                rc_actor[child_actor].mesh_node->setRotation(rot);
                rc_actor[child_actor].mesh_node->setScale(scale);
                rc_actor[child_actor].mesh_node->updateAbsolutePosition();

                rc_actor[child_actor].parent_id = actor;

                rc_physics3D.world->removeCollisionObject(rc_actor[child_actor].physics.rigid_body, false);

                rc_actor[child_actor].physics.rigid_body->setWorldTransform( rc_actor[child_actor].mesh_node->getAbsoluteTransformation() );

                rc_composite_child child;
                child.id = child_actor;
                child.child_transform = irr_mat;
                child.shape = parent_shape->getChildShape(index);

                rc_actor[actor].child_actors.push_back(child);

                //std::cout << "Add Child Actor" << std::endl;

            }
            break;
    }

    return index;
}


//Function GetCompositeChildCount(actor)
int rc_getCompositeChildCount(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    int child_count = 0;
    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_COMPOSITE:
            {
                child_count = rc_actor[actor].child_actors.size();
            }
            break;
    }

    return child_count;
}


//Function GetCompositeChild(actor, child_index)
int rc_getCompositeChild(int actor, int child_index)
{
	if(actor < 0 || actor >= rc_actor.size())
        return -1;

    if(child_index < 0 || child_index >= rc_actor[actor].child_actors.size())
        return -1;

    int child_id = -1;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_COMPOSITE:
            {
                child_id = rc_actor[actor].child_actors[child_index].id;
            }
            break;
    }

    return child_id;
}


//Function GetCompositeChildIndex(actor, child_actor)
int rc_getCompositeChildIndex(int actor, int child_actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return -1;

    if(child_actor < 0 || child_actor >= rc_actor.size())
        return -1;

    int child_index = -1;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_COMPOSITE:
            {
                for(int i = 0; i < rc_actor[actor].child_actors.size(); i++)
                {
                    if(rc_actor[actor].child_actors[i].id == child_actor)
                    {
                        child_index = i;
                        break;
                    }
                }
            }
            break;
    }

    return child_index;
}


//Sub RemoveCompositeChild(actor, child_index)
void rc_removeCompositeChild(int actor, int child_index)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(child_index < 0 || child_index >= rc_actor[actor].child_actors.size())
        return;

    int child_actor = rc_actor[actor].child_actors[child_index].id;

    if(rc_actor[child_actor].mesh_node == NULL)
        return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_COMPOSITE:
            {
                ICompoundShape* parent_shape = (ICompoundShape*)rc_actor[actor].physics.rigid_body->getCollisionShape();

                ICollisionShape* child_shape = rc_actor[actor].child_actors[child_index].shape;

                parent_shape->removeChildShape(child_shape);

                int child_actor = rc_actor[actor].child_actors[child_index].id;

                if(rc_actor[actor].mesh_node != NULL && rc_actor[child_actor].mesh_node != NULL)
                {
                    //rc_actor[child_actor].mesh_node->grab();
                    rc_actor[child_actor].mesh_node->setParent( SceneManager->getRootSceneNode() );
                }

                rc_actor[child_actor].physics.rigid_body->setCollisionShape(child_shape);

                rc_physics3D.world->addRigidBody(rc_actor[child_actor].physics.rigid_body);

                irr::core::matrix4 irr_mat_t = rc_actor[actor].physics.rigid_body->getWorldTransform();
                irr_mat_t = irr_mat_t * rc_actor[actor].child_actors[child_index].child_transform;

                rc_actor[child_actor].physics.rigid_body->setWorldTransform(irr_mat_t);

                irr::core::vector3df pos = irr_mat_t.getTranslation();
                irr::core::vector3df rot = irr_mat_t.getRotationDegrees();
                irr::core::vector3df scale = irr_mat_t.getScale();

                //std::cout << "child_actor = " << child_actor << std::endl;

                rc_actor[child_actor].mesh_node->setPosition(pos);
                rc_actor[child_actor].mesh_node->setRotation(rot);
                rc_actor[child_actor].mesh_node->setScale(scale);
                rc_actor[child_actor].mesh_node->updateAbsolutePosition();

                rc_actor[child_actor].parent_id = -1;


                rc_actor[actor].child_actors.erase(child_index);
            }
            break;
    }

    return;
}


//Function GetCompositeChildTransform(actor, child_index, t_matrix)
bool rc_getCompositeChildTransform(int actor, int child_index, int t_matrix)
{
	if(actor < 0 || actor >= rc_actor.size())
        return false;

    if(child_index < 0 || child_index >= rc_actor[actor].child_actors.size())
        return false;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_COMPOSITE:
            {
                ICompoundShape* parent_shape = (ICompoundShape*)rc_actor[actor].physics.rigid_body->getCollisionShape();
                //std::cout << "child_index = " << child_index << ",  t_matrix = " << t_matrix << std::endl;
                irr::core::matrix4 irr_mat = parent_shape->getChildTransform(child_index);
                rc_convertFromIrrMatrix(irr_mat, t_matrix);
            }
            break;
    }

    return true;
}


//Function GetCompositeAABB(actor, t_matrix, ByRef min_x, ByRef min_y, ByRef min_z, ByRef max_x, ByRef max_y, ByRef max_z)
bool rc_getCompositeAABB(int actor, int t_matrix, double* min_x, double* min_y, double* min_z, double* max_x, double* max_y, double* max_z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return false;

    if(t_matrix < 0 || t_matrix >= rc_matrix.size())
        return false;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_COMPOSITE:
            {
                ICompoundShape* parent_shape = (ICompoundShape*)rc_actor[actor].physics.rigid_body->getCollisionShape();
                irr::core::matrix4 irr_mat;
                irr::core::vector3df aabb_min(0.0f, 0.0f, 0.0f);
                irr::core::vector3df aabb_max(0.0f, 0.0f, 0.0f);
                parent_shape->getAabb(irr_mat, aabb_min, aabb_max);
                rc_convertFromIrrMatrix(irr_mat, t_matrix);

                *min_x = (double)aabb_min.X;
                *min_y = (double)aabb_min.Y;
                *min_z = (double)aabb_min.Z;

                *max_x = (double)aabb_max.X;
                *max_y = (double)aabb_max.Y;
                *max_z = (double)aabb_max.Z;
            }
            break;
    }

    return true;
}


//Sub RecalculateCompositeAABB(actor)
void rc_recalculateCompositeAABB(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_COMPOSITE:
            {
                ICompoundShape* parent_shape = (ICompoundShape*)rc_actor[actor].physics.rigid_body->getCollisionShape();
                parent_shape->recalculateLocalAabb();
            }
            break;
    }

    return;
}


//Sub GenerateCompositeAABBFromChildren(actor)
void rc_generateCompositeAABBFromChildren(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_COMPOSITE:
            {
                ICompoundShape* parent_shape = (ICompoundShape*)rc_actor[actor].physics.rigid_body->getCollisionShape();
                parent_shape->createAabbTreeFromChildren();
            }
            break;
    }

    return;
}


//Sub CalculateCompositePrincipalTransform(actor, ByRef masses, principal_matrix, ByRef x, ByRef y, ByRef z)
void rc_calculateCompositePrincipalTransform(int actor, double* masses, int principal_matrix, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(principal_matrix < 0 || principal_matrix >= rc_matrix.size())
        return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_COMPOSITE:
            {
                ICompoundShape* parent_shape = (ICompoundShape*)rc_actor[actor].physics.rigid_body->getCollisionShape();

                irr::core::matrix4 irr_mat = rc_convertToIrrMatrix(principal_matrix);

                int num_children = rc_actor[actor].child_actors.size();
                float f_mass[num_children];
                for(int i = 0; i < num_children; i++)
                    f_mass[i] = (float)masses[i];

                irr::core::vector3df inertia(x[0], y[0], z[0]);

                parent_shape->calculatePrincipalAxisTransform(f_mass, irr_mat, inertia);

                *x = inertia.X;
                *y = inertia.Y;
                *z = inertia.Z;

                for(int i = 0; i < num_children; i++)
                    masses[i] = f_mass[i];

                rc_convertFromIrrMatrix(irr_mat, principal_matrix);
            }
            break;
    }

    return;
}


//Sub UpdateCompositeChildTransform(actor, child_index, t_matrix, recalc_flag)
void rc_updateCompositeChildTransform(int actor, int child_index, int t_matrix, bool recalc_flag)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(child_index < 0 || child_index >= rc_actor[actor].child_actors.size())
        return;

    if(t_matrix < 0 || t_matrix >= rc_matrix.size())
        return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_COMPOSITE:
            {
                ICompoundShape* parent_shape = (ICompoundShape*)rc_actor[actor].physics.rigid_body->getCollisionShape();

                irr::core::matrix4 irr_mat = rc_convertToIrrMatrix(t_matrix);

                parent_shape->updateChildTransform(child_index, irr_mat, recalc_flag);

                rc_convertFromIrrMatrix(irr_mat, t_matrix);
            }
            break;
    }

    return;
}


//Function GetCompositeUpdateRevision(actor)
int rc_getCompositeUpdateRevision(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return -1;

    int update_rev = -1;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_COMPOSITE:
            {
                ICompoundShape* parent_shape = (ICompoundShape*)rc_actor[actor].physics.rigid_body->getCollisionShape();
                update_rev = parent_shape->getUpdateRevision();
            }
            break;
    }

    return update_rev;
}



//---------------PROPERTIES------------------------

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
        case RC_NODE_TYPE_OTMESH:
        {
            irr::scene::IOctreeSceneNode* node = (irr::scene::IOctreeSceneNode*)rc_actor[actor].mesh_node;
            if(!rc_actor[actor].shadow)
            {
                rc_actor[actor].shadow = node->addShadowVolumeSceneNode();
            }
        }
        break;

		case RC_NODE_TYPE_STMESH:
        {
            irr::scene::IMeshSceneNode* node = (irr::scene::IMeshSceneNode*)rc_actor[actor].mesh_node;
            if(!rc_actor[actor].shadow)
            {
                rc_actor[actor].shadow = node->addShadowVolumeSceneNode();
            }
        }
        break;

        case RC_NODE_TYPE_MESH:
        {
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            if(!rc_actor[actor].shadow)
            {
                rc_actor[actor].shadow = node->addShadowVolumeSceneNode();
            }
        }
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
        case RC_NODE_TYPE_OTMESH:
		case RC_NODE_TYPE_STMESH:
        case RC_NODE_TYPE_MESH:
            irr::scene::ISceneNode* node = rc_actor[actor].mesh_node;
            if(rc_actor[actor].shadow)
				node->removeChild(rc_actor[actor].shadow);
            rc_actor[actor].shadow = NULL;
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
            irr::video::SColor c(color);
            irr::video::SColorf cf(c);
            node->getLightData().AmbientColor = cf;
            break;
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
            node->getLightData().Attenuation.set(l_constant, l_linear, l_quadratic);
            break;
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
            irr::video::SColor c(color);
            irr::video::SColorf cf(c);
            node->getLightData().DiffuseColor = cf;
            break;
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
            node->getLightData().Falloff = falloff;
            break;
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
            node->getLightData().InnerCone = angle;
            break;
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
            node->getLightData().OuterCone = angle;
            break;
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
            irr::video::SColor c(color);
            irr::video::SColorf cf(c);
            node->getLightData().SpecularColor = cf;
            break;
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


int rc_getActorBoneCount( int actor )
{
    if(actor < 0 || actor >= rc_actor.size())
		return 0;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
        {
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            return node->getJointCount();
        }
        break;
    }

    return 0;
}

irr::u32 rc_getActorBoneIndex( int actor, std::string bone_name )
{
    if(actor < 0 || actor >= rc_actor.size())
		return 0;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
        {
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            irr::scene::IBoneSceneNode* bone = node->getJointNode(bone_name.c_str());
            if(bone)
            {
                return bone->getBoneIndex();
            }
        }
        break;
    }

    return -1;
}

std::string rc_getActorBoneName( int actor, irr::u32 bone_index )
{
    if(actor < 0 || actor >= rc_actor.size())
		return "";

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
        {
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            irr::scene::IBoneSceneNode* bone = node->getJointNode(bone_index);
            if(bone)
            {
                return (std::string)bone->getBoneName() + "\0";
            }
        }
        break;
    }

    return "";
}

bool rc_getActorBonePosition( int actor, int bone_index, double* x, double* y, double* z )
{
    if(actor < 0 || actor >= rc_actor.size())
		return false;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
        {
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            irr::scene::IBoneSceneNode* bone = node->getJointNode(bone_index);
            if(bone)
            {
                *x = (double)bone->getPosition().X;
                *y = (double)bone->getPosition().Y;
                *z = (double)bone->getPosition().Z;
                return true;
            }
        }
        break;
    }

    return false;
}

bool rc_getActorBoneRotation( int actor, int bone_index, double* x, double* y, double* z )
{
    if(actor < 0 || actor >= rc_actor.size())
		return false;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
        {
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            irr::scene::IBoneSceneNode* bone = node->getJointNode(bone_index);
            if(bone)
            {
                *x = (double)bone->getRotation().X;
                *y = (double)bone->getRotation().Y;
                *z = (double)bone->getRotation().Z;
                return true;
            }
        }
        break;
    }

    return false;
}

bool rc_getActorBoneScale( int actor, int bone_index, double* x, double* y, double* z )
{
    if(actor < 0 || actor >= rc_actor.size())
		return false;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
        {
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            irr::scene::IBoneSceneNode* bone = node->getJointNode(bone_index);
            if(bone)
            {
                *x = (double)bone->getScale().X;
                *y = (double)bone->getScale().Y;
                *z = (double)bone->getScale().Z;
                return true;
            }
        }
        break;
    }

    return false;
}

bool rc_getActorBoneRelativeTranform( int actor, int bone_index, int t_matrix )
{
    if(actor < 0 || actor >= rc_actor.size())
		return false;

    if(!rc_matrixExists(t_matrix))
        return false;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
        {
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            irr::scene::IBoneSceneNode* bone = node->getJointNode(bone_index);
            if(bone)
            {
                rc_convertFromIrrMatrix(bone->getRelativeTransformation(), t_matrix);
                return true;
            }
        }
        break;
    }

    return false;
}


bool rc_getActorBoneAbsoluteTranform( int actor, int bone_index, int t_matrix )
{
    if(actor < 0 || actor >= rc_actor.size())
		return false;

    if(!rc_matrixExists(t_matrix))
        return false;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
        {
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            irr::scene::IBoneSceneNode* bone = node->getJointNode(bone_index);
            if(bone)
            {
                rc_convertFromIrrMatrix(bone->getAbsoluteTransformation(), t_matrix);
                return true;
            }
        }
        break;
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
            irr::core::aabbox3d<irr::f32> bbox = node->getBoundingBox(patch_x, patch_z);

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


//BILLBOARDS
void rc_setBillboardSize(int actor, double w, double h)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

	switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_BILLBOARD:
			irr::scene::IBillboardSceneNode* node = (irr::scene::IBillboardSceneNode*) rc_actor[actor].mesh_node;
			node->setSize(irr::core::dimension2df(w, h));
			break;
    }
}


void rc_getBillboardSize(int actor, double* w, double* h)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

	switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_BILLBOARD:
			irr::scene::IBillboardSceneNode* node = (irr::scene::IBillboardSceneNode*) rc_actor[actor].mesh_node;
			*w = node->getSize().Width;
			*h = node->getSize().Height;
			break;
    }
}


//PROJECTORS
void rc_setProjectorTarget(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_PROJECTOR:
			CProjectiveTextures* projector = (CProjectiveTextures*) rc_actor[actor].mesh_node;
			projector->setTarget(irr::core::vector3df(x,y,z));
			break;
    }
}

void rc_getProjectorTarget(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_PROJECTOR:
			CProjectiveTextures* projector = (CProjectiveTextures*) rc_actor[actor].mesh_node;
			*x = projector->getTarget().X;
			*y = projector->getTarget().Y;
			*z = projector->getTarget().Z;
			break;
    }
}

void rc_setProjectorFOV(int actor, double fov)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_PROJECTOR:
			CProjectiveTextures* projector = (CProjectiveTextures*) rc_actor[actor].mesh_node;
			return projector->setFOV(fov);
    }
}

double rc_getProjectorFOV(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

	switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_PROJECTOR:
			CProjectiveTextures* projector = (CProjectiveTextures*) rc_actor[actor].mesh_node;
			return projector->getFOV();
    }
}


void rc_setProjectorTexture(int actor, int img_id)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(img_id < 0 || img_id >= rc_image.size())
        return;

    if(!rc_image[img_id].image)
        return;

	switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_PROJECTOR:
			CProjectiveTextures* projector = (CProjectiveTextures*) rc_actor[actor].mesh_node;
			projector->texture = rc_image[img_id].image;
			rc_actor[actor].projector_properties.project_texture_id = img_id;
			break;
    }
}

int rc_getProjectorTexture(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return -1;

	switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_PROJECTOR:
			return rc_actor[actor].projector_properties.project_texture_id;
    }

    return -1;
}


int rc_addProjectorEffectActor(int actor, int tgt_actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return -1;

    if(tgt_actor < 0 || tgt_actor >= rc_actor.size())
        return -1;

    if(rc_actor[actor].mesh_node == NULL || rc_actor[tgt_actor].mesh_node == NULL)
        return -1;

    int n_index = -1;

	switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_PROJECTOR:
    	    {
    	        CProjectiveTextures* projector = (CProjectiveTextures*) rc_actor[actor].mesh_node;

                bool na_found = false;

                for(int i = 0; i < projector->nodeArray.size(); i++)
                {
                    if(projector->nodeArray[i] == rc_actor[tgt_actor].mesh_node)
                    {
                        na_found = true;
                        break;
                    }
                }

                if(!na_found)
                {
                    n_index = projector->nodeArray.size();
                    projector->nodeArray.push_back(rc_actor[tgt_actor].mesh_node);

                    removeProjectorParent(actor, tgt_actor);

                    rc_actor[tgt_actor].projector_parent.push_back(actor);

                    bool id_found = false;
                    for(int i = 0; i < rc_actor[actor].projector_properties.effect_actors.size(); i++)
                    {
                        if(rc_actor[actor].projector_properties.effect_actors[i] == tgt_actor)
                        {
                            id_found = true;
                            break;
                        }
                    }

                    if(!id_found)
                    {
                        rc_actor[actor].projector_properties.effect_actors.push_back(tgt_actor);
                    }
                }
    	    }
    	    break;
    }

    return n_index;
}


int rc_getProjectorEffectActorCount(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(rc_actor[actor].mesh_node == NULL)
        return 0;

	switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_PROJECTOR:
    	    CProjectiveTextures* projector = (CProjectiveTextures*) rc_actor[actor].mesh_node;
			return projector->nodeArray.size();
    }

    return 0;
}

int rc_getProjectorEffectActor(int actor, int tgt_index)
{
	if(actor < 0 || actor >= rc_actor.size())
        return -1;

    if(rc_actor[actor].mesh_node == NULL)
        return -1;


	switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_PROJECTOR:
    	    CProjectiveTextures* projector = (CProjectiveTextures*) rc_actor[actor].mesh_node;

    	    if(tgt_index < 0 || tgt_index >= projector->nodeArray.size())
            {
                return -1;
            }
            else
            {
                for(int i = 0; i < rc_actor[actor].projector_properties.effect_actors.size(); i++)
                {
                    int tgt_id = rc_actor[actor].projector_properties.effect_actors[i];
                    if(tgt_id < 0 || tgt_id >= rc_actor.size())
                        continue;

                    if(rc_actor[tgt_id].mesh_node == projector->nodeArray[tgt_index])
                        return tgt_id;
                }
            }

			break;

    }

    return -1;
}


void rc_removeProjectorEffectActor(int actor, int tgt_index)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].mesh_node == NULL)
        return;

	switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_PROJECTOR:
    	    CProjectiveTextures* projector = (CProjectiveTextures*) rc_actor[actor].mesh_node;
			if(tgt_index >= 0 && tgt_index < projector->nodeArray.size())
            {
                for(int i = 0; i < rc_actor[actor].projector_properties.effect_actors.size(); i++)
                {
                    int tgt_id = rc_actor[actor].projector_properties.effect_actors[i];
                    if(tgt_id < 0 || tgt_id >= rc_actor.size())
                        continue;

                    if(rc_actor[tgt_id].mesh_node == projector->nodeArray[tgt_index])
                    {
                        removeProjectorParent(actor, tgt_id);
                        rc_actor[actor].projector_properties.effect_actors.erase(i);
                        break;
                    }
                }

                projector->nodeArray.erase(tgt_index);
            }
			break;

    }

}


//-----------------VEHICLE ACTOR------------------------------

int rc_addVehicleWheel( int actor, int wheel_actor, bool is_front_wheel )
{
    if(actor < 0 || actor >= rc_actor.size())
        return -1;

    if(!rc_actor[actor].mesh_node)
        return -1;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return -1;

    if(wheel_actor < 0 || wheel_actor >= rc_actor.size())
        return -1;

    if(!rc_actor[wheel_actor].mesh_node)
        return -1;

    SWheelInfoConstructionInfo wheel_info;
    wheel_info.isFrontWheel = is_front_wheel;

    int wheel_index = rc_actor[actor].vehicle_properties.wheels.size();

    rc_vehicle_wheel wheel_obj;
    rc_physics3D.world->removeCollisionObject(rc_actor[wheel_actor].physics.rigid_body, false);
    wheel_obj.actor_id = wheel_actor;
    wheel_obj.offset_transform.makeIdentity();

    rc_actor[actor].vehicle_properties.wheels.push_back(wheel_obj);

    SWheelInfo& info = rc_actor[actor].vehicle_properties.vehicle->addWheel(wheel_info);

    rc_actor[wheel_actor].physics.rigid_body->setWorldTransform(info.worldTransform);
    rc_actor[wheel_actor].isWheel = true;
    rc_actor[wheel_actor].parent_id = actor;

    irr::core::matrix4 actor_transform = rc_actor[actor].physics.rigid_body->getWorldTransform();
    rc_actor[actor].physics.rigid_body->clearForces();
    rc_actor[actor].physics.rigid_body->setWorldTransform(actor_transform);
    rc_actor[actor].mesh_node->setPosition( actor_transform.getTranslation() );
    rc_actor[actor].mesh_node->setRotation( actor_transform.getRotationDegrees() );
    rc_actor[actor].mesh_node->setScale( actor_transform.getScale() );
    rc_actor[actor].mesh_node->updateAbsolutePosition();

    return wheel_index;
}


void rc_setWheelActorOffsetTransform( int actor, int wheel_index, int t_matrix )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    if(t_matrix < 0 || t_matrix >= rc_matrix.size())
        return;

    rc_actor[actor].vehicle_properties.wheels[wheel_index].offset_transform = rc_convertToIrrMatrix(t_matrix);
}

void rc_getWheelActorOffsetTransform( int actor, int wheel_index, int t_matrix )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    if(t_matrix < 0 || t_matrix >= rc_matrix.size())
        return;

    rc_convertFromIrrMatrix(rc_actor[actor].vehicle_properties.wheels[wheel_index].offset_transform, t_matrix);
}


void rc_setWheelConnectionPoint( int actor, int wheel_index, double x, double y, double z )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    //std::cout << "setWheelConnectionPoint: " << wheel_index << std::endl;
    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    info.chassisConnectionPointCS.set((float)x, (float)y, (float)z);

    rc_actor[actor].vehicle_properties.vehicle->updateWheelInfo(wheel_index);

    //info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    //std::cout << "setWheelConnectionPoint OUT: " << info.chassisConnectionPointCS.X << ", " << info.chassisConnectionPointCS.Y << ", " << info.chassisConnectionPointCS.Z << std::endl;
}

void rc_setWheelDirection( int actor, int wheel_index, double x, double y, double z )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    info.wheelDirectionCS.set((float)x, (float)y, (float)z);

    rc_actor[actor].vehicle_properties.vehicle->updateWheelInfo(wheel_index);
}

void rc_setWheelAxel( int actor, int wheel_index, double x, double y, double z )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    info.wheelAxleCS.set((float)x, (float)y, (float)z);

    rc_actor[actor].vehicle_properties.vehicle->updateWheelInfo(wheel_index);
}

void rc_setWheelSuspensionLength( int actor, int wheel_index, double s_length )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    info.suspensionRestLength = s_length;

    rc_actor[actor].vehicle_properties.vehicle->updateWheelInfo(wheel_index);
}

void rc_setWheelMaxSuspensionTravel( int actor, int wheel_index, double max_travel )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    info.maxSuspensionTravelCm = max_travel;

    rc_actor[actor].vehicle_properties.vehicle->updateWheelInfo(wheel_index);
}

void rc_setWheelRadius( int actor, int wheel_index, double radius )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    info.wheelRadius = radius;

    rc_actor[actor].vehicle_properties.vehicle->updateWheelInfo(wheel_index);
}


void rc_getVehicleAxis( int actor, double* x, double* y, double* z  )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    *x = rc_actor[actor].vehicle_properties.vehicle->getRightAxis();
    *y = rc_actor[actor].vehicle_properties.vehicle->getUpAxis();
    *z = rc_actor[actor].vehicle_properties.vehicle->getForwardAxis();

}

void rc_getVehicleForwardVector( int actor, double* x, double* y, double* z )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    *x = rc_actor[actor].vehicle_properties.vehicle->getForwardVector().X;
    *y = rc_actor[actor].vehicle_properties.vehicle->getForwardVector().Y;
    *z = rc_actor[actor].vehicle_properties.vehicle->getForwardVector().Z;
}

double rc_getVehicleCurrentSpeed( int actor )
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(!rc_actor[actor].mesh_node)
        return 0;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return 0;

    return rc_actor[actor].vehicle_properties.vehicle->getCurrentSpeedKmHour();
}

int rc_getWheelCount( int actor )
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(!rc_actor[actor].mesh_node)
        return 0;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return 0;

    return rc_actor[actor].vehicle_properties.wheels.size();
}

void rc_getVehicleChassisWorldTransform( int actor, int t_matrix )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(t_matrix < 0 || t_matrix >= rc_matrix.size())
        return;

    rc_convertFromIrrMatrix(rc_actor[actor].vehicle_properties.vehicle->getChassisWorldTransform(), t_matrix);
}


double rc_getWheelSteeringValue( int actor, int wheel_index )
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(!rc_actor[actor].mesh_node)
        return 0;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return 0;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return 0;

    return rc_actor[actor].vehicle_properties.vehicle->getSteeringValue(wheel_index);
}


void rc_getWheelWorldTransform( int actor, int wheel_index, int t_matrix )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    if(t_matrix < 0 || t_matrix >= rc_matrix.size())
        return;

    rc_convertFromIrrMatrix(rc_actor[actor].vehicle_properties.vehicle->getWheelTransformWS(wheel_index), t_matrix);
}

void rc_getWheelConnectionPoint( int actor, int wheel_index, double* x, double* y, double* z)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    *x = info.chassisConnectionPointCS.X;
    *y = info.chassisConnectionPointCS.Y;
    *z = info.chassisConnectionPointCS.Z;
}

void rc_getWheelDirection( int actor, int wheel_index, double* x, double* y, double* z )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    *x = info.wheelDirectionCS.X;
    *y = info.wheelDirectionCS.Y;
    *z = info.wheelDirectionCS.Z;
}

void rc_getWheelAxel( int actor, int wheel_index, double* x, double* y, double* z )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    *x = info.wheelAxleCS.X;
    *y = info.wheelAxleCS.Y;
    *z = info.wheelAxleCS.Z;
}


double rc_getWheelSuspensionLength( int actor, int wheel_index )
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(!rc_actor[actor].mesh_node)
        return 0;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return 0;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return 0;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    return info.suspensionRestLength;
}


double rc_getWheelMaxSuspensionTravel( int actor, int wheel_index )
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(!rc_actor[actor].mesh_node)
        return 0;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return 0;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return 0;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    return info.maxSuspensionTravelCm;
}

double rc_getWheelRadius( int actor, int wheel_index )
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(!rc_actor[actor].mesh_node)
        return 0;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return 0;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return 0;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    return info.wheelRadius;
}

double rc_getWheelSuspensionStiffness( int actor, int wheel_index )
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(!rc_actor[actor].mesh_node)
        return 0;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return 0;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return 0;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    return info.suspensionStiffness;
}

double rc_getWheelDampingCompression( int actor, int wheel_index )
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(!rc_actor[actor].mesh_node)
        return 0;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return 0;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return 0;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    return info.wheelDampingCompression;
}

double rc_getWheelDampingRelaxation( int actor, int wheel_index )
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(!rc_actor[actor].mesh_node)
        return 0;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return 0;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return 0;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    return info.wheelDampingRelaxation;
}

double rc_getWheelFrictionSlip( int actor, int wheel_index )
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(!rc_actor[actor].mesh_node)
        return 0;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return 0;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return 0;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    return info.frictionSlip;
}

double rc_getWheelRotation( int actor, int wheel_index )
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(!rc_actor[actor].mesh_node)
        return 0;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return 0;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return 0;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    return info.wheelRotation;
}

double rc_getWheelRotationDelta( int actor, int wheel_index )
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(!rc_actor[actor].mesh_node)
        return 0;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return 0;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return 0;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    return info.deltaRotation;
}

double rc_getWheelRollInfluence( int actor, int wheel_index )
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(!rc_actor[actor].mesh_node)
        return 0;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return 0;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return 0;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    return info.rollInfluence;
}

double rc_getWheelEngineForce( int actor, int wheel_index )
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(!rc_actor[actor].mesh_node)
        return 0;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return 0;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return 0;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    return info.engineForce;
}

double rc_getWheelBrake( int actor, int wheel_index )
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(!rc_actor[actor].mesh_node)
        return 0;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return 0;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return 0;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    return info.brake;
}

bool rc_wheelIsFront( int actor, int wheel_index )
{
    if(actor < 0 || actor >= rc_actor.size())
        return false;

    if(!rc_actor[actor].mesh_node)
        return false;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return false;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return false;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    return info.isFrontWheel;
}

double rc_getWheelInverseContactSuspension( int actor, int wheel_index )
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(!rc_actor[actor].mesh_node)
        return 0;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return 0;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return 0;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    return info.clippedInvContactDotSuspension;
}

double rc_getWheelSuspensionVelocity( int actor, int wheel_index )
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(!rc_actor[actor].mesh_node)
        return 0;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return 0;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return 0;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    return info.suspensionRelativeVelocity;
}

void rc_resetVehicleSuspension( int actor )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;


    rc_actor[actor].vehicle_properties.vehicle->resetSuspension();
}

void rc_setWheelSteeringValue( int actor, int wheel_index, double steering )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    rc_actor[actor].vehicle_properties.vehicle->setSteeringValue(steering, wheel_index);
}

void rc_applyWheelEngineForce( int actor, int wheel_index, double force )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    rc_actor[actor].vehicle_properties.vehicle->applyEngineForce(force, wheel_index);
}

void rc_setWheelBrake( int actor, int wheel_index, double brake )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    rc_actor[actor].vehicle_properties.vehicle->setBrake(brake, wheel_index);
}

void rc_setVehiclePitchControl( int actor, double pitch )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    rc_actor[actor].vehicle_properties.vehicle->setPitchControl(pitch);
}



void rc_setWheelSuspensionStiffness( int actor, int wheel_index, double stiffness )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    info.suspensionStiffness = stiffness;

    rc_actor[actor].vehicle_properties.vehicle->updateWheelInfo(wheel_index);
}

void rc_setWheelDampingCompression( int actor, int wheel_index, double dcomp_value )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    info.wheelDampingCompression = dcomp_value;

    rc_actor[actor].vehicle_properties.vehicle->updateWheelInfo(wheel_index);
}

void rc_setWheelDampingRelaxation( int actor, int wheel_index, double drel_value )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    info.wheelDampingRelaxation = drel_value;

    rc_actor[actor].vehicle_properties.vehicle->updateWheelInfo(wheel_index);
}

void rc_setWheelFrictionSlip( int actor, int wheel_index, double fslip_value )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    info.frictionSlip = fslip_value;

    rc_actor[actor].vehicle_properties.vehicle->updateWheelInfo(wheel_index);
}

void rc_setWheelRotation( int actor, int wheel_index, double rot )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    info.wheelRotation = rot;

    rc_actor[actor].vehicle_properties.vehicle->updateWheelInfo(wheel_index);
}

void rc_setWheelRotationDelta( int actor, int wheel_index, double rot_delta )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    info.deltaRotation = rot_delta;

    rc_actor[actor].vehicle_properties.vehicle->updateWheelInfo(wheel_index);
}

void rc_setWheelRollInfluence( int actor, int wheel_index, double roll_influence )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    info.rollInfluence = roll_influence;

    rc_actor[actor].vehicle_properties.vehicle->updateWheelInfo(wheel_index);
}

void rc_setWheelInverseContactSuspension( int actor, int wheel_index, double c_value )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    info.clippedInvContactDotSuspension = c_value;

    rc_actor[actor].vehicle_properties.vehicle->updateWheelInfo(wheel_index);
}

void rc_setWheelSuspensionVelocity( int actor, int wheel_index, double velocity )
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    if(!rc_actor[actor].mesh_node)
        return;

    if(rc_actor[actor].node_type != RC_NODE_TYPE_VEHICLE)
        return;

    if(wheel_index < 0 || wheel_index >= rc_actor[actor].vehicle_properties.wheels.size())
        return;

    SWheelInfo &info = rc_actor[actor].vehicle_properties.vehicle->getWheelInfo(wheel_index);

    info.suspensionRelativeVelocity = velocity;

    rc_actor[actor].vehicle_properties.vehicle->updateWheelInfo(wheel_index);
}


#endif // RC_BASE_ACTOR_H_INCLUDED
