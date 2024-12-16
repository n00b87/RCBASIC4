#ifndef RC_JOINTS_H_INCLUDED
#define RC_JOINTS_H_INCLUDED

#ifdef RC_ANDROID
	#include "SDL.h"
#else
	#include <SDL2/SDL.h>
#endif // _IRR_ANDROID_PLATFORM_

#include "rc_sprite2D.h"
#include "rc_gfx_core.h"


int rc_createDistanceJoint(int spriteA, int spriteB, double aX, double aY, double bX, double bY, bool collide_connected)
{
	if(rc_active_canvas < 0 || rc_active_canvas >= rc_canvas.size())
		return -1;

	if(rc_canvas[rc_active_canvas].type != RC_CANVAS_TYPE_SPRITE)
		return -1;

	if(spriteA < 0 || spriteA >= rc_sprite.size())
		return -1;

	if(spriteB < 0 || spriteB >= rc_sprite.size())
		return -1;

	if(!(rc_sprite[spriteA].active && rc_sprite[spriteB].active))
		return -1;

	int joint_id = -1;

	for(int i = 0; i < rc_joint.size(); i++)
	{
		if(!rc_joint[i].active)
		{
			joint_id = i;
			break;
		}
	}

	if(joint_id < 0)
	{
		joint_id = rc_joint.size();
		rc_b2Joint_obj joint;
		rc_joint.push_back(joint);
	}

	rc_joint[joint_id].active = true;
	rc_joint[joint_id].canvas = rc_active_canvas;

	b2DistanceJointDef joint_def;
	joint_def.Initialize(rc_sprite[spriteA].physics.body, rc_sprite[spriteB].physics.body, b2Vec2(aX, aY), b2Vec2(bX, bY));
	joint_def.collideConnected = collide_connected;

	rc_joint[joint_id].joint = rc_canvas[rc_active_canvas].physics2D.world->CreateJoint(&joint_def);
	rc_joint[joint_id].type = RC_JOINT_TYPE_DISTANCE;

	return joint_id;
}

int rc_createFrictionJoint(int spriteA, int spriteB, double x, double y, bool collide_connected)
{
	if(rc_active_canvas < 0 || rc_active_canvas >= rc_canvas.size())
		return -1;

	if(rc_canvas[rc_active_canvas].type != RC_CANVAS_TYPE_SPRITE)
		return -1;

	if(spriteA < 0 || spriteA >= rc_sprite.size())
		return -1;

	if(spriteB < 0 || spriteB >= rc_sprite.size())
		return -1;

	if(!(rc_sprite[spriteA].active && rc_sprite[spriteB].active))
		return -1;

	int joint_id = -1;

	for(int i = 0; i < rc_joint.size(); i++)
	{
		if(!rc_joint[i].active)
		{
			joint_id = i;
			break;
		}
	}

	if(joint_id < 0)
	{
		joint_id = rc_joint.size();
		rc_b2Joint_obj joint;
		rc_joint.push_back(joint);
	}

	rc_joint[joint_id].active = true;
	rc_joint[joint_id].canvas = rc_active_canvas;

	b2FrictionJointDef joint_def;
	joint_def.Initialize(rc_sprite[spriteA].physics.body, rc_sprite[spriteB].physics.body, b2Vec2(x, y));
	joint_def.collideConnected = collide_connected;

	rc_joint[joint_id].joint = rc_canvas[rc_active_canvas].physics2D.world->CreateJoint(&joint_def);
	rc_joint[joint_id].type = RC_JOINT_TYPE_FRICTION;

	return joint_id;
}

int rc_createGearJoint(int jointA, int jointB, double g_ratio, bool collide_connected)
{
	if(rc_active_canvas < 0 || rc_active_canvas >= rc_canvas.size())
		return -1;

	if(rc_canvas[rc_active_canvas].type != RC_CANVAS_TYPE_SPRITE)
		return -1;

	if(jointA < 0 || jointA >= rc_joint.size())
		return -1;

	if(rc_joint[jointA].type != RC_JOINT_TYPE_PRISMATIC && rc_joint[jointA].type != RC_JOINT_TYPE_REVOLUTE)
		return -1;

	if(rc_joint[jointB].type != RC_JOINT_TYPE_PRISMATIC && rc_joint[jointB].type != RC_JOINT_TYPE_REVOLUTE)
		return -1;

	if(!(rc_joint[jointA].active && rc_joint[jointB].active))
		return -1;

	int joint_id = -1;

	for(int i = 0; i < rc_joint.size(); i++)
	{
		if(!rc_joint[i].active)
		{
			joint_id = i;
			break;
		}
	}

	if(joint_id < 0)
	{
		joint_id = rc_joint.size();
		rc_b2Joint_obj joint;
		rc_joint.push_back(joint);
	}

	rc_joint[joint_id].active = true;
	rc_joint[joint_id].canvas = rc_active_canvas;

	b2GearJointDef joint_def;
	joint_def.joint1 = rc_joint[jointA].joint;
	joint_def.joint2 = rc_joint[jointB].joint;
	joint_def.collideConnected = collide_connected;

	rc_joint[joint_id].joint = rc_canvas[rc_active_canvas].physics2D.world->CreateJoint(&joint_def);
	rc_joint[joint_id].type = RC_JOINT_TYPE_GEAR;

	return joint_id;
}

