#ifndef RC_SPRITE2D_H_INCLUDED
#define RC_SPRITE2D_H_INCLUDED

#include <irrlicht.h>
#include <box2d/box2d.h>

struct rc_sprite2D_physics_obj
{
	b2Body* body;
};

struct rc_sprite2D_obj
{
	bool active = false;
	int image_id;
	irr::core::vector2d<irr::f64> position;
	irr::f64 rotation;
	irr::core::vector2d<irr::f64> scale;

	bool visible = true;
	Uint8 alpha;

	irr::video::SColor color_mod;

	bool physics_enabled = false;
	rc_sprite2D_physics_obj physics;

	int parent_canvas = -1;

	double z;
};

irr::core::array<rc_sprite2D_obj> rc_sprite;


#endif // RC_SPRITE2D_H_INCLUDED
