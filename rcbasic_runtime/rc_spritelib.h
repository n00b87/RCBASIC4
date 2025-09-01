#ifndef RC_SPRITELIB_H_INCLUDED
#define RC_SPRITELIB_H_INCLUDED

#ifdef RC_ANDROID
	#include "SDL.h"
#else
	#include <SDL2/SDL.h>
#endif // _IRR_ANDROID_PLATFORM_

#include "rc_sprite2D.h"
#include "rc_gfx_core.h"

#include "rc_sprite_physics.h"
#include "rc_joints.h"

#define RC_SPRITE_BASE_ANIMATION 0

int rc_createSpriteAnimation(int spr_id, int anim_length, double fps)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return -1;

	if(!rc_sprite[spr_id].active)
		return -1;

	if(anim_length <= 0)
		anim_length = 1;

	rc_sprite2D_animation_obj animation;
	animation.current_frame = 0;
	animation.fps = fps;
	animation.frame_swap_time = 1000/fps;
	animation.num_frames = anim_length;
	for(int i = 0; i < anim_length; i++)
		animation.frames.push_back(0);

	int animation_id = rc_sprite[spr_id].animation.size();
	if(rc_sprite[spr_id].deleted_animation.size() > 0)
	{
		animation_id = rc_sprite[spr_id].deleted_animation[0];
		rc_sprite[spr_id].deleted_animation.erase(0);
		rc_sprite[spr_id].animation[animation_id] = animation;
	}
	else
		rc_sprite[spr_id].animation.push_back(animation);

	return animation_id;
}

void rc_deleteSpriteAnimation(int spr_id, int animation)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	for(int i = 0; i < rc_sprite[spr_id].deleted_animation.size(); i++)
	{
		if(rc_sprite[spr_id].deleted_animation[i] == animation)
			return;
	}

	rc_sprite[spr_id].deleted_animation.push_back(animation);
}

void rc_setSpriteFrame(int spr_id, int frame)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	if(frame < 0 || frame >= rc_sprite[spr_id].sheet_numFrames)
		return;

	rc_sprite[spr_id].current_animation = RC_SPRITE_BASE_ANIMATION;
	rc_sprite[spr_id].animation[RC_SPRITE_BASE_ANIMATION].current_frame = 0;
	rc_sprite[spr_id].animation[RC_SPRITE_BASE_ANIMATION].frames[0] = frame;
}

int rc_getSpriteFrame(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return -1;

	if(!rc_sprite[spr_id].active)
		return -1;

	int current_animation = rc_sprite[spr_id].current_animation;
	int current_frame = rc_sprite[spr_id].animation[current_animation].current_frame;
	return rc_sprite[spr_id].animation[current_animation].frames[current_frame];
}

void rc_setSpriteAnimationFrame(int spr_id, int spr_animation, int anim_frame, int frame)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	if(anim_frame < 0 || anim_frame >= rc_sprite[spr_id].animation[spr_animation].num_frames)
		return;

	if(frame < 0 || frame >= rc_sprite[spr_id].sheet_numFrames)
		return;

	rc_sprite[spr_id].animation[spr_animation].frames[anim_frame] = frame;
}

int rc_getSpriteAnimationFrame(int spr_id, int spr_animation, int anim_frame)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return -1;

	if(!rc_sprite[spr_id].active)
		return -1;

	if(anim_frame < 0 || anim_frame >= rc_sprite[spr_id].animation[spr_animation].num_frames)
		return -1;

	return rc_sprite[spr_id].animation[spr_animation].frames[anim_frame];
}


void rc_setSpriteAnimationLength(int spr_id, int animation, int num_frames)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	// I intentionally checked for less than or equal to 0 because 0 is the base animation and should not be changed
	if(animation <= 0 || animation >= rc_sprite[spr_id].animation.size())
		return;

	if(num_frames <= 0)
		num_frames = 1;

	if(num_frames > rc_sprite[spr_id].animation[animation].num_frames)
	{
		for(int i = rc_sprite[spr_id].animation[animation].num_frames; i < rc_sprite[spr_id].animation[animation].frames.size(); i++)
			rc_sprite[spr_id].animation[animation].frames[i] = 0;
	}

	rc_sprite[spr_id].animation[animation].num_frames = num_frames;
	if(num_frames > rc_sprite[spr_id].animation[animation].frames.size())
	{
		while(num_frames > rc_sprite[spr_id].animation[animation].frames.size())
			rc_sprite[spr_id].animation[animation].frames.push_back(0);
	}

	if(num_frames < rc_sprite[spr_id].animation[animation].frames.size())
	{
		if(rc_sprite[spr_id].animation[animation].current_frame >= num_frames)
			rc_sprite[spr_id].animation[animation].current_frame = num_frames - 1;
	}
}

int rc_getSpriteAnimationLength(int spr_id, int animation)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

	if(animation < 0 || animation >= rc_sprite[spr_id].animation.size())
		return 0;

	return rc_sprite[spr_id].animation[animation].num_frames;
}

void rc_setSpriteAnimationSpeed(int spr_id, int animation, double fps)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	if(animation < 0 || animation >= rc_sprite[spr_id].animation.size())
		return;

	rc_sprite[spr_id].animation[animation].fps = fps;
	rc_sprite[spr_id].animation[animation].frame_swap_time = 1000/fps;
}

double rc_getSpriteAnimationSpeed(int spr_id, int animation)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

	if(animation < 0 || animation >= rc_sprite[spr_id].animation.size())
		return 0;

	return rc_sprite[spr_id].animation[animation].fps;
}

void rc_setSpriteAnimation(int spr_id, int animation, int num_loops)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	if(animation < 0 || animation >= rc_sprite[spr_id].animation.size())
		return;

	rc_sprite[spr_id].current_animation = animation;
	rc_sprite[spr_id].animation[animation].current_frame = 0;
	rc_sprite[spr_id].isPlaying = true;
	rc_sprite[spr_id].animation[animation].frame_start_time = SDL_GetTicks();
	rc_sprite[spr_id].num_animation_loops = num_loops;
}

int rc_getSpriteAnimation(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return -1;

	if(!rc_sprite[spr_id].active)
		return -1;

	return rc_sprite[spr_id].current_animation;
}

int rc_getSpriteCurrentAnimationFrame(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return -1;

	if(!rc_sprite[spr_id].active)
		return -1;

	int current_animation = rc_sprite[spr_id].current_animation;
	return rc_sprite[spr_id].animation[current_animation].current_frame;
}

void rc_setSpriteAnimationLoops(int spr_id, int num_loops)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	rc_sprite[spr_id].num_animation_loops = num_loops;
}

int rc_numSpriteAnimationLoops(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

	return rc_sprite[spr_id].num_animation_loops;
}

bool rc_spriteAnimationIsPlaying(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return false;

	if(!rc_sprite[spr_id].active)
		return false;

	return rc_sprite[spr_id].isPlaying;
}

//------------------------------SPRITES-------------------------------------------------------
//Larger z gets drawn first
void sortSpriteZ(int canvas_id)
{
	if(canvas_id < 0 || canvas_id >= rc_canvas.size())
		return;

	if(!rc_canvas[canvas_id].texture)
		return;

	for(int i = 0; i < rc_canvas[canvas_id].sprite_id.size(); i++)
	{
		int spriteA = rc_canvas[canvas_id].sprite_id[i];

		for(int j = i+1; j < rc_canvas[canvas_id].sprite_id.size(); j++)
		{
			int spriteB = rc_canvas[canvas_id].sprite_id[j];

			if(rc_sprite[spriteB].z > rc_sprite[spriteA].z)
			{
				rc_canvas[canvas_id].sprite_id.erase(j);
				rc_canvas[canvas_id].sprite_id.insert(spriteB, i);
			}
		}
	}
}

