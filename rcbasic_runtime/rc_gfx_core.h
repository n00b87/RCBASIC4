#ifndef RC_GFX_CORE_H_INCLUDED
#define RC_GFX_CORE_H_INCLUDED

#if defined(RC_ANDROID)
	#include "SDL.h"
	#include "btBulletDynamicsCommon.h"
	#include "BulletSoftBody/btSoftRigidDynamicsWorld.h"
	#include "BulletCollision/NarrowPhaseCollision/btRaycastCallback.h"
#else
	#include <SDL2/SDL.h>
	#include <bullet/btBulletDynamicsCommon.h>
	#include <BulletSoftBody/btSoftRigidDynamicsWorld.h>
	#include <bullet/BulletCollision/NarrowPhaseCollision/btRaycastCallback.h>
#endif // _IRR_ANDROID_PLATFORM_
#include <irrlicht.h>
#include <iostream>
#include <sstream>
#include <string>
#include <locale>
#include <codecvt>
#include <cmath>
#include <set>
#include "gui_freetype_font.h"
#include "rc_utf8.h"
#include "camera.h"
#include <box2d/box2d.h>
#include "rc_sprite2D.h"
#include <irrBullet.h>
#ifdef RC_ANDROID
	#include "an8parser.h"
#else
	#include <an8parser.h>
#endif

using namespace irr;

using namespace core;
using namespace video;
using namespace scene;


#define MAX_JOYSTICKS 32

#define MAX_FINGERS 10

#define MAX_ACCELS 32
#define MAX_GYROS 32

SDL_Joystick * rc_joystick[MAX_JOYSTICKS];
int rc_joy_axis[MAX_JOYSTICKS][100];
int rc_numJoysticks = 0;
int rc_joybutton[MAX_JOYSTICKS][100];
SDL_JoystickID rc_joyID[MAX_JOYSTICKS];

SDL_Joystick * tmp_joy;
SDL_JoystickID tmp_joy_id;
int tmp_joy_flag = 0;

SDL_Haptic * rc_haptic[MAX_JOYSTICKS]; //1 for each joystick

double rc_pressure = 0;
int rc_touchX = 0;
int rc_touchY = 0;
int rc_motionX = 0;
int rc_motionY = 0;
int rc_touch = 0;
int rc_mt_status = 0;
int rc_mt_x = 0;
int rc_mt_y = 0;
int rc_mt_numFingers = 0;
double rc_mt_theta = 0;
double rc_mt_dist = 0;
SDL_TouchID rc_touchDevice;
SDL_Finger rc_finger[MAX_FINGERS];
set<int> rc_fingers_pressed;

SDL_Sensor * rc_accel[MAX_ACCELS];
int num_accels = 0;

SDL_Sensor * rc_gyro[MAX_GYROS];
int num_gyros = 0;


struct SDLKeyMap
{
    SDLKeyMap() {}
    SDLKeyMap(s32 x11, s32 win32)
        : SDLKey(x11), Win32Key(win32)
    {
    }

    s32 SDLKey;
    s32 Win32Key;

    bool operator<(const SDLKeyMap& o) const
    {
        return SDLKey<o.SDLKey;
    }
};

core::array<SDLKeyMap> KeyMap;