int rc_createMotorJoint(int spriteA, int spriteB, bool collide_connected)
{
	if(rc_active_canvas < 0 || rc_active_canvas >= rc_canvas.size())
		return -1;

	if(rc_canvas[rc_active_canvas].type != RC_CANVAS_TYPE_SPRITE)
		return -1;

	if(spriteA < 0 || spriteA >= rc_sprite.size())
		return -1;

	if(spriteB < 0 || spriteB >= rc_sprite.size())
		return -1;

	if(!(rc_sprite[spriteA].active && rc_sprite[spriteB].active))
		return -1;

	int joint_id = -1;

	for(int i = 0; i < rc_joint.size(); i++)
	{
		if(!rc_joint[i].active)
		{
			joint_id = i;
			break;
		}
	}

	if(joint_id < 0)
	{
		joint_id = rc_joint.size();
		rc_b2Joint_obj joint;
		rc_joint.push_back(joint);
	}

	rc_joint[joint_id].active = true;
	rc_joint[joint_id].canvas = rc_active_canvas;

	b2MotorJointDef joint_def;
	joint_def.Initialize(rc_sprite[spriteA].physics.body, rc_sprite[spriteB].physics.body);
	joint_def.collideConnected = collide_connected;

	rc_joint[joint_id].joint = rc_canvas[rc_active_canvas].physics2D.world->CreateJoint(&joint_def);
	rc_joint[joint_id].type = RC_JOINT_TYPE_MOTOR;

	return joint_id;
}

int rc_createPrismaticJoint(int spriteA, int spriteB, double aX, double aY, double axisX, double axisY, bool collide_connected)
{
	if(rc_active_canvas < 0 || rc_active_canvas >= rc_canvas.size())
		return -1;

	if(rc_canvas[rc_active_canvas].type != RC_CANVAS_TYPE_SPRITE)
		return -1;

	if(spriteA < 0 || spriteA >= rc_sprite.size())
		return -1;

	if(spriteB < 0 || spriteB >= rc_sprite.size())
		return -1;

	if(!(rc_sprite[spriteA].active && rc_sprite[spriteB].active))
		return -1;

	int joint_id = -1;

	for(int i = 0; i < rc_joint.size(); i++)
	{
		if(!rc_joint[i].active)
		{
			joint_id = i;
			break;
		}
	}

	if(joint_id < 0)
	{
		joint_id = rc_joint.size();
		rc_b2Joint_obj joint;
		rc_joint.push_back(joint);
	}

	rc_joint[joint_id].active = true;
	rc_joint[joint_id].canvas = rc_active_canvas;

	b2PrismaticJointDef joint_def;
	joint_def.Initialize(rc_sprite[spriteA].physics.body, rc_sprite[spriteB].physics.body, b2Vec2(aX, aY), b2Vec2(axisX, axisY));
	joint_def.collideConnected = collide_connected;

	rc_joint[joint_id].joint = rc_canvas[rc_active_canvas].physics2D.world->CreateJoint(&joint_def);
	rc_joint[joint_id].type = RC_JOINT_TYPE_PRISMATIC;

	return joint_id;
}

int rc_createPulleyJoint(int spriteA, int spriteB, double gaX, double gaY, double gbX, double gbY, double aX, double aY, double bX, double bY, double j_ratio, bool collide_connected)
{
	if(rc_active_canvas < 0 || rc_active_canvas >= rc_canvas.size())
		return -1;

	if(rc_canvas[rc_active_canvas].type != RC_CANVAS_TYPE_SPRITE)
		return -1;

	if(spriteA < 0 || spriteA >= rc_sprite.size())
		return -1;

	if(spriteB < 0 || spriteB >= rc_sprite.size())
		return -1;

	if(!(rc_sprite[spriteA].active && rc_sprite[spriteB].active))
		return -1;

	int joint_id = -1;

	for(int i = 0; i < rc_joint.size(); i++)
	{
		if(!rc_joint[i].active)
		{
			joint_id = i;
			break;
		}
	}

	if(joint_id < 0)
	{
		joint_id = rc_joint.size();
		rc_b2Joint_obj joint;
		rc_joint.push_back(joint);
	}

	rc_joint[joint_id].active = true;
	rc_joint[joint_id].canvas = rc_active_canvas;

	b2PulleyJointDef joint_def;
	joint_def.Initialize(rc_sprite[spriteA].physics.body, rc_sprite[spriteB].physics.body, b2Vec2(gaX, gaY), b2Vec2(gbX, gbY), b2Vec2(aX, aY), b2Vec2(bX, bY), j_ratio);
	joint_def.collideConnected = collide_connected;

	rc_joint[joint_id].joint = rc_canvas[rc_active_canvas].physics2D.world->CreateJoint(&joint_def);
	rc_joint[joint_id].type = RC_JOINT_TYPE_PULLEY;

	return joint_id;
}