bool rc_spriteExists(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return false;

	return rc_sprite[spr_id].active;
}

int rc_createSprite(int img_id, double w, double h)
{
	if(rc_active_canvas < 0 || rc_active_canvas >= rc_canvas.size())
		return -1;

	if(rc_canvas[rc_active_canvas].type != RC_CANVAS_TYPE_SPRITE)
		return -1;

	//std::cout << "debug 1" << std::endl;

	int spr_id = -1;
	for(int i = 0; i < rc_sprite.size(); i++)
	{
		if(!rc_sprite[i].active)
		{
			spr_id = i;
			break;
		}
	}

	if(spr_id < 0)
	{
		spr_id = rc_sprite.size();
		rc_sprite2D_obj sprite;
		rc_sprite.push_back(sprite);
	}

	rc_sprite[spr_id].active = true;
	rc_sprite[spr_id].id = spr_id;
	rc_sprite[spr_id].image_id = img_id;
	rc_sprite[spr_id].frame_size.set(w, h);

	if(img_id >= 0 && img_id < rc_image.size())
	{
		if(rc_image[img_id].image)
		{
			int img_w = rc_image[img_id].image->getSize().Width;
			int img_h = rc_image[img_id].image->getSize().Height;

			rc_sprite[spr_id].frames_per_row = (int)(img_w / w);
			rc_sprite[spr_id].sheet_numFrames = ((int)(img_h / h)) * rc_sprite[spr_id].frames_per_row;
		}
		else
			rc_sprite[spr_id].image_id = -1;
	}
	else
		rc_sprite[spr_id].image_id = -1;

	b2BodyDef sprBodyDef;
	sprBodyDef.type = b2_dynamicBody;
	sprBodyDef.position.Set(w/2, h/2);
	sprBodyDef.angle = 0;
	sprBodyDef.userData.pointer = spr_id;
	rc_sprite[spr_id].physics.body = rc_canvas[rc_active_canvas].physics2D.world->CreateBody(&sprBodyDef);

	b2FixtureDef sprFixtureDef;
	rc_sprite[spr_id].physics.shape = new b2PolygonShape();
	b2PolygonShape* fix_shape = (b2PolygonShape*)rc_sprite[spr_id].physics.shape;
	fix_shape->SetAsBox(w/2, h/2);
	rc_sprite[spr_id].physics.shape_type = RC_SPRITE_SHAPE_BOX;
	rc_sprite[spr_id].physics.box_width = w;
	rc_sprite[spr_id].physics.box_height = h;
	sprFixtureDef.shape = rc_sprite[spr_id].physics.shape;
	sprFixtureDef.isSensor = true;
	sprFixtureDef.density = 1;
	rc_sprite[spr_id].physics.fixture = rc_sprite[spr_id].physics.body->CreateFixture(&sprFixtureDef);

	rc_sprite[spr_id].physics.body->SetTransform(b2Vec2(w/2, h/2), 0);


	rc_sprite[spr_id].physics.base_offset_x = w/2;
	rc_sprite[spr_id].physics.base_offset_y = h/2;
	rc_sprite[spr_id].physics.base_user_offset_x = 0;
	rc_sprite[spr_id].physics.base_user_offset_y = 0;

	rc_sprite[spr_id].physics.offset_x = w/2;
	rc_sprite[spr_id].physics.offset_y = h/2;
	rc_sprite[spr_id].physics.user_offset_x = 0;
	rc_sprite[spr_id].physics.user_offset_y = 0;

	rc_sprite[spr_id].isSolid = false;

	if(rc_sprite[spr_id].image_id < 0)
		rc_sprite[spr_id].visible =false;
	else
		rc_sprite[spr_id].visible = true;

	rc_sprite[spr_id].scale.set(1.0, 1.0);
	rc_sprite[spr_id].alpha = 255;
	rc_sprite[spr_id].z = 0;
	rc_sprite[spr_id].color_mod.set(255,255,255,255);
	rc_sprite[spr_id].parent_canvas = rc_active_canvas;

	rc_sprite[spr_id].current_animation = RC_SPRITE_BASE_ANIMATION;
	rc_sprite[spr_id].num_animation_loops = 0;
	rc_sprite[spr_id].current_animation_loop = 0;
	rc_sprite[spr_id].isPlaying = false;
	rc_sprite[spr_id].animation.clear();
	rc_createSpriteAnimation(spr_id, 1, 0);

	int i = rc_canvas[rc_active_canvas].sprite_id.size();
	rc_canvas[rc_active_canvas].sprite_id.push_back(spr_id);

	//std::cout << "Create Debug: [" << rc_active_canvas << "]   index = " << i << "   spr_id = " << rc_canvas[rc_active_canvas].sprite[i]->id << std::endl;

	sortSpriteZ(rc_active_canvas);

	return spr_id;
}

void rc_deleteSprite(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(rc_sprite[spr_id].physics.body)
	{
		if(rc_sprite[spr_id].parent_canvas >= 0 && rc_sprite[spr_id].parent_canvas < rc_canvas.size())
		{
			if(rc_canvas[rc_sprite[spr_id].parent_canvas].physics2D.world)
				rc_canvas[rc_sprite[spr_id].parent_canvas].physics2D.world->DestroyBody(rc_sprite[spr_id].physics.body);
		}
		rc_sprite[spr_id].physics.body = NULL;
	}

	int parent_canvas = rc_sprite[spr_id].parent_canvas;

	rc_sprite[spr_id].active = false;
	rc_sprite[spr_id].parent_canvas = -1;
	rc_sprite[spr_id].animation.clear();

	//std::cout << "DEBUG: Clear " << spr_id << " From " << parent_canvas << std::endl;

	if(parent_canvas >= 0 && parent_canvas < rc_canvas.size())
	{
		for(int i = 0; i < rc_canvas[parent_canvas].sprite_id.size(); i++)
		{
			int canvas_sprite = rc_canvas[parent_canvas].sprite_id[i];

			if(canvas_sprite == spr_id)
			{
				//std::cout << "Erase: " << i << std::endl;
				rc_canvas[parent_canvas].sprite_id.erase(i);
				break;
			}
		}
	}
}

void rc_setSpriteSource(int spr_id, int img_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	if(img_id < 0)
	{
		rc_sprite[spr_id].image_id = -1;
		return;
	}

	if(img_id >= rc_image.size())
		return;

	if(!rc_image[img_id].image)
		return;

	rc_sprite[spr_id].image_id = img_id;
}

int rc_getSpriteSource(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return -1;

	if(!rc_sprite[spr_id].active)
		return -1;

	return rc_sprite[spr_id].image_id;
}

