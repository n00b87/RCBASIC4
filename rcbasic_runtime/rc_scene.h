#ifndef RC_SCENE_H_INCLUDED
#define RC_SCENE_H_INCLUDED

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

void rc_removeSceneSky()
{
	if(rc_scene_properties.sky)
		rc_scene_properties.sky->remove();

	rc_scene_properties.sky = NULL;
}

#endif // RC_SCENE_H_INCLUDED