int rc_createRevoluteJoint(int spriteA, int spriteB, double x, double y, bool collide_connected)
{
	if(rc_active_canvas < 0 || rc_active_canvas >= rc_canvas.size())
		return -1;

	if(rc_canvas[rc_active_canvas].type != RC_CANVAS_TYPE_SPRITE)
		return -1;

	if(spriteA < 0 || spriteA >= rc_sprite.size())
		return -1;

	if(spriteB < 0 || spriteB >= rc_sprite.size())
		return -1;

	if(!(rc_sprite[spriteA].active && rc_sprite[spriteB].active))
		return -1;

	int joint_id = -1;

	for(int i = 0; i < rc_joint.size(); i++)
	{
		if(!rc_joint[i].active)
		{
			joint_id = i;
			break;
		}
	}

	if(joint_id < 0)
	{
		joint_id = rc_joint.size();
		rc_b2Joint_obj joint;
		rc_joint.push_back(joint);
	}

	rc_joint[joint_id].active = true;
	rc_joint[joint_id].canvas = rc_active_canvas;

	b2RevoluteJointDef joint_def;
	joint_def.Initialize(rc_sprite[spriteA].physics.body, rc_sprite[spriteB].physics.body, b2Vec2(x, y));
	joint_def.collideConnected = collide_connected;

	rc_joint[joint_id].joint = rc_canvas[rc_active_canvas].physics2D.world->CreateJoint(&joint_def);
	rc_joint[joint_id].type = RC_JOINT_TYPE_REVOLUTE;

	return joint_id;
}

int rc_createWeldJoint(int spriteA, int spriteB, double x, double y, bool collide_connected)
{
	if(rc_active_canvas < 0 || rc_active_canvas >= rc_canvas.size())
		return -1;

	if(rc_canvas[rc_active_canvas].type != RC_CANVAS_TYPE_SPRITE)
		return -1;

	if(spriteA < 0 || spriteA >= rc_sprite.size())
		return -1;

	if(spriteB < 0 || spriteB >= rc_sprite.size())
		return -1;

	if(!(rc_sprite[spriteA].active && rc_sprite[spriteB].active))
		return -1;

	int joint_id = -1;

	for(int i = 0; i < rc_joint.size(); i++)
	{
		if(!rc_joint[i].active)
		{
			joint_id = i;
			break;
		}
	}

	if(joint_id < 0)
	{
		joint_id = rc_joint.size();
		rc_b2Joint_obj joint;
		rc_joint.push_back(joint);
	}

	rc_joint[joint_id].active = true;
	rc_joint[joint_id].canvas = rc_active_canvas;

	b2WeldJointDef joint_def;
	joint_def.Initialize(rc_sprite[spriteA].physics.body, rc_sprite[spriteB].physics.body, b2Vec2(x, y));
	joint_def.collideConnected = collide_connected;

	rc_joint[joint_id].joint = rc_canvas[rc_active_canvas].physics2D.world->CreateJoint(&joint_def);
	rc_joint[joint_id].type = RC_JOINT_TYPE_WELD;

	return joint_id;
}

int rc_createWheelJoint(int spriteA, int spriteB, double aX, double aY, double axisX, double axisY, bool collide_connected)
{
	if(rc_active_canvas < 0 || rc_active_canvas >= rc_canvas.size())
		return -1;

	if(rc_canvas[rc_active_canvas].type != RC_CANVAS_TYPE_SPRITE)
		return -1;

	if(spriteA < 0 || spriteA >= rc_sprite.size())
		return -1;

	if(spriteB < 0 || spriteB >= rc_sprite.size())
		return -1;

	if(!(rc_sprite[spriteA].active && rc_sprite[spriteB].active))
		return -1;

	int joint_id = -1;

	for(int i = 0; i < rc_joint.size(); i++)
	{
		if(!rc_joint[i].active)
		{
			joint_id = i;
			break;
		}
	}

	if(joint_id < 0)
	{
		joint_id = rc_joint.size();
		rc_b2Joint_obj joint;
		rc_joint.push_back(joint);
	}

	rc_joint[joint_id].active = true;
	rc_joint[joint_id].canvas = rc_active_canvas;

	b2WheelJointDef joint_def;
	joint_def.Initialize(rc_sprite[spriteA].physics.body, rc_sprite[spriteB].physics.body, b2Vec2(aX, aY), b2Vec2(axisX, axisY));
	joint_def.collideConnected = collide_connected;

	rc_joint[joint_id].joint = rc_canvas[rc_active_canvas].physics2D.world->CreateJoint(&joint_def);
	rc_joint[joint_id].type = RC_JOINT_TYPE_WHEEL;

	return joint_id;
}

