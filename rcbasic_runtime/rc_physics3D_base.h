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