void createKeyMap()
{
	// I don't know if this is the best method  to create
	// the lookuptable, but I'll leave it like that until
	// I find a better version.

	KeyMap.reallocate(105);

	// buttons missing

	KeyMap.push_back(SDLKeyMap(SDLK_BACKSPACE, irr::EKEY_CODE::KEY_BACK));
	KeyMap.push_back(SDLKeyMap(SDLK_TAB, irr::EKEY_CODE::KEY_TAB));
	KeyMap.push_back(SDLKeyMap(SDLK_CLEAR, irr::EKEY_CODE::KEY_CLEAR));
	KeyMap.push_back(SDLKeyMap(SDLK_RETURN, irr::EKEY_CODE::KEY_RETURN));

	// combined modifiers missing

	KeyMap.push_back(SDLKeyMap(SDLK_PAUSE, irr::EKEY_CODE::KEY_PAUSE));
	KeyMap.push_back(SDLKeyMap(SDLK_CAPSLOCK, irr::EKEY_CODE::KEY_CAPITAL));

	// asian letter keys missing

	KeyMap.push_back(SDLKeyMap(SDLK_ESCAPE, irr::EKEY_CODE::KEY_ESCAPE));

	// asian letter keys missing

	KeyMap.push_back(SDLKeyMap(SDLK_SPACE, irr::EKEY_CODE::KEY_SPACE));
	KeyMap.push_back(SDLKeyMap(SDLK_PAGEUP, irr::EKEY_CODE::KEY_PRIOR));
	KeyMap.push_back(SDLKeyMap(SDLK_PAGEDOWN, irr::EKEY_CODE::KEY_NEXT));
	KeyMap.push_back(SDLKeyMap(SDLK_END, irr::EKEY_CODE::KEY_END));
	KeyMap.push_back(SDLKeyMap(SDLK_HOME, irr::EKEY_CODE::KEY_HOME));
	KeyMap.push_back(SDLKeyMap(SDLK_LEFT, irr::EKEY_CODE::KEY_LEFT));
	KeyMap.push_back(SDLKeyMap(SDLK_UP, irr::EKEY_CODE::KEY_UP));
	KeyMap.push_back(SDLKeyMap(SDLK_RIGHT, irr::EKEY_CODE::KEY_RIGHT));
	KeyMap.push_back(SDLKeyMap(SDLK_DOWN, irr::EKEY_CODE::KEY_DOWN));

	// select missing
	KeyMap.push_back(SDLKeyMap(SDLK_PRINTSCREEN, irr::EKEY_CODE::KEY_PRINT));
	// execute missing
	KeyMap.push_back(SDLKeyMap(SDLK_PRINTSCREEN, irr::EKEY_CODE::KEY_SNAPSHOT));

	KeyMap.push_back(SDLKeyMap(SDLK_INSERT, irr::EKEY_CODE::KEY_INSERT));
	KeyMap.push_back(SDLKeyMap(SDLK_DELETE, irr::EKEY_CODE::KEY_DELETE));
	KeyMap.push_back(SDLKeyMap(SDLK_HELP, irr::EKEY_CODE::KEY_HELP));

	KeyMap.push_back(SDLKeyMap(SDLK_0, irr::EKEY_CODE::KEY_KEY_0));
	KeyMap.push_back(SDLKeyMap(SDLK_1, irr::EKEY_CODE::KEY_KEY_1));
	KeyMap.push_back(SDLKeyMap(SDLK_2, irr::EKEY_CODE::KEY_KEY_2));
	KeyMap.push_back(SDLKeyMap(SDLK_3, irr::EKEY_CODE::KEY_KEY_3));
	KeyMap.push_back(SDLKeyMap(SDLK_4, irr::EKEY_CODE::KEY_KEY_4));
	KeyMap.push_back(SDLKeyMap(SDLK_5, irr::EKEY_CODE::KEY_KEY_5));
	KeyMap.push_back(SDLKeyMap(SDLK_6, irr::EKEY_CODE::KEY_KEY_6));
	KeyMap.push_back(SDLKeyMap(SDLK_7, irr::EKEY_CODE::KEY_KEY_7));
	KeyMap.push_back(SDLKeyMap(SDLK_8, irr::EKEY_CODE::KEY_KEY_8));
	KeyMap.push_back(SDLKeyMap(SDLK_9, irr::EKEY_CODE::KEY_KEY_9));

	KeyMap.push_back(SDLKeyMap(SDLK_a, irr::EKEY_CODE::KEY_KEY_A));
	KeyMap.push_back(SDLKeyMap(SDLK_b, irr::EKEY_CODE::KEY_KEY_B));
	KeyMap.push_back(SDLKeyMap(SDLK_c, irr::EKEY_CODE::KEY_KEY_C));
	KeyMap.push_back(SDLKeyMap(SDLK_d, irr::EKEY_CODE::KEY_KEY_D));
	KeyMap.push_back(SDLKeyMap(SDLK_e, irr::EKEY_CODE::KEY_KEY_E));
	KeyMap.push_back(SDLKeyMap(SDLK_f, irr::EKEY_CODE::KEY_KEY_F));
	KeyMap.push_back(SDLKeyMap(SDLK_g, irr::EKEY_CODE::KEY_KEY_G));
	KeyMap.push_back(SDLKeyMap(SDLK_h, irr::EKEY_CODE::KEY_KEY_H));
	KeyMap.push_back(SDLKeyMap(SDLK_i, irr::EKEY_CODE::KEY_KEY_I));
	KeyMap.push_back(SDLKeyMap(SDLK_j, irr::EKEY_CODE::KEY_KEY_J));
	KeyMap.push_back(SDLKeyMap(SDLK_k, irr::EKEY_CODE::KEY_KEY_K));
	KeyMap.push_back(SDLKeyMap(SDLK_l, irr::EKEY_CODE::KEY_KEY_L));
	KeyMap.push_back(SDLKeyMap(SDLK_m, irr::EKEY_CODE::KEY_KEY_M));
	KeyMap.push_back(SDLKeyMap(SDLK_n, irr::EKEY_CODE::KEY_KEY_N));
	KeyMap.push_back(SDLKeyMap(SDLK_o, irr::EKEY_CODE::KEY_KEY_O));
	KeyMap.push_back(SDLKeyMap(SDLK_p, irr::EKEY_CODE::KEY_KEY_P));
	KeyMap.push_back(SDLKeyMap(SDLK_q, irr::EKEY_CODE::KEY_KEY_Q));
	KeyMap.push_back(SDLKeyMap(SDLK_r, irr::EKEY_CODE::KEY_KEY_R));
	KeyMap.push_back(SDLKeyMap(SDLK_s, irr::EKEY_CODE::KEY_KEY_S));
	KeyMap.push_back(SDLKeyMap(SDLK_t, irr::EKEY_CODE::KEY_KEY_T));
	KeyMap.push_back(SDLKeyMap(SDLK_u, irr::EKEY_CODE::KEY_KEY_U));
	KeyMap.push_back(SDLKeyMap(SDLK_v, irr::EKEY_CODE::KEY_KEY_V));
	KeyMap.push_back(SDLKeyMap(SDLK_w, irr::EKEY_CODE::KEY_KEY_W));
	KeyMap.push_back(SDLKeyMap(SDLK_x, irr::EKEY_CODE::KEY_KEY_X));
	KeyMap.push_back(SDLKeyMap(SDLK_y, irr::EKEY_CODE::KEY_KEY_Y));
	KeyMap.push_back(SDLKeyMap(SDLK_z, irr::EKEY_CODE::KEY_KEY_Z));

        // TODO:
	//KeyMap.push_back(SDLKeyMap(SDLK_LSUPER, KEY_LWIN));
        // TODO:
	//KeyMap.push_back(SDLKeyMap(SDLK_RSUPER, KEY_RWIN));
	// apps missing
	KeyMap.push_back(SDLKeyMap(SDLK_POWER, irr::EKEY_CODE::KEY_SLEEP)); //??

	KeyMap.push_back(SDLKeyMap(SDLK_KP_0, irr::EKEY_CODE::KEY_NUMPAD0));
	KeyMap.push_back(SDLKeyMap(SDLK_KP_1, irr::EKEY_CODE::KEY_NUMPAD1));
	KeyMap.push_back(SDLKeyMap(SDLK_KP_2, irr::EKEY_CODE::KEY_NUMPAD2));
	KeyMap.push_back(SDLKeyMap(SDLK_KP_3, irr::EKEY_CODE::KEY_NUMPAD3));
	KeyMap.push_back(SDLKeyMap(SDLK_KP_4, irr::EKEY_CODE::KEY_NUMPAD4));
	KeyMap.push_back(SDLKeyMap(SDLK_KP_5, irr::EKEY_CODE::KEY_NUMPAD5));
	KeyMap.push_back(SDLKeyMap(SDLK_KP_6, irr::EKEY_CODE::KEY_NUMPAD6));
	KeyMap.push_back(SDLKeyMap(SDLK_KP_7, irr::EKEY_CODE::KEY_NUMPAD7));
	KeyMap.push_back(SDLKeyMap(SDLK_KP_8, irr::EKEY_CODE::KEY_NUMPAD8));
	KeyMap.push_back(SDLKeyMap(SDLK_KP_9, irr::EKEY_CODE::KEY_NUMPAD9));
	KeyMap.push_back(SDLKeyMap(SDLK_KP_MULTIPLY, irr::EKEY_CODE::KEY_MULTIPLY));
	KeyMap.push_back(SDLKeyMap(SDLK_KP_PLUS, irr::EKEY_CODE::KEY_ADD));
//	KeyMap.push_back(SDLKeyMap(SDLK_KP_, KEY_SEPARATOR));
	KeyMap.push_back(SDLKeyMap(SDLK_KP_MINUS, irr::EKEY_CODE::KEY_SUBTRACT));
	KeyMap.push_back(SDLKeyMap(SDLK_KP_PERIOD, irr::EKEY_CODE::KEY_DECIMAL));
	KeyMap.push_back(SDLKeyMap(SDLK_KP_DIVIDE, irr::EKEY_CODE::KEY_DIVIDE));

	KeyMap.push_back(SDLKeyMap(SDLK_F1,  irr::EKEY_CODE::KEY_F1));
	KeyMap.push_back(SDLKeyMap(SDLK_F2,  irr::EKEY_CODE::KEY_F2));
	KeyMap.push_back(SDLKeyMap(SDLK_F3,  irr::EKEY_CODE::KEY_F3));
	KeyMap.push_back(SDLKeyMap(SDLK_F4,  irr::EKEY_CODE::KEY_F4));
	KeyMap.push_back(SDLKeyMap(SDLK_F5,  irr::EKEY_CODE::KEY_F5));
	KeyMap.push_back(SDLKeyMap(SDLK_F6,  irr::EKEY_CODE::KEY_F6));
	KeyMap.push_back(SDLKeyMap(SDLK_F7,  irr::EKEY_CODE::KEY_F7));
	KeyMap.push_back(SDLKeyMap(SDLK_F8,  irr::EKEY_CODE::KEY_F8));
	KeyMap.push_back(SDLKeyMap(SDLK_F9,  irr::EKEY_CODE::KEY_F9));
	KeyMap.push_back(SDLKeyMap(SDLK_F10, irr::EKEY_CODE::KEY_F10));
	KeyMap.push_back(SDLKeyMap(SDLK_F11, irr::EKEY_CODE::KEY_F11));
	KeyMap.push_back(SDLKeyMap(SDLK_F12, irr::EKEY_CODE::KEY_F12));
	KeyMap.push_back(SDLKeyMap(SDLK_F13, irr::EKEY_CODE::KEY_F13));
	KeyMap.push_back(SDLKeyMap(SDLK_F14, irr::EKEY_CODE::KEY_F14));
	KeyMap.push_back(SDLKeyMap(SDLK_F15, irr::EKEY_CODE::KEY_F15));
	// no higher F-keys

        // TODO:
	//KeyMap.push_back(SDLKeyMap(SDLK_NUMLOCK, KEY_NUMLOCK));
	KeyMap.push_back(SDLKeyMap(SDLK_SCROLLLOCK, irr::EKEY_CODE::KEY_SCROLL));
	KeyMap.push_back(SDLKeyMap(SDLK_LSHIFT, irr::EKEY_CODE::KEY_LSHIFT));
	KeyMap.push_back(SDLKeyMap(SDLK_RSHIFT, irr::EKEY_CODE::KEY_RSHIFT));
	KeyMap.push_back(SDLKeyMap(SDLK_LCTRL,  irr::EKEY_CODE::KEY_LCONTROL));
	KeyMap.push_back(SDLKeyMap(SDLK_RCTRL,  irr::EKEY_CODE::KEY_RCONTROL));
	KeyMap.push_back(SDLKeyMap(SDLK_LALT,  irr::EKEY_CODE::KEY_LMENU));
	KeyMap.push_back(SDLKeyMap(SDLK_RALT,  irr::EKEY_CODE::KEY_RMENU));

	KeyMap.push_back(SDLKeyMap(SDLK_PLUS,   irr::EKEY_CODE::KEY_PLUS));
	KeyMap.push_back(SDLKeyMap(SDLK_COMMA,  irr::EKEY_CODE::KEY_COMMA));
	KeyMap.push_back(SDLKeyMap(SDLK_MINUS,  irr::EKEY_CODE::KEY_MINUS));
	KeyMap.push_back(SDLKeyMap(SDLK_PERIOD, irr::EKEY_CODE::KEY_PERIOD));

	// some special keys missing

	KeyMap.sort();
}