void rc_deleteJoint(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	int j_canvas = rc_joint[joint_id].canvas;

	rc_canvas[j_canvas].physics2D.world->DestroyJoint(rc_joint[joint_id].joint);
	rc_joint[joint_id].joint = NULL;
	rc_joint[joint_id].canvas = -1;
	rc_joint[joint_id].active = false;
}

void rc_getJointWorldAnchorA(int joint_id, double* x, double* y)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	b2Vec2 anchor = rc_joint[joint_id].joint->GetAnchorA();
	*x = anchor.x;
	*y = anchor.y;
}

void rc_getJointWorldAnchorB(int joint_id, double* x, double* y)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	b2Vec2 anchor = rc_joint[joint_id].joint->GetAnchorB();
	*x = anchor.x;
	*y = anchor.y;
}

void rc_getJointReactionForce(int joint_id, double inv_dt, double* x, double* y)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	b2Vec2 v = rc_joint[joint_id].joint->GetReactionForce(inv_dt);
	*x = v.x;
	*y = v.y;
}

double rc_getJointReactionTorque(int joint_id, double inv_dt)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	return rc_joint[joint_id].joint->GetReactionTorque(inv_dt);
}

void rc_getJointLocalAnchorA(int joint_id, double* x, double* y)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_DISTANCE:
		{
			b2DistanceJoint* j = (b2DistanceJoint*)rc_joint[joint_id].joint;
			b2Vec2 anchor = j->GetLocalAnchorA();
			*x = anchor.x;
			*y = anchor.y;
		}
		break;

		case RC_JOINT_TYPE_FRICTION:
		{
			b2FrictionJoint* j = (b2FrictionJoint*)rc_joint[joint_id].joint;
			b2Vec2 anchor = j->GetLocalAnchorA();
			*x = anchor.x;
			*y = anchor.y;
		}
		break;

		case RC_JOINT_TYPE_PRISMATIC:
		{
			b2PrismaticJoint* j = (b2PrismaticJoint*)rc_joint[joint_id].joint;
			b2Vec2 anchor = j->GetLocalAnchorA();
			*x = anchor.x;
			*y = anchor.y;
		}
		break;

		case RC_JOINT_TYPE_REVOLUTE:
		{
			b2RevoluteJoint* j = (b2RevoluteJoint*)rc_joint[joint_id].joint;
			b2Vec2 anchor = j->GetLocalAnchorA();
			*x = anchor.x;
			*y = anchor.y;
		}
		break;

		case RC_JOINT_TYPE_WELD:
		{
			b2WeldJoint* j = (b2WeldJoint*)rc_joint[joint_id].joint;
			b2Vec2 anchor = j->GetLocalAnchorA();
			*x = anchor.x;
			*y = anchor.y;
		}
		break;

		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			b2Vec2 anchor = j->GetLocalAnchorA();
			*x = anchor.x;
			*y = anchor.y;
		}
		break;

	}
}

void rc_getJointLocalAnchorB(int joint_id, double* x, double* y)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_DISTANCE:
		{
			b2DistanceJoint* j = (b2DistanceJoint*)rc_joint[joint_id].joint;
			b2Vec2 anchor = j->GetLocalAnchorB();
			*x = anchor.x;
			*y = anchor.y;
		}
		break;

		case RC_JOINT_TYPE_FRICTION:
		{
			b2FrictionJoint* j = (b2FrictionJoint*)rc_joint[joint_id].joint;
			b2Vec2 anchor = j->GetLocalAnchorB();
			*x = anchor.x;
			*y = anchor.y;
		}
		break;

		case RC_JOINT_TYPE_PRISMATIC:
		{
			b2PrismaticJoint* j = (b2PrismaticJoint*)rc_joint[joint_id].joint;
			b2Vec2 anchor = j->GetLocalAnchorB();
			*x = anchor.x;
			*y = anchor.y;
		}
		break;

		case RC_JOINT_TYPE_REVOLUTE:
		{
			b2RevoluteJoint* j = (b2RevoluteJoint*)rc_joint[joint_id].joint;
			b2Vec2 anchor = j->GetLocalAnchorB();
			*x = anchor.x;
			*y = anchor.y;
		}
		break;

		case RC_JOINT_TYPE_WELD:
		{
			b2WeldJoint* j = (b2WeldJoint*)rc_joint[joint_id].joint;
			b2Vec2 anchor = j->GetLocalAnchorB();
			*x = anchor.x;
			*y = anchor.y;
		}
		break;

		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			b2Vec2 anchor = j->GetLocalAnchorB();
			*x = anchor.x;
			*y = anchor.y;
		}
		break;

	}
}

void rc_setJointLength(int joint_id, double jlen)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_DISTANCE:
			b2DistanceJoint* j = (b2DistanceJoint*)rc_joint[joint_id].joint;
			j->SetLength(jlen);
			break;
	}
}

