#ifndef RC_PHYSICS3D_BASE_H_INCLUDED
#define RC_PHYSICS3D_BASE_H_INCLUDED

#include "rc_gfx_core.h"

struct rc_rayHit3D_obj
{
	int actor_id;
	btVector3 hit_point;
	btVector3 hit_normal;
};

irr::core::array<rc_rayHit3D_obj> rc_rayHit3D;

///all hits
int rc_castRay3D_All(double from_x, double from_y, double from_z, double to_x, double to_y, double to_z)
{
	rc_rayHit3D.clear();
	btVector3 from(from_x, from_y, from_z);
	btVector3 to(to_x, to_y, to_z);
	//m_dynamicsWorld->getDebugDrawer()->drawLine(from, to, btVector4(0, 0, 0, 1));
	btCollisionWorld::AllHitsRayResultCallback allResults(from, to);
	allResults.m_flags |= btTriangleRaycastCallback::kF_KeepUnflippedNormal;
	//kF_UseGjkConvexRaytest flag is now enabled by default, use the faster but more approximate algorithm
	//allResults.m_flags |= btTriangleRaycastCallback::kF_UseSubSimplexConvexCastRaytest;
	allResults.m_flags |= btTriangleRaycastCallback::kF_UseSubSimplexConvexCastRaytest;

	rc_physics3D.world->getPointer()->rayTest(from, to, allResults);

	for (int i = 0; i < allResults.m_hitFractions.size(); i++)
	{
		rc_rayHit3D_obj hit;
		hit.hit_point = from.lerp(to, allResults.m_hitFractions[i]);
		hit.hit_normal = allResults.m_hitNormalWorld[i];
		btRigidBody* body = (btRigidBody*)allResults.m_collisionObjects[i];
		SCollisionObjectIdentification* colID = (SCollisionObjectIdentification*)body->getUserPointer();
		hit.actor_id = colID->getId();
		rc_rayHit3D.push_back(hit);
		//m_dynamicsWorld->getDebugDrawer()->drawSphere(p, 0.1, red);
		//m_dynamicsWorld->getDebugDrawer()->drawLine(p, p + allResults.m_hitNormalWorld[i], red);
	}

	return allResults.m_hitFractions.size();
}

///first hit
bool rc_castRay3D(double from_x, double from_y, double from_z, double to_x, double to_y, double to_z)
{
	rc_rayHit3D.clear();
	btVector3 from(from_x, from_y, from_z);
	btVector3 to(to_x, to_y, to_z);
	//m_dynamicsWorld->getDebugDrawer()->drawLine(from, to, btVector4(0, 0, 1, 1));

	btCollisionWorld::ClosestRayResultCallback closestResults(from, to);
	closestResults.m_flags |= btTriangleRaycastCallback::kF_FilterBackfaces;

	rc_physics3D.world->getPointer()->rayTest(from, to, closestResults);

	if (closestResults.hasHit())
	{
		rc_rayHit3D_obj hit;
		hit.hit_point = from.lerp(to, closestResults.m_closestHitFraction);
		hit.hit_normal = closestResults.m_hitNormalWorld;
		btRigidBody* body = (btRigidBody*)closestResults.m_collisionObject;
		SCollisionObjectIdentification* colID = (SCollisionObjectIdentification*)body->getUserPointer();
		hit.actor_id = colID->getId();
		rc_rayHit3D.push_back(hit);

		//m_dynamicsWorld->getDebugDrawer()->drawSphere(p, 0.1, blue);
		//m_dynamicsWorld->getDebugDrawer()->drawLine(p, p + closestResults.m_hitNormalWorld, blue);
	}

	return closestResults.hasHit();
}

void rc_getRayHit3D( int index, double* actor_id, double* x, double* y, double* z, double* normal_x, double* normal_y, double* normal_z )
{
	if(index < 0 || index >= rc_rayHit3D.size())
	{
		*actor_id = -1;
		return;
	}

	*actor_id = rc_rayHit3D[index].actor_id;
	*x = rc_rayHit3D[index].hit_point.getX();
	*y = rc_rayHit3D[index].hit_point.getY();
	*z = rc_rayHit3D[index].hit_point.getZ();
	*normal_x = rc_rayHit3D[index].hit_normal.getX();
	*normal_y = rc_rayHit3D[index].hit_normal.getY();
	*normal_z = rc_rayHit3D[index].hit_normal.getZ();
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

double rc_getWorld3DMaxSubSteps()
{
	return rc_physics3D.maxSubSteps;
}

double rc_getWorld3DTimeStep()
{
	return rc_physics3D.fixedTimeStep;
}

void rc_setSceneFog (Uint32 color, int fog_type, double start_val, double end_val, double density, bool pixelFog, bool rangeFog)
{
	if(VideoDriver)
		VideoDriver->setFog(irr::video::SColor(color), (irr::video::E_FOG_TYPE)fog_type, start_val, end_val, density, pixelFog, rangeFog);
}

void rc_getSceneFog (double* color, double* fog_type, double* start_val, double* end_val, double* density, double* pixelFog, double* rangeFog)
{
	irr::video::SColor col;
	irr::video::E_FOG_TYPE ftype;
	irr::f32 sv, ev, den;
	bool pf, rf;
	if(VideoDriver)
	{
		VideoDriver->getFog(col, ftype, sv, ev, den, pf, rf);

		*color = (double)col.color;
		*fog_type = (double)( (irr::video::E_FOG_TYPE) ftype);
		*start_val = (double)sv;
		*end_val = (double)ev;
		*density = (double)den;
		*pixelFog = (double)( pf ? 1.0 : 0.0 );
		*rangeFog = (double)( rf ? 1.0 : 0.0 );
	}
}

#endif // RC_PHYSICS3D_BASE_H_INCLUDED