IrrlichtDevice* device;
irr::video::IVideoDriver * VideoDriver;
irr::scene::ISceneManager *SceneManager;
SDL_Window* rc_window;
irr::core::dimension2d<u32> rc_window_size;
double rc_window_mouse_scale_x = 1;
double rc_window_mouse_scale_y = 1;
bool rc_mouse_zone_active = false;
double rc_window_zone_scale_x = 1;
double rc_window_zone_scale_y = 1;
SDL_Rect rc_mouse_zone;
bool rc_window_setfps = false;
int rc_setfps_refresh_rate = 0;
Uint32 rc_setfps_timer = 0;

struct rc_scene_properties_obj
{
	irr::scene::ISceneNode* sky = NULL;
};

rc_scene_properties_obj rc_scene_properties;

#define RC_CONSTRAINT_TYPE_POINT	1
#define RC_CONSTRAINT_TYPE_HINGE	2
#define RC_CONSTRAINT_TYPE_SLIDER	3
#define RC_CONSTRAINT_TYPE_CONE		4

struct rc_constraint_obj
{
	btTypedConstraint* constraint;

	int type;
};

struct rc_physicsWorld3D_obj
{
	irrBulletWorld* world;

	irr::f32 DeltaTime;
	irr::u32 maxSubSteps;
	irr::f32 fixedTimeStep;

