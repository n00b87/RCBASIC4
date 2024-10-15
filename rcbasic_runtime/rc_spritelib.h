#ifndef RC_SPRITELIB_H_INCLUDED
#define RC_SPRITELIB_H_INCLUDED

#include "rc_sprite2D.h"
#include "rc_gfx_core.h"

//------------------------------SPRITES-------------------------------------------------------
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
	rc_sprite[spr_id].image_id = img_id;

	b2BodyDef sprBodyDef;
	sprBodyDef.type = b2_staticBody;
	sprBodyDef.position.Set(0, 0);
	sprBodyDef.angle = 0;
	rc_sprite[spr_id].physics.body = rc_canvas[rc_active_canvas].physics2D.world->CreateBody(&sprBodyDef);

	b2FixtureDef sprFixtureDef;
	rc_sprite[spr_id].physics.shape = new b2PolygonShape();
	b2PolygonShape* fix_shape = (b2PolygonShape*)rc_sprite[spr_id].physics.shape;
	fix_shape->SetAsBox(w/2, h/2);
	sprFixtureDef.shape = rc_sprite[spr_id].physics.shape;
	sprFixtureDef.isSensor = true;
	rc_sprite[spr_id].physics.fixture = rc_sprite[spr_id].physics.body->CreateFixture(&sprFixtureDef);

	rc_sprite[spr_id].physics.offset_x = 0;
	rc_sprite[spr_id].physics.offset_y = 0;
	rc_sprite[spr_id].isSolid = false;
	rc_sprite[spr_id].visible = true;
	rc_sprite[spr_id].scale.set(1.0, 1.0);
	rc_sprite[spr_id].alpha = 255;
	rc_sprite[spr_id].z = 0;
	rc_sprite[spr_id].color_mod.set(255,255,255,255);
	rc_sprite[spr_id].parent_canvas = rc_active_canvas;

	rc_canvas[rc_active_canvas].sprite.push_back(&rc_sprite[spr_id]);

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

void rc_setSpriteType(int spr_id, int body_type)
{
	if(spr_id < 0 || spr_id >= rc_sprite.size())
		return;

	if(!rc_sprite[spr_id].active)
		return;

	rc_sprite[spr_id].physics.body->SetType((b2BodyType) body_type);
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

	if(rc_sprite[spr_id].isSolid)
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



//This function is called on each canvas on update
void drawSprites(int canvas_id)
{
	float step = rc_canvas[canvas_id].physics2D.timeStep;
	int32 velocityIterations = rc_canvas[canvas_id].physics2D.velocityIterations;
	int32 positionIterations = rc_canvas[canvas_id].physics2D.positionIterations;

	if(rc_canvas[canvas_id].physics2D.enabled)
		rc_canvas[canvas_id].physics2D.world->Step(step, velocityIterations, positionIterations);

	//Setting the render target to the current canvas.  NOTE: I might change this target to a separate sprite layer later.
	VideoDriver->setRenderTarget(rc_canvas[canvas_id].texture, false, false);


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

	for(int spr_index = 0; spr_index < rc_canvas[canvas_id].sprite.size(); spr_index++)
	{
		rc_sprite2D_obj* sprite = rc_canvas[canvas_id].sprite[spr_index];
		if(!sprite->visible)
			continue;

		int img_id = sprite->image_id;
		if(img_id < 0 || img_id >= rc_image.size())
			continue;

		src_size = rc_image[img_id].image->getSize();
		sourceRect = irr::core::rect<irr::s32>( irr::core::vector2d<irr::s32>(0, 0), src_size);

		physics_pos = sprite->physics.body->GetPosition();
		x = (int)physics_pos.x;
		y = (int)physics_pos.y;
		position.set(x, y);


		rotationPoint.set(x + (src_size.Width/2), y + (src_size.Height/2)); //TODO: need to account for offset once that is implemented
		rotation = -1 * (sprite->physics.body->GetAngle() * RAD_TO_DEG); //convert Box2D radians to degrees

		scale.set(sprite->scale.X, sprite->scale.Y);

		color.set(sprite->alpha,
							 sprite->color_mod.getRed(),
							 sprite->color_mod.getGreen(),
							 sprite->color_mod.getBlue());

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
