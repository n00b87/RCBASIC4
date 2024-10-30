#ifndef RC_BASE_ACTOR_H_INCLUDED
#define RC_BASE_ACTOR_H_INCLUDED

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
int rc_createAnimatedActor(int mesh_id)
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

    //animation
    rc_actor_animation_obj animation;
    animation.start_frame = 0;
    animation.end_frame = 0;
    animation.fps = 60.0;
    animation.frame_start_time = SDL_GetTicks();
    animation.frame_swap_time = 1000/60;
    rc_actor[actor_id].animation.push_back(animation);
    rc_animEndCallBack* anim_callback = new rc_animEndCallBack();
    anim_callback->ref_actor = &rc_actor[actor_id];
    anim_callback->OnAnimationEnd(node);
    node->setAnimationEndCallback(anim_callback);
	node->setLoopMode(false);
	node->setFrameLoop(0, 0);
	anim_callback->drop();


    //Actor RigidBody
    rc_actor[actor_id].physics.shape_type = RC_NODE_SHAPE_TYPE_BOX;
    rc_actor[actor_id].physics.rigid_body = NULL;
    rc_actor[actor_id].physics.isSolid = false;

    rc_setActorCollisionShape(actor_id, RC_NODE_SHAPE_TYPE_BOX, 1);

    return actor_id;
}


//add mesh actor to scene
int rc_createOctreeActor(int mesh_id)
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

#endif // RC_BASE_ACTOR_H_INCLUDED