	irr::u32 TimeStamp;

	irr::core::array<rc_constraint_obj> constraints;
};

rc_physicsWorld3D_obj rc_physics3D;

//Canvases
class rc_contactListener_obj : public b2ContactListener
{
	void BeginContact(b2Contact* contact)
	{
		rc_sprite2D_obj* spriteA = &rc_sprite[contact->GetFixtureA()->GetBody()->GetUserData().pointer];

		rc_sprite2D_obj* spriteB = &rc_sprite[contact->GetFixtureB()->GetBody()->GetUserData().pointer];

	  //std::cout << "sprite[" << spriteA->id << "] collide with sprite[" << spriteB->id << "]" << std::endl;

	}

	void EndContact(b2Contact* contact)
	{

	}
};

struct rc_physicsWorld2D_obj
{
	bool enabled = false;
	b2World* world;

	rc_contactListener_obj* contact_listener;
	Uint32 time_stamp;
	float timeStep = 1/60.0;      //the length of time passed to simulate (seconds)
	int velocityIterations = 8;   //how strongly to correct velocity
	int positionIterations = 3;   //how strongly to correct position
};

#define RC_CANVAS_TYPE_2D		0
#define RC_CANVAS_TYPE_3D		1
#define RC_CANVAS_TYPE_SPRITE	2

#define RC_PROJECTION_TYPE_ORTHOGRAPHIC		0
#define RC_PROJECTION_TYPE_PERSPECTIVE		1

struct rc_canvas_obj
{
    irr::video::ITexture* texture;

    //irr::video::ITexture* sprite_layer;

    int type;

    irr::core::dimension2d<u32> dimension;

    struct rc_canvas_viewport
    {
        irr::core::vector2d<s32> position;
        irr::core::dimension2d<u32> dimension;
    } viewport;


    bool show3D = false;
    Camera camera;

    irr::core::vector2d<s32> offset;

    int mode;

    bool visible = true;
    int z = 0;

    irr::u32 color_mod;

    rc_physicsWorld2D_obj physics2D;
    irr::core::array<irr::s32> sprite_id;
};

irr::core::array<rc_canvas_obj> rc_canvas;
irr::core::array<u32> rc_canvas_zOrder;
int rc_active_canvas = -1;
bool hasPreUpdated = false;

irr::video::SColor rc_active_color(0,0,0,0);
irr::video::SColor rc_clear_color(0,0,0,0);

bool rc_init_events = false;
bool rc_init_timer = false;
bool rc_init_video = false;
bool rc_init_joystick = false;
bool rc_init_haptic = false;
bool rc_init_sensor = false;
bool rc_init_noparachute = false;
bool rc_init_audio = false;


irr::s32 MouseX, MouseY, MouseXRel, MouseYRel;
irr::u32 MouseButtonStates;


int rc_win_event = -1;
#define RC_WIN_EVENT_CLOSE 1
#define RC_WIN_EVENT_MINIMIZE 2
#define RC_WIN_EVENT_MAXIMIZE 3
#define RC_WIN_EVENT_RESIZE 4

bool rc_win_exitOnClose = true;

std::string rc_textinput_string = "";
std::string rc_textinput_char = "";
int rc_textinput_timer = 0;
int rc_textinput_delay = 100;
bool rc_textinput_flag = true;
bool rc_textinput_isActive = false;
int rc_textinput_waitHold = 800;
bool rc_textinput_hold = false;
bool rc_toggleBackspace = true;


static Uint32 baseticks = 0;

int rc_inkey_val = 0;

const Uint8 * keyState = NULL;



std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

struct rc_font_obj
{
    CGUITTFace* face;
    CGUIFreetypeFont* font;
    int font_size;
    bool active;
};

irr::core::array<rc_font_obj> rc_font;

int rc_active_font = -1;


bool mobile_active_window_flag = true;



//------------ 3D Graphics ----------------//
struct rc_material_obj
{
    irr::video::SMaterial mat;
    bool isUsed = false;
    bool isReference = false;
    int refActor = -1;
    int refMatNum = 0;
};

irr::core::array<rc_material_obj> rc_material;

#define RC_MESH_TYPE_NONE       0
#define RC_MESH_TYPE_ANIMATED   1


struct rc_mesh_obj
{
    int mesh_type = 0;
    irr::scene::IMesh* mesh;
};
irr::core::array<rc_mesh_obj> rc_mesh;

struct rc_an8_obj
{
	bool active;
	an8::an8_project project;
};

irr::core::array<rc_an8_obj> rc_an8;

#define RC_NODE_TYPE_NONE   	0
#define RC_NODE_TYPE_MESH   	1
#define RC_NODE_TYPE_OTMESH		2
#define RC_NODE_TYPE_LIGHT		3
#define RC_NODE_TYPE_TERRAIN	4
#define RC_NODE_TYPE_WATER		5
#define RC_NODE_TYPE_BILLBOARD	6
#define RC_NODE_TYPE_PARTICLE	7
#define RC_NODE_TYPE_STMESH   	8


