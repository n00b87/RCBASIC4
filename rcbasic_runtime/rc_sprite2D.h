#ifndef RC_SPRITE2D_H_INCLUDED
#define RC_SPRITE2D_H_INCLUDED

#include <irrlicht.h>
#include <box2d/box2d.h>

struct rc_sprite2D_physics_obj
{
	b2Body* body;
	b2Fixture* fixture;
	b2Shape* shape;

	int offset_x;
	int offset_y;
};

struct rc_sprite2D_animation_obj
{
	irr::core::array<int> frames;

	int num_frames;

	int current_frame;

	double fps;
	double frame_start_time;
	double frame_swap_time;
};

struct rc_sprite2D_obj
{
	int id; //This is needed to reference this sprite in the contact listener
	bool active = false;
	int image_id;
	int sheet_numFrames;
	int frames_per_row;

	irr::core::vector2d<irr::f64> scale;

	irr::core::dimension2d<irr::f64> frame_size;

	bool visible = true;
	Uint8 alpha;

	irr::video::SColor color_mod;

	bool isSolid = false;
	rc_sprite2D_physics_obj physics;

	int current_animation;
	int num_animation_loops;
	int current_animation_loop;
	bool isPlaying;
	irr::core::array<rc_sprite2D_animation_obj> animation;

	int parent_canvas = -1;

	double z;
};

irr::core::array<rc_sprite2D_obj> rc_sprite;


#endif // RC_SPRITE2D_H_INCLUDED
