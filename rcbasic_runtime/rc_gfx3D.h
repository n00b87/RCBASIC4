#ifndef RC_GFX3D_H_INCLUDED
#define RC_GFX3D_H_INCLUDED

#ifdef RC_ANDROID
	#include "SDL.h"
	#include <btBulletDynamicsCommon.h>
	#include <BulletCollision/CollisionDispatch/btGhostObject.h>
#else
	#include <SDL2/SDL.h>
	#include <bullet/btBulletDynamicsCommon.h>
	#include <bullet/BulletCollision/CollisionDispatch/btGhostObject.h>
#endif // _IRR_ANDROID_PLATFORM_
#include <irrlicht.h>
#include <iostream>
#include <sstream>
#include <string>
#include <locale>
#include <codecvt>
#include <cmath>
#include <set>

#include "camera.h"
#include "rc_gfx_core.h"
#include "rc_matrix.h"

#include "rc_physics3D_base.h"

#include "rc_base_actor.h"
#include "rc_actor_material.h"
#include "rc_actor_animation.h"
#include "rc_actor_physics.h"
#include "rc_constraint.h"
#include "rc_mesh.h"
#include "rc_particles.h"
#include "rc_scene.h"
#include "rc_camera.h"


#endif // RC_GFX3D_H_INCLUDED