void rc_setSpriteCollisionShape(int spr_id, int sprite_shape)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	//Delete Shape
	bool isSensor = rc_sprite[spr_id].physics.fixture->IsSensor();
	float density = rc_sprite[spr_id].physics.fixture->GetDensity();

	float actual_x = rc_sprite[spr_id].physics.body->GetPosition().x - (rc_sprite[spr_id].physics.offset_x + rc_sprite[spr_id].physics.user_offset_x);
	float actual_y = rc_sprite[spr_id].physics.body->GetPosition().y - (rc_sprite[spr_id].physics.offset_y + rc_sprite[spr_id].physics.user_offset_y);

	if(rc_sprite[spr_id].physics.shape)
		delete rc_sprite[spr_id].physics.shape;

	rc_sprite[spr_id].physics.shape = NULL;

	//Delete Fixture
	if(rc_sprite[spr_id].physics.fixture)
		rc_sprite[spr_id].physics.body->DestroyFixture(rc_sprite[spr_id].physics.fixture);

	rc_sprite[spr_id].physics.fixture = NULL;


	b2FixtureDef sprFixtureDef;

	switch(sprite_shape)
	{
		case RC_SPRITE_SHAPE_BOX:
		{
			rc_sprite[spr_id].physics.shape = new b2PolygonShape();
			b2PolygonShape* fix_shape = (b2PolygonShape*)rc_sprite[spr_id].physics.shape;
			fix_shape->SetAsBox(rc_sprite[spr_id].frame_size.Width/2, rc_sprite[spr_id].frame_size.Height/2);
			rc_sprite[spr_id].physics.box_width = rc_sprite[spr_id].frame_size.Width;
			rc_sprite[spr_id].physics.box_height = rc_sprite[spr_id].frame_size.Height;

			rc_sprite[spr_id].physics.base_offset_x = rc_sprite[spr_id].physics.box_width/2;
			rc_sprite[spr_id].physics.base_offset_y = rc_sprite[spr_id].physics.box_height/2;

			rc_sprite[spr_id].physics.offset_x = rc_sprite[spr_id].physics.box_width/2;
			rc_sprite[spr_id].physics.offset_y = rc_sprite[spr_id].physics.box_height/2;

			sprFixtureDef.shape = rc_sprite[spr_id].physics.shape;
			sprFixtureDef.isSensor = isSensor;
			sprFixtureDef.density = density;
			rc_sprite[spr_id].physics.fixture = rc_sprite[spr_id].physics.body->CreateFixture(&sprFixtureDef);
			rc_sprite[spr_id].physics.shape_type = RC_SPRITE_SHAPE_BOX;

			float center_x = actual_x + (rc_sprite[spr_id].physics.offset_x + rc_sprite[spr_id].physics.user_offset_x);
			float center_y = actual_y + (rc_sprite[spr_id].physics.offset_y + rc_sprite[spr_id].physics.user_offset_y);
			rc_sprite[spr_id].physics.body->SetTransform(b2Vec2(center_x, center_y), rc_sprite[spr_id].physics.body->GetAngle());
		}
		break;

		case RC_SPRITE_SHAPE_POLYGON:
		{
			rc_sprite[spr_id].physics.shape = new b2PolygonShape();
			b2PolygonShape* fix_shape = (b2PolygonShape*)rc_sprite[spr_id].physics.shape;
			fix_shape->SetAsBox(rc_sprite[spr_id].frame_size.Width/2, rc_sprite[spr_id].frame_size.Width/2);
			rc_sprite[spr_id].physics.box_width = rc_sprite[spr_id].frame_size.Width;
			rc_sprite[spr_id].physics.box_height = rc_sprite[spr_id].frame_size.Height;

			rc_sprite[spr_id].physics.base_offset_x = rc_sprite[spr_id].physics.box_width/2;
			rc_sprite[spr_id].physics.base_offset_y = rc_sprite[spr_id].physics.box_height/2;

			rc_sprite[spr_id].physics.offset_x = rc_sprite[spr_id].physics.box_width/2;
			rc_sprite[spr_id].physics.offset_y = rc_sprite[spr_id].physics.box_height/2;

			sprFixtureDef.shape = rc_sprite[spr_id].physics.shape;
			sprFixtureDef.isSensor = isSensor;
			sprFixtureDef.density = density;
			rc_sprite[spr_id].physics.fixture = rc_sprite[spr_id].physics.body->CreateFixture(&sprFixtureDef);
			rc_sprite[spr_id].physics.shape_type = RC_SPRITE_SHAPE_POLYGON;

			rc_sprite[spr_id].physics.base_user_offset_x = 0;
			rc_sprite[spr_id].physics.base_user_offset_y = 0;

			rc_sprite[spr_id].physics.user_offset_x = 0;
			rc_sprite[spr_id].physics.user_offset_y = 0;

			float center_x = actual_x + (rc_sprite[spr_id].physics.offset_x + rc_sprite[spr_id].physics.user_offset_x);
			float center_y = actual_y + (rc_sprite[spr_id].physics.offset_y + rc_sprite[spr_id].physics.user_offset_y);
			rc_sprite[spr_id].physics.body->SetTransform(b2Vec2(center_x, center_y), rc_sprite[spr_id].physics.body->GetAngle());
		}
		break;

		case RC_SPRITE_SHAPE_CIRCLE:
		{
			rc_sprite[spr_id].physics.shape = new b2CircleShape();
			b2CircleShape* fix_shape = (b2CircleShape*)rc_sprite[spr_id].physics.shape;
			float new_radius = (rc_sprite[spr_id].frame_size.Width + rc_sprite[spr_id].frame_size.Height)/4;
			fix_shape->m_radius = new_radius * (rc_sprite[spr_id].scale.X + rc_sprite[spr_id].scale.Y)/2;
			sprFixtureDef.shape = rc_sprite[spr_id].physics.shape;
			sprFixtureDef.isSensor = isSensor;
			sprFixtureDef.density = density;
			rc_sprite[spr_id].physics.radius = new_radius; //only storing what the sprite is as scale 1

			rc_sprite[spr_id].physics.base_offset_x = rc_sprite[spr_id].frame_size.Width/2;
			rc_sprite[spr_id].physics.base_offset_y = rc_sprite[spr_id].frame_size.Height/2;

			rc_sprite[spr_id].physics.offset_x = rc_sprite[spr_id].frame_size.Width/2;
			rc_sprite[spr_id].physics.offset_y = rc_sprite[spr_id].frame_size.Height/2;

			rc_sprite[spr_id].physics.fixture = rc_sprite[spr_id].physics.body->CreateFixture(&sprFixtureDef);
			rc_sprite[spr_id].physics.shape_type = RC_SPRITE_SHAPE_CIRCLE;

			float center_x = actual_x + (rc_sprite[spr_id].physics.offset_x + rc_sprite[spr_id].physics.user_offset_x);
			float center_y = actual_y + (rc_sprite[spr_id].physics.offset_y + rc_sprite[spr_id].physics.user_offset_y);
			rc_sprite[spr_id].physics.body->SetTransform(b2Vec2(center_x, center_y), rc_sprite[spr_id].physics.body->GetAngle());
		}
		break;

		case RC_SPRITE_SHAPE_CHAIN:
		{
			rc_sprite[spr_id].physics.shape = new b2ChainShape();
			b2ChainShape* fix_shape = (b2ChainShape*)rc_sprite[spr_id].physics.shape;
			b2Vec2 v[3];
			v[0].Set(0, 0);
			v[1].Set(1, 1);
			v[2].Set(2, 2);
			fix_shape->Clear();
			fix_shape->CreateLoop(v, 3);
			float new_radius = (rc_sprite[spr_id].frame_size.Width + rc_sprite[spr_id].frame_size.Height)/4;
			fix_shape->m_radius = new_radius * ((rc_sprite[spr_id].scale.X + rc_sprite[spr_id].scale.Y)/2);
			sprFixtureDef.shape = rc_sprite[spr_id].physics.shape;
			sprFixtureDef.isSensor = isSensor;
			sprFixtureDef.density = density;
			rc_sprite[spr_id].physics.fixture = rc_sprite[spr_id].physics.body->CreateFixture(&sprFixtureDef);
			rc_sprite[spr_id].physics.shape_type = RC_SPRITE_SHAPE_CHAIN;

			rc_sprite[spr_id].physics.base_user_offset_x = 0;
			rc_sprite[spr_id].physics.base_user_offset_y = 0;
			rc_sprite[spr_id].physics.user_offset_x = 0;
			rc_sprite[spr_id].physics.user_offset_y = 0;
		}
		break;
	}
}