#define RC_NODE_SHAPE_TYPE_NONE			0
#define RC_NODE_SHAPE_TYPE_BOX			1
#define RC_NODE_SHAPE_TYPE_SPHERE		2
#define RC_NODE_SHAPE_TYPE_CYLINDER		3
#define RC_NODE_SHAPE_TYPE_CAPSULE		4
#define RC_NODE_SHAPE_TYPE_CONE			5
#define RC_NODE_SHAPE_TYPE_CONVEXHULL	6
#define RC_NODE_SHAPE_TYPE_TRIMESH		7
#define RC_NODE_SHAPE_TYPE_HEIGHTFIELD	8

struct rc_node_physics_collision
{
	int actorA;
	int actorB;
	irr::core::array<irr::core::vector3df> pointA;
	irr::core::array<irr::core::vector3df> pointB;
	irr::core::array<irr::core::vector3df> normalB;
};

irr::core::array<rc_node_physics_collision> rc_collisions;

struct rc_node_physics
{
	IRigidBody* rigid_body;

	int shape_type;
	bool isSolid;
	double mass;

	irr::core::vector3df gravity; //only used when changing from Solid to Non-Solid and vice versa

	irr::core::array<irr::u32> collisions;
};

#define RC_PARTICLE_TYPE_POINT		1
#define RC_PARTICLE_TYPE_BOX		2
#define RC_PARTICLE_TYPE_SPHERE		3
#define RC_PARTICLE_TYPE_CYLINDER	4
#define RC_PARTICLE_TYPE_MESH		5
#define RC_PARTICLE_TYPE_RING		6

struct rc_particle_properties_obj
{
	int particle_type = 0;
	bool everyMeshVertex;
	irr::s32 mbNumber = 0;
	irr::f32 normalDirectionModifier;
	bool useNormalDirection;
	irr::s32 mesh_id;
	irr::core::vector3df direction;
	irr::u32 minParticlesPerSecond;
	irr::u32 maxParticlesPerSecond;
	irr::video::SColor minStartColor;
	irr::video::SColor maxStartColor;
	irr::u32 lifeTimeMin;
	irr::u32 lifeTimeMax;
	irr::s32 maxAngleDegrees;
	irr::core::dimension2df minStartSize;
	irr::core::dimension2df maxStartSize;
	irr::core::vector3df center;
	irr::f32 radius;
	irr::f32 ringThickness;
	irr::core::aabbox3df box;
	irr::core::vector3df normal;
	irr::f32 length;
	bool outlineOnly;
};

#define RC_ANIMATION_MD2 		-2
#define RC_ANIMATION_TRANSITION	-3

struct rc_actor_animation_obj
{
	bool active;
	int start_frame;
	int end_frame;
	double fps;
	irr::u32 frame_start_time;
	irr::u32 frame_swap_time;
};

struct rc_scene_node
{
    int node_type = 0;

    irr::scene::ISceneNode* mesh_node;
    irr::scene::IShadowVolumeSceneNode* shadow;
    rc_node_physics physics;

    bool transition;
    double transition_frame;
    double transition_time;
    double transition_start_time;

    rc_particle_properties_obj particle_properties;

    int material_ref_index = -1;

    int current_animation;
    int num_animation_loops;
	int current_animation_loop;
	bool isPlaying;
    irr::core::array<int> deleted_animation;
    irr::core::array<rc_actor_animation_obj> animation;
};

irr::core::array<rc_scene_node> rc_actor;

irr::core::array<int> rc_transition_actor;


class rc_animEndCallBack : public IAnimationEndCallBack
{
  public:
  	int ref_id;

    void OnAnimationEnd( IAnimatedMeshSceneNode *node)
    {
    	rc_scene_node* ref_actor = &rc_actor[ref_id];
    	if(ref_actor->current_animation_loop < ref_actor->num_animation_loops || ref_actor->num_animation_loops < 0)
		{
			//std::cout << "animating" << std::endl;
			irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*) ref_actor->mesh_node;
			int animation = ref_actor->current_animation;
			if(animation == RC_ANIMATION_MD2)
			{
				int start_frame = node->getStartFrame();
				int end_frame = node->getEndFrame();
				node->setFrameLoop(start_frame, end_frame);
				ref_actor->current_animation_loop++;
			}
			else if(animation == RC_ANIMATION_TRANSITION)
			{
				//TODO: Transitions are currently broken
			}
			else if(animation < 0 || animation >= ref_actor->animation.size())
			{
				return;
			}
			else
			{
				if(!ref_actor->animation[animation].active)
				{
					ref_actor->isPlaying = false;
					ref_actor->current_animation_loop = 0;
					return;
				}
				int start_frame = ref_actor->animation[animation].start_frame;
				int end_frame = ref_actor->animation[animation].end_frame;
				node->setFrameLoop(start_frame, end_frame);
				ref_actor->current_animation_loop++;
			}
		}
		else
		{
			ref_actor->isPlaying = false;
		}
      //std::cout << "The animation has ended!" << std::endl;
      // Your callback code goes there.
    }
};


