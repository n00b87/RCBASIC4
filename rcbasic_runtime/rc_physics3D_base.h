#ifndef RC_PHYSICS3D_BASE_H_INCLUDED
#define RC_PHYSICS3D_BASE_H_INCLUDED

#include "rc_gfx_core.h"

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

#endif // RC_PHYSICS3D_BASE_H_INCLUDED