int rc_getSpriteCollisionShape(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

	return rc_sprite[spr_id].physics.shape_type;
}

void rc_setSpriteRadius(int spr_id, double radius)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	if(rc_sprite[spr_id].physics.shape_type == RC_SPRITE_SHAPE_CIRCLE)
	{
		bool isSensor = rc_sprite[spr_id].physics.fixture->IsSensor();
		float density = rc_sprite[spr_id].physics.fixture->GetDensity();

		//Delete Fixture
		if(rc_sprite[spr_id].physics.fixture)
			rc_sprite[spr_id].physics.body->DestroyFixture(rc_sprite[spr_id].physics.fixture);

		rc_sprite[spr_id].physics.fixture = NULL;

		rc_sprite[spr_id].physics.radius = radius / ((rc_sprite[spr_id].scale.X + rc_sprite[spr_id].scale.Y)/2); //calculate what it would be at scale 1

		b2FixtureDef sprFixtureDef;

		b2CircleShape* fix_shape = (b2CircleShape*)rc_sprite[spr_id].physics.shape;
		fix_shape->m_radius = (float)radius;
		sprFixtureDef.shape = rc_sprite[spr_id].physics.shape;
		sprFixtureDef.isSensor = isSensor;
		sprFixtureDef.density = density;
		rc_sprite[spr_id].physics.fixture = rc_sprite[spr_id].physics.body->CreateFixture(&sprFixtureDef);

		//NOTE: Changing the radius doesn't move its position so a new transform is not necessary
	}
}

double rc_getSpriteRadius(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

	if(rc_sprite[spr_id].physics.shape_type == RC_SPRITE_SHAPE_CIRCLE)
	{
		b2CircleShape* fix_shape = (b2CircleShape*)rc_sprite[spr_id].physics.shape;
		return (double)fix_shape->m_radius;
	}

	return 0;
}

void rc_setSpriteBox(int spr_id, int w, int h)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	if(rc_sprite[spr_id].physics.shape_type == RC_SPRITE_SHAPE_BOX)
	{
		bool isSensor = rc_sprite[spr_id].physics.fixture->IsSensor();
		float density = rc_sprite[spr_id].physics.fixture->GetDensity();

		b2Vec2 pos = rc_sprite[spr_id].physics.body->GetPosition();

		float bx = pos.x - (rc_sprite[spr_id].physics.offset_x + rc_sprite[spr_id].physics.user_offset_x);
		float by = pos.y - (rc_sprite[spr_id].physics.offset_y + rc_sprite[spr_id].physics.user_offset_y);

		//Delete Fixture
		if(rc_sprite[spr_id].physics.fixture)
			rc_sprite[spr_id].physics.body->DestroyFixture(rc_sprite[spr_id].physics.fixture);

		rc_sprite[spr_id].physics.fixture = NULL;


		b2FixtureDef sprFixtureDef;

		b2PolygonShape* fix_shape = (b2PolygonShape*)rc_sprite[spr_id].physics.shape;
		fix_shape->SetAsBox(w/2, h/2);

		rc_sprite[spr_id].physics.vertices.clear();
		for(int i = 0; i < fix_shape->m_count; i++)
		{
			rc_sprite[spr_id].physics.vertices.push_back(fix_shape->m_vertices[i]);
		}

		rc_sprite[spr_id].physics.box_width = w;
		rc_sprite[spr_id].physics.box_height = h;

		rc_sprite[spr_id].physics.base_offset_x = w/2;
		rc_sprite[spr_id].physics.base_offset_y = h/2;

		rc_sprite[spr_id].physics.offset_x = w/2;
		rc_sprite[spr_id].physics.offset_y = h/2;

		sprFixtureDef.shape = rc_sprite[spr_id].physics.shape;
		sprFixtureDef.isSensor = isSensor;
		sprFixtureDef.density = density;
		rc_sprite[spr_id].physics.fixture = rc_sprite[spr_id].physics.body->CreateFixture(&sprFixtureDef);

		float off_x = rc_sprite[spr_id].physics.offset_x + rc_sprite[spr_id].physics.user_offset_x;
		float off_y = rc_sprite[spr_id].physics.offset_y + rc_sprite[spr_id].physics.user_offset_y;

		//rc_setSpritePosition(spr_id, bx, by);
		//std::cout << "Box At: " << bx << ", " << by << std::endl;
		rc_sprite[spr_id].physics.body->SetTransform(b2Vec2(bx + off_x, by + off_y), rc_sprite[spr_id].physics.body->GetAngle());
	}
}

void rc_getSpriteBoxSize(int spr_id, double* w, double* h)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	*w = -1;
	*h = -1;

	if(rc_sprite[spr_id].physics.shape_type == RC_SPRITE_SHAPE_BOX)
	{
		*w = (double)rc_sprite[spr_id].physics.box_width;
		*h = (double)rc_sprite[spr_id].physics.box_height;
	}
}


void rc_setSpriteChain(int spr_id, double* vx, double* vy, int v_count, double prev_x, double prev_y, double next_x, double next_y)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	if(rc_sprite[spr_id].physics.shape_type == RC_SPRITE_SHAPE_CHAIN)
	{
		bool isSensor = rc_sprite[spr_id].physics.fixture->IsSensor();
		float density = rc_sprite[spr_id].physics.fixture->GetDensity();

		b2Vec2 pos = rc_sprite[spr_id].physics.body->GetPosition();

		float bx = pos.x - (rc_sprite[spr_id].physics.offset_x + rc_sprite[spr_id].physics.user_offset_x);
		float by = pos.y - (rc_sprite[spr_id].physics.offset_y + rc_sprite[spr_id].physics.user_offset_y);

		//Delete Fixture
		if(rc_sprite[spr_id].physics.fixture)
			rc_sprite[spr_id].physics.body->DestroyFixture(rc_sprite[spr_id].physics.fixture);

		rc_sprite[spr_id].physics.fixture = NULL;


		b2FixtureDef sprFixtureDef;

		b2ChainShape* fix_shape = (b2ChainShape*)rc_sprite[spr_id].physics.shape;
		fix_shape->Clear();

		b2Vec2 vert[v_count+1];

		rc_sprite[spr_id].physics.vertices.clear();

		float cx = 0;
		float cy = 0;

		for(int i = 0; i < v_count; i++)
		{
			vert[i] = b2Vec2((float)vx[i], (float)vy[i]);
			cx += vx[i];
			cy += vy[i];
		}

		cx = cx / v_count;
		cy = cy / v_count;

		for(int i = 0; i < v_count; i++)
		{
			vert[i] -= b2Vec2(cx, cy);
			rc_sprite[spr_id].physics.vertices.push_back(vert[i]);
		}

		b2Vec2 prev_vert((float)prev_x-cx, (float)prev_y-cy);
		b2Vec2 next_vert((float)next_x-cx, (float)next_y-cy);

		rc_sprite[spr_id].physics.prev_vertex = prev_vert;
		rc_sprite[spr_id].physics.next_vertex = next_vert;

		fix_shape->CreateChain(vert, v_count, prev_vert, next_vert);

		sprFixtureDef.shape = rc_sprite[spr_id].physics.shape;
		sprFixtureDef.isSensor = isSensor;
		sprFixtureDef.density = density;
		rc_sprite[spr_id].physics.fixture = rc_sprite[spr_id].physics.body->CreateFixture(&sprFixtureDef);


		rc_sprite[spr_id].physics.base_offset_x = cx;
		rc_sprite[spr_id].physics.base_offset_y = cy;

		rc_sprite[spr_id].physics.offset_x = cx;
		rc_sprite[spr_id].physics.offset_y = cy;

		float off_x = rc_sprite[spr_id].physics.offset_x;
		float off_y = rc_sprite[spr_id].physics.offset_y;

		//rc_setSpritePosition(spr_id, bx, by);
		//std::cout << "Box At: " << bx << ", " << by << std::endl;
		rc_sprite[spr_id].physics.body->SetTransform(b2Vec2(bx + off_x, by + off_y), rc_sprite[spr_id].physics.body->GetAngle());
	}
}

