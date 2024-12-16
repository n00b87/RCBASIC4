#ifndef RC_PARTICLES_H_INCLUDED
#define RC_PARTICLES_H_INCLUDED

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

#endif // RC_PARTICLES_H_INCLUDED