double rc_getJointLength(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_DISTANCE:
			b2DistanceJoint* j = (b2DistanceJoint*)rc_joint[joint_id].joint;
			return j->GetLength();
	}

	return 0;
}

void rc_setJointMinLength(int joint_id, double jlen)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_DISTANCE:
			b2DistanceJoint* j = (b2DistanceJoint*)rc_joint[joint_id].joint;
			j->SetMinLength(jlen);
			break;
	}
}

double rc_getJointMinLength(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_DISTANCE:
			b2DistanceJoint* j = (b2DistanceJoint*)rc_joint[joint_id].joint;
			return j->GetMinLength();
	}

	return 0;
}

void rc_setJointMaxLength(int joint_id, double jlen)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_DISTANCE:
			b2DistanceJoint* j = (b2DistanceJoint*)rc_joint[joint_id].joint;
			j->SetMaxLength(jlen);
	}
}

double rc_getJointMaxLength(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_DISTANCE:
			b2DistanceJoint* j = (b2DistanceJoint*)rc_joint[joint_id].joint;
			return j->GetMaxLength();
	}

	return 0;
}

double rc_getJointCurrentLength(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_DISTANCE:
			b2DistanceJoint* j = (b2DistanceJoint*)rc_joint[joint_id].joint;
			return j->GetCurrentLength();
	}

	return 0;
}

void rc_setJointStiffness(int joint_id, double stiffness)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_DISTANCE:
		{
			b2DistanceJoint* j = (b2DistanceJoint*)rc_joint[joint_id].joint;
			j->SetStiffness(stiffness);
		}
		break;

		case RC_JOINT_TYPE_WELD:
		{
			b2WeldJoint* j = (b2WeldJoint*)rc_joint[joint_id].joint;
			j->SetStiffness(stiffness);
		}
		break;

		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			j->SetStiffness(stiffness);
		}
		break;
	}
}

double rc_getJointStiffness(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_DISTANCE:
		{
			b2DistanceJoint* j = (b2DistanceJoint*)rc_joint[joint_id].joint;
			return j->GetStiffness();
		}
		break;

		case RC_JOINT_TYPE_WELD:
		{
			b2WeldJoint* j = (b2WeldJoint*)rc_joint[joint_id].joint;
			return j->GetStiffness();
		}
		break;

		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			return j->GetStiffness();
		}
		break;
	}

	return 0;
}

void rc_setJointDamping(int joint_id, double damping)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_DISTANCE:
		{
			b2DistanceJoint* j = (b2DistanceJoint*)rc_joint[joint_id].joint;
			j->SetDamping(damping);
		}
		break;

		case RC_JOINT_TYPE_WELD:
		{
			b2WeldJoint* j = (b2WeldJoint*)rc_joint[joint_id].joint;
			j->SetDamping(damping);
		}
		break;

		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			j->SetDamping(damping);
		}
		break;
	}
}

double rc_getJointDamping(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_DISTANCE:
		{
			b2DistanceJoint* j = (b2DistanceJoint*)rc_joint[joint_id].joint;
			return j->GetDamping();
		}
		break;

		case RC_JOINT_TYPE_WELD:
		{
			b2WeldJoint* j = (b2WeldJoint*)rc_joint[joint_id].joint;
			return j->GetDamping();
		}
		break;

		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			return j->GetDamping();
		}
		break;
	}

	return 0;
}


void rc_setJointMaxForce(int joint_id, double force)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_FRICTION:
		{
			b2FrictionJoint* j = (b2FrictionJoint*)rc_joint[joint_id].joint;
			j->SetMaxForce(force);
		}
		break;

		case RC_JOINT_TYPE_MOTOR:
		{
			b2MotorJoint* j = (b2MotorJoint*)rc_joint[joint_id].joint;
			j->SetMaxForce(force);
		}
		break;
	}
}

double rc_getJointMaxForce(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_FRICTION:
		{
			b2FrictionJoint* j = (b2FrictionJoint*)rc_joint[joint_id].joint;
			return j->GetMaxForce();
		}
		break;

		case RC_JOINT_TYPE_MOTOR:
		{
			b2MotorJoint* j = (b2MotorJoint*)rc_joint[joint_id].joint;
			j->GetMaxForce();
		}
		break;
	}

	return 0;
}

void rc_setJointMaxTorque(int joint_id, double torque)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_FRICTION:
		{
			b2FrictionJoint* j = (b2FrictionJoint*)rc_joint[joint_id].joint;
			j->SetMaxTorque(torque);
		}
		break;

		case RC_JOINT_TYPE_MOTOR:
		{
			b2MotorJoint* j = (b2MotorJoint*)rc_joint[joint_id].joint;
			j->SetMaxTorque(torque);
		}
		break;
	}
}

