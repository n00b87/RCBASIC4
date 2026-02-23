#ifndef RC_VECTORMATH_H_INCLUDED
#define RC_VECTORMATH_H_INCLUDED

#include <irrlicht.h>


double rc_getLineAngle(double x1, double y1, double x2, double y2)
{
    irr::core::vector2df v(x1, y1);
    double angle = (double)v.getAngleWith(irr::core::vector2df(x2, y2));
    return angle;
}


double rc_dotProduct(double x1, double y1, double z1, double x2, double y2, double z2)
{
    irr::core::vector3df v(x1, y1, z1);
    double dp = (double)v.dotProduct(irr::core::vector3df(x2, y2, z2));
    return dp;
}

void rc_interpolateVector(double x1, double y1, double z1, double x2, double y2, double z2, double distance, double* ix, double* iy, double* iz)
{
    irr::core::vector3df v(x1, y1, z1);
    irr::core::vector3df iv = v.getInterpolated(irr::core::vector3df(x2, y2, z2), distance);
    *ix = iv.X;
    *iy = iv.Y;
    *iz = iv.Z;
}

void rc_interpolateVectorQ(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3, double distance, double* ix, double* iy, double* iz)
{
    irr::core::vector3df v(x1, y1, z1);
    irr::core::vector3df iv = v.getInterpolated_quadratic(irr::core::vector3df(x2, y2, z2), irr::core::vector3df(x3, y3, z3), distance);
    *ix = iv.X;
    *iy = iv.Y;
    *iz = iv.Z;
}


bool rc_vectorIsBetweenPoints (double x, double y, double z, double start_x, double start_y, double start_z, double end_x, double end_y, double end_z)
{
    return irr::core::vector3df(x, y, z).isBetweenPoints(irr::core::vector3df(start_x, start_y, start_z), irr::core::vector3df(end_x, end_y, end_z));
}

void rc_normalizeVector(double x, double y, double z, double* nx, double* ny, double* nz)
{
    irr::core::vector3df v(x, y, z);
    irr::core::vector3df nv = v.normalize();
    *nx = nv.X;
    *ny = nv.Y;
    *nz = nv.Z;
}

void rc_getHorizontalAngle(double x, double y, double z, double* hx, double* hy, double* hz)
{
    irr::core::vector3df angle(x, y, z);
    irr::core::vector3df h_angle = angle.getHorizontalAngle();
    *hx = h_angle.X;
    *hy = h_angle.Y;
    *hz = h_angle.Z;
}


void rc_getRotationToTarget(double x, double y, double z, double tgt_x, double tgt_y, double tgt_z, double* rx, double* ry, double* rz)
{
    irr::core::vector3df v(x, y, z);
    irr::core::vector3df rot = v.rotationToDirection(irr::core::vector3df(tgt_x, tgt_y, tgt_z));
    *rx = rot.X;
    *ry = rot.Y;
    *rz = rot.Z;
}



#endif // RC_VECTORMATH_H_INCLUDED
