//#include "main.h"

#include <irrlicht.h>

#ifndef __CProjectiveTextures__
#define __CProjectiveTextures__

class CProjectiveTextures : public irr::video::IShaderConstantSetCallBack, public irr::scene::ISceneNode
{
public:

	// Constructor / Destructor.
	CProjectiveTextures(irr::IrrlichtDevice* dev, irr::scene::ISceneNode* parent, irr::scene::ISceneManager* mgr, irr::s32 id,
			const irr::core::vector3df& position = irr::core::vector3df(0,0,0),
			const irr::core::vector3df& lookat = irr::core::vector3df(0,0,0));

	~CProjectiveTextures();

	//! Sets the look at target of the projector
	virtual void setTarget(const irr::core::vector3df& pos);

	//! Gets the current look at target of the projector
	virtual const irr::core::vector3df& getTarget() const;

	//! Sets the field of view (Default: PI / 3.5f)
	virtual void setFOV(irr::f32 f);

	//! Gets the field of view (Default: PI / 3.5f)
	virtual irr::f32 getFOV();

	//! Returns the axis aligned bounding box of this node
	virtual const irr::core::aabbox3d<irr::f32>& getBoundingBox() const;

	//! Render
	virtual void render();

	virtual void OnSetConstants(irr::video::IMaterialRendererServices* services, irr::s32 userData);

	irr::video::ITexture* texture;
	irr::core::array<irr::scene::ISceneNode*> nodeArray;

private:

	int projTex;
	irr::video::SMaterial projMat;

protected:

	void recalculateProjectionMatrix();
	void recalculateViewArea();

	irr::core::vector3df Target;

	irr::f32 Fovy;	// Field of view, in radians.

	irr::scene::SViewFrustum ViewArea;

	irr::IrrlichtDevice		* pDevice;
	irr::video::IVideoDriver			* pVideo;
	irr::scene::ISceneManager		   * pScene;
	irr::gui::IGUIEnvironment		   * pGUI;
	irr::video::IGPUProgrammingServices * pGPU;
	irr::ILogger				   * pLog;
	irr::scene::ISceneCollisionManager  * pCollision;

};

#endif