void myTickCallback2(btSoftRigidDynamicsWorld* dynamicsWorld, btScalar timeStep)
{
	rc_collisions.clear();
    int numManifolds = dynamicsWorld->getDispatcher()->getNumManifolds();

    int c_index = 0;

    rc_node_physics_collision collision;

    for(int i = 0; i < rc_actor.size(); i++)
	{
		rc_actor[i].physics.collisions.clear();
	}


    for (int i = 0; i < rc_physics3D.world->getNumManifolds(); i++)
	{
		ICollisionCallbackInformation* manifold = rc_physics3D.world->getCollisionCallback(i);

        int numContacts = manifold->getPointer()->getNumContacts();

        int actorA = manifold->getBody0()->getIdentification()->getId();
        int actorB = manifold->getBody1()->getIdentification()->getId();

        collision.actorA = actorA;
        collision.actorB = actorB;

        //std::cout << "Collision Details: " << actorA << ", " << actorB << ", " << numContacts << std::endl;

        if(numContacts < 1)
			continue;

        for (int j = 0; j < numContacts; j++)
		{
            SManifoldPoint pt = manifold->getContactPoint(j);
            collision.pointA.push_back(pt.getPositionWorldOnA());
            collision.pointB.push_back(pt.getPositionWorldOnB());
            collision.normalB.push_back(pt.getNormalWorldOnB());
        }

        c_index = rc_collisions.size();
        rc_collisions.push_back(collision);
        rc_actor[actorA].physics.collisions.push_back(c_index);
        rc_actor[actorB].physics.collisions.push_back(c_index);
    }

    for(int i = 0; i < rc_actor.size(); i++)
	{
		if(!rc_actor[i].physics.isSolid)
		{
			if(rc_actor[i].physics.collisions.size() > 0)
			{
				rc_physics3D.world->removeCollisionObject(rc_actor[i].physics.rigid_body, false);
				rc_physics3D.world->addRigidBody(rc_actor[i].physics.rigid_body);
				rc_actor[i].physics.rigid_body->setMassProps(1, irr::core::vector3df(0,0,0));
				rc_actor[i].physics.rigid_body->setGravity(irr::core::vector3df(0,0,0));
			}
		}
	}
}


#define RC_ACTOR_TEXTURE_TYPE_IMAGE     0
#define RC_ACTOR_TEXTURE_TYPE_CANVAS    1


// Function to calculate a point on a cubic Bezier curve
vector3df bezierPoint(const vector3df& p0, const vector3df& p1, const vector3df& p2, const vector3df& p3, float t) {
    float u = 1.0f - t;
    float tt = t * t;
    float uu = u * u;
    float uuu = uu * u;
    float ttt = tt * t;

    vector3df p = uuu * p0; // (1-t)^3 * p0
    p += 3 * uu * t * p1;   // 3 * (1-t)^2 * t * p1
    p += 3 * u * tt * p2;   // 3 * (1-t) * t^2 * p2
    p += ttt * p3;          // t^3 * p3

    return p;
}

// Function to draw a Bezier curve
void drawBezierCurve(IVideoDriver* driver, const vector3df& p0, const vector3df& p1, const vector3df& p2, const vector3df& p3, SColor color, int segments) {
    std::vector<vector3df> points;

    for (int i = 0; i <= segments; ++i) {
        float t = static_cast<float>(i) / segments;
        points.push_back(bezierPoint(p0, p1, p2, p3, t));
    }

    for (size_t i = 0; i < points.size() - 1; ++i) {
        driver->draw3DLine(points[i], points[i + 1], color);
    }
}


void printIrrMatrix(irr::core::matrix4 m)
{
	for(int i = 0; i < 4; i++)
		std::cout << "[ " << m[i*4] << ", " << m[i*4+1] << ", " << m[i*4+2] << ", " << m[i*4+3] << " ]" << std::endl;
}


struct rc_image_obj
{
    irr::video::ITexture* image;
    Uint8 alpha = 255;
    irr::video::SColor color_mod = irr::video::SColor(255,255,255,255);
};
irr::core::array<rc_image_obj> rc_image;

irr::video::E_BLEND_OPERATION rc_blend_mode = irr::video::EBO_ADD;
bool rc_bilinear_filter = false;
irr::video::E_ANTI_ALIASING_MODE rc_anti_alias = irr::video::EAAM_OFF;

#define PRIM3D_LINE 1
#define PRIM3D_TRIANGLE 2
#define PRIM3D_BOX 3

struct rc_prim3d_op_obj
{
	int prim_type;

	double x[4], y[4], z[4];
	irr::video::SColor color;
};

irr::core::array<rc_prim3d_op_obj> rc_prim3d_operation;

void rc_setDriverMaterial()
{
	if(!VideoDriver)
		return;

	irr::video::SMaterial material;
    material.Lighting = false;
    material.ZWriteEnable = irr::video::EZW_OFF;
    material.ZBuffer = false;
    material.BackfaceCulling = false;
    material.TextureLayer[0].Texture = 0;
    material.TextureLayer[0].BilinearFilter = rc_bilinear_filter;
    material.MaterialTypeParam = irr::video::pack_textureBlendFunc(irr::video::EBF_SRC_ALPHA, irr::video::EBF_ONE_MINUS_SRC_ALPHA, irr::video::EMFN_MODULATE_1X, irr::video::EAS_TEXTURE | irr::video::EAS_VERTEX_COLOR);
    material.BlendOperation = rc_blend_mode;
    //material.BlendOperation = irr::video::EBO_ADD;
    material.AntiAliasing = rc_anti_alias;

    material.MaterialType = irr::video::EMT_ONETEXTURE_BLEND;

    VideoDriver->setMaterial(material);
}


