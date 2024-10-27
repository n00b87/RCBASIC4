#include "rc_sprite2D.h"

void rc_applySpriteAngularImpulse(int spr_id, float impulse, bool wake)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

    rc_sprite[spr_id].physics.body->ApplyAngularImpulse(impulse, wake);
}

void rc_applySpriteForce(int spr_id, double fX, double fY, double pX, double pY, bool wake)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

    rc_sprite[spr_id].physics.body->ApplyForce(b2Vec2(fX, fY), b2Vec2(pX, pY), wake);
}

void rc_applySpriteForceToCenter(int spr_id, double x, double y, bool wake)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

    rc_sprite[spr_id].physics.body->ApplyForceToCenter(b2Vec2(x, y), wake);
}

void rc_applySpriteLinearImpulse(int spr_id, double iX, double iY, double pX, double pY, bool wake)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

    rc_sprite[spr_id].physics.body->ApplyLinearImpulse(b2Vec2(iX, iY), b2Vec2(pX, pY), wake);
}

void rc_applySpriteLinearForceToCenter(int spr_id, double x, double y, bool wake)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

    rc_sprite[spr_id].physics.body->ApplyLinearImpulseToCenter(b2Vec2(x, y), wake);
}

void rc_applySpriteTorque(int spr_id, float torque, bool wake)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

    rc_sprite[spr_id].physics.body->ApplyTorque(torque, wake);
}

float rc_getSpriteAngle(int spr_id)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

    return rc_sprite[spr_id].physics.body->GetAngle();
}

float rc_getSpriteAngularVelocity(int spr_id)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

    return rc_sprite[spr_id].physics.body->GetAngularVelocity();
}

float rc_getSpriteInertia(int spr_id)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

    return rc_sprite[spr_id].physics.body->GetInertia();
}

void rc_getSpriteLinearVelocity(int spr_id, double* x, double* y)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

    *x  = (double)rc_sprite[spr_id].physics.body->GetLinearVelocity().x;
    *y  = (double)rc_sprite[spr_id].physics.body->GetLinearVelocity().y;
}

void rc_getSpriteLinearVelocityFromLocalPoint(int spr_id, double* x, double* y, double pX, double pY)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

    b2Vec2 pos = rc_sprite[spr_id].physics.body->GetLinearVelocityFromLocalPoint(b2Vec2(pX, pY));
    *x = pos.x;
    *y = pos.y;
}

void rc_getSpriteLinearVelocityFromWorldPoint(int spr_id, double* x, double* y, double wX, double wY)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

    b2Vec2 pos = rc_sprite[spr_id].physics.body->GetLinearVelocityFromWorldPoint(b2Vec2(wX, wY));
    *x = pos.x;
    *y = pos.y;
}

void rc_getSpriteLocalPoint()                   *******************************
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;
}

void rc_getSpriteLocalVector()                  *******************************
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;
}

float rc_getSpriteMass(int spr_id)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

    return rc_sprite[spr_id].physics.body->GetMass();
}

void rc_getSpriteMassData(int spr_id)           *******************************
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;
}

void rc_getSpriteTransform(int spr_id)          *******************************
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;
}