double rc_getJointMaxTorque(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_FRICTION:
		{
			b2FrictionJoint* j = (b2FrictionJoint*)rc_joint[joint_id].joint;
			return j->GetMaxTorque();
		}
		break;

		case RC_JOINT_TYPE_MOTOR:
		{
			b2MotorJoint* j = (b2MotorJoint*)rc_joint[joint_id].joint;
			return j->GetMaxTorque();
		}
		break;
	}

	return 0;
}


void rc_setJointCorrectionFactor(int joint_id, double factor)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_MOTOR:
		{
			b2MotorJoint* j = (b2MotorJoint*)rc_joint[joint_id].joint;
			j->SetCorrectionFactor(factor);
		}
		break;
	}
}

double rc_getJointCorrectionFactor(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_MOTOR:
		{
			b2MotorJoint* j = (b2MotorJoint*)rc_joint[joint_id].joint;
			return j->GetCorrectionFactor();
		}
		break;
	}

	return 0;
}


void rc_setJointRatio(int joint_id, double j_ratio)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_GEAR:
		{
			b2GearJoint* j = (b2GearJoint*)rc_joint[joint_id].joint;
			j->SetRatio(j_ratio);
		}
		break;
	}
}

double rc_getJointRatio(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_GEAR:
		{
			b2GearJoint* j = (b2GearJoint*)rc_joint[joint_id].joint;
			return j->GetRatio();
		}
		break;

		case RC_JOINT_TYPE_PULLEY:
		{
			b2PulleyJoint* j = (b2PulleyJoint*)rc_joint[joint_id].joint;
			return j->GetRatio();
		}
		break;
	}

	return 0;
}


void rc_setJointLinearOffset(int joint_id, double x, double y)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_MOTOR:
		{
			b2MotorJoint* j = (b2MotorJoint*)rc_joint[joint_id].joint;
			j->SetLinearOffset(b2Vec2(x, y));
		}
		break;
	}
}

void rc_getJointLinearOffset(int joint_id, double* x, double* y)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_MOTOR:
		{
			b2MotorJoint* j = (b2MotorJoint*)rc_joint[joint_id].joint;
			b2Vec2 v = j->GetLinearOffset();
			*x = v.x;
			*y = v.y;
		}
		break;
	}
}

void rc_setJointAngularOffset(int joint_id, double angleOffset)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	angleOffset = rc_util_radians(angleOffset);

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_MOTOR:
		{
			b2MotorJoint* j = (b2MotorJoint*)rc_joint[joint_id].joint;
			j->SetAngularOffset(angleOffset);
		}
		break;
	}
}

double rc_getJointAngularOffset(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_MOTOR:
		{
			b2MotorJoint* j = (b2MotorJoint*)rc_joint[joint_id].joint;
			return rc_util_degrees(j->GetAngularOffset());
		}
		break;
	}

	return 0;
}


void rc_getJointLocalAxisA(int joint_id, double* x, double* y)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PRISMATIC:
		{
			b2PrismaticJoint* j = (b2PrismaticJoint*)rc_joint[joint_id].joint;
			b2Vec2 v = j->GetLocalAxisA();
			*x = v.x;
			*y = v.y;
		}
		break;

		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			b2Vec2 v = j->GetLocalAxisA();
			*x = v.x;
			*y = v.y;
		}
		break;

	}
}

double rc_getJointReferenceAngle(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PRISMATIC:
		{
			b2PrismaticJoint* j = (b2PrismaticJoint*)rc_joint[joint_id].joint;
			return rc_util_degrees(j->GetReferenceAngle());
		}
		break;

		case RC_JOINT_TYPE_REVOLUTE:
		{
			b2RevoluteJoint* j = (b2RevoluteJoint*)rc_joint[joint_id].joint;
			return rc_util_degrees(j->GetReferenceAngle());
		}
		break;

	}

	return 0;
}

double rc_getJointTranslation(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PRISMATIC:
		{
			b2PrismaticJoint* j = (b2PrismaticJoint*)rc_joint[joint_id].joint;
			return j->GetJointTranslation();
		}
		break;

		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			return j->GetJointTranslation();
		}
		break;

	}

	return 0;
}

double rc_getJointSpeed(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PRISMATIC:
		{
			b2PrismaticJoint* j = (b2PrismaticJoint*)rc_joint[joint_id].joint;
			return j->GetJointSpeed();
		}
		break;

		case RC_JOINT_TYPE_REVOLUTE:
		{
			b2RevoluteJoint* j = (b2RevoluteJoint*)rc_joint[joint_id].joint;
			return rc_util_degrees(j->GetJointSpeed());
		}
		break;

	}

	return 0;
}


bool rc_jointIsLimitEnabled(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return false;

	if(!rc_joint[joint_id].active)
		return false;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PRISMATIC:
		{
			b2PrismaticJoint* j = (b2PrismaticJoint*)rc_joint[joint_id].joint;
			return j->IsLimitEnabled();
		}
		break;

		case RC_JOINT_TYPE_REVOLUTE:
		{
			b2RevoluteJoint* j = (b2RevoluteJoint*)rc_joint[joint_id].joint;
			return j->IsLimitEnabled();
		}
		break;

		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			return j->IsLimitEnabled();
		}
		break;

	}

	return false;
}