void rc_setSpriteChainLoop(int spr_id, double* vx, double* vy, int v_count)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	if(rc_sprite[spr_id].physics.shape_type == RC_SPRITE_SHAPE_CHAIN)
	{
		bool isSensor = rc_sprite[spr_id].physics.fixture->IsSensor();
		float density = rc_sprite[spr_id].physics.fixture->GetDensity();

		b2Vec2 pos = rc_sprite[spr_id].physics.body->GetPosition();

		float bx = pos.x - (rc_sprite[spr_id].physics.offset_x + rc_sprite[spr_id].physics.user_offset_x);
		float by = pos.y - (rc_sprite[spr_id].physics.offset_y + rc_sprite[spr_id].physics.user_offset_y);

		//Delete Fixture
		if(rc_sprite[spr_id].physics.fixture)
			rc_sprite[spr_id].physics.body->DestroyFixture(rc_sprite[spr_id].physics.fixture);

		rc_sprite[spr_id].physics.fixture = NULL;


		b2FixtureDef sprFixtureDef;

		b2ChainShape* fix_shape = (b2ChainShape*)rc_sprite[spr_id].physics.shape;
		fix_shape->Clear();

		b2Vec2 vert[v_count];

		rc_sprite[spr_id].physics.vertices.clear();

		float cx = 0;
		float cy = 0;

		for(int i = 0; i < v_count; i++)
		{
			vert[i] = b2Vec2((float)vx[i], (float)vy[i]);
			cx += vx[i];
			cy += vy[i];
		}

		cx = cx / v_count;
		cy = cy / v_count;

		for(int i = 0; i < v_count; i++)
		{
			vert[i] -= b2Vec2(cx, cy);
			rc_sprite[spr_id].physics.vertices.push_back(vert[i]);
		}

		fix_shape->CreateLoop(vert, v_count);

		sprFixtureDef.shape = rc_sprite[spr_id].physics.shape;
		sprFixtureDef.isSensor = isSensor;
		sprFixtureDef.density = density;
		rc_sprite[spr_id].physics.fixture = rc_sprite[spr_id].physics.body->CreateFixture(&sprFixtureDef);


		rc_sprite[spr_id].physics.base_offset_x = cx;
		rc_sprite[spr_id].physics.base_offset_y = cy;

		rc_sprite[spr_id].physics.offset_x = cx;
		rc_sprite[spr_id].physics.offset_y = cy;

		float off_x = rc_sprite[spr_id].physics.offset_x;
		float off_y = rc_sprite[spr_id].physics.offset_y;

		//rc_setSpritePosition(spr_id, bx, by);
		//std::cout << "Box At: " << bx << ", " << by << std::endl;
		rc_sprite[spr_id].physics.body->SetTransform(b2Vec2(bx + off_x, by + off_y), rc_sprite[spr_id].physics.body->GetAngle());
	}
}

void rc_setSpritePolygon(int spr_id, double* vx, double* vy, int v_count)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	if(v_count < 3)
		return; // A convex hull must have atleast 3 points

	if(rc_sprite[spr_id].physics.shape_type == RC_SPRITE_SHAPE_POLYGON)
	{
		bool isSensor = rc_sprite[spr_id].physics.fixture->IsSensor();
		float density = rc_sprite[spr_id].physics.fixture->GetDensity();

		b2Vec2 pos = rc_sprite[spr_id].physics.body->GetPosition();

		float bx = pos.x - (rc_sprite[spr_id].physics.offset_x + rc_sprite[spr_id].physics.user_offset_x);
		float by = pos.y - (rc_sprite[spr_id].physics.offset_y + rc_sprite[spr_id].physics.user_offset_y);

		//Delete Fixture
		if(rc_sprite[spr_id].physics.fixture)
			rc_sprite[spr_id].physics.body->DestroyFixture(rc_sprite[spr_id].physics.fixture);

		rc_sprite[spr_id].physics.fixture = NULL;


		b2FixtureDef sprFixtureDef;

		b2PolygonShape* fix_shape = (b2PolygonShape*)rc_sprite[spr_id].physics.shape;

		b2Vec2 vert[v_count];

		rc_sprite[spr_id].physics.vertices.clear();

		float cx = 0;
		float cy = 0;

		for(int i = 0; i < v_count; i++)
		{
			vert[i] = b2Vec2((float)vx[i], (float)vy[i]);
			cx += vx[i];
			cy += vy[i];
		}

		cx = cx / v_count;
		cy = cy / v_count;

		for(int i = 0; i < v_count; i++)
		{
			vert[i] -= b2Vec2(cx, cy);
			rc_sprite[spr_id].physics.vertices.push_back(vert[i]);
		}

		fix_shape->Set(vert, v_count);
		//fix_shape->m_centroid = b2Vec2(cx/v_count, cy/v_count);

		sprFixtureDef.shape = rc_sprite[spr_id].physics.shape;
		sprFixtureDef.isSensor = isSensor;
		sprFixtureDef.density = density;
		rc_sprite[spr_id].physics.fixture = rc_sprite[spr_id].physics.body->CreateFixture(&sprFixtureDef);

		rc_sprite[spr_id].physics.base_offset_x = cx;
		rc_sprite[spr_id].physics.base_offset_y = cy;

		rc_sprite[spr_id].physics.offset_x = cx;
		rc_sprite[spr_id].physics.offset_y = cy;

		float off_x = rc_sprite[spr_id].physics.offset_x;
		float off_y = rc_sprite[spr_id].physics.offset_y;

		//rc_setSpritePosition(spr_id, bx, by);
		//std::cout << "Box At: " << bx << ", " << by << std::endl;
		rc_sprite[spr_id].physics.body->SetTransform(b2Vec2(bx + off_x, by + off_y), rc_sprite[spr_id].physics.body->GetAngle());
	}
}

