#ifndef RC_GFX_CORE_H_INCLUDED
#define RC_GFX_CORE_H_INCLUDED

#include <SDL2/SDL.h>
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
#include <bullet/btBulletDynamicsCommon.h>
#include <BulletSoftBody/btSoftRigidDynamicsWorld.h>
#include <irrBullet.h>

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
struct rc_physicsWorld2D_obj
{
	bool enabled = false;
	b2World* world;
	float timeStep = 1/20.0;      //the length of time passed to simulate (seconds)
	int velocityIterations = 8;   //how strongly to correct velocity
	int positionIterations = 3;   //how strongly to correct position
};

#define RC_CANVAS_TYPE_2D		0
#define RC_CANVAS_TYPE_3D		1
#define RC_CANVAS_TYPE_SPRITE	2

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
    irr::core::array<rc_sprite2D_obj*> sprite;
};

irr::core::array<rc_canvas_obj> rc_canvas;
irr::core::array<u32> rc_canvas_zOrder;
int rc_active_canvas = -1;

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
};

irr::core::array<rc_font_obj*> rc_font;

int rc_active_font = -1;


bool mobile_active_window_flag = true;



//------------ 3D Graphics ----------------//
#define RC_MESH_TYPE_NONE       0
#define RC_MESH_TYPE_ANIMATED   1


struct rc_mesh_obj
{
    int mesh_type = 0;
    irr::scene::IAnimatedMesh* mesh;
};
irr::core::array<rc_mesh_obj> rc_mesh;

#define RC_NODE_TYPE_NONE   	0
#define RC_NODE_TYPE_MESH   	1
#define RC_NODE_TYPE_OTMESH		2
#define RC_NODE_TYPE_LIGHT		3
#define RC_NODE_TYPE_TERRAIN	4
#define RC_NODE_TYPE_WATER		5
#define RC_NODE_TYPE_BILLBOARD	6
#define RC_NODE_TYPE_PARTICLE	7


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

struct rc_scene_node
{
    int node_type = 0;

    irr::scene::ISceneNode* mesh_node;
    irr::scene::IShadowVolumeSceneNode* shadow;
    rc_node_physics physics;

    bool transition;
    double transition_time;
    double transition_start_time;

    rc_particle_properties_obj particle_properties;

    int material_ref_index = -1;
};

irr::core::array<rc_scene_node> rc_actor;

irr::core::array<int> rc_transition_actor;


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

#endif // RC_GFX_CORE_H_INCLUDED