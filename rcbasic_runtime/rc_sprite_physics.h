#include "rc_sprite2D.h"

void rc_getSpriteCenter(int spr_id, double* x, double* y)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	*x = (double)rc_sprite[spr_id].physics.body->GetLocalCenter().x;
	*y = (double)rc_sprite[spr_id].physics.body->GetLocalCenter().y;
}

void rc_setSpriteLinearVelocity(int spr_id, double x, double y)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

    rc_sprite[spr_id].physics.body->SetLinearVelocity(b2Vec2(x, y));
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

void rc_setSpriteAngularVelocity(int spr_id, double av)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

    rc_sprite[spr_id].physics.body->SetAngularVelocity(av);
}

double rc_getSpriteAngularVelocity(int spr_id)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

    return (double)rc_sprite[spr_id].physics.body->GetAngularVelocity();
}

void rc_applySpriteForce(int spr_id, double fX, double fY, double pX, double pY)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

    rc_sprite[spr_id].physics.body->ApplyForce(b2Vec2(fX, fY), b2Vec2(pX, pY), true);
}

void rc_applySpriteCentralForce(int spr_id, double x, double y)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

    rc_sprite[spr_id].physics.body->ApplyForceToCenter(b2Vec2(x, y), true);
}

void rc_applySpriteTorque(int spr_id, double torque)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

    rc_sprite[spr_id].physics.body->ApplyTorque(torque, true);
}

void rc_applySpriteLinearImpulse(int spr_id, double iX, double iY, double pX, double pY)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

    rc_sprite[spr_id].physics.body->ApplyLinearImpulse(b2Vec2(iX, iY), b2Vec2(pX, pY), true);
}

void rc_applySpriteAngularImpulse(int spr_id, double impulse)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

    rc_sprite[spr_id].physics.body->ApplyAngularImpulse(impulse, true);
}

double rc_getSpriteMass(int spr_id)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

    return rc_sprite[spr_id].physics.body->GetMass();
}

double rc_getSpriteInertia(int spr_id)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

    return rc_sprite[spr_id].physics.body->GetInertia();
}

void rc_getSpriteWorldPoint(int spr_id, double lX, double lY, double* x, double* y)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	b2Vec2 wp = rc_sprite[spr_id].physics.body->GetWorldPoint(b2Vec2(lX, lY));
	*x = wp.x;
	*y = wp.y;
}

void rc_getSpriteWorldVector(int spr_id, double lX, double lY, double* x, double* y)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	b2Vec2 wv = rc_sprite[spr_id].physics.body->GetWorldVector(b2Vec2(lX, lY));
	*x = wv.x;
	*y = wv.y;
}

void rc_getSpriteLocalPoint(int spr_id, double wX, double wY, double* x, double* y)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	b2Vec2 lp = rc_sprite[spr_id].physics.body->GetLocalPoint(b2Vec2(wX, wY));
	*x = lp.x;
	*y = lp.y;
}

void rc_getSpriteLocalVector(int spr_id, double wX, double wY, double* x, double* y)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	b2Vec2 lv = rc_sprite[spr_id].physics.body->GetLocalVector(b2Vec2(wX, wY));
	*x = lv.x;
	*y = lv.y;
}

void rc_getSpriteLinearVelocityFromLocalPoint(int spr_id, double pX, double pY, double* x, double* y)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

    b2Vec2 pos = rc_sprite[spr_id].physics.body->GetLinearVelocityFromLocalPoint(b2Vec2(pX, pY));
    *x = pos.x;
    *y = pos.y;
}

void rc_getSpriteLinearVelocityFromWorldPoint(int spr_id, double wX, double wY, double* x, double* y)
{
    if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

    b2Vec2 pos = rc_sprite[spr_id].physics.body->GetLinearVelocityFromWorldPoint(b2Vec2(wX, wY));
    *x = pos.x;
    *y = pos.y;
}

double rc_getSpriteLinearDamping(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

	return rc_sprite[spr_id].physics.body->GetLinearDamping();
}

void rc_setSpriteLinearDamping(int spr_id, double linearDamping)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	rc_sprite[spr_id].physics.body->SetLinearDamping(linearDamping);
}

double rc_getSpriteAngularDamping(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

	return rc_sprite[spr_id].physics.body->GetAngularDamping();
}

void rc_setSpriteAngularDamping(int spr_id, double angularDamping)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	rc_sprite[spr_id].physics.body->SetAngularDamping(angularDamping);
}

double rc_getSpriteGravityScale(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

	return rc_sprite[spr_id].physics.body->GetGravityScale();
}

void rc_setSpriteGravityScale(int spr_id, double g_scale)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	rc_sprite[spr_id].physics.body->SetGravityScale(g_scale);
}

void rc_setSpriteBullet(int spr_id, bool flag)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	rc_sprite[spr_id].physics.body->SetBullet(flag);
}

bool rc_spriteIsBullet(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return false;

	if(!rc_sprite[spr_id].active)
		return false;

	return rc_sprite[spr_id].physics.body->IsBullet();
}

void rc_setSpriteSleepAllowed(int spr_id, bool flag)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	rc_sprite[spr_id].physics.body->SetSleepingAllowed(flag);
}

bool rc_spriteSleepAllowed(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return false;

	if(!rc_sprite[spr_id].active)
		return false;

	return rc_sprite[spr_id].physics.body->IsSleepingAllowed();
}

void rc_setSpriteAwake(int spr_id, bool flag)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	rc_sprite[spr_id].physics.body->SetAwake(flag);
}

bool rc_spriteIsAwake(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return false;

	if(!rc_sprite[spr_id].active)
		return false;

	return rc_sprite[spr_id].physics.body->IsAwake();
}

void rc_setSpriteFixedRotation(int spr_id, bool flag)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	rc_sprite[spr_id].physics.body->SetFixedRotation(flag);
}

bool rc_spriteIsFixedRotation(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return false;

	if(!rc_sprite[spr_id].active)
		return false;

	return rc_sprite[spr_id].physics.body->IsFixedRotation();
}