void rc_setSpriteShapeOffset(int spr_id, int offset_x, int offset_y)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	int old_offset_x = rc_sprite[spr_id].physics.user_offset_x;
	int old_offset_y = rc_sprite[spr_id].physics.user_offset_y;

	rc_sprite[spr_id].physics.base_user_offset_x = offset_x;
	rc_sprite[spr_id].physics.base_user_offset_y = offset_y;

	rc_sprite[spr_id].physics.user_offset_x = offset_x;
	rc_sprite[spr_id].physics.user_offset_y = offset_y;

	float current_angle = rc_sprite[spr_id].physics.body->GetAngle();

	double off_x = rc_sprite[spr_id].physics.user_offset_x;
	double off_y = rc_sprite[spr_id].physics.user_offset_y;

	switch(rc_sprite[spr_id].physics.shape_type)
	{
		case RC_SPRITE_SHAPE_BOX:
		{
			off_x += rc_sprite[spr_id].physics.box_width/2;
			off_y += rc_sprite[spr_id].physics.box_height/2;
		}
		break;

		case RC_SPRITE_SHAPE_CIRCLE:
		{
			off_x += rc_sprite[spr_id].physics.shape->m_radius;
			off_y += rc_sprite[spr_id].physics.shape->m_radius;
		}
		break;

		default:
		{
			//POLYGON AND CHAIN SHAPES KEEP THE SAME OFFSETS
			off_x = 0;
			off_y = 0;
		}
	}

	double x = rc_sprite[spr_id].physics.body->GetPosition().x - (old_offset_x + rc_sprite[spr_id].physics.offset_x);
	double y = rc_sprite[spr_id].physics.body->GetPosition().y - (old_offset_y + rc_sprite[spr_id].physics.offset_y);

	rc_sprite[spr_id].physics.body->SetTransform(b2Vec2(x+off_x, y+off_y), current_angle);
}

void rc_getSpriteShapeOffset(int spr_id, double* offset_x, double* offset_y)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	*offset_x = (double)rc_sprite[spr_id].physics.user_offset_x;
	*offset_y = (double)rc_sprite[spr_id].physics.user_offset_y;
}

void rc_setSpriteType(int spr_id, int body_type)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	rc_sprite[spr_id].physics.body->SetType((b2BodyType) body_type);
}

int rc_getSpriteType(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return -1;

	if(!rc_sprite[spr_id].active)
		return -1;

	return (int)rc_sprite[spr_id].physics.body->GetType();
}

void rc_setSpriteSolid(int spr_id, bool flag)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	rc_sprite[spr_id].isSolid = flag;
	rc_sprite[spr_id].physics.fixture->SetSensor(!flag);
}

bool rc_spriteIsSolid(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return false;

	if(!rc_sprite[spr_id].active)
		return false;

	return rc_sprite[spr_id].isSolid;
}

void rc_setSpritePosition(int spr_id, double x, double y)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	float current_angle = rc_sprite[spr_id].physics.body->GetAngle();
	double off_x = rc_sprite[spr_id].physics.offset_x;
	double off_y = rc_sprite[spr_id].physics.offset_y;

	off_x += rc_sprite[spr_id].physics.user_offset_x;
	off_y += rc_sprite[spr_id].physics.user_offset_y;

	rc_sprite[spr_id].physics.body->SetTransform(b2Vec2(x+off_x, y+off_y), current_angle);
}

void rc_translateSprite(int spr_id, double x, double y)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	float current_angle = rc_sprite[spr_id].physics.body->GetAngle();
	double spr_x = rc_sprite[spr_id].physics.body->GetPosition().x + x;
	double spr_y = rc_sprite[spr_id].physics.body->GetPosition().y + y;
	rc_sprite[spr_id].physics.body->SetTransform(b2Vec2(spr_x, spr_y), current_angle);
}

void rc_getSpritePosition(int spr_id, double* x, double* y)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	double off_x = rc_sprite[spr_id].physics.offset_x;
	double off_y = rc_sprite[spr_id].physics.offset_y;

	off_x += rc_sprite[spr_id].physics.user_offset_x;
	off_y += rc_sprite[spr_id].physics.user_offset_y;

	*x = (double)rc_sprite[spr_id].physics.body->GetPosition().x - off_x;
	*y = (double)rc_sprite[spr_id].physics.body->GetPosition().y - off_y;
}

double rc_spriteX(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

	double off_x = rc_sprite[spr_id].physics.offset_x;
	off_x += rc_sprite[spr_id].physics.user_offset_x;

	return (double)rc_sprite[spr_id].physics.body->GetPosition().x - off_x;
}

double rc_spriteY(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

	double off_y = rc_sprite[spr_id].physics.offset_y;
	off_y += rc_sprite[spr_id].physics.user_offset_y;

	return (double)rc_sprite[spr_id].physics.body->GetPosition().y - off_y;
}

void rc_setSpriteRotation(int spr_id, double angle)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	//convert angle to radians
	angle = rc_util_radians(angle);

	rc_sprite[spr_id].physics.body->SetTransform(rc_sprite[spr_id].physics.body->GetPosition(), angle);
}

void rc_rotateSprite(int spr_id, double angle)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	//convert angle to radians
	angle = rc_util_radians(angle);

	float new_angle = rc_sprite[spr_id].physics.body->GetAngle() + angle;

	rc_sprite[spr_id].physics.body->SetTransform(rc_sprite[spr_id].physics.body->GetPosition(), new_angle);
}

double rc_getSpriteRotation(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

	return rc_util_degrees(rc_sprite[spr_id].physics.body->GetAngle());
}