void draw2DImage(irr::video::IVideoDriver *driver, irr::video::ITexture* texture, irr::core::rect<irr::s32> sourceRect, irr::core::position2d<irr::s32> position, irr::core::position2d<irr::s32> rotationPoint, irr::f32 rotation, irr::core::vector2df scale, bool useAlphaChannel, irr::video::SColor color, irr::core::vector2d<irr::f32> screenSize)
{
    if(rc_active_canvas < 0 || rc_active_canvas >= rc_canvas.size())
        return;

    // Store and clear the projection matrix
    irr::core::matrix4 oldProjMat = driver->getTransform(irr::video::ETS_PROJECTION);
    driver->setTransform(irr::video::ETS_PROJECTION,irr::core::matrix4());

    // Store and clear the view matrix
    irr::core::matrix4 oldViewMat = driver->getTransform(irr::video::ETS_VIEW);
    driver->setTransform(irr::video::ETS_VIEW,irr::core::matrix4());

    // Store and clear the world matrix
    irr::core::matrix4 oldWorldMat = driver->getTransform(irr::video::ETS_WORLD);
    driver->setTransform(irr::video::ETS_WORLD,irr::core::matrix4());

    // Find horizontal and vertical axes after rotation
    irr::f32 c = cos(-rotation*irr::core::DEGTORAD);
    irr::f32 s = sin(-rotation*irr::core::DEGTORAD);
    irr::core::vector2df horizontalAxis(c,s);
    irr::core::vector2df verticalAxis(s,-c);

    // First, we'll find the offset of the center and then where the center would be after rotation
    irr::core::vector2df centerOffset(position.X+sourceRect.getWidth()/2.0f*scale.X-rotationPoint.X,position.Y+sourceRect.getHeight()/2.0f*scale.Y-rotationPoint.Y);
    irr::core::vector2df center = centerOffset.X*horizontalAxis - centerOffset.Y*verticalAxis;
    center.X += rotationPoint.X;
    center.Y += rotationPoint.Y;

    // Now find the corners based off the center
    irr::core::vector2df cornerOffset(sourceRect.getWidth()*scale.X/2.0f,sourceRect.getHeight()*scale.Y/2.0f);
    verticalAxis *= cornerOffset.Y;
    horizontalAxis *= cornerOffset.X;
    irr::core::vector2df corner[4];
    corner[0] = center + verticalAxis - horizontalAxis;
    corner[1] = center + verticalAxis + horizontalAxis;
    corner[2] = center - verticalAxis - horizontalAxis;
    corner[3] = center - verticalAxis + horizontalAxis;

    // Find the uv coordinates of the sourceRect
    irr::core::vector2df textureSize(texture->getSize().Width, texture->getSize().Height);
    irr::core::vector2df uvCorner[4];
    uvCorner[0] = irr::core::vector2df(sourceRect.UpperLeftCorner.X,sourceRect.UpperLeftCorner.Y);
    uvCorner[1] = irr::core::vector2df(sourceRect.LowerRightCorner.X,sourceRect.UpperLeftCorner.Y);
    uvCorner[2] = irr::core::vector2df(sourceRect.UpperLeftCorner.X,sourceRect.LowerRightCorner.Y);
    uvCorner[3] = irr::core::vector2df(sourceRect.LowerRightCorner.X,sourceRect.LowerRightCorner.Y);
    for (irr::s32 i = 0; i < 4; i++)
            uvCorner[i] /= textureSize;

    // Vertices for the image
    irr::video::S3DVertex vertices[4];
    irr::u16 indices[6] = { 0, 1, 2, 3 ,2 ,1 };

    // Convert pixels to world coordinates
    //irr::core::vector2df screenSize(rc_canvas[rc_active_canvas].dimension.Width, rc_canvas[rc_active_canvas].dimension.Height);

    for (irr::s32 i = 0; i < 4; i++) {
            vertices[i].Pos = irr::core::vector3df(((corner[i].X/screenSize.X)-0.5f)*2.0f,((corner[i].Y/screenSize.Y)-0.5f)*-2.0f,1);
            vertices[i].TCoords = uvCorner[i];
            vertices[i].Color = color;
    }

    // Create the material
    // IMPORTANT: For irrlicht 1.8 and above you MUST ADD THIS LINE:
    // material.BlendOperation = irr::video::EBO_ADD;
    irr::video::SMaterial material;
    material.Lighting = false;
    material.ZWriteEnable = irr::video::EZW_OFF;
    material.ZBuffer = false;
    material.BackfaceCulling = false;
    material.TextureLayer[0].Texture = texture;
    material.TextureLayer[0].BilinearFilter = rc_bilinear_filter;
    material.MaterialTypeParam = irr::video::pack_textureBlendFunc(irr::video::EBF_SRC_ALPHA, irr::video::EBF_ONE_MINUS_SRC_ALPHA, irr::video::EMFN_MODULATE_1X, irr::video::EAS_TEXTURE | irr::video::EAS_VERTEX_COLOR);
    material.BlendOperation = rc_blend_mode;
    material.AntiAliasing = rc_anti_alias;
    //material.BlendOperation = irr::video::EBO_ADD;

    if (useAlphaChannel)
            material.MaterialType = irr::video::EMT_ONETEXTURE_BLEND;
    else
            material.MaterialType = irr::video::EMT_SOLID;

    driver->setMaterial(material);
    driver->drawIndexedTriangleList(&vertices[0],4,&indices[0],2);

    // Restore projection, world, and view matrices
    driver->setTransform(irr::video::ETS_PROJECTION,oldProjMat);
    driver->setTransform(irr::video::ETS_VIEW,oldViewMat);
    driver->setTransform(irr::video::ETS_WORLD,oldWorldMat);

    rc_setDriverMaterial();
}

