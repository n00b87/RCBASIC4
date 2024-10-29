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
	if(rc_sprite[spr_id].deleted_sprites.size() > 0)
	{
		animation_id = rc_sprite[spr_id].deleted_sprites[0];
		rc_sprite[spr_id].deleted_sprites.erase(0);
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

	rc_sprite[spr_id].deleted_sprites.push_back(animation);
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

	for(int i = 0; i < rc_canvas[canvas_id].sprite.size(); i++)
	{
		rc_sprite2D_obj* spriteA = rc_canvas[canvas_id].sprite[i];

		for(int j = i+1; j < rc_canvas[canvas_id].sprite.size(); j++)
		{
			rc_sprite2D_obj* spriteB = rc_canvas[canvas_id].sprite[j];

			if(spriteB->z > spriteA->z)
			{
				rc_canvas[canvas_id].sprite[j] = NULL;
				rc_canvas[canvas_id].sprite.erase(j);
				rc_canvas[canvas_id].sprite.insert(spriteB, i);
			}
		}
	}
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
	sprBodyDef.position.Set(0, 0);
	sprBodyDef.angle = 0;
	sprBodyDef.userData.pointer = (uintptr_t)&rc_sprite[spr_id];
	rc_sprite[spr_id].physics.body = rc_canvas[rc_active_canvas].physics2D.world->CreateBody(&sprBodyDef);

	b2FixtureDef sprFixtureDef;
	rc_sprite[spr_id].physics.shape = new b2PolygonShape();
	b2PolygonShape* fix_shape = (b2PolygonShape*)rc_sprite[spr_id].physics.shape;
	fix_shape->SetAsBox(w/2, h/2);
	sprFixtureDef.shape = rc_sprite[spr_id].physics.shape;
	sprFixtureDef.isSensor = true;
	sprFixtureDef.density = 1;
	rc_sprite[spr_id].physics.fixture = rc_sprite[spr_id].physics.body->CreateFixture(&sprFixtureDef);

	rc_sprite[spr_id].physics.offset_x = 0;
	rc_sprite[spr_id].physics.offset_y = 0;
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

	rc_canvas[rc_active_canvas].sprite.push_back(&rc_sprite[spr_id]);

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

	rc_sprite[spr_id].active = false;
	rc_sprite[spr_id].parent_canvas = -1;
	rc_sprite[spr_id].animation.clear();

	for(int i = 0; i < rc_canvas[rc_active_canvas].sprite.size(); i++)
	{
		rc_sprite2D_obj* canvas_sprite = rc_canvas[rc_active_canvas].sprite[i];
		rc_sprite2D_obj* global_sprite = &rc_sprite[spr_id];
		if(canvas_sprite == global_sprite)
		{
			rc_canvas[rc_active_canvas].sprite.erase(i);
			break;
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
	rc_sprite[spr_id].physics.body->SetTransform(b2Vec2(x, y), current_angle);
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

	*x = (double)rc_sprite[spr_id].physics.body->GetPosition().x;
	*y = (double)rc_sprite[spr_id].physics.body->GetPosition().y;
}

double rc_spriteX(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

	return (double)rc_sprite[spr_id].physics.body->GetPosition().x;
}

double rc_spriteY(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

	return (double)rc_sprite[spr_id].physics.body->GetPosition().y;
}

void rc_setSpriteRotation(int spr_id, double angle)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	rc_sprite[spr_id].physics.body->SetTransform(rc_sprite[spr_id].physics.body->GetPosition(), angle);
}

void rc_rotateSprite(int spr_id, double angle)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	float new_angle = rc_sprite[spr_id].physics.body->GetAngle() + angle;
	rc_sprite[spr_id].physics.body->SetTransform(rc_sprite[spr_id].physics.body->GetPosition(), new_angle);
}