void rc_enableJointLimit(int joint_id, bool flag)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PRISMATIC:
		{
			b2PrismaticJoint* j = (b2PrismaticJoint*)rc_joint[joint_id].joint;
			return j->EnableLimit(flag);
		}
		break;

		case RC_JOINT_TYPE_REVOLUTE:
		{
			b2RevoluteJoint* j = (b2RevoluteJoint*)rc_joint[joint_id].joint;
			return j->EnableLimit(flag);
		}
		break;

		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			return j->EnableLimit(flag);
		}
		break;

	}
}

double rc_getJointLowerLimit(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PRISMATIC:
		{
			b2PrismaticJoint* j = (b2PrismaticJoint*)rc_joint[joint_id].joint;
			return j->GetLowerLimit();
		}
		break;

		case RC_JOINT_TYPE_REVOLUTE:
		{
			b2RevoluteJoint* j = (b2RevoluteJoint*)rc_joint[joint_id].joint;
			return rc_util_degrees(j->GetLowerLimit());
		}
		break;

		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			return j->GetLowerLimit();
		}
		break;

	}

	return 0;
}

double rc_getJointUpperLimit(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PRISMATIC:
		{
			b2PrismaticJoint* j = (b2PrismaticJoint*)rc_joint[joint_id].joint;
			return j->GetUpperLimit();
		}
		break;

		case RC_JOINT_TYPE_REVOLUTE:
		{
			b2RevoluteJoint* j = (b2RevoluteJoint*)rc_joint[joint_id].joint;
			return rc_util_degrees(j->GetUpperLimit());
		}
		break;

		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			return j->GetUpperLimit();
		}
		break;

	}

	return 0;
}

void rc_setJointLimits(int joint_id, double lower_limit, double upper_limit)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PRISMATIC:
		{
			b2PrismaticJoint* j = (b2PrismaticJoint*)rc_joint[joint_id].joint;
			j->SetLimits(lower_limit, upper_limit);
		}
		break;

		case RC_JOINT_TYPE_REVOLUTE:
		{
			b2RevoluteJoint* j = (b2RevoluteJoint*)rc_joint[joint_id].joint;
			j->SetLimits(rc_util_radians(lower_limit), rc_util_radians(upper_limit));
		}
		break;

		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			j->SetLimits(lower_limit, upper_limit);
		}
		break;

	}
}

bool rc_jointMotorIsEnabled(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return false;

	if(!rc_joint[joint_id].active)
		return false;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PRISMATIC:
		{
			b2PrismaticJoint* j = (b2PrismaticJoint*)rc_joint[joint_id].joint;
			return j->IsMotorEnabled();
		}
		break;

		case RC_JOINT_TYPE_REVOLUTE:
		{
			b2RevoluteJoint* j = (b2RevoluteJoint*)rc_joint[joint_id].joint;
			return j->IsMotorEnabled();
		}
		break;

		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			return j->IsMotorEnabled();
		}
		break;

	}

	return false;
}

void rc_enableJointMotor(int joint_id, bool flag)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PRISMATIC:
		{
			b2PrismaticJoint* j = (b2PrismaticJoint*)rc_joint[joint_id].joint;
			j->EnableMotor(flag);
		}
		break;

		case RC_JOINT_TYPE_REVOLUTE:
		{
			b2RevoluteJoint* j = (b2RevoluteJoint*)rc_joint[joint_id].joint;
			j->EnableMotor(flag);
		}
		break;

		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			j->EnableMotor(flag);
		}
		break;

	}
}

void rc_setJointMotorSpeed(int joint_id, double speed)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PRISMATIC:
		{
			b2PrismaticJoint* j = (b2PrismaticJoint*)rc_joint[joint_id].joint;
			j->SetMotorSpeed(speed);
		}
		break;

		case RC_JOINT_TYPE_REVOLUTE:
		{
			b2RevoluteJoint* j = (b2RevoluteJoint*)rc_joint[joint_id].joint;
			j->SetMotorSpeed(rc_util_radians(speed));
		}
		break;

		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			j->SetMotorSpeed(rc_util_radians(speed));
		}
		break;

	}
}

double rc_getJointMotorSpeed(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PRISMATIC:
		{
			b2PrismaticJoint* j = (b2PrismaticJoint*)rc_joint[joint_id].joint;
			return j->GetMotorSpeed();
		}
		break;

		case RC_JOINT_TYPE_REVOLUTE:
		{
			b2RevoluteJoint* j = (b2RevoluteJoint*)rc_joint[joint_id].joint;
			return rc_util_degrees(j->GetMotorSpeed());
		}
		break;

		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			return rc_util_degrees(j->GetMotorSpeed());
		}
		break;

	}

	return 0;
}

