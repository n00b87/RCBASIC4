#ifndef RC_SCENE_H_INCLUDED
#define RC_SCENE_H_INCLUDED

#include "rc_gfx_core.h"
#include "rc_base_actor.h"
#include "rc_constraint.h"

void rc_addSceneSkyBox(int img_top, int img_bottom, int img_left, int img_right, int img_front, int img_back)
{
	if(!SceneManager)
		return;

	if(rc_scene_properties.sky)
		return;

	irr::video::ITexture* tp = rc_image[img_top].image;
	irr::video::ITexture* bt = rc_image[img_bottom].image;
	irr::video::ITexture* lf = rc_image[img_left].image;
	irr::video::ITexture* rt = rc_image[img_right].image;
	irr::video::ITexture* ft = rc_image[img_front].image;
	irr::video::ITexture* bk = rc_image[img_back].image;
	rc_scene_properties.sky = SceneManager->addSkyBoxSceneNode(tp, bt, lf, rt, ft, bk);
}

void rc_addSceneSkyDome(int img)
{
	if(!SceneManager)
		return;

	if(rc_scene_properties.sky)
		return;

	irr::video::ITexture* texture = rc_image[img].image;
	rc_scene_properties.sky = SceneManager->addSkyDomeSceneNode(texture);
}

void rc_addSceneSkyDomeEx(int img, Uint32 horiRes, Uint32 vertRes, double txPercentage, double spherePercentage, double radius)
{
	if(!SceneManager)
		return;

	if(rc_scene_properties.sky)
		return;

	irr::video::ITexture* texture = rc_image[img].image;
	rc_scene_properties.sky = SceneManager->addSkyDomeSceneNode(texture, horiRes, vertRes, txPercentage, spherePercentage, radius);
}

void rc_setSceneShadowColor( Uint32 color )
{
	SceneManager->setShadowColor(irr::video::SColor(color));
}

Uint32 rc_getSceneShadowColor( )
{
	return SceneManager->getShadowColor().color;
}

void rc_setSceneAmbientColor( Uint32 color )
{
	SceneManager->setAmbientLight(irr::video::SColor(color));
}

Uint32 rc_getSceneAmbientColor()
{
	return SceneManager->getAmbientLight().toSColor().color;
}

void rc_removeSceneSky()
{
	if(rc_scene_properties.sky)
		rc_scene_properties.sky->remove();

	rc_scene_properties.sky = NULL;
}

void rc_clearScene()
{
	if(SceneManager)
	{
		for(int i = 0; i < rc_physics3D.constraints.size(); i++)
		{
		    rc_deleteConstraint(i);
		}

		rc_projector_actors.clear();

		for(int i = 0; i < rc_actor.size(); i++)
		{
		    rc_deleteActor(i);
		}

		rc_removeSceneSky();
	}
}

#endif // RC_SCENE_H_INCLUDED