void draw2DImage2(irr::video::IVideoDriver *driver, irr::video::ITexture* texture, irr::core::rect<irr::s32> sourceRect, irr::core::rect<irr::s32> destRect, irr::core::position2d<irr::s32> rotationPoint, irr::f32 rotation, bool useAlphaChannel, irr::video::SColor color, irr::core::vector2d<irr::f32> screenSize )
{
    if(rc_active_canvas < 0 || rc_active_canvas >= rc_canvas.size())
        return;

    // Store and clear the projection matrix
    irr::core::matrix4 oldProjMat = driver->getTransform(irr::video::ETS_PROJECTION);
    driver->setTransform(irr::video::ETS_PROJECTION,irr::core::matrix4());

    // Store and clear the view matrix
    irr::core::matrix4 oldViewMat = driver->getTransform(irr::video::ETS_VIEW);
    driver->setTransform(irr::video::ETS_VIEW,irr::core::matrix4());

    // Store and clear the world matrix
    irr::core::matrix4 oldWorldMat = driver->getTransform(irr::video::ETS_WORLD);
    driver->setTransform(irr::video::ETS_WORLD,irr::core::matrix4());

    // Find horizontal and vertical axes after rotation
    irr::f32 c = cos(-rotation*irr::core::DEGTORAD);
    irr::f32 s = sin(-rotation*irr::core::DEGTORAD);
    irr::core::vector2df horizontalAxis(c,s);
    irr::core::vector2df verticalAxis(s,-c);

    // First, we'll find the offset of the center and then where the center would be after rotation
    irr::core::vector2df centerOffset(destRect.UpperLeftCorner.X+destRect.getWidth()/2.0f-rotationPoint.X,destRect.UpperLeftCorner.Y+destRect.getHeight()/2.0f-rotationPoint.Y);
    irr::core::vector2df center = centerOffset.X*horizontalAxis - centerOffset.Y*verticalAxis;
    center.X += rotationPoint.X;
    center.Y += rotationPoint.Y;

    // Now find the corners based off the center
    irr::core::vector2df cornerOffset(destRect.getWidth()/2.0f,destRect.getHeight()/2.0f);
    verticalAxis *= cornerOffset.Y;
    horizontalAxis *= cornerOffset.X;
    irr::core::vector2df corner[4];
    corner[0] = center + verticalAxis - horizontalAxis;
    corner[1] = center + verticalAxis + horizontalAxis;
    corner[2] = center - verticalAxis - horizontalAxis;
    corner[3] = center - verticalAxis + horizontalAxis;

    // Find the uv coordinates of the sourceRect
    irr::core::vector2df textureSize(texture->getSize().Width, texture->getSize().Height);
    irr::core::vector2df uvCorner[4];
    uvCorner[0] = irr::core::vector2df(sourceRect.UpperLeftCorner.X,sourceRect.UpperLeftCorner.Y);
    uvCorner[1] = irr::core::vector2df(sourceRect.LowerRightCorner.X,sourceRect.UpperLeftCorner.Y);
    uvCorner[2] = irr::core::vector2df(sourceRect.UpperLeftCorner.X,sourceRect.LowerRightCorner.Y);
    uvCorner[3] = irr::core::vector2df(sourceRect.LowerRightCorner.X,sourceRect.LowerRightCorner.Y);
    for (irr::s32 i = 0; i < 4; i++)
            uvCorner[i] /= textureSize;

    // Vertices for the image
    irr::video::S3DVertex vertices[4];
    irr::u16 indices[6] = { 0, 1, 2, 3 ,2 ,1 };

    // Convert pixels to world coordinates
    //irr::core::vector2df screenSize(rc_canvas[rc_active_canvas].dimension.Width, rc_canvas[rc_active_canvas].dimension.Height);

    for (irr::s32 i = 0; i < 4; i++) {
            vertices[i].Pos = irr::core::vector3df(((corner[i].X/screenSize.X)-0.5f)*2.0f,((corner[i].Y/screenSize.Y)-0.5f)*-2.0f,1);
            vertices[i].TCoords = uvCorner[i];
            vertices[i].Color = color;
    }

    // Create the material
    // IMPORTANT: For irrlicht 1.8 and above you MUST ADD THIS LINE:
    // material.BlendOperation = irr::video::EBO_ADD;
    irr::video::SMaterial material;
    material.Lighting = false;
    material.ZWriteEnable = irr::video::EZW_OFF;
    material.ZBuffer = false;
    material.BackfaceCulling = false;
    material.TextureLayer[0].Texture = texture;
    material.TextureLayer[0].BilinearFilter = rc_bilinear_filter; //TODO: Add option to switch this on/off
    material.BlendOperation = rc_blend_mode;
    material.MaterialTypeParam = irr::video::pack_textureBlendFunc(irr::video::EBF_SRC_ALPHA, irr::video::EBF_ONE_MINUS_SRC_ALPHA, irr::video::EMFN_MODULATE_1X, irr::video::EAS_TEXTURE | irr::video::EAS_VERTEX_COLOR);
    material.AntiAliasing = rc_anti_alias;

    if (useAlphaChannel)
            material.MaterialType = irr::video::EMT_ONETEXTURE_BLEND;
    else
            material.MaterialType = irr::video::EMT_SOLID;

    driver->setMaterial(material);
    driver->drawIndexedTriangleList(&vertices[0],4,&indices[0],2);

    // Restore projection, world, and view matrices
    driver->setTransform(irr::video::ETS_PROJECTION,oldProjMat);
    driver->setTransform(irr::video::ETS_VIEW,oldViewMat);
    driver->setTransform(irr::video::ETS_WORLD,oldWorldMat);

    rc_setDriverMaterial();
}


SDL_Surface* convertTextureToSurface(irr::video::ITexture* itexture)
{
	Uint32 t_width, t_height;
	t_width = itexture->getSize().Width;
	t_height = itexture->getSize().Height;

	SDL_Surface* surface = SDL_CreateRGBSurface(0, t_width, t_height, 32, 0, 0, 0, 0);

	if(surface)
	{
		Uint32* surface_pixels = (Uint32*)surface->pixels;

		Uint32* texture_pixels = (Uint32*)rc_canvas[rc_active_canvas].texture->lock();

		int i = 0;
		for(int y = 0; y < t_height; y++)
		{
			for(int x = 0; x < t_width; x++)
			{
				surface_pixels[i] = texture_pixels[i];
			}
		}

		rc_canvas[rc_active_canvas].texture->unlock();
	}

	return surface;
}


#endif // RC_GFX_CORE_H_INCLUDED