void rc_setSpriteScale(int spr_id, double x, double y)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	rc_sprite[spr_id].scale.set(x, y);

	if(true) //(rc_sprite[spr_id].isSolid) //I probably originally planned on not having a fixture for non-solid sprites but then I discovered sensors
	{
		if(rc_sprite[spr_id].physics.fixture)
		{
			b2FixtureDef fixdef;
			fixdef.density = rc_sprite[spr_id].physics.fixture->GetDensity();
			fixdef.friction = rc_sprite[spr_id].physics.fixture->GetFriction();
			fixdef.restitution = rc_sprite[spr_id].physics.fixture->GetRestitution();
			fixdef.restitutionThreshold = rc_sprite[spr_id].physics.fixture->GetRestitutionThreshold();
			fixdef.shape = rc_sprite[spr_id].physics.shape;
			fixdef.isSensor = !(rc_sprite[spr_id].isSolid);

			switch(fixdef.shape->GetType())
			{
				case b2Shape::e_circle:
				{
					b2CircleShape* shape = (b2CircleShape*)fixdef.shape;
					shape->m_radius = rc_sprite[spr_id].physics.radius * ((x+y)/2);

				}
				break;

				case b2Shape::e_polygon:
				{
					b2PolygonShape* shape = (b2PolygonShape*)fixdef.shape;
					if(rc_sprite[spr_id].physics.vertices.size() < shape->m_count)
					{
						for(int i = rc_sprite[spr_id].physics.vertices.size(); i < shape->m_count; i++)
						{
							//std::cout << "Add vec2" << std::endl;
							rc_sprite[spr_id].physics.vertices.push_back(shape->m_vertices[i]);
						}
					}

					b2Vec2 vert[shape->m_count];
					for(int i = 0; i < shape->m_count; i++)
					{
						vert[i].x = rc_sprite[spr_id].physics.vertices[i].x * x;
						vert[i].y = rc_sprite[spr_id].physics.vertices[i].y * y;

						//std::cout << "SV: " << shape->m_vertices[i].x << ", " << shape->m_vertices[i].y << std::endl;
					}
					shape->Set(vert, shape->m_count);

				}
				break;

				case b2Shape::e_chain:
				{
					b2ChainShape* shape = (b2ChainShape*)fixdef.shape;
					if(rc_sprite[spr_id].physics.vertices.size() < shape->m_count)
					{
						while(rc_sprite[spr_id].physics.vertices.size() < shape->m_count)
						{
							rc_sprite[spr_id].physics.vertices.push_back(b2Vec2(0,0));
						}
					}

					b2Vec2 vert[shape->m_count];
					for(int i = 0; i < shape->m_count; i++)
					{
						vert[i].x = rc_sprite[spr_id].physics.vertices[i].x * x;
						vert[i].y = rc_sprite[spr_id].physics.vertices[i].y * y;

						//std::cout << "SV: " << shape->m_vertices[i].x << ", " << shape->m_vertices[i].y << std::endl;
					}

					b2Vec2 prev_vert(rc_sprite[spr_id].physics.prev_vertex.x * x, rc_sprite[spr_id].physics.prev_vertex.y * y);
					b2Vec2 next_vert(rc_sprite[spr_id].physics.next_vertex.x * x, rc_sprite[spr_id].physics.next_vertex.y * y);

					shape->CreateChain(vert, shape->m_count, prev_vert, next_vert);
				}
				break;

				case b2Shape::e_edge:
				{
					b2EdgeShape* shape = (b2EdgeShape*)fixdef.shape;

					shape->m_vertex0.x *= x;
					shape->m_vertex0.y *= y;

					shape->m_vertex1.x *= x;
					shape->m_vertex1.y *= y;

					shape->m_vertex2.x *= x;
					shape->m_vertex2.y *= y;

					shape->m_vertex3.x *= x;
					shape->m_vertex3.y *= y;
				}
				break;
			}

			rc_sprite[spr_id].physics.body->DestroyFixture(rc_sprite[spr_id].physics.fixture);

			//std::cout << "Make magic happen: " << spr_id << std::endl;
			rc_sprite[spr_id].physics.fixture = rc_sprite[spr_id].physics.body->CreateFixture(&fixdef);





			b2Vec2 old_offset = b2Vec2(rc_sprite[spr_id].physics.offset_x, rc_sprite[spr_id].physics.offset_y) + b2Vec2(rc_sprite[spr_id].physics.user_offset_x, rc_sprite[spr_id].physics.user_offset_y);
			b2Vec2 pos = rc_sprite[spr_id].physics.body->GetPosition() - old_offset;

			/*
			if(spr_id == 1)
			{
				std::cout << "dbg1: " << pos.x << ", " << pos.y << " -- " << rc_sprite[spr_id].physics.offset_x << ", " << rc_sprite[spr_id].physics.offset_y << std::endl;

				std::cout << "dbg2: " << rc_sprite[spr_id].physics.base_offset_x << ", " << rc_sprite[spr_id].physics.base_offset_y << std::endl;
			}
			*/

			rc_sprite[spr_id].physics.user_offset_x = rc_sprite[spr_id].physics.base_user_offset_x * x;
			rc_sprite[spr_id].physics.user_offset_y = rc_sprite[spr_id].physics.base_user_offset_y * y;

			rc_sprite[spr_id].physics.offset_x = rc_sprite[spr_id].physics.base_offset_x * x;
			rc_sprite[spr_id].physics.offset_y = rc_sprite[spr_id].physics.base_offset_y * y;

			b2Vec2 new_offset = b2Vec2(rc_sprite[spr_id].physics.offset_x, rc_sprite[spr_id].physics.offset_y) + b2Vec2(rc_sprite[spr_id].physics.user_offset_x, rc_sprite[spr_id].physics.user_offset_y);

			pos += new_offset;

			rc_sprite[spr_id].physics.body->SetTransform(pos, rc_sprite[spr_id].physics.body->GetAngle());
			//std::cout << "Done" << std::endl;
		}
	}
}

void rc_scaleSprite(int spr_id, double x, double y)
{
	double scale_x = rc_sprite[spr_id].scale.X * x;
	double scale_y = rc_sprite[spr_id].scale.Y * y;
	rc_setSpriteScale(spr_id, scale_x, scale_y);
}


void rc_getSpriteScale(int spr_id, double* x, double* y)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	*x = rc_sprite[spr_id].scale.X;
	*y = rc_sprite[spr_id].scale.Y;
}

double rc_spriteWidth(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

	return rc_sprite[spr_id].frame_size.Width;
}

double rc_spriteHeight(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

	return rc_sprite[spr_id].frame_size.Height;
}

void rc_getSpriteSize(int spr_id, double* w, double* h)
{
	*w = 0;
	*h = 0;

	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	*w = rc_sprite[spr_id].frame_size.Width;
	*h = rc_sprite[spr_id].frame_size.Height;
}

void rc_setSpriteZ(int spr_id, double z)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	rc_sprite[spr_id].z = z;
	sortSpriteZ(rc_sprite[spr_id].parent_canvas);
}

double rc_spriteZ(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

	return rc_sprite[spr_id].z;
}

void rc_setSpriteVisible(int spr_id, bool flag)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	if(rc_sprite[spr_id].image_id >= 0)
		rc_sprite[spr_id].visible = flag;
	else
		rc_sprite[spr_id].visible = false;
}

bool rc_spriteIsVisible(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return false;

	if(!rc_sprite[spr_id].active)
		return false;

	return rc_sprite[spr_id].visible;
}

void rc_setSpriteColorMod(int spr_id, Uint32 color)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	if(rc_sprite[spr_id].image_id >= 0)
		rc_sprite[spr_id].color_mod = irr::video::SColor(color);
}

void rc_setSpriteAlpha(int spr_id, Uint32 alpha)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	if(rc_sprite[spr_id].image_id >= 0)
		rc_sprite[spr_id].alpha = (Uint8)alpha;
}

Uint32 rc_getSpriteColorMod(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

	return rc_sprite[spr_id].color_mod.color;
}

Uint32 rc_getSpriteAlpha(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

	return (Uint32)rc_sprite[spr_id].alpha;
}

//-----------------------------------PHYSICS----------------------------------------------------------------------------------