void rc_setJointMaxMotorForce(int joint_id, double force)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PRISMATIC:
		{
			b2PrismaticJoint* j = (b2PrismaticJoint*)rc_joint[joint_id].joint;
			j->SetMaxMotorForce(force);
		}
		break;

	}
}

double rc_getJointMaxMotorForce(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PRISMATIC:
		{
			b2PrismaticJoint* j = (b2PrismaticJoint*)rc_joint[joint_id].joint;
			return j->GetMaxMotorForce();
		}
		break;

	}

	return 0;
}

double rc_getJointMotorForce(int joint_id, double inv_dt)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PRISMATIC:
		{
			b2PrismaticJoint* j = (b2PrismaticJoint*)rc_joint[joint_id].joint;
			return j->GetMotorForce(inv_dt);
		}
		break;

	}

	return 0;
}

void rc_setJointMaxMotorTorque(int joint_id, double torque)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_REVOLUTE:
		{
			b2RevoluteJoint* j = (b2RevoluteJoint*)rc_joint[joint_id].joint;
			j->SetMaxMotorTorque(torque);
		}
		break;

		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			j->SetMaxMotorTorque(torque);
		}
		break;

	}
}

double rc_getJointMaxMotorTorque(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_REVOLUTE:
		{
			b2RevoluteJoint* j = (b2RevoluteJoint*)rc_joint[joint_id].joint;
			return j->GetMaxMotorTorque();
		}
		break;

		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			return j->GetMaxMotorTorque();
		}
		break;

	}

	return 0;
}

double rc_getJointMotorTorque(int joint_id, double inv_dt)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_REVOLUTE:
		{
			b2RevoluteJoint* j = (b2RevoluteJoint*)rc_joint[joint_id].joint;
			return j->GetMotorTorque(inv_dt);
		}
		break;

		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			return j->GetMotorTorque(inv_dt);
		}
		break;

	}

	return 0;
}


void rc_getJointGroundAnchorA(int joint_id, double* x, double* y)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PULLEY:
		{
			b2PulleyJoint* j = (b2PulleyJoint*)rc_joint[joint_id].joint;
			b2Vec2 v = j->GetGroundAnchorA();
			*x = v.x;
			*y = v.y;
		}
		break;

	}

}

void rc_getJointGroundAnchorB(int joint_id, double* x, double* y)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PULLEY:
		{
			b2PulleyJoint* j = (b2PulleyJoint*)rc_joint[joint_id].joint;
			b2Vec2 v = j->GetGroundAnchorB();
			*x = v.x;
			*y = v.y;
		}
		break;

	}

}

double rc_getJointLengthA(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PULLEY:
		{
			b2PulleyJoint* j = (b2PulleyJoint*)rc_joint[joint_id].joint;
			return j->GetLengthA();
		}
		break;

	}

	return 0;
}

double rc_getJointLengthB(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PULLEY:
		{
			b2PulleyJoint* j = (b2PulleyJoint*)rc_joint[joint_id].joint;
			return j->GetLengthB();
		}
		break;

	}

	return 0;
}

double rc_getJointCurrentLengthA(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PULLEY:
		{
			b2PulleyJoint* j = (b2PulleyJoint*)rc_joint[joint_id].joint;
			return j->GetCurrentLengthA();
		}
		break;

	}

	return 0;
}

double rc_getJointCurrentLengthB(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PULLEY:
		{
			b2PulleyJoint* j = (b2PulleyJoint*)rc_joint[joint_id].joint;
			return j->GetCurrentLengthB();
		}
		break;

	}

	return 0;
}

void rc_setJointOrigin(int joint_id, double x, double y)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return;

	if(!rc_joint[joint_id].active)
		return;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_PULLEY:
		{
			b2PulleyJoint* j = (b2PulleyJoint*)rc_joint[joint_id].joint;
			j->ShiftOrigin(b2Vec2(x, y));
		}
		break;

	}

}

double rc_getJointAngle(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_REVOLUTE:
		{
			b2RevoluteJoint* j = (b2RevoluteJoint*)rc_joint[joint_id].joint;
			return rc_util_degrees(j->GetJointAngle());
		}
		break;

		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			return rc_util_degrees(j->GetJointAngle());
		}
		break;

	}

	return 0;
}

double rc_getJointLinearSpeed(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			return j->GetJointLinearSpeed();
		}
		break;

	}

	return 0;
}

double rc_getJointAngularSpeed(int joint_id)
{
	if(joint_id < 0 || joint_id >= rc_joint.size())
		return 0;

	if(!rc_joint[joint_id].active)
		return 0;

	switch(rc_joint[joint_id].type)
	{
		case RC_JOINT_TYPE_WHEEL:
		{
			b2WheelJoint* j = (b2WheelJoint*)rc_joint[joint_id].joint;
			return rc_util_degrees(j->GetJointAngularSpeed());
		}
		break;
	}

	return 0;
}

#endif // RC_JOINTS_H_INCLUDED