double rc_getSpriteRotation(int spr_id)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return 0;

	if(!rc_sprite[spr_id].active)
		return 0;

	return rc_sprite[spr_id].physics.body->GetAngle();
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
					shape->m_radius = (x+y)/2;
				}
				break;

				case b2Shape::e_polygon:
				{
					b2PolygonShape* shape = (b2PolygonShape*)fixdef.shape;
					for(int i = 0; i < shape->m_count; i++)
					{
						shape->m_vertices[i].x *= x;
						shape->m_vertices[i].y *= y;
					}
				}
				break;

				case b2Shape::e_chain:
				{
					b2ChainShape* shape = (b2ChainShape*)fixdef.shape;
					for(int i = 0; i < shape->m_count; i++)
					{
						shape->m_vertices[i].x *= x;
						shape->m_vertices[i].y *= y;
					}
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
			rc_sprite[spr_id].physics.fixture = rc_sprite[spr_id].physics.body->CreateFixture(&fixdef);
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

	if(rc_sprite[spr_id].image_id)
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



//-----------------------------------PHYSICS----------------------------------------------------------------------------------



//This function is called on each canvas on update
void drawSprites(int canvas_id)
{
	float step = rc_canvas[canvas_id].physics2D.timeStep;
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

	for(int spr_index = 0; spr_index < rc_canvas[canvas_id].sprite.size(); spr_index++)
	{
		rc_sprite2D_obj* sprite = rc_canvas[canvas_id].sprite[spr_index];
		if(!sprite->visible)
			continue;

		physics_pos = sprite->physics.body->GetPosition();
		x = (int)physics_pos.x - offset_x;
		y = (int)physics_pos.y - offset_y;

		int xf = x + sprite->frame_size.Width;
		int yf = y + sprite->frame_size.Height;

		//std::cout << "sprite info: " << xf << ", " << x << ", " << rc_canvas[canvas_id].viewport.dimension.Width << std::endl;

		if( (xf < 0) || (x > ((int)rc_canvas[canvas_id].viewport.dimension.Width)) )
		{
			//std::cout << "skip draw[X]: " << spr_index << std::endl;
			continue;
		}

		if( (yf < 0) || (y > ((int)rc_canvas[canvas_id].viewport.dimension.Height)) )
		{
			//std::cout << "skip draw[Y]: " << spr_index << std::endl;
			continue;
		}

		position.set(x, y);

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


		rotationPoint.set(x + (src_size.Width/2), y + (src_size.Height/2)); //TODO: need to account for offset once that is implemented
		rotation = -1 * (sprite->physics.body->GetAngle() * RAD_TO_DEG); //convert Box2D radians to degrees

		scale.set(sprite->scale.X, sprite->scale.Y);

		color.set(sprite->alpha,
							 sprite->color_mod.getRed(),
							 sprite->color_mod.getGreen(),
							 sprite->color_mod.getBlue());

		//I don't want to draw an image that doesn't exists. Thats just crazy.
		draw2DImage(VideoDriver, rc_image[img_id].image, sourceRect, position, rotationPoint, rotation, scale, useAlphaChannel, color, screenSize);
	}
	//Must set back to canvas 0 (the backbuffer) before returning

	VideoDriver->setRenderTarget(rc_canvas[0].texture, false, false);
}

//NOTE TO TBIRD
// 1. Each sprite has a Box2D body.  You can look in "rc_sprite2D.h" to see how a sprite is structured.
// 2. A box2D world is setup for each canvas. So a sprite will be attached to the canvas thats active when its created. When that canvas is destroyed, so is the sprite.
// 3. By default, I have the sprite.physics_enabled attribute set to false. I feel like it makes sense to have a user intentionally enable physics since a user may not want physics for every sprite.
// 4. The sprite.visible attribute only determines whether to draw the sprite. The physics simulation will still happen each frame unless physics are disabled.
// 5. Don't change the value of sprite.active. Its used to check whether a sprite exists or not. I have an array of sprites in rc_sprite2D.h and if the active attribute is set to false, I reuse that slot to create a new sprite. If there is no inactive sprites in the array then I add a new sprite index to the array.
// 6. The time step, velocity Iterations, and position iterations are part of the canvas.physics2D attribute. You will need to make functions to allow the user to change those.
// 7. If you want to modify how sprites are rendered then you can just change the drawSprites() function above these notes.

//-----------------------------END OF SPRITE STUFF------------------------------------------------------------------------------

#endif // RC_SPRITELIB_H_INCLUDED