//This function is called on each canvas on update
void drawSprites(int canvas_id)
{
    rc_setDriverMaterial_B(rc_canvas[canvas_id].spriteCanvasProperties.blend_mode,
                           rc_canvas[canvas_id].spriteCanvasProperties.anti_alias,
                           rc_canvas[canvas_id].spriteCanvasProperties.bilinear_filter);

	Uint32 delta_time = SDL_GetTicks() - rc_canvas[canvas_id].physics2D.time_stamp;
	rc_canvas[canvas_id].physics2D.time_stamp = SDL_GetTicks();
	float step = rc_canvas[canvas_id].physics2D.timeStep < 0 ? (delta_time*0.001f) : rc_canvas[canvas_id].physics2D.timeStep;
	int32 velocityIterations = rc_canvas[canvas_id].physics2D.velocityIterations;
	int32 positionIterations = rc_canvas[canvas_id].physics2D.positionIterations;

	if(rc_canvas[canvas_id].physics2D.enabled && (!hasPreUpdated))
		rc_canvas[canvas_id].physics2D.world->Step(step, velocityIterations, positionIterations);

	//Setting the render target to the current canvas.  NOTE: I might change this target to a separate sprite layer later.
	VideoDriver->setRenderTarget(rc_canvas[canvas_id].texture, true, true);
	VideoDriver->clearBuffers(true, true, true, irr::video::SColor(0,0,0,0));


	irr::core::dimension2d<irr::u32> src_size;
	irr::core::rect<irr::s32> sourceRect;

	irr::core::position2d<irr::s32> position;

	irr::core::position2d<irr::s32> rotationPoint;

	irr::f32 rotation = 0;
	irr::core::vector2df scale(1.0, 1.0);
	bool useAlphaChannel = true;
	irr::video::SColor color;

	//irr::core::rect<irr::s32> dest( irr::core::vector2d(x, y), irr::core::dimension2d(src_w, src_h));;

	irr::core::vector2df screenSize(rc_canvas[canvas_id].dimension.Width, rc_canvas[canvas_id].dimension.Height);

	int x = 0;
	int y = 0;

	b2Vec2 physics_pos;

	irr::f32 RAD_TO_DEG = 180.0/3.141592653589793238463;

	double spr_timer = SDL_GetTicks();

	int offset_x = rc_canvas[canvas_id].offset.X;
	int offset_y = rc_canvas[canvas_id].offset.Y;

	for(int spr_index = 0; spr_index < rc_canvas[canvas_id].sprite_id.size(); spr_index++)
	{
		int spr_id = rc_canvas[canvas_id].sprite_id[spr_index];
		rc_sprite2D_obj* sprite = &rc_sprite[spr_id];
		//std::cout << "debug info: " << canvas_id << " --> " << spr_index << "   id = " << sprite->id << "   anim_size = " << sprite->animation.size() << std::endl; continue;
		//if(!sprite->visible)
		//	continue;

		physics_pos = sprite->physics.body->GetPosition();
		x = (int)(physics_pos.x - sprite->physics.offset_x) - offset_x;
		y = (int)(physics_pos.y - sprite->physics.offset_y) - offset_y;

		if(rc_sprite[spr_id].physics.shape_type == RC_SPRITE_SHAPE_POLYGON)
		{
			b2PolygonShape* shape = (b2PolygonShape*)sprite->physics.shape;
			x = (int)(sprite->physics.body->GetWorldCenter().x - sprite->physics.offset_x - offset_x);
			y = (int)(sprite->physics.body->GetWorldCenter().y - sprite->physics.offset_y - offset_y);
		}

		int frame_offset_x =  sprite->physics.user_offset_x;
		int frame_offset_y =  sprite->physics.user_offset_y;

		/*
		if(spr_id == 1)
		{
			b2Vec2 tform = sprite->physics.body->GetWorldCenter();


			std::cout << "SPRITE: " << spr_id << " (" << tform.x << ", " << tform.y << ") " << std::endl;
			if(sprite->physics.shape_type == RC_SPRITE_SHAPE_CIRCLE)
			{
				//b2CircleShape* cshape = (b2CircleShape*) sprite->physics.body->GetFixtureList()[0].GetShape();
				std::cout << "offset: " << frame_offset_x << ", " << frame_offset_y << std::endl;
				std::cout << "debug: " << "pbody = (" << physics_pos.x << ", " << physics_pos.y << ")  radius = " << sprite->physics.body->GetFixtureList()->GetShape()->m_radius << std::endl;
				std::cout << "calc: calc_pos (" << x << ", " << y << ")  p_offset = (" << offset_x << ", " << offset_y << ") " << std::endl << std::endl;
				std::cout << "-----------------" << std::endl;

			}
			else
			{
				//b2CircleShape* cshape = (b2CircleShape*) sprite->physics.body->GetFixtureList()[0].GetShape();
				std::cout << "offset: " << frame_offset_x << ", " << frame_offset_y << std::endl;
				std::cout << "debug: " << "pbody = (" << physics_pos.x << ", " << physics_pos.y << ") " << sprite->physics.box_width << " x " << sprite->physics.box_height << std::endl;
				std::cout << "calc: calc_pos (" << x << ", " << y << ")  canvas_offset = (" << offset_x << ", " << offset_y << ") " << std::endl << std::endl;
				std::cout << "-----------------" << std::endl;
			}

		}
		*/

		//if(!sprite->visible)
		//	continue;

		int radius = sprite->frame_size.Width;
		if(sprite->frame_size.Height > radius)
			radius = sprite->frame_size.Height;

		radius += 1;

		float max_scale = sprite->scale.X;
		if(sprite->scale.Y > max_scale)
			max_scale = sprite->scale.Y;

		radius = (radius * max_scale) + 1;

		int xf = x + radius;
		int yf = y + radius;

		//std::cout << "sprite info[" << spr_index << "]: (" << x << ", " << y << ") (" << xf << ", " << yf << ")" << std::endl;

		position.set(x-frame_offset_x, y-frame_offset_y);
		//position.set(x, y);

		if( (xf < 0) || ((position.X - radius) > ((int)rc_canvas[canvas_id].viewport.dimension.Width)) )
		{
			//std::cout << "skip draw[X]: " << spr_index << std::endl;
			continue;
		}

		if( (yf < 0) || ((position.Y-radius) > ((int)rc_canvas[canvas_id].viewport.dimension.Height)) )
		{
			//std::cout << "skip draw[Y]: " << spr_index << std::endl;
			continue;
		}

		int img_id = sprite->image_id;
		if(img_id < 0 || img_id >= rc_image.size())
			continue;

		//src_size = rc_image[img_id].image->getSize();
		int current_animation = sprite->current_animation;
		if((spr_timer - sprite->animation[current_animation].frame_start_time) >= sprite->animation[current_animation].frame_swap_time)
		{
			sprite->animation[current_animation].current_frame++;

			if(sprite->animation[current_animation].current_frame >= sprite->animation[current_animation].num_frames)
			{
				sprite->animation[current_animation].current_frame = 0;
				sprite->current_animation_loop++;

				if(sprite->current_animation_loop >= sprite->num_animation_loops)
				{
					if(sprite->num_animation_loops < 0)
						sprite->isPlaying = true;
					else
						sprite->isPlaying = false;
					sprite->current_animation_loop = 0;
				}
			}

			if(!sprite->isPlaying)
				sprite->animation[current_animation].current_frame = 0;

			sprite->animation[current_animation].frame_start_time = spr_timer;
		}

		int current_animation_frame = sprite->animation[current_animation].current_frame;

		int frame_x = (int)(sprite->animation[current_animation].frames[current_animation_frame]%sprite->frames_per_row)*sprite->frame_size.Width;
		int frame_y = (int)(sprite->animation[current_animation].frames[current_animation_frame]/sprite->frames_per_row)*sprite->frame_size.Height;
		irr::core::vector2d<irr::s32> frame_pos(frame_x, frame_y);
		src_size = sprite->frame_size;
		sourceRect = irr::core::rect<irr::s32>( frame_pos, src_size);
		//sourceRect = irr::core::rect<irr::s32>( irr::core::vector2d<irr::s32>(0, 0), src_size);

		//physics_pos = sprite->physics.body->GetPosition();
		//x = (int)physics_pos.x;
		//y = (int)physics_pos.y;
		//position.set(x, y);


		scale.set(sprite->scale.X, sprite->scale.Y);

		rotationPoint.set(x + (src_size.Width/2)*scale.X - sprite->physics.user_offset_x, y + (src_size.Height/2)*scale.Y - sprite->physics.user_offset_y); //TODO: need to account for offset once that is implemented
		rotation = -1 * (sprite->physics.body->GetAngle() * RAD_TO_DEG); //convert Box2D radians to degrees

		color.set(sprite->alpha,
							 sprite->color_mod.getRed(),
							 sprite->color_mod.getGreen(),
							 sprite->color_mod.getBlue());

		//I don't want to draw an image that doesn't exists. Thats just crazy.
		draw2DImage(VideoDriver, rc_image[img_id].image, sourceRect, position, rotationPoint, rotation, scale, useAlphaChannel, color, screenSize);
	}
	//Must set back to canvas 0 (the backbuffer) before returning

	VideoDriver->setRenderTarget(rc_canvas[0].texture, false, false);
	rc_setDriverMaterial();
}

//-----------------------------END OF SPRITE STUFF------------------------------------------------------------------------------

#endif // RC_SPRITELIB_H_INCLUDED
