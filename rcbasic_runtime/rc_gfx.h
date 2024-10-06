#ifndef RC_GFX_INCLUDED
#define RC_GFX_INCLUDED

#include <SDL2/SDL.h>
#include <irrlicht.h>
#include <iostream>
#include <sstream>
#include <string>
#include <locale>
#include <codecvt>
#include <cmath>
#include <set>
#include "rc_gfx_core.h"
#include "gui_freetype_font.h"
#include "rc_utf8.h"
#include <box2d/box2d.h>
#include "rc_sprite2D.h"
#include <bullet/btBulletDynamicsCommon.h>
#include <irrtheora.h>

using namespace irr;

using namespace core;
using namespace video;
using namespace scene;


void rc_setTouchFingerEvent(SDL_FingerID fingerID, double x, double y, double pressure)
{
    for(int i = 0; i < MAX_FINGERS; i++)
    {
        if(rc_finger[i].id == -1 || rc_finger[i].id == fingerID)
        {
            rc_finger[i].id = fingerID;
            rc_finger[i].x = x;
            rc_finger[i].y = y;
            rc_finger[i].pressure = pressure;
            if(rc_finger[i].pressure > 0)
            {
                rc_fingers_pressed.insert(i);
            }
            return;
        }
    }
}

int mobile_event_filter(void* userdata, SDL_Event* evt)
{
    SDL_Event event = evt[0];

    int rc_win_width = 0;
    int rc_win_height = 0;

    if(rc_window)
        SDL_GetWindowSize(rc_window, &rc_win_width, &rc_win_height);

    switch(evt->type)
    {
        case SDL_APP_WILLENTERBACKGROUND:
            mobile_active_window_flag = false;
            break;
        case SDL_APP_DIDENTERFOREGROUND:
            if(!mobile_active_window_flag)
            {
                //rc_win_renderer[0] = SDL_GetRenderer(rc_win[0]);
            }
            mobile_active_window_flag = true;
            break;

        case SDL_FINGERDOWN:
            rc_touch = 1;
            rc_touchX = event.tfinger.x * rc_win_width;
            rc_touchY = event.tfinger.y * rc_win_height;
#ifdef RC_IOS
            rc_pressure = 1; //FIXME: On IOS pressure is always getting reported as 0 on finger down so I am just setting it to 1 until I figure this out
#else
            rc_pressure = event.tfinger.pressure;
#endif
            rc_setTouchFingerEvent(event.tfinger.fingerId, rc_touchX, rc_touchY, rc_pressure);
            break;
        case SDL_FINGERUP:
            rc_touch = 0;
            rc_mt_status = 0;
            rc_touchX = event.tfinger.x * rc_win_width;
            rc_touchY = event.tfinger.y * rc_win_height;
            rc_pressure = event.tfinger.pressure;
            rc_setTouchFingerEvent(event.tfinger.fingerId, -1, -1, 0);
            break;
        case SDL_FINGERMOTION:
            rc_touch = 1;
            rc_touchX = event.tfinger.x * rc_win_width;
            rc_touchY = event.tfinger.y * rc_win_height;
            rc_motionX = event.tfinger.dx * rc_win_width;
            rc_motionY = event.tfinger.dy * rc_win_height;
#ifdef RC_IOS
            rc_pressure = 1;
#else
            rc_pressure = event.tfinger.pressure;
#endif
            rc_setTouchFingerEvent(event.tfinger.fingerId, rc_touchX, rc_touchY, rc_pressure);
            break;
        case SDL_MULTIGESTURE:
            rc_touch = 2;
            rc_mt_status = 1;
            rc_mt_x = event.mgesture.x;
            rc_mt_y = event.mgesture.y;
            rc_mt_numFingers = event.mgesture.numFingers;
            rc_mt_dist = event.mgesture.dDist;
            rc_mt_theta = event.mgesture.dTheta;
#ifdef RC_IOS
            rc_pressure = 1;
#else
            rc_pressure = event.tfinger.pressure;
#endif
            break;

    }
    return 0;
}


bool rc_gfx_init()
{
    if(SDL_Init(SDL_INIT_EVENTS | SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC | SDL_INIT_SENSOR | SDL_INIT_NOPARACHUTE) < 0) //Audio causes init to fail on Fedora40 so I am leaving it out for now
    {
        bool rc_init_events = true;
        bool rc_init_timer = true;
        bool rc_init_video = true;
        bool rc_init_joystick = true;
        bool rc_init_haptic = true;
        bool rc_init_sensor = true;
        bool rc_init_noparachute = true;
        //os::Printer::log("SDL_Init Error: ", SDL_GetError());
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    if(SDL_Init(SDL_INIT_AUDIO) < 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        rc_init_audio = false;
    }

    #ifdef RC_MOBILE
        SDL_SetEventFilter(mobile_event_filter, NULL);
    #endif // RC_MOBILE

    device = NULL;
    VideoDriver = NULL;
    rc_window = NULL;

    keyState = SDL_GetKeyboardState(NULL);
    createKeyMap();


    for(int i = 0; i < MAX_FINGERS; i++)
    {
        rc_finger[i].id = -1;
        rc_finger[i].x = -1;
        rc_finger[i].y = -1;
        rc_finger[i].pressure = 0;
    }

    for(int i = 0; i < SDL_NumSensors(); i++)
    {
        rc_accel[num_accels] =  NULL;
        rc_gyro[num_gyros] =    NULL;
        switch(SDL_SensorGetDeviceType(i))
        {
            case SDL_SENSOR_ACCEL:
                rc_accel[num_accels] = SDL_SensorOpen(i);
                num_accels++;
                break;
            case SDL_SENSOR_GYRO:
                rc_gyro[num_gyros] = SDL_SensorOpen(i);
                num_gyros++;
                break;
        }
    }

    for(int i = 0; i < MAX_JOYSTICKS; i++)
    {
        if(i < SDL_NumJoysticks())
        {
            rc_joystick[i] = SDL_JoystickOpen(i);
            if(rc_joystick[i]==NULL)
            {
                cout << "Joystick " << i << " could not be opened: " << SDL_GetError() << endl;
            }
            rc_joyID[i] = SDL_JoystickInstanceID(rc_joystick[i]);
            #ifdef RC_WEB
            rc_haptic[i] = NULL;
            #else
            rc_haptic[i] = SDL_HapticOpenFromJoystick(rc_joystick[i]);
            SDL_HapticRumbleInit(rc_haptic[i]);
            #endif
            //if(rc_haptic[i] == NULL){ cout << "HAP NULL: " << SDL_GetError() << endl; }
            rc_numJoysticks++;
        }
        else
        {
            rc_joystick[i] = NULL;
            rc_haptic[i] =  NULL;
            rc_joyID[i] = -1;
        }
    }
    SDL_SetHint("SDL_JOYSTICK_ALLOW_BACKGROUND_EVENTS", "1");

    return true;

}

void rc_gfx_quit()
{
	if(irrtheora::videoExists())
	{
		irrtheora::stopVideo();
		irrtheora::deleteVideo();
	}

	if(device)
		device->drop();

    SDL_Quit();
}

bool rc_windowOpenEx(std::string title, int x, int y, int w, int h, uint32_t window_flags, irr::u8 AntiAlias, bool stencil_buffer, bool vsync)
{
    if(rc_window)
    {
        return false;
    }

    bool fullscreen = (window_flags & SDL_WINDOW_FULLSCREEN_DESKTOP) || (window_flags & SDL_WINDOW_FULLSCREEN);
    bool high_dpi = window_flags & SDL_WINDOW_ALLOW_HIGHDPI;
    bool borderless = window_flags & SDL_WINDOW_BORDERLESS;
    bool resizable = window_flags & SDL_WINDOW_RESIZABLE;
    bool visible = window_flags & SDL_WINDOW_SHOWN;

    uint32_t flags = SDL_WINDOW_OPENGL;
    flags |= (fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
    flags |= (high_dpi ? SDL_WINDOW_ALLOW_HIGHDPI : 0);
    flags |= (borderless ? SDL_WINDOW_BORDERLESS : 0);
    flags |= (resizable ? SDL_WINDOW_RESIZABLE : 0);
    flags |= (visible ? SDL_WINDOW_SHOWN : SDL_WINDOW_HIDDEN);

    //This size is used for virtual resolution
    rc_window_size.Width = w;
    rc_window_size.Height = h;

    rc_window = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);

    //Get the actual size of the window to set the dimensions of the device
    if(rc_window)
        SDL_GetWindowSize(rc_window, &w, &h);

    SIrrlichtCreationParameters irr_creation_params;
    irr_creation_params.DeviceType = EIDT_SDL;
    irr_creation_params.DriverType = video::EDT_OPENGL;
    irr_creation_params.WindowId = rc_window;
    irr_creation_params.WindowSize = dimension2d<u32>((u32)w, (u32)h);
    irr_creation_params.Bits = 16;
    irr_creation_params.Fullscreen = fullscreen;
    irr_creation_params.Stencilbuffer = stencil_buffer;
    irr_creation_params.Vsync = vsync;
    irr_creation_params.EventReceiver = 0;
    irr_creation_params.WindowPosition = position2d<s32>(x, y);
    irr_creation_params.AntiAlias = AntiAlias;

	device = createDeviceEx(irr_creation_params);


	if (!device)
    {
        std::cout << "WindowOpen Error: Failed to Create Renderer" << std::endl;
        return false;
    }

    VideoDriver = device->getVideoDriver();
    SceneManager = device->getSceneManager();

    irrtheora::init_irrTheora(device);

    rc_canvas.clear();
    rc_canvas_zOrder.clear();
    rc_font.clear();

    rc_canvas_obj back_buffer;
    back_buffer.texture = VideoDriver->addRenderTargetTexture(irr::core::dimension2d((irr::u32)w, (irr::u32)h), "rt", ECF_A8R8G8B8);
    back_buffer.dimension.Width = w;
    back_buffer.dimension.Height = h;
    back_buffer.viewport.position.set(0,0);
    back_buffer.viewport.dimension.set(w,h);
    VideoDriver->setRenderTarget(back_buffer.texture, true, true);
    rc_canvas.push_back(back_buffer);

	rc_physics3D.world = createIrrBulletWorld(device, true, false);
	rc_physics3D.TimeStamp = device->getTimer()->getTime();

	rc_physics3D.maxSubSteps = 1;
	rc_physics3D.fixedTimeStep = irr::f32(1.) / irr::f64(60.);

	rc_physics3D.world->setInternalTickCallback((btInternalTickCallback)myTickCallback2);

    return true;
}

bool rc_windowOpen(std::string title, int w, int h, bool fullscreen, bool vsync)
{
    uint32_t flags = SDL_WINDOW_SHOWN | (fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
    if(!rc_windowOpenEx(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flags, 0, false, vsync))
    {
        return false;
    }

    return true;
}

void rc_closeWindow_hw()
{
	irrtheora::stopVideo();
	irrtheora::deleteVideo();

    if(rc_window!=NULL)
        SDL_DestroyWindow(rc_window);
    rc_window = NULL;

    rc_canvas.clear();
    rc_canvas_zOrder.clear();
    rc_font.clear();

    device->drop();
    device = NULL;
}

void rc_cls()
{
    if(rc_canvas.size()>0)
    {
        if(rc_canvas[0].texture)
        {
            VideoDriver->setRenderTarget(rc_canvas[0].texture);
            VideoDriver->clearBuffers(true, true, true, rc_clear_color);

            if(rc_active_canvas >= 0 && rc_active_canvas < rc_canvas.size())
                if(rc_canvas[rc_active_canvas].texture)
                    VideoDriver->setRenderTarget(rc_canvas[rc_active_canvas].texture, false, false);
        }
    }
}

Uint32 rc_windowMode(int visible_flag, int fullscreen_flag, int resizable_flag, int borderless_flag, int highDPI_flag)
{
    Uint32 window_mode = ( visible_flag == 0 ? SDL_WINDOW_HIDDEN : SDL_WINDOW_SHOWN ) |
                         ( fullscreen_flag == 0 ? 0 : SDL_WINDOW_FULLSCREEN_DESKTOP ) |
                         ( resizable_flag == 0 ? 0 : SDL_WINDOW_RESIZABLE ) |
                         ( borderless_flag == 0 ? 0 : SDL_WINDOW_BORDERLESS ) |
                         ( highDPI_flag == 0 ? 0 : SDL_WINDOW_ALLOW_HIGHDPI );
    return window_mode;
}

Uint32 rc_getWindowMode()
{
    if(rc_window == NULL)
    {
        return 0;
    }
    return SDL_GetWindowFlags(rc_window);
}

void rc_raiseWindow()
{
    if(rc_window==NULL)
    {
        return;
    }
    SDL_RaiseWindow(rc_window);
}

void rc_showWindow()
{
    if(rc_window==NULL)
    {
        return;
    }
    SDL_ShowWindow(rc_window);
}

void rc_hideWindow()
{
    if(rc_window==NULL)
    {
        return;
    }
    SDL_HideWindow(rc_window);
}

void rc_getDesktopDisplayMode(int index, double * w, double * h, double * freq)
{
    SDL_DisplayMode dm;
    SDL_GetDesktopDisplayMode(index, &dm);
    *w = (double)dm.w;
    *h = (double)dm.h;
    *freq = (double)dm.refresh_rate;
}

void rc_setWindowTitle(std::string title)
{
    if(rc_window)
    {
        SDL_SetWindowTitle(rc_window, title.c_str());
    }
}

std::string rc_getWindowTitle()
{
    if(rc_window)
    {
        return SDL_GetWindowTitle(rc_window);
    }
    return "";
}

void rc_setWindowPosition(int x, int y)
{
    if(rc_window)
        SDL_SetWindowPosition(rc_window, x, y);
}

void rc_getWindowPosition(double * x, double * y)
{
    int x_data=0, y_data=0;
    if(rc_window)
        SDL_GetWindowPosition(rc_window,&x_data,&y_data);
    *x = x_data;
    *y = y_data;
}

void rc_setWindowSize(int w, int h)
{
    if(rc_window)
    {
        SDL_SetWindowSize(rc_window, w, h);

        irr::core::dimension2d<u32> win_size;
        int w, h;
        SDL_GetWindowSize(rc_window, &w, &h);
        win_size.Width = w;
        win_size.Height = h;

        device->setWindowSize(win_size);

        rc_window_size.Width = w;
        rc_window_size.Height = h;

    }
}

void rc_getWindowSize(double * w, double * h)
{
    int w_data = -1, h_data = -1;
    if(rc_window)
        SDL_GetWindowSize(rc_window, &w_data, &h_data);
    *w = w_data;
    *h = h_data;
}

void rc_setWindowMinSize(int w, int h)
{
    if(rc_window)
        SDL_SetWindowMinimumSize(rc_window, w, h);
}

void rc_getWindowMinSize(double * w, double * h)
{
    int w_data=0, h_data=0;
    if(rc_window)
        SDL_GetWindowMinimumSize(rc_window, &w_data, &h_data);
    *w = w_data;
    *h = h_data;
}

void rc_setWindowMaxSize(int w, int h)
{
    if(rc_window)
        SDL_SetWindowMaximumSize(rc_window, w, h);
}

void rc_getWindowMaxSize(double * w, double * h)
{
    int w_data=0, h_data=0;
    if(rc_window)
        SDL_GetWindowMaximumSize(rc_window, &w_data, &h_data);
    *w = w_data;
    *h = h_data;
}

bool rc_windowIsFullscreen()
{
    if(rc_window)
    {
        Uint32 wflags = SDL_GetWindowFlags(rc_window);
        Uint32 wflags_cmp1 = wflags & SDL_WINDOW_FULLSCREEN;
        Uint32 wflags_cmp2 = wflags & SDL_WINDOW_FULLSCREEN_DESKTOP;

        if(wflags_cmp1 || wflags_cmp2)
            return true;
        else
            return false;
    }

    return false;

}

bool rc_windowIsVisible()
{
    if(rc_window)
    {
        Uint32 wflags = SDL_GetWindowFlags(rc_window);
        if(wflags & SDL_WINDOW_SHOWN)
            return true;
        else
            return false;
    }

    return false;
}

bool rc_windowHasMouseFocus()
{
    if(rc_window)
    {
        Uint32 wflags = SDL_GetWindowFlags(rc_window);
        if(wflags & SDL_WINDOW_MOUSE_FOCUS)
            return true;
        else
            return false;
    }

    return false;
}

bool rc_windowHasInputFocus()
{
    if(rc_window)
    {
        Uint32 wflags = SDL_GetWindowFlags(rc_window);
        if(wflags & SDL_WINDOW_INPUT_FOCUS)
            return true;
        else
            return false;
    }

    return false;
}

bool rc_windowIsBordered()
{
    if(rc_window)
    {
        Uint32 wflags = SDL_GetWindowFlags(rc_window);
        if(wflags & SDL_WINDOW_BORDERLESS)
            return false;
        else
            return true;
    }

    return false;
}

bool rc_windowIsResizable()
{
    if(rc_window)
    {
        Uint32 wflags = SDL_GetWindowFlags(rc_window);
        if(wflags & SDL_WINDOW_RESIZABLE)
            return true;
        else
            return false;
    }

    return false;
}

bool rc_windowIsMinimized()
{
    if(rc_window)
    {
        Uint32 wflags = SDL_GetWindowFlags(rc_window);
        if(wflags & SDL_WINDOW_MINIMIZED)
            return true;
        else
            return false;
    }

    return false;
}

bool rc_windowIsMaximized()
{
    if(rc_window)
    {
        Uint32 wflags = SDL_GetWindowFlags(rc_window);
        if(wflags & SDL_WINDOW_MAXIMIZED)
            return true;
        else
            return false;
    }

    return false;
}

bool rc_setWindowFullscreen(int flag)
{
    if(rc_window)
    {
        switch(flag)
        {
            case 0:
                flag = 0;
                break;
            default:
                flag = SDL_WINDOW_FULLSCREEN_DESKTOP;
                break;
        }

        Uint32 wflags_preOp = SDL_GetWindowFlags(rc_window);
        if( flag != 0 && ( (wflags_preOp & SDL_WINDOW_FULLSCREEN_DESKTOP) || (wflags_preOp & SDL_WINDOW_FULLSCREEN) ) )
            return true;
        else if( flag == 0 && !((wflags_preOp & SDL_WINDOW_FULLSCREEN_DESKTOP) || (wflags_preOp & SDL_WINDOW_FULLSCREEN)))
            return true;

        if(SDL_SetWindowFullscreen(rc_window, flag) < 0)
        {
            return false;
        }


        int w, h;
        SDL_GetWindowSize(rc_window, &w, &h);

        irr::core::dimension2d<u32> win_size(w, h);
        device->setWindowSize(win_size);

        if(!(w==rc_window_size.Width && h==rc_window_size.Height))
        {
            //TODO: change mouse scale adjust
        }

        SDL_PumpEvents();
        SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);

        return true;
    }

    return false;
}

bool rc_maximizeWindow()
{
    if(rc_window)
    {
        SDL_MaximizeWindow(rc_window);

        SDL_DisplayMode mode;
        SDL_GetWindowDisplayMode(rc_window, &mode);

        irr::core::dimension2d<u32> win_size(mode.w, mode.h);
        device->setWindowSize(win_size);

        return true;
    }

    return false;
}

bool rc_minimizeWindow()
{
    if(rc_window)
    {
        SDL_MinimizeWindow(rc_window);

        SDL_DisplayMode mode;
        SDL_GetWindowDisplayMode(rc_window, &mode);

        irr::core::dimension2d<u32> win_size(mode.w, mode.h);
        device->setWindowSize(win_size);

        return true;
    }

    return false;
}

void rc_setWindowBordered(bool b)
{
    SDL_bool bswitch = SDL_FALSE;
    if(b)
        bswitch = SDL_TRUE;
    if(rc_window)
        SDL_SetWindowBordered(rc_window, bswitch);
}

void rc_setWindowResizable(bool b)
{
    SDL_bool bswitch = SDL_FALSE;
    if(b)
        bswitch = SDL_TRUE;
    if(rc_window)
    {
        SDL_SetWindowResizable(rc_window, bswitch);
        device->setResizable(true);
    }
}

bool rc_windowExists()
{
    return (rc_window!=NULL);
}

bool rc_restoreWindow()
{
    if(rc_window)
    {
        SDL_RestoreWindow(rc_window);

        SDL_DisplayMode mode;
        SDL_GetWindowDisplayMode(rc_window, &mode);

        irr::core::dimension2d<u32> win_size(mode.w, mode.h);
        device->setWindowSize(win_size);

        return true;
    }

    return false;
}

void rc_setWindowIcon(int slot)
{
    SDL_Rect img_rect;
    img_rect.x = 0;
    img_rect.y = 0;
    //img_rect.w = rc_image_width[slot];
    //img_rect.h = rc_image_height[slot];
    /*
    if(rc_himage[slot][win_num] != NULL)
    {
        //SDL_RendererFlip rf = (SDL_RendererFlip)(SDL_FLIP_VERTICAL);

        SDL_Surface * tmp_surf = SDL_CreateRGBSurface(0, rc_image_width[slot], rc_image_height[slot], 32, 0, 0, 0, 0);
        SDL_Texture * tmp_tex = SDL_CreateTexture(rc_win_renderer[rc_active_window], rc_pformat->format, SDL_TEXTUREACCESS_TARGET, rc_image_width[slot], rc_image_height[slot]);
        SDL_SetRenderTarget(rc_win_renderer[rc_active_window],NULL);
        SDL_RenderCopy(rc_win_renderer[rc_active_window],rc_himage[slot][rc_active_window],NULL,&img_rect);
        //SDL_RenderCopyEx(rc_win_renderer[rc_active_window],rc_himage[slot][rc_active_window],NULL,NULL,0,NULL,rf);

        SDL_RenderReadPixels(rc_win_renderer[rc_active_window], &img_rect, rc_pformat->format,tmp_surf->pixels,tmp_surf->pitch);

        SDL_SetColorKey(tmp_surf,SDL_TRUE,rc_image_colorKey[slot]);

        SDL_SetWindowIcon(rc_win[rc_active_window], tmp_surf);


        if(rc_active_screen >= 0)
            SDL_SetRenderTarget(rc_win_renderer[rc_active_window], rc_hscreen[rc_active_window][rc_active_screen]);

        SDL_DestroyTexture(tmp_tex);
        SDL_FreeSurface(tmp_surf);
    }
    */
}


bool rc_windowEvent_Close( )
{
	if(rc_win_event==RC_WIN_EVENT_CLOSE)
	{
		return true;
	}

    return false;
}

bool rc_windowEvent_Minimize( )
{
    if(rc_win_event==RC_WIN_EVENT_MINIMIZE)
		return true;

    return false;
}

bool rc_windowEvent_Maximize( )
{
    if(rc_win_event==RC_WIN_EVENT_MAXIMIZE)
		return true;

    return false;
}

bool rc_windowEvent_Resize( )
{
    if(rc_win_event==RC_WIN_EVENT_RESIZE)
		return true;

    return false;
}

void rc_setWindowAutoClose(bool exitOnClose)
{
    rc_win_exitOnClose = exitOnClose;
}



std::string rc_getClipboardText()
{
    return (std::string) SDL_GetClipboardText();
}

void rc_setClipboardText(std::string txt)
{
    SDL_SetClipboardText(txt.c_str());
}

int rc_hasClipboardText()
{
    return (int)SDL_HasClipboardText();
}


//The greater Z is, the further back the canvas is
void sortCanvasZ()
{
    for(int i = 0; i < rc_canvas_zOrder.size(); i++)
    {
        for(int j = i+1; j < rc_canvas_zOrder.size(); j++)
        {
            int ca = rc_canvas_zOrder[i];
            int cb = rc_canvas_zOrder[j];
            if(rc_canvas[cb].z >= rc_canvas[ca].z)
            {
                rc_canvas_zOrder.erase(j);
                rc_canvas_zOrder.insert(cb, i);
            }
        }
    }

    //for(int i = 0; i < rc_canvas_zOrder.size(); i++)
    //{
    //    std::cout << "Canvas[" << i << "] Z = " << rc_canvas_zOrder[i] << ( (i+1)==rc_canvas_zOrder.size() ? "" : ", " );
    //}
    //std::cout << std::endl;
}

int rc_canvasOpen(int w, int h, int vx, int vy, int vw, int vh, int mode, int canvas_type=RC_CANVAS_TYPE_2D)
{
    if(!VideoDriver)
        return -1;

    rc_canvas_obj canvas;
    canvas.type = canvas_type;
    canvas.show3D = false;
    canvas.physics2D.enabled = false;

    canvas.texture = VideoDriver->addRenderTargetTexture(irr::core::dimension2d<u32>(w,h), "rt", ECF_A8R8G8B8);
    //canvas.sprite_layer = VideoDriver->addRenderTargetTexture(irr::core::dimension2d<u32>(w,h), "rt", ECF_A8R8G8B8);

    if(!canvas.texture)
        return -1;


    if(SceneManager && canvas_type==RC_CANVAS_TYPE_3D)
    {
    	canvas.show3D = true;
        canvas.camera.init(SceneManager, 0, 0, 0);
        //canvas.camera = SceneManager->addCameraSceneNode(0, vector3df(0,0,0), vector3df(0,0,0));
        //canvas.camera->setPosition(irr::core::vector3df(0,0,0));
        //canvas.camera->setTarget(irr::core::vector3df(0,0,100));
        //canvas.camera->bindTargetAndRotation(true);
    }
    else if(!SceneManager)
		return -1;

    //std::cout << "texture format = " << canvas.texture->getColorFormat() << std::endl;

    canvas.dimension.Width = w;
    canvas.dimension.Height = h;

    canvas.viewport.position.X = vx;
    canvas.viewport.position.Y = vy;
    canvas.viewport.dimension.Width = vw;
    canvas.viewport.dimension.Height = vh;

    canvas.offset.X = 0;
    canvas.offset.Y = 0;

    canvas.mode = mode;

    canvas.color_mod = irr::video::SColor(255,255,255,255).color;

    //2D Physics World
    canvas.physics2D.world = NULL;
    if(canvas_type == RC_CANVAS_TYPE_SPRITE)
    {
    	b2Vec2 gravity(0, -9.8);
		canvas.physics2D.world = new b2World(gravity);
		canvas.physics2D.timeStep = 1/20.0;      //the length of time passed to simulate (seconds)
		canvas.physics2D.velocityIterations = 8;   //how strongly to correct velocity
		canvas.physics2D.positionIterations = 3;   //how strongly to correct position
		canvas.physics2D.enabled = true;
    }

    switch(mode)
    {
        case 0:
            break;
        case 1:
            VideoDriver->makeColorKeyTexture(canvas.texture, irr::video::SColor(0,0,0,0));
            break;
    }

    int canvas_id = -1;

    for(int i = 0; i < rc_canvas.size(); i++)
    {
        if(!rc_canvas[i].texture)
        {
            canvas_id = i;
            break;
        }
    }

    if(canvas_id < 0)
    {
        canvas_id = rc_canvas.size();
        rc_canvas.push_back(canvas);
    }

    if(rc_active_canvas < 0)
        rc_active_canvas = canvas_id;

    for(int i = 0; i < rc_canvas_zOrder.size(); i++)
    {
        if(rc_canvas_zOrder[i] == canvas_id)
        {
            rc_canvas_zOrder.erase(i);
            i--;
        }
    }

    rc_canvas_zOrder.push_back(canvas_id);

    sortCanvasZ();


    return canvas_id;
}


void rc_canvasClose(int canvas_id)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size()) //canvas 0 is being excluded because its the back buffer
        return;

    if(rc_canvas[canvas_id].texture != NULL)
        VideoDriver->removeTexture(rc_canvas[canvas_id].texture);

    rc_canvas[canvas_id].texture = NULL;

    if(rc_canvas[canvas_id].physics2D.world)
		delete rc_canvas[canvas_id].physics2D.world;

	rc_canvas[canvas_id].physics2D.world = NULL;

	//sprites are destroyed when the world is deleted so I just to set the active attribute to false and set the body to NULL
	for(int i = 0; i < rc_canvas[canvas_id].sprite.size(); i++)
	{
		rc_canvas[canvas_id].sprite[i]->active = false;
		rc_canvas[canvas_id].sprite[i]->physics.body = NULL;
	}

	rc_canvas[canvas_id].sprite.clear();

    if(rc_active_canvas == canvas_id)
        rc_active_canvas = -1;

    for(int i = 0; i < rc_canvas_zOrder.size(); i++)
    {
        if(rc_canvas_zOrder[i] == canvas_id)
        {
            rc_canvas_zOrder.erase(i);
            break;
        }
    }
}

void rc_setCanvas3D(int canvas_id, bool flag)
{
    if(canvas_id > 0 && canvas_id < rc_canvas.size())
        rc_canvas[canvas_id].show3D = flag;
}

int rc_canvasOpen3D(int vx, int vy, int vw, int vh, int mode)
{
	return rc_canvasOpen(vw, vh, vx, vy, vw, vh, mode, RC_CANVAS_TYPE_3D);
}

int rc_canvasOpenSpriteLayer(int w, int h, int vx, int vy, int vw, int vh)
{
	return rc_canvasOpen(w, h, vx, vy, vw, vh, 1, RC_CANVAS_TYPE_SPRITE);
}

void rc_setCanvasPhysics2D(int canvas_id, bool flag)
{
	if(canvas_id > 0 && canvas_id < rc_canvas.size())
		rc_canvas[canvas_id].physics2D.enabled = flag;
}

void rc_setActiveCanvas(int canvas_id)
{
    rc_active_canvas = canvas_id;

    if(rc_active_canvas >= 0 && rc_active_canvas < rc_canvas.size())
    {
        if(rc_canvas[rc_active_canvas].texture)
            VideoDriver->setRenderTarget(rc_canvas[rc_active_canvas].texture, false, false);
    }
}

int rc_activeCanvas()
{
    return rc_active_canvas;
}

void rc_clearCanvas()
{
    if(rc_active_canvas >= 0 && rc_active_canvas < rc_canvas.size())
    {
        if(rc_canvas[rc_active_canvas].texture)
            VideoDriver->clearBuffers(true, true, true, rc_clear_color);
    }
}

void rc_setCanvasVisible(int canvas_id, bool flag)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size()) //canvas 0 is being excluded because its the back buffer
        return;

    if(rc_canvas[canvas_id].texture)
        rc_canvas[canvas_id].visible = flag;
}

bool rc_canvasIsVisible(int canvas_id)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size()) //canvas 0 is being excluded because its the back buffer
        return false;

    if(rc_canvas[canvas_id].texture)
        return rc_canvas[canvas_id].visible;

    return false;
}

void rc_setCanvasViewport(int canvas_id, int x, int y, int w, int h)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size()) //canvas 0 is being excluded because its the back buffer
        return;

    if(rc_canvas[canvas_id].texture)
    {
        rc_canvas[canvas_id].viewport.position = irr::core::vector2d<irr::s32>(x, y);
        rc_canvas[canvas_id].viewport.dimension = irr::core::dimension2d<irr::u32>(w, h);
    }
}

void rc_getCanvasViewport(int canvas_id, double* x, double* y, double* w, double* h)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size()) //canvas 0 is being excluded because its the back buffer
        return;

    if(rc_canvas[canvas_id].texture)
    {
        *x = (double)rc_canvas[canvas_id].viewport.position.X;
        *y = (double)rc_canvas[canvas_id].viewport.position.Y;
        *w = rc_canvas[canvas_id].viewport.dimension.Width;
        *h = rc_canvas[canvas_id].viewport.dimension.Height;
    }
}

void rc_setCanvasOffset(int canvas_id, int x, int y)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size()) //canvas 0 is being excluded because its the back buffer
        return;

    if(rc_canvas[canvas_id].texture)
    {
        rc_canvas[canvas_id].offset = irr::core::vector2d<irr::s32>(x, y);
    }
}

void rc_getCanvasOffset(int canvas_id, double* x, double* y)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size()) //canvas 0 is being excluded because its the back buffer
        return;

    if(rc_canvas[canvas_id].texture)
    {
        *x = (double)rc_canvas[canvas_id].offset.X;
        *y = (double)rc_canvas[canvas_id].offset.Y;
    }
}

void rc_getCanvasSize(int canvas_id, double* w, double* h)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size()) //canvas 0 is being excluded because its the back buffer
        return;

    if(rc_canvas[canvas_id].texture)
    {
        *w = (double)rc_canvas[canvas_id].dimension.Width;
        *h = (double)rc_canvas[canvas_id].dimension.Height;
    }
}

void rc_setCanvasColorMod(int canvas_id, Uint32 color_mod)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size()) //canvas 0 is being excluded because its the back buffer
        return;

    if(rc_canvas[canvas_id].texture)
    {
        rc_canvas[canvas_id].color_mod = color_mod;
    }
}

Uint32 rc_getCanvasColorMod(int canvas_id)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size()) //canvas 0 is being excluded because its the back buffer
        return 0;

    if(rc_canvas[canvas_id].texture)
    {
        return rc_canvas[canvas_id].color_mod;
    }

    return 0;
}

void rc_setCanvasAlpha(int canvas_id, Uint32 alpha)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size()) //canvas 0 is being excluded because its the back buffer
        return;

    if(rc_canvas[canvas_id].texture)
    {
        irr::video::SColor color(rc_canvas[canvas_id].color_mod);
        color.setAlpha(alpha);
        rc_canvas[canvas_id].color_mod = color.color;
    }
}

Uint32 rc_canvasAlpha(int canvas_id)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size()) //canvas 0 is being excluded because its the back buffer
        return 0;

    if(rc_canvas[canvas_id].texture)
    {
        irr::video::SColor color(rc_canvas[canvas_id].color_mod);
        Uint32 alpha = color.getAlpha();
        return alpha;
    }
    return 0;
}

void rc_setCanvasZ(int canvas_id, int z)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size()) //canvas 0 is being excluded because its the back buffer
        return;

    rc_canvas[canvas_id].z = z;
    sortCanvasZ();
}

int rc_getCanvasZ(int canvas_id)
{
    if(canvas_id <= 0 || canvas_id >= rc_canvas.size()) //canvas 0 is being excluded because its the back buffer
        return 0;

    if(rc_canvas[canvas_id].texture)
    {
        return rc_canvas[canvas_id].z;
    }

    return 0;
}

int rc_cloneCanvas(int origin_canvas_id, int mode)
{
	if(!VideoDriver)
        return -1;

	if(origin_canvas_id < 0 || origin_canvas_id >= rc_canvas.size())
		return -1;

	if(!rc_canvas[origin_canvas_id].texture)
		return -1;

    rc_canvas_obj canvas;
    canvas.type = rc_canvas[origin_canvas_id].type;
    canvas.physics2D.enabled = false; //There is no need for this to process its own physics since its done on the origin
    canvas.show3D = rc_canvas[origin_canvas_id].show3D;
    canvas.color_mod = rc_canvas[origin_canvas_id].color_mod;
    canvas.texture = rc_canvas[origin_canvas_id].texture;
    //canvas.sprite_layer = rc_canvas[origin_canvas_id].sprite_layer;

    if(!canvas.texture)
        return -1;


    if(SceneManager)
    {
        canvas.camera.init(SceneManager, 0, 0, 0);
        //canvas.camera = SceneManager->addCameraSceneNode(0, vector3df(0,0,0), vector3df(0,0,0));
        //canvas.camera->setPosition(irr::core::vector3df(0,0,0));
        //canvas.camera->setTarget(irr::core::vector3df(0,0,100));
        //canvas.camera->bindTargetAndRotation(true);
    }

    //std::cout << "texture format = " << canvas.texture->getColorFormat() << std::endl;

    canvas.dimension.Width = rc_canvas[origin_canvas_id].dimension.Width;
    canvas.dimension.Height = rc_canvas[origin_canvas_id].dimension.Height;

    canvas.viewport.position.X = rc_canvas[origin_canvas_id].viewport.position.X;
    canvas.viewport.position.Y = rc_canvas[origin_canvas_id].viewport.position.Y;
    canvas.viewport.dimension.Width = rc_canvas[origin_canvas_id].viewport.dimension.Width;
    canvas.viewport.dimension.Height = rc_canvas[origin_canvas_id].viewport.dimension.Height;

    canvas.offset.X = 0;
    canvas.offset.Y = 0;

    canvas.mode = mode;

    canvas.color_mod = irr::video::SColor(255,255,255,255).color;

    //2D Physics World
    b2Vec2 gravity(0, -9.8);
    canvas.physics2D.world = new b2World(gravity);
    canvas.physics2D.timeStep = 1/20.0;      //the length of time passed to simulate (seconds)
	canvas.physics2D.velocityIterations = 8;   //how strongly to correct velocity
	canvas.physics2D.positionIterations = 3;   //how strongly to correct position


    switch(mode)
    {
        case 0:
            break;
        case 1:
            VideoDriver->makeColorKeyTexture(canvas.texture, irr::video::SColor(0,0,0,0));
            break;
    }

    int canvas_id = -1;

    for(int i = 0; i < rc_canvas.size(); i++)
    {
        if(!rc_canvas[i].texture)
        {
            canvas_id = i;
            break;
        }
    }

    if(canvas_id < 0)
    {
        canvas_id = rc_canvas.size();
        rc_canvas.push_back(canvas);
    }

    if(rc_active_canvas < 0)
        rc_active_canvas = canvas_id;

    for(int i = 0; i < rc_canvas_zOrder.size(); i++)
    {
        if(rc_canvas_zOrder[i] == canvas_id)
        {
            rc_canvas_zOrder.erase(i);
            i--;
        }
    }

    rc_canvas_zOrder.push_back(canvas_id);

    sortCanvasZ();


    return canvas_id;
}

void rc_setClearColor(Uint32 color)
{
    rc_clear_color.set(color);
}



Uint32 rc_rgba(Uint32 r, Uint32 g, Uint32 b, Uint32 a)
{
    irr::video::SColor color(a, r, g, b);
    return color.color;
}

Uint32 rc_rgb(Uint32 r, Uint32 g, Uint32 b)
{
    irr::video::SColor color(255, r, g, b);
    return color.color;
}


void rc_setColor(Uint32 color)
{
    rc_active_color.set(color);
}

Uint32 rc_getPixel(int x, int y)
{
    if(!rc_canvas[0].texture)
    {
        return 0;
    }

    if(x < 0 || x >= rc_window_size.Width)
        x = 0;

    if(y < 0 || y >= rc_window_size.Height)
        y = 0;


    irr::video::ITexture* texture = rc_canvas[0].texture;

    video::ECOLOR_FORMAT format = texture->getColorFormat(); //std::cout << "format = " << (int) format << std::endl;

    Uint32 color = 0;

    //this if statement is unnessesary since right now ECF_A8R8G8B8 is the only color format supported.
    //I am leaving it here since I may want to support more color formats in the future
    if(video::ECF_A8R8G8B8 == format)
    {
        u8 * texels = (u8 *)texture->lock(irr::video::ETLM_READ_ONLY);

        u32 pitch = texture->getPitch();

        irr::video::SColor * texel = (SColor *)(texels + ((y * pitch) + (x * sizeof(SColor))));

        irr::video::SColor c = texel[0];

        texture->unlock();

        //std::cout << "color(" << x << ", " << y << ") = " << c.getRed() << ", " << c.getGreen() << ", " << c.getBlue() << std::endl;
    }

    return color;

}

void rc_drawRect(int x, int y, int w, int h)
{
    irr::core::vector2d<s32> r_pos(x,y);
    irr::core::dimension2d<s32> r_dim(w,h);
    irr::core::rect<s32> r(r_pos, r_dim);
    //std::cout << "drawRect: color=" << rc_active_color.color << " ( " << x << ", " << y << ", " << w << ", " << h << " ) " << std::endl;
    VideoDriver->draw2DRectangleOutline(r, rc_active_color);
}

void rc_drawRectFill(int x, int y, int w, int h)
{
    irr::core::vector2d<s32> r_pos(x,y);
    irr::core::dimension2d<s32> r_dim(w,h);
    irr::core::rect<s32> r(r_pos, r_dim);
    //std::cout << "drawRect: color=" << rc_active_color.color << " ( " << x << ", " << y << ", " << w << ", " << h << " ) " << std::endl;
    VideoDriver->draw2DRectangle(rc_active_color, r);
}

void rc_drawCircle(int x, int y, double r)
{
    irr::core::vector2d<s32> r_pos(x,y);

    VideoDriver->draw2DPolygon(r_pos, r, rc_active_color, 30);
}



//Filled Circle Code from CuteAlien on Irrlicht forum
struct CircleSettings
{
    vector2di center;       // in screen coordinates
    f32 radius;             // in pixels
    f32 radius2;
    video::SColor color;
    u32 numVertices = 21;   // including center
};

void makeCircle(irr::core::array<irr::video::S3DVertex>& vertices, irr::core::array<irr::u16>& indices, const CircleSettings& settings)
{
    const f64 stepSize = 360.0 / (f64)(settings.numVertices-1); // degree angles between vertex points on circle
    indices.set_used(settings.numVertices+1);   // one more as first and last vertex in circle is identical
    for ( u32 i=0; i<settings.numVertices; ++i)
        indices[i] = i;
    indices[settings.numVertices] = 1;

    const vector2df centerf((f32)settings.center.X, (f32)settings.center.Y);
    vertices.set_used(settings.numVertices);
    vertices[0] = video::S3DVertex(centerf.X, centerf.Y, 0.f, 0.f, 1.f, 0.f, settings.color, 0.5f, 0.5f);
    for ( u32 i=0; i < settings.numVertices-1; ++i )
    {
        vector2df offset(0.f, settings.radius);
        offset.rotateBy(i*stepSize);
        vertices[i+1] = video::S3DVertex(centerf.X+offset.X, centerf.Y+offset.Y, 0.f, 0.f, 1.f, 0.f, settings.color, 0.5f, 0.5f);
    }
}

void rc_drawCircleFill(int x, int y, double r)
{
    irr::core::vector2d<s32> r_pos(x,y);

    // create the circle
    irr::core::array<irr::video::S3DVertex> verticesCircle;
    irr::core::array<irr::u16> indicesCircle;
    CircleSettings circle;
    circle.center = r_pos;
    circle.radius = r;
    circle.color = rc_active_color;
    makeCircle(verticesCircle, indicesCircle, circle);

    VideoDriver->draw2DVertexPrimitiveList(verticesCircle.pointer(), verticesCircle.size(),
        indicesCircle.pointer(), indicesCircle.size()-2, video::EVT_STANDARD, scene::EPT_TRIANGLE_FAN,
        video::EIT_16BIT);
}

void rc_drawLine(int x1, int y1, int x2, int y2)
{
    irr::core::vector2d<s32> r_pos_start(x1,y1);
    irr::core::vector2d<s32> r_pos_end(x2,y2);

    VideoDriver->draw2DLine(r_pos_start, r_pos_end, rc_active_color);
}

void rc_poly(Uint32 n, double* vx_d, double* vy_d)
{
    if(n <= 0)
        return;

    for(int i = 1; i < n; i++)
    {
        rc_drawLine((int)vx_d[i-1], (int)vy_d[i-1], (int)vx_d[i], (int)vy_d[i]);
    }

    rc_drawLine((int)vx_d[n-1], (int)vy_d[n-1], (int)vx_d[0], (int)vy_d[0]);
}

void rc_drawPixel(int x, int y)
{
    VideoDriver->drawPixel(x, y, rc_active_color);
}


double radians(double degree)
{
    double pi = 3.14159265359;
    return (degree * (pi / 180));
}

void makeEllipse(irr::core::array<irr::video::S3DVertex>& vertices, irr::core::array<irr::u16>& indices, const CircleSettings& settings)
{
    const f64 stepSize = 360.0 / (f64)(settings.numVertices-1); // degree angles between vertex points on circle
    indices.set_used(settings.numVertices+1);   // one more as first and last vertex in circle is identical
    for ( u32 i=0; i<settings.numVertices; ++i)
        indices[i] = i;
    indices[settings.numVertices] = 1;

    const vector2df centerf((f32)settings.center.X, (f32)settings.center.Y);
    vertices.set_used(settings.numVertices);
    vertices[0] = video::S3DVertex(centerf.X, centerf.Y, 0.f, 0.f, 1.f, 0.f, settings.color, 0.5f, 0.5f);
    int rx = settings.radius2;
    int ry = settings.radius;
    for ( u32 i=1; i < settings.numVertices; i++ )
    {
        irr::f32 x = rx * std::cos( radians(i*stepSize) ) + centerf.Y ;
        irr::f32 y = ry * std::sin( radians(i*stepSize) ) + centerf.X ;

        vertices[i] = video::S3DVertex(x, y, 0.f, 0.f, 1.f, 0.f, settings.color, 0.5f, 0.5f);
    }
}

void rc_drawEllipse(int x, int y, int rx, int ry)
{
    irr::core::vector2d<s32> r_pos(x,y);

    // create the circle
    irr::core::array<irr::video::S3DVertex> verticesCircle;
    irr::core::array<irr::u16> indicesCircle;
    CircleSettings circle;
    circle.center = r_pos;
    circle.radius = ry;
    circle.radius2 = rx;
    circle.color = rc_active_color;
    circle.numVertices = 21;
    makeEllipse(verticesCircle, indicesCircle, circle);

    for(int i = 2; i < verticesCircle.size(); i++)
    {
        rc_drawLine(verticesCircle[i-1].Pos.X, verticesCircle[i-1].Pos.Y, verticesCircle[i].Pos.X, verticesCircle[i].Pos.Y);
    }

    int n = verticesCircle.size()-1;
    rc_drawLine(verticesCircle[n].Pos.X, verticesCircle[n].Pos.Y, verticesCircle[1].Pos.X, verticesCircle[1].Pos.Y);
}

void rc_drawEllipseFill(int x, int y, int rx, int ry)
{
    irr::core::vector2d<s32> r_pos(x,y);

    // create the circle
    irr::core::array<irr::video::S3DVertex> verticesCircle;
    irr::core::array<irr::u16> indicesCircle;
    CircleSettings circle;
    circle.center = r_pos;
    circle.radius = ry;
    circle.radius2 = rx;
    circle.color = rc_active_color;
    circle.numVertices = 21;
    makeEllipse(verticesCircle, indicesCircle, circle);

    VideoDriver->draw2DVertexPrimitiveList(verticesCircle.pointer(), verticesCircle.size(),
        indicesCircle.pointer(), indicesCircle.size()-2, video::EVT_STANDARD, scene::EPT_TRIANGLE_FAN,
        video::EIT_16BIT);
}



int rc_loadFont(std::string fnt_file, int font_size)
{
	irr::io::path file_path = fnt_file.c_str();
    int font_id = -1;
    for(int i = 0; i < rc_font.size(); i++)
    {
        if(rc_font[i]!=NULL)
        {
            font_id = i;
            break;
        }
    }

    CGUITTFace* Face;
    CGUIFreetypeFont* dfont;

    Face = new CGUITTFace();
    Face->load(file_path);

    dfont = new CGUIFreetypeFont(VideoDriver);
    dfont->attach(Face, font_size);


    if(font_id < 0)
    {
        font_id = rc_font.size();

        rc_font_obj* f = new rc_font_obj();

        f->face = Face;
        f->font = dfont;
        f->font_size = font_size;

        rc_font.push_back(f);

        rc_active_font = font_id;
    }
    else
    {
        rc_font[font_id]->face = Face;
        rc_font[font_id]->font = dfont;
        rc_font[font_id]->font_size = font_size;
    }

    return font_id;
}

bool rc_fontExists(int font_id)
{
    if(font_id >= 0 && font_id < rc_font.size())
    {
        if(rc_font[font_id]->font != NULL)
            return true;
    }
    return false;
}

void rc_deleteFont(int font_id)
{
    if(rc_fontExists(font_id))
    {
        delete rc_font[font_id]->font;
        delete rc_font[font_id]->face;
        rc_font[font_id]->font = NULL;
        rc_font[font_id]->face = NULL;
        rc_font[font_id]->font_size = 0;
    }
}

void rc_setFont(int font_id)
{
    if(rc_fontExists(font_id))
        rc_active_font = font_id;
}

void rc_drawText(std::string txt, int x, int y)
{
    if(rc_fontExists(rc_active_font))
    {
        std::wstring text = utf8_to_wstring(txt);
        irr::core::dimension2d<irr::u32> text_dim = rc_font[rc_active_font]->font->getDimension(text.c_str());
        irr::core::rect<s32> tpos(x, y, text_dim.Width, rc_font[rc_active_font]->font_size);

        //std::cout << "Start drawing text: " << tpos.getWidth() << ", " << tpos.getHeight() << std::endl;
        rc_font[rc_active_font]->font->draw(text.c_str(), tpos, rc_active_color);
        //std::cout << "------------------" << std::endl;
    }
}

Uint32 rc_getTextWidth(const std::string txt)
{
    if(rc_fontExists(rc_active_font))
    {
        std::wstring text = utf8_to_wstring(txt);
        irr::core::dimension2d<irr::u32> text_dim = rc_font[rc_active_font]->font->getDimension(text.c_str());
        return text_dim.Width;
    }
    return 0;
}

Uint32 rc_getTextHeight(const std::string txt)
{
    if(rc_fontExists(rc_active_font))
    {
        std::wstring text = utf8_to_wstring(txt);
        //std::wstring wide = converter.from_bytes(txt);
        //irr::core::dimension2d<irr::u32> text_dim = rc_font[rc_active_font]->getDimension(wide.c_str());
        return rc_font[rc_active_font]->font_size;
    }
    return 0;
}

void rc_getTextSize(const std::string txt, double* w, double* h)
{
    if(rc_fontExists(rc_active_font))
    {
        std::wstring text = utf8_to_wstring(txt);
        irr::core::dimension2d<irr::u32> text_dim = rc_font[rc_active_font]->font->getDimension(text.c_str());
        *w = text_dim.Width;
        *h = rc_font[rc_active_font]->font_size;
    }
    else
    {
        *w = 0;
        *h = 0;
    }
}


#define RC_MOUSE_BUTTON_LEFT 0
#define RC_MOUSE_BUTTON_MIDDLE 1
#define RC_MOUSE_BUTTON_RIGHT 2

int rc_mwheelx = -1;
int rc_mwheely = -1;

bool rc_cursor_visible = true;


bool rc_mouseButton(int b)
{
	int ix, iy;
    int current_button_state = SDL_GetMouseState(&ix, &iy);
    return (current_button_state & SDL_BUTTON(b));
}

int rc_mouseX()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    return x;
}

int rc_mouseY()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    return y;
}

void rc_getMouse(double* x, double* y, double* mb1, double* mb2, double* mb3)
{
    int ix, iy;
    int current_button_state = SDL_GetMouseState(&ix, &iy);

    *mb1 = (current_button_state & SDL_BUTTON(SDL_BUTTON_LEFT))!=0;
    *mb2 = (current_button_state & SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0;
    *mb3 = (current_button_state & SDL_BUTTON(SDL_BUTTON_RIGHT))!=0;

    *x = ix;
    *y = iy;
}

int rc_mouseWheelX()
{
    return rc_mwheelx;
}

int rc_mouseWheelY()
{
    return rc_mwheely;
}

int rc_globalMouseX()
{
    int x, y;
    SDL_GetGlobalMouseState(&x,&y);
    return x;
}

int rc_globalMouseY()
{
    int x, y;
    SDL_GetGlobalMouseState(&x,&y);
    return y;
}

void rc_getGlobalMouse(double * x, double* y, double* mb1, double* mb2, double* mb3)
{
    int ix, iy;
    int current_button_state = SDL_GetGlobalMouseState(&ix,&iy);

    *mb1 = (current_button_state & SDL_BUTTON(SDL_BUTTON_LEFT))!=0;
    *mb2 = (current_button_state & SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0;
    *mb3 = (current_button_state & SDL_BUTTON(SDL_BUTTON_RIGHT))!=0;

    *x = ix;
    *y = iy;
}

void rc_getMouseWheel(double* x, double* y)
{
    *x = rc_mwheelx;
    *y = rc_mwheely;
}

void rc_hideMouse()
{
    SDL_ShowCursor(0);
    rc_cursor_visible = false;
}

void rc_showMouse()
{
    SDL_ShowCursor(1);
    rc_cursor_visible = true;
}

bool rc_mouseIsVisible()
{
    return rc_cursor_visible;
}


int rc_inKey()
{
    return rc_inkey_val;
}

int rc_key(int check_Key)
{
    return keyState[SDL_GetScancodeFromKey(check_Key)];
}

int rc_waitKey()
{
    bool wk_loop = true;
    SDL_Event e;
    while(wk_loop)
    {
        while(SDL_WaitEvent(&e))
        {
            if(e.type == SDL_KEYDOWN)
                return (int)e.key.keysym.sym;
        }
    }
    return 0;
}

void rc_wait(Uint32 ms)
{
    SDL_Delay(ms);
}



void rc_grabInput(bool flag)
{
    SDL_SetWindowGrab(rc_window, flag ? SDL_TRUE : SDL_FALSE);
}

int rc_windowIsGrabbed()
{
    return SDL_GetWindowGrab(rc_window);
}

void rc_warpMouse(int x, int y)
{
    SDL_WarpMouseInWindow(rc_window, x, y);
}

void rc_warpMouseGlobal(int x, int y)
{
    SDL_WarpMouseGlobal(x, y);
}

void rc_setMouseZone(int x, int y, int w, int h)
{
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = h;
    SDL_SetWindowMouseRect(rc_window, &r);
}

void rc_clearMouseZone()
{
    SDL_SetWindowMouseRect(rc_window, NULL);
}

void rc_setWindowAlwaysOnTop(bool flag)
{
    SDL_SetWindowAlwaysOnTop(rc_window, flag ? SDL_TRUE : SDL_FALSE);
}

void rc_setMouseRelative(bool flag)
{
    SDL_SetRelativeMouseMode(flag ? SDL_TRUE : SDL_FALSE);
}

void rc_setWindowVSync(bool flag)
{
    //TODO
}

int rc_openURL(std::string url)
{
    return SDL_OpenURL(url.c_str());
}

std::string rc_SDLVersion()
{
    SDL_version version;
    SDL_GetVersion(&version);

    std::stringstream ss;
    ss << (uint32_t)version.major << "." << (uint32_t)version.minor << "." << (uint32_t)version.patch;
    return ss.str();

}

int rc_flashWindow(int flag)
{
    switch(flag)
    {
        case 0:
            return SDL_FlashWindow(rc_window, SDL_FLASH_CANCEL);
        case 1:
            return SDL_FlashWindow(rc_window, SDL_FLASH_BRIEFLY);
        case 2:
            return SDL_FlashWindow(rc_window, SDL_FLASH_UNTIL_FOCUSED);
    }

    return -1;
}

int rc_messageBox(std::string title, std::string msg)
{
    return SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, title.c_str(), msg.c_str(), NULL);
}

int rc_FPS()
{
    return VideoDriver->getFPS();
}




int rc_getNumJoysticks()
{
    return SDL_NumJoysticks();
}

int rc_joyAxis(int joy_num, int axis)
{
    if(joy_num >= 0 && joy_num < MAX_JOYSTICKS)
        return SDL_JoystickGetAxis(rc_joystick[joy_num], axis);
    return 0;
}

int rc_joyButton(int joy_num, int jbutton)
{
    if(joy_num >= 0 && joy_num < MAX_JOYSTICKS)
        return SDL_JoystickGetButton(rc_joystick[joy_num], jbutton);
    return 0;
}

std::string rc_joyName(int joy_num)
{
    if(joy_num >= 0 && joy_num < MAX_JOYSTICKS)
        return (std::string)SDL_JoystickName(rc_joystick[joy_num]);
    return "";
}

int rc_numJoyButtons(int joy_num)
{
    if(joy_num >= 0 && joy_num < MAX_JOYSTICKS)
        return SDL_JoystickNumButtons(rc_joystick[joy_num]);
    return 0;
}

int rc_numJoyAxes(int joy_num)
{
    if(joy_num >= 0 && joy_num < MAX_JOYSTICKS)
        return SDL_JoystickNumAxes(rc_joystick[joy_num]);
    return 0;
}

int rc_numJoyHats(int joy_num)
{
    if(joy_num >= 0 && joy_num < MAX_JOYSTICKS)
        return SDL_JoystickNumHats(rc_joystick[joy_num]);
    return 0;
}

int rc_joyHat(int joy_num, int hat)
{
    if(joy_num >= 0 && joy_num < MAX_JOYSTICKS)
        return SDL_JoystickGetHat(rc_joystick[joy_num], hat);
    return 0;
}

int rc_numJoyTrackBalls(int joy_num)
{
    if(joy_num >= 0 && joy_num < MAX_JOYSTICKS)
        return SDL_JoystickNumBalls(rc_joystick[joy_num]);
    return 0;
}

void rc_getJoyTrackBall(int joy_num, int ball, double * dx, double * dy)
{
    int x = 0;
    int y = 0;
    if(joy_num >= 0 && joy_num < MAX_JOYSTICKS)
        SDL_JoystickGetBall(rc_joystick[joy_num], ball, &x, &y);
    *dx = x;
    *dy = y;
}

bool rc_joystickIsConnected( int joy_num )
{
    if(joy_num >= 0 && joy_num < MAX_JOYSTICKS)
    {
        if(rc_joystick[joy_num])
            return true;
        return false;
    }
    return false;
}

void rc_joyRumblePlay(int joy_num, double strength, double duration)
{
    if(joy_num >= 0 && joy_num < MAX_JOYSTICKS)
    {
        SDL_HapticRumblePlay(rc_haptic[joy_num], strength, (Uint32)duration);
    }
}

void rc_joyRumbleStop(int joy_num)
{
    if(joy_num >= 0 && joy_num < MAX_JOYSTICKS)
        SDL_HapticRumbleStop(rc_haptic[joy_num]);
}

int rc_joystickIsHaptic( int joy_num )
{
    if(joy_num >= 0 && joy_num < MAX_JOYSTICKS)
    {
        if(rc_haptic[joy_num])
            return 1;
    }
    return 0;
}





void rc_getTouchFinger(int finger, double * x, double * y, double * pressure)
{
    if(finger < MAX_FINGERS)
    {
        *x = rc_finger[finger].x;
        *y = rc_finger[finger].y;
        *pressure = rc_finger[finger].pressure;
    }
}

int rc_numFingers()
{
    return rc_fingers_pressed.size();
}

double rc_touchPressure()
{
    return rc_pressure;
}

void rc_getTouch(double * status, double * x, double * y, double * distX, double * distY)
{
    *status = (double)rc_touch;
    *x = (double)rc_touchX;
    *y = (double)rc_touchY;
    *distX = (double)rc_motionX;
    *distY = (double)rc_motionY;
    return;
}

void rc_getMultiTouch(double * status, double * x, double * y, double * numFingers, double * dist, double * theta)
{
    *status = (double)rc_mt_status;
    *x = (double)rc_mt_x;
    *y = (double)rc_mt_y;
    *numFingers = (double)rc_mt_numFingers;
    *dist = rc_mt_dist;
    *theta = rc_mt_theta;
    return;
}

void rc_getAccel(uint32_t accel_num, double * x, double * y, double * z)
{
    float sensor_data[4];
    if(accel_num < num_accels)
        SDL_SensorGetData(rc_accel[accel_num], &sensor_data[0], 3);
    *x = sensor_data[0];
    *y = sensor_data[1];
    *z = sensor_data[2];
}

std::string rc_accelName(uint32_t accel_num)
{
    if(accel_num < num_accels)
        return (std::string)SDL_SensorGetName(rc_accel[accel_num]);
    return "";
}

int rc_numAccels()
{
    return num_accels;
}

void rc_getGyro(uint32_t gyro_num, double * x, double * y, double * z)
{
    float sensor_data[4];
    if(gyro_num < num_gyros)
        SDL_SensorGetData(rc_gyro[gyro_num], &sensor_data[0], 3);
    *x = sensor_data[0];
    *y = sensor_data[1];
    *z = sensor_data[2];
}

std::string rc_gyroName(uint32_t gyro_num)
{
    if(gyro_num < num_gyros)
        return (std::string)SDL_SensorGetName(rc_gyro[gyro_num]);
    return "";
}

int rc_numGyros()
{
    return num_gyros;
}

void rc_readInput_Start()
{
    SDL_StartTextInput();
    rc_textinput_isActive = true;
    rc_textinput_string = "";
    rc_textinput_timer = clock() / (double)(CLOCKS_PER_SEC / 1000);
}

void rc_readInput_Stop()
{
    rc_textinput_isActive = false;
    rc_textinput_timer = 0;
    rc_textinput_string = "";
    SDL_StopTextInput();
}

std::string rc_readInput_Text()
{
    return rc_textinput_string;
}

void rc_readInput_SetText(std::string txt)
{
    rc_textinput_string = txt;
}

void rc_readInput_ToggleBackspace(bool flag)
{
    rc_toggleBackspace = flag;
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


int rc_loadImageEx(std::string img_file, Uint32 color_key = 0, bool use_color_key = true)
{
    rc_image_obj img;
    img.image = VideoDriver->getTexture(img_file.c_str());

    if(img.image == NULL)
        return -1;

    if(use_color_key)
        VideoDriver->makeColorKeyTexture(img.image, irr::video::SColor(color_key), false);

    int img_id = -1;

    for(int i = 0; i < rc_image.size(); i++)
    {
        if(rc_image[i].image == NULL)
        {
            img_id = i;
            break;
        }
    }

    if(img_id < 0)
    {
        img_id = rc_image.size();
        rc_image.push_back(img);
    }
    else
    {
        rc_image[img_id] = img;
    }

    return img_id;
}

int rc_loadImage(std::string img_file)
{
    return rc_loadImageEx(img_file, 0, false);
}

void rc_deleteImage(int img_id)
{
    if(img_id < 0 || img_id >= rc_image.size())
        return;

    if(rc_image[img_id].image)
    {
        rc_image[img_id].image->drop();
        rc_image[img_id].image = NULL;
        rc_image[img_id].alpha = 255;
    }
}

int rc_createImageEx(int w, int h, double * pdata, Uint32 colorkey, bool use_color_key=true)
{
    if(w <= 0 || h <=0)
        return -1;

    irr::video::IImage* image = VideoDriver->createImage(irr::video::ECF_A8R8G8B8, irr::core::dimension2d((irr::u32)w,(irr::u32)h));
    if(!image)
        return -1;

    Uint32 * img_pixels = (Uint32*)image->getData();
    for(int i = 0; i < (w*h); i++)
    {
        img_pixels[i] = (Uint32)pdata[i];
    }

    irr::video::ITexture* texture = VideoDriver->addTexture("buffer_image", image);
    image->drop();

    if(!texture)
        return -1;

    if(use_color_key)
        VideoDriver->makeColorKeyTexture(texture, irr::video::SColor(colorkey));

    int img_id = -1;
    rc_image_obj img;
    img.image = texture;
    img.alpha = 255;

    for(int i = 0; i < rc_image.size(); i++)
    {
        if(rc_image[i].image == NULL)
        {
            img_id = i;
            break;
        }
    }

    if(img_id < 0)
    {
        img_id = rc_image.size();
        rc_image.push_back(img);
    }
    else
    {
        rc_image[img_id] = img;
    }

    return img_id;
}

int rc_createImage(int w, int h, double* pdata)
{
    return rc_createImageEx(w, h, pdata, 0, false);
}


void rc_getImageBuffer(int img_id, double * pdata)
{
    if(img_id < 0 || img_id >= rc_image.size())
        return;

    if(!rc_image[img_id].image)
        return;

    Uint32* img_pixels = (Uint32*)rc_image[img_id].image->lock();

    int image_size = rc_image[img_id].image->getSize().Width * rc_image[img_id].image->getSize().Height;

    for(int i = 0; i < image_size; i++)
        pdata[i] = (double)img_pixels[i];

    rc_image[img_id].image->unlock();
}

void rc_setBilinearFilter(bool flag)
{
    rc_bilinear_filter = flag;
}

bool rc_getBilinearFilter()
{
    return rc_bilinear_filter;
}

void rc_setImageColorMod(int img_id, Uint32 color)
{
    if(img_id < 0 || img_id >= rc_image.size())
        return;

    if(rc_image[img_id].image)
    {
        rc_image[img_id].color_mod = irr::video::SColor(color);
    }
}

Uint32 rc_getImageColorMod(int img_id)
{
    if(img_id < 0 || img_id >= rc_image.size())
        return 0;

    if(rc_image[img_id].image)
    {
        return rc_image[img_id].color_mod.color;
    }

    return 0;
}


void rc_setBlendMode(int blend_mode)
{
    switch(blend_mode)
    {
        case 0: rc_blend_mode = EBO_NONE; break;
        case 1: rc_blend_mode = EBO_ADD; break;
        case 2: rc_blend_mode = EBO_SUBTRACT; break;
        case 3: rc_blend_mode = EBO_REVSUBTRACT; break;
        case 4: rc_blend_mode = EBO_MIN; break;
        case 5: rc_blend_mode = EBO_MAX; break;
        case 6: rc_blend_mode = EBO_MIN_FACTOR; break;
        case 7: rc_blend_mode = EBO_MAX_FACTOR; break;
        case 8: rc_blend_mode = EBO_MIN_ALPHA; break;
        case 9: rc_blend_mode = EBO_MAX_ALPHA; break;
    }
}

int rc_getBlendMode()
{
    return (int)rc_blend_mode;
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
    //material.AntiAliasing = irr::video::EAAM_OFF;

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
}


void rc_drawImage(int img_id, int x, int y)
{
    if(img_id < 0 || img_id >= rc_image.size())
        return;

    if(rc_image[img_id].image)
    {
        irr::core::dimension2d<irr::u32> src_size = rc_image[img_id].image->getSize();
        irr::core::rect<irr::s32> sourceRect( irr::core::vector2d(0, 0), src_size);

        irr::core::position2d<irr::s32> position(x, y);

        irr::core::position2d<irr::s32> rotationPoint(0, 0); //since we are not rotating it doesn't matter

        irr::f32 rotation = 0;
        irr::core::vector2df scale(1.0, 1.0);
        bool useAlphaChannel = true;
        irr::video::SColor color(rc_image[img_id].alpha,
                                 rc_image[img_id].color_mod.getRed(),
                                 rc_image[img_id].color_mod.getGreen(),
                                 rc_image[img_id].color_mod.getBlue());

        //irr::core::rect<irr::s32> dest( irr::core::vector2d(x, y), irr::core::dimension2d(src_w, src_h));;

        irr::core::vector2df screenSize(rc_canvas[rc_active_canvas].dimension.Width, rc_canvas[rc_active_canvas].dimension.Height);

        draw2DImage(VideoDriver, rc_image[img_id].image, sourceRect, position, rotationPoint, rotation, scale, useAlphaChannel, color, screenSize);
    }
}

int rc_copyImage(int src_id)
{
    if(src_id < 0 || src_id >= rc_image.size())
        return -1;

    if(!rc_image[src_id].image)
        return -1;

    irr::video::ITexture* texture = VideoDriver->addRenderTargetTexture(rc_image[src_id].image->getSize(), "img_copy", irr::video::ECF_A8R8G8B8);

    if(!texture)
        return -1;

    VideoDriver->setRenderTarget(texture, true, false, irr::video::SColor(0));


    irr::core::dimension2d<irr::u32> src_size = rc_image[src_id].image->getSize();
    irr::core::rect<irr::s32> sourceRect( irr::core::vector2d(0, 0), src_size);
    irr::core::position2d<irr::s32> position(0, 0);
    irr::core::position2d<irr::s32> rotationPoint(0, 0); //since we are not rotating it doesn't matter
    irr::f32 rotation = 0;
    irr::core::vector2df scale(1.0, 1.0);
    bool useAlphaChannel = true;
    irr::video::SColor color(rc_image[src_id].alpha,
                             rc_image[src_id].color_mod.getRed(),
                             rc_image[src_id].color_mod.getGreen(),
                             rc_image[src_id].color_mod.getBlue());
    irr::core::vector2df screenSize(src_size.Width, src_size.Height);

    draw2DImage(VideoDriver, rc_image[src_id].image, sourceRect, position, rotationPoint, rotation, scale, useAlphaChannel, color, screenSize);

    rc_setActiveCanvas(rc_active_canvas);

    int img_id = -1;
    rc_image_obj img;
    img.image = texture;
    img.alpha = 255;

    for(int i = 0; i < rc_image.size(); i++)
    {
        if(rc_image[i].image == NULL)
        {
            img_id = i;
            break;
        }
    }

    if(img_id < 0)
    {
        img_id = rc_image.size();
        rc_image.push_back(img);
    }
    else
    {
        rc_image[img_id] = img;
    }

    return img_id;
}


void rc_drawImage_Rotate(int img_id, int x, int y, double angle)
{
    if(img_id < 0 || img_id >= rc_image.size())
        return;

    if(rc_image[img_id].image)
    {
        irr::core::dimension2d<irr::u32> src_size = rc_image[img_id].image->getSize();
        irr::core::rect<irr::s32> sourceRect(0, 0, src_size.Width, src_size.Height);

        irr::core::position2d<irr::s32> position(x, y);

        irr::core::position2d<irr::s32> rotationPoint(x + (src_size.Width/2), y + (src_size.Height/2));

        irr::f32 rotation = -1*angle;
        irr::core::vector2df scale(1.0, 1.0);
        bool useAlphaChannel = true;
        irr::video::SColor color(rc_image[img_id].alpha,
                                 rc_image[img_id].color_mod.getRed(),
                                 rc_image[img_id].color_mod.getGreen(),
                                 rc_image[img_id].color_mod.getBlue());

        irr::core::vector2df screenSize(rc_canvas[rc_active_canvas].dimension.Width, rc_canvas[rc_active_canvas].dimension.Height);

        draw2DImage(VideoDriver, rc_image[img_id].image, sourceRect, position, rotationPoint, rotation, scale, useAlphaChannel, color, screenSize);
    }
}

void rc_drawImage_Zoom(int img_id, int x, int y, double zx, double zy)
{
    if(img_id < 0 || img_id >= rc_image.size())
        return;

    if(rc_image[img_id].image)
    {
        irr::core::dimension2d<irr::u32> src_size = rc_image[img_id].image->getSize();
        irr::core::rect<irr::s32> sourceRect(0, 0, src_size.Width, src_size.Height);

        irr::core::position2d<irr::s32> position(x, y);

        irr::core::position2d<irr::s32> rotationPoint(x + (src_size.Width/2), y + (src_size.Height/2));

        irr::f32 rotation = 0;
        irr::core::vector2df scale((irr::f32)zx, (irr::f32)zy);
        bool useAlphaChannel = true;
        irr::video::SColor color(rc_image[img_id].alpha,
                                 rc_image[img_id].color_mod.getRed(),
                                 rc_image[img_id].color_mod.getGreen(),
                                 rc_image[img_id].color_mod.getBlue());

        irr::core::vector2df screenSize(rc_canvas[rc_active_canvas].dimension.Width, rc_canvas[rc_active_canvas].dimension.Height);

        draw2DImage(VideoDriver, rc_image[img_id].image, sourceRect, position, rotationPoint, rotation, scale, useAlphaChannel, color, screenSize);
    }
}

void rc_drawImage_ZoomEx(int img_id, int x, int y, int src_x, int src_y, int src_w, int src_h, double zx, double zy)
{
    if(img_id < 0 || img_id >= rc_image.size())
        return;

    if(rc_image[img_id].image)
    {
        //irr::core::dimension2d<irr::u32> src_size = rc_image[img_id].image->getSize();
        irr::core::rect<irr::s32> sourceRect( irr::core::vector2d(src_x, src_y), irr::core::dimension2d(src_w, src_h));

        irr::core::position2d<irr::s32> position(x, y);

        irr::core::position2d<irr::s32> rotationPoint(x + (src_w/2), y + (src_h/2));

        irr::f32 rotation = 0;
        irr::core::vector2df scale((irr::f32)zx, (irr::f32)zy);
        bool useAlphaChannel = true;
        irr::video::SColor color(rc_image[img_id].alpha,
                                 rc_image[img_id].color_mod.getRed(),
                                 rc_image[img_id].color_mod.getGreen(),
                                 rc_image[img_id].color_mod.getBlue());

        irr::core::vector2df screenSize(rc_canvas[rc_active_canvas].dimension.Width, rc_canvas[rc_active_canvas].dimension.Height);

        draw2DImage(VideoDriver, rc_image[img_id].image, sourceRect, position, rotationPoint, rotation, scale, useAlphaChannel, color, screenSize);
    }
}

void rc_drawImage_Rotozoom(int img_id, int x, int y, double angle, double zx, double zy)
{
    if(img_id < 0 || img_id >= rc_image.size())
        return;

    if(rc_image[img_id].image)
    {
        irr::core::dimension2d<irr::u32> src_size = rc_image[img_id].image->getSize();
        irr::core::rect<irr::s32> sourceRect(0, 0, src_size.Width, src_size.Height);

        irr::core::position2d<irr::s32> position(x, y);

        irr::core::position2d<irr::s32> rotationPoint(x + (src_size.Width/2)*zx, y + (src_size.Height/2)*zy);

        irr::f32 rotation = -1*angle;
        irr::core::vector2df scale((irr::f32)zx, (irr::f32)zy);
        bool useAlphaChannel = true;
        irr::video::SColor color(rc_image[img_id].alpha,
                                 rc_image[img_id].color_mod.getRed(),
                                 rc_image[img_id].color_mod.getGreen(),
                                 rc_image[img_id].color_mod.getBlue());

        irr::core::vector2df screenSize(rc_canvas[rc_active_canvas].dimension.Width, rc_canvas[rc_active_canvas].dimension.Height);

        draw2DImage(VideoDriver, rc_image[img_id].image, sourceRect, position, rotationPoint, rotation, scale, useAlphaChannel, color, screenSize);
    }
}

void rc_drawImage_RotozoomEx(int img_id, int x, int y, int src_x, int src_y, int src_w, int src_h, double angle, double zx, double zy)
{
    if(img_id < 0 || img_id >= rc_image.size())
        return;

    if(rc_image[img_id].image)
    {
        //irr::core::dimension2d<irr::u32> src_size = rc_image[img_id].image->getSize();
        irr::core::rect<irr::s32> sourceRect( irr::core::vector2d(src_x, src_y), irr::core::dimension2d(src_w, src_h));

        irr::core::position2d<irr::s32> position(x, y);

        irr::core::position2d<irr::s32> rotationPoint(x + (src_w/2)*zx, y + (src_h/2)*zy);

        irr::f32 rotation = -1*angle;
        irr::core::vector2df scale((irr::f32)zx, (irr::f32)zy);
        bool useAlphaChannel = true;
        irr::video::SColor color(rc_image[img_id].alpha,
                                 rc_image[img_id].color_mod.getRed(),
                                 rc_image[img_id].color_mod.getGreen(),
                                 rc_image[img_id].color_mod.getBlue());

        irr::core::vector2df screenSize(rc_canvas[rc_active_canvas].dimension.Width, rc_canvas[rc_active_canvas].dimension.Height);

        draw2DImage(VideoDriver, rc_image[img_id].image, sourceRect, position, rotationPoint, rotation, scale, useAlphaChannel, color, screenSize);
    }
}


void rc_drawImage_Flip(int img_id, int x, int y, bool h, bool v)
{
    if(img_id < 0 || img_id >= rc_image.size())
        return;

    if(rc_image[img_id].image)
    {
        irr::core::dimension2d<irr::u32> src_size = rc_image[img_id].image->getSize();
        irr::core::rect<irr::s32> sourceRect(0, 0, src_size.Width, src_size.Height);

        irr::core::position2d<irr::s32> rotationPoint(x + (src_size.Width/2), y + (src_size.Height/2));

        irr::f32 rotation = 0;
        irr::core::vector2df scale((irr::f32)(h ? -1 : 1), (irr::f32) (v ? -1 : 1));

        irr::core::position2d<irr::s32> position( (h ? x+src_size.Width : x), (v ? y+src_size.Height : y));

        bool useAlphaChannel = true;
        irr::video::SColor color(rc_image[img_id].alpha,
                                 rc_image[img_id].color_mod.getRed(),
                                 rc_image[img_id].color_mod.getGreen(),
                                 rc_image[img_id].color_mod.getBlue());

        irr::core::vector2df screenSize(rc_canvas[rc_active_canvas].dimension.Width, rc_canvas[rc_active_canvas].dimension.Height);

        draw2DImage(VideoDriver, rc_image[img_id].image, sourceRect, position, rotationPoint, rotation, scale, useAlphaChannel, color, screenSize);
    }
}

void rc_drawImage_FlipEx(int img_id, int x, int y, int src_x, int src_y, int src_w, int src_h, bool h, bool v)
{
    if(img_id < 0 || img_id >= rc_image.size())
        return;

    if(rc_image[img_id].image)
    {
        //irr::core::dimension2d<irr::u32> src_size = rc_image[img_id].image->getSize();
        irr::core::rect<irr::s32> sourceRect( irr::core::vector2d(src_x, src_y), irr::core::dimension2d(src_w, src_h));

        irr::core::position2d<irr::s32> rotationPoint(x + (src_w/2), y + (src_h/2));

        irr::f32 rotation = 0;
        irr::core::vector2df scale((irr::f32)(h ? -1 : 1), (irr::f32) (v ? -1 : 1));

        irr::core::position2d<irr::s32> position( (h ? x+src_w : x), (v ? y+src_h : y));

        bool useAlphaChannel = true;
        irr::video::SColor color(rc_image[img_id].alpha,
                                 rc_image[img_id].color_mod.getRed(),
                                 rc_image[img_id].color_mod.getGreen(),
                                 rc_image[img_id].color_mod.getBlue());

        irr::core::vector2df screenSize(rc_canvas[rc_active_canvas].dimension.Width, rc_canvas[rc_active_canvas].dimension.Height);

        draw2DImage(VideoDriver, rc_image[img_id].image, sourceRect, position, rotationPoint, rotation, scale, useAlphaChannel, color, screenSize);
    }
}


void rc_drawImage_Blit(int img_id, int x, int y, int src_x, int src_y, int src_w, int src_h)
{
    if(img_id < 0 || img_id >= rc_image.size())
        return;

    if(rc_image[img_id].image)
    {
        //irr::core::dimension2d<irr::u32> src_size = rc_image[img_id].image->getSize();
        irr::core::rect<irr::s32> sourceRect( irr::core::vector2d(src_x, src_y), irr::core::dimension2d(src_w, src_h));

        irr::core::position2d<irr::s32> position(x, y);

        irr::core::position2d<irr::s32> rotationPoint(0, 0); //since we are not rotating it doesn't matter

        irr::f32 rotation = 0;
        irr::core::vector2df scale(1.0, 1.0);
        bool useAlphaChannel = true;
        irr::video::SColor color(rc_image[img_id].alpha,
                                 rc_image[img_id].color_mod.getRed(),
                                 rc_image[img_id].color_mod.getGreen(),
                                 rc_image[img_id].color_mod.getBlue());

        irr::core::rect<irr::s32> dest( irr::core::vector2d(x, y), irr::core::dimension2d(src_w, src_h));

        irr::core::vector2df screenSize(rc_canvas[rc_active_canvas].dimension.Width, rc_canvas[rc_active_canvas].dimension.Height);

        draw2DImage(VideoDriver, rc_image[img_id].image, sourceRect, position, rotationPoint, rotation, scale, useAlphaChannel, color, screenSize);
    }
}


void rc_drawImage_RotateEx(int img_id, int x, int y, int src_x, int src_y, int src_w, int src_h, int angle)
{
    if(img_id < 0 || img_id >= rc_image.size())
        return;

    if(rc_image[img_id].image)
    {
        //irr::core::dimension2d<irr::u32> src_size = rc_image[img_id].image->getSize();
        irr::core::rect<irr::s32> sourceRect( irr::core::vector2d(src_x, src_y), irr::core::dimension2d(src_w, src_h));

        //irr::core::position2d<irr::s32> position(x, y);

        irr::core::vector2d<irr::s32> rotationPoint(x + (src_w/2), y + (src_h/2));

        irr::f32 rotation = -1*angle;
        //irr::core::vector2df scale(1.0, 1.0);
        bool useAlphaChannel = true;
        irr::video::SColor color(rc_image[img_id].alpha,
                                 rc_image[img_id].color_mod.getRed(),
                                 rc_image[img_id].color_mod.getGreen(),
                                 rc_image[img_id].color_mod.getBlue());

        irr::core::vector2df screenSize(rc_canvas[rc_active_canvas].dimension.Width, rc_canvas[rc_active_canvas].dimension.Height);

        irr::core::rect<irr::s32> dest( irr::core::vector2d(x, y), irr::core::dimension2d(src_w, src_h));

        draw2DImage2(VideoDriver, rc_image[img_id].image, sourceRect, dest, rotationPoint, rotation, useAlphaChannel, color, screenSize);
    }
}

void rc_drawImage_BlitEx(int img_id, int x, int y, int w, int h, int src_x, int src_y, int src_w, int src_h)
{
    if(img_id < 0 || img_id >= rc_image.size())
        return;

    if(rc_image[img_id].image)
    {
        //irr::core::dimension2d<irr::u32> src_size = rc_image[img_id].image->getSize();
        irr::core::rect<irr::s32> sourceRect( irr::core::vector2d(src_x, src_y), irr::core::dimension2d(src_w, src_h));

        //irr::core::position2d<irr::s32> position(x, y);

        irr::core::position2d<irr::s32> rotationPoint(0, 0); //since we are not rotating it doesn't matter

        irr::f32 rotation = 0;
        irr::core::vector2df scale(1.0, 1.0);
        bool useAlphaChannel = true;
        irr::video::SColor color(rc_image[img_id].alpha,
                                 rc_image[img_id].color_mod.getRed(),
                                 rc_image[img_id].color_mod.getGreen(),
                                 rc_image[img_id].color_mod.getBlue());

        irr::core::rect<irr::s32> dest( irr::core::vector2d(x, y), irr::core::dimension2d(w, h));

        irr::core::vector2df screenSize(rc_canvas[rc_active_canvas].dimension.Width, rc_canvas[rc_active_canvas].dimension.Height);

        draw2DImage2(VideoDriver, rc_image[img_id].image, sourceRect, dest, rotationPoint, rotation, useAlphaChannel, color, screenSize );
    }
}

void rc_setImageAlpha(int img_id, Uint8 alpha)
{
    if(img_id < 0 || img_id >= rc_image.size())
        return;

    if(rc_image[img_id].image)
    {
        rc_image[img_id].alpha = alpha;
    }
}

Uint32 rc_getImageAlpha(int img_id)
{
    if(img_id < 0 || img_id >= rc_image.size())
        return 0;

    if(rc_image[img_id].image)
    {
        return rc_image[img_id].alpha;
    }

    return 0;
}

bool rc_imageExists(int img_id)
{
    if(img_id < 0 || img_id >= rc_image.size())
        return false;

    if(rc_image[img_id].image)
        return true;

    return false;
}

void rc_getImageSize(int img_id, double* w, double* h)
{
    if(img_id < 0 || img_id >= rc_image.size())
        return;

    if(rc_image[img_id].image)
    {
        *w = (double)rc_image[img_id].image->getSize().Width;
        *h = (double)rc_image[img_id].image->getSize().Height;
    }
}

void rc_setColorKey(int img_id, Uint32 colorkey)
{
    if(!rc_imageExists(img_id))
        return;

    VideoDriver->makeColorKeyTexture(rc_image[img_id].image, irr::video::SColor(colorkey));
}



//FloodFill is technically a primitive but it uses the draw2Dimage function since the pixels returned by lock are flipped vertically
void floodFill(int x, int y, Uint32* img_pixels, Uint32 prev_color)
{
	if(x < 0 || x >= rc_canvas[rc_active_canvas].texture->getSize().Width)
		return;

	if(y < 0 || y >= rc_canvas[rc_active_canvas].texture->getSize().Height)
		return;

	if(img_pixels[y*rc_canvas[rc_active_canvas].texture->getSize().Width+x] != prev_color)
		return;

	img_pixels[y*rc_canvas[rc_active_canvas].texture->getSize().Width+x] = rc_active_color.color;

	floodFill(x-1, y, img_pixels, prev_color);
	floodFill(x, y-1, img_pixels, prev_color);
	floodFill(x+1, y, img_pixels, prev_color);
	floodFill(x, y+1, img_pixels, prev_color);
}

void rc_floodFill(int x, int y)
{
    if(!rc_canvas[rc_active_canvas].texture)
        return;

	if(x < 0 || x >= rc_canvas[rc_active_canvas].dimension.Width)
		return;

	if(y < 0 || y >= rc_canvas[rc_active_canvas].dimension.Height)
		return;

    Uint32* img_pixels = (Uint32*)rc_canvas[rc_active_canvas].texture->lock();

    Uint32 flood_size = rc_canvas[rc_active_canvas].texture->getSize().Width*rc_canvas[rc_active_canvas].texture->getSize().Height;
    Uint32* flood_buffer = new Uint32[flood_size];

    for(int i = 0; i < flood_size; i++)
	{
		flood_buffer[i] = img_pixels[i];
	}

    floodFill(x, y,flood_buffer, flood_buffer[y*rc_canvas[rc_active_canvas].texture->getSize().Width+x]);

    for(int i = 0; i < flood_size; i++)
	{
		img_pixels[i] = flood_buffer[i];
	}

    rc_canvas[rc_active_canvas].texture->unlock();

    Uint32 nw = rc_canvas[rc_active_canvas].dimension.Width;
	Uint32 nh = rc_canvas[rc_active_canvas].dimension.Height;
    irr::video::ITexture* new_canvas = VideoDriver->addRenderTargetTexture(irr::core::dimension2d<u32>(nw,nh), "rt", ECF_A8R8G8B8);
    irr::video::ITexture* old_canvas = rc_canvas[rc_active_canvas].texture;
    rc_canvas[rc_active_canvas].texture = new_canvas;

    irr::core::dimension2d<irr::u32> src_size = new_canvas->getSize();
	irr::core::rect<irr::s32> sourceRect(0, 0, src_size.Width, src_size.Height);

	irr::core::position2d<irr::s32> rotationPoint((src_size.Width/2), (src_size.Height/2));

	irr::f32 rotation = 0;
	irr::core::vector2df scale((irr::f32)1, (irr::f32)-1);

	irr::core::position2d<irr::s32> position(0, src_size.Height);

	bool useAlphaChannel = true;
	irr::video::SColor color(rc_canvas[rc_active_canvas].color_mod);

	irr::core::vector2df screenSize(rc_canvas[rc_active_canvas].dimension.Width, rc_canvas[rc_active_canvas].dimension.Height);

	rc_setActiveCanvas(rc_active_canvas);
	draw2DImage(VideoDriver, old_canvas, sourceRect, position, rotationPoint, rotation, scale, useAlphaChannel, color, screenSize);

	VideoDriver->removeTexture(old_canvas);
}




void drawCanvasImage(irr::video::ITexture* texture, int x, int y, int src_x, int src_y, int src_w, int src_h, int tgt_width, int tgt_height)
{
    if(texture)
    {
        irr::core::rect<irr::s32> sourceRect( irr::core::vector2d(src_x, src_y), irr::core::dimension2d(src_w, src_h));

        irr::core::position2d<irr::s32> position(x, y);

        irr::core::position2d<irr::s32> rotationPoint(0, 0); //since we are not rotating it doesn't matter

        irr::f32 rotation = 0;
        irr::core::vector2df scale(1.0, 1.0);
        bool useAlphaChannel = true;
        irr::video::SColor color(255,255,255,255);

        irr::core::rect<irr::s32> dest( irr::core::vector2d(x, y), irr::core::dimension2d(src_w, src_h));

        irr::core::vector2df screenSize(tgt_width, tgt_height);

        draw2DImage(VideoDriver, texture, sourceRect, position, rotationPoint, rotation, scale, useAlphaChannel, color, screenSize);
    }
}


int rc_windowClip(int x, int y, int w, int h)
{
    if(w <= 0 || h <=0)
        return -1;

    if(rc_canvas.size()>0)
    {
        if(!rc_canvas[0].texture)
            return -1;
    }
    else
        return -1;

    irr::video::ITexture* texture = VideoDriver->addRenderTargetTexture(irr::core::dimension2d((irr::u32)w, (irr::u32)h), "win_clip_image", irr::video::ECF_A8R8G8B8);

    if(!texture)
        return -1;

    VideoDriver->setRenderTarget(texture);

    drawCanvasImage(rc_canvas[0].texture, 0, 0, x, y, w, h, w, h);

    VideoDriver->setRenderTarget(rc_canvas[0].texture);

    if(rc_active_canvas >= 0 && rc_active_canvas < rc_canvas.size())
        if(rc_canvas[rc_active_canvas].texture)
            VideoDriver->setRenderTarget(rc_canvas[rc_active_canvas].texture, false, false);


    int img_id = -1;
    rc_image_obj img;
    img.image = texture;
    img.alpha = 255;

    for(int i = 0; i < rc_image.size(); i++)
    {
        if(rc_image[i].image == NULL)
        {
            img_id = i;
            break;
        }
    }

    if(img_id < 0)
    {
        img_id = rc_image.size();
        rc_image.push_back(img);
    }
    else
    {
        rc_image[img_id] = img;
    }

    return img_id;
}


int rc_canvasClip(int x, int y, int w, int h)
{
    if(w <= 0 || h <=0)
        return -1;

    if(rc_active_canvas >= 0 && rc_active_canvas < rc_canvas.size())
    {
        if(!rc_canvas[rc_active_canvas].texture)
            return -1;
    }
    else
        return -1;

    irr::video::ITexture* texture = VideoDriver->addRenderTargetTexture(irr::core::dimension2d((irr::u32)w, (irr::u32)h), "canvas_clip_image", irr::video::ECF_A8R8G8B8);

    if(!texture)
        return -1;

    VideoDriver->setRenderTarget(texture);

    drawCanvasImage(rc_canvas[rc_active_canvas].texture, 0, 0, x, y, w, h, w, h);

    VideoDriver->setRenderTarget(rc_canvas[rc_active_canvas].texture, false, false);

    int img_id = -1;
    rc_image_obj img;
    img.image = texture;
    img.alpha = 255;

    for(int i = 0; i < rc_image.size(); i++)
    {
        if(rc_image[i].image == NULL)
        {
            img_id = i;
            break;
        }
    }

    if(img_id < 0)
    {
        img_id = rc_image.size();
        rc_image.push_back(img);
    }
    else
    {
        rc_image[img_id] = img;
    }

    return img_id;
}



//------------------------------SPRITES-------------------------------------------------------
int rc_createSprite(int img_id)
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
	rc_sprite[spr_id].physics_enabled = false;
	rc_sprite[spr_id].visible = true;
	rc_sprite[spr_id].scale.set(1.0, 1.0);
	rc_sprite[spr_id].position.set(0, 0);
	rc_sprite[spr_id].alpha = 255;
	rc_sprite[spr_id].rotation = 0;
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
		sourceRect = irr::core::rect<irr::s32>( irr::core::vector2d(0, 0), src_size);

		physics_pos = sprite->physics.body->GetPosition();
		x = (int)physics_pos.x;
		y = (int)physics_pos.y;
		position.set(x, y);


		rotationPoint.set(x + (src_size.Width/2), y + (src_size.Height/2));
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




bool rc_update()
{
    if(!device->run())
        return false;

    int win_w = 0, win_h = 0;
    int w_scale = 1, h_scale = 1;

    if(rc_window)
    {
        SDL_GetWindowSize(rc_window, &win_w, &win_h);
        //std::cout << "size = " << win_w << ", " << win_h << std::endl;
    }

    SEvent irrevent;
	SDL_Event SDL_event;
	bool Close = false;

	rc_inkey_val = 0;

	while ( !Close && SDL_PollEvent( &SDL_event ) )
	{
		// os::Printer::log("event: ", core::stringc((int)SDL_event.type).c_str(),   ELL_INFORMATION);	// just for debugging

		switch ( SDL_event.type )
		{
        case SDL_QUIT:
            SDL_PumpEvents();
            Close = true;
            break;
		case SDL_MOUSEMOTION:
			irrevent.EventType = irr::EET_MOUSE_INPUT_EVENT;
			irrevent.MouseInput.Event = irr::EMIE_MOUSE_MOVED;
			MouseX = irrevent.MouseInput.X = SDL_event.motion.x;
			MouseY = irrevent.MouseInput.Y = SDL_event.motion.y;
			MouseXRel = SDL_event.motion.xrel;
			MouseYRel = SDL_event.motion.yrel;
			irrevent.MouseInput.ButtonStates = MouseButtonStates;

			device->postEventFromUser(irrevent);
			break;

		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:

			irrevent.EventType = irr::EET_MOUSE_INPUT_EVENT;
			irrevent.MouseInput.X = SDL_event.button.x;
			irrevent.MouseInput.Y = SDL_event.button.y;

			irrevent.MouseInput.Event = irr::EMIE_MOUSE_MOVED;

			switch(SDL_event.button.button)
			{
			case SDL_BUTTON_LEFT:
				if (SDL_event.type == SDL_MOUSEBUTTONDOWN)
				{
					irrevent.MouseInput.Event = irr::EMIE_LMOUSE_PRESSED_DOWN;
					MouseButtonStates |= irr::EMBSM_LEFT;
				}
				else
				{
					irrevent.MouseInput.Event = irr::EMIE_LMOUSE_LEFT_UP;
					MouseButtonStates &= !irr::EMBSM_LEFT;
				}

				//std::cout << "Position = " << SDL_event.button.x << ", " << SDL_event.button.y << std::endl;
				//rc_canvas[0].offset.X++;
				break;

			case SDL_BUTTON_RIGHT:
				if (SDL_event.type == SDL_MOUSEBUTTONDOWN)
				{
					irrevent.MouseInput.Event = irr::EMIE_RMOUSE_PRESSED_DOWN;
					MouseButtonStates |= irr::EMBSM_RIGHT;
				}
				else
				{
					irrevent.MouseInput.Event = irr::EMIE_RMOUSE_LEFT_UP;
					MouseButtonStates &= !irr::EMBSM_RIGHT;
				}

				//rc_setWindowFullscreen(1);
				//rc_canvas[0].offset.X--;
				break;

			case SDL_BUTTON_MIDDLE:
				if (SDL_event.type == SDL_MOUSEBUTTONDOWN)
				{
					irrevent.MouseInput.Event = irr::EMIE_MMOUSE_PRESSED_DOWN;
					MouseButtonStates |= irr::EMBSM_MIDDLE;
				}
				else
				{
					irrevent.MouseInput.Event = irr::EMIE_MMOUSE_LEFT_UP;
					MouseButtonStates &= !irr::EMBSM_MIDDLE;
				}
				break;

			}

			irrevent.MouseInput.ButtonStates = MouseButtonStates;

			if (irrevent.MouseInput.Event != irr::EMIE_MOUSE_MOVED)
			{
				device->postEventFromUser(irrevent);

				if ( irrevent.MouseInput.Event >= EMIE_LMOUSE_PRESSED_DOWN && irrevent.MouseInput.Event <= EMIE_MMOUSE_PRESSED_DOWN )
				{
					u32 clicks = device->checkSuccessiveClicks(irrevent.MouseInput.X, irrevent.MouseInput.Y, irrevent.MouseInput.Event);
					if ( clicks == 2 )
					{
						irrevent.MouseInput.Event = (EMOUSE_INPUT_EVENT)(EMIE_LMOUSE_DOUBLE_CLICK + irrevent.MouseInput.Event-EMIE_LMOUSE_PRESSED_DOWN);
						device->postEventFromUser(irrevent);
					}
					else if ( clicks == 3 )
					{
						irrevent.MouseInput.Event = (EMOUSE_INPUT_EVENT)(EMIE_LMOUSE_TRIPLE_CLICK + irrevent.MouseInput.Event-EMIE_LMOUSE_PRESSED_DOWN);
						device->postEventFromUser(irrevent);
					}
				}
			}
			break;

        case SDL_MOUSEWHEEL:
            irrevent.MouseInput.Event = irr::EMIE_MOUSE_WHEEL;
            irrevent.MouseInput.Wheel = SDL_event.wheel.y;
            rc_mwheelx = SDL_event.wheel.x;
            rc_mwheely = SDL_event.wheel.y;
            break;

        case SDL_TEXTINPUT:
            if(rc_textinput_flag == true)
            {
                rc_textinput_string += SDL_event.text.text;
            }
            break;

		case SDL_KEYUP:
		case SDL_KEYDOWN:
			{
				SDLKeyMap mp;
				mp.SDLKey = SDL_event.key.keysym.sym;
				s32 idx = KeyMap.binary_search(mp);

				EKEY_CODE key;
				if (idx == -1)
					key = (EKEY_CODE)0;
				else
					key = (EKEY_CODE)KeyMap[idx].Win32Key;

				irrevent.EventType = irr::EET_KEY_INPUT_EVENT;
				irrevent.KeyInput.Char = SDL_event.key.keysym.sym;
				irrevent.KeyInput.Key = key;
				irrevent.KeyInput.PressedDown = (SDL_event.type == SDL_KEYDOWN);
				irrevent.KeyInput.Shift = (SDL_event.key.keysym.mod & KMOD_SHIFT) != 0;
				irrevent.KeyInput.Control = (SDL_event.key.keysym.mod & KMOD_CTRL ) != 0;
				device->postEventFromUser(irrevent);
			}

			if(SDL_event.type == SDL_KEYDOWN)
			{
			    if(rc_textinput_flag && SDL_event.key.keysym.sym == SDLK_BACKSPACE && rc_textinput_string.length() > 0
                   && rc_toggleBackspace)
                {
                    rc_textinput_string = rc_utf8_substr(rc_textinput_string, 0, rc_utf8_length(rc_textinput_string)-1);
                }

                rc_inkey_val = SDL_event.key.keysym.sym;
			}
			break;


		case SDL_WINDOWEVENT:
			if (SDL_event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
			{
			// FIXME: Implement more precise window control
				// FIXME: Check if the window is game window
				s32 Width = SDL_event.window.data1;
                s32 Height = SDL_event.window.data2;

                rc_win_event = RC_WIN_EVENT_RESIZE;

                //resizeWindow(Width, Height);
                if (VideoDriver)
                    VideoDriver->OnResize(core::dimension2d<u32>(Width, Height));

                win_w = Width;
                win_h = Height;

			}
			else if(SDL_event.window.event == SDL_WINDOWEVENT_CLOSE)
            {
                if(rc_window)
                {
                    rc_win_event = RC_WIN_EVENT_CLOSE;

                    if(SDL_QuitRequested() != 0)
                    {
                        SDL_FlushEvent(SDL_QUIT);
                    }
                    if(rc_win_exitOnClose)
                    {
                        rc_closeWindow_hw();
                        Close = true;
                    }

                }
            }
            else if(SDL_event.window.event == SDL_WINDOWEVENT_MINIMIZED)
            {
                if(rc_window)
                {
                    rc_win_event = RC_WIN_EVENT_MINIMIZE;
                }
            }
            else if(SDL_event.window.event == SDL_WINDOWEVENT_MAXIMIZED)
            {
                if(rc_window)
                {
                    rc_win_event = RC_WIN_EVENT_MAXIMIZE;
                }
            }

			break;

        case SDL_JOYDEVICEREMOVED:
            //cout << "Joystick Removed: Instance " << event.jdevice.which << endl;
            for(int i = 0; i < 8; i++)
            {
                if(SDL_event.jdevice.which == rc_joyID[i] && rc_joystick[i])
                {
                    //cout << "Joystick [" << i << "] was removed" << endl;
                    SDL_HapticClose(rc_haptic[i]);
                    SDL_JoystickClose(rc_joystick[i]);
                    rc_joystick[i] = NULL;
                    rc_haptic[i] = NULL;
                    rc_joyID[i] = -1;
                    rc_numJoysticks--;
                    break;
                }
            }
            break;
        case SDL_JOYDEVICEADDED:
            //cout << "Joystick Added: " << event.jdevice.which << endl;
            tmp_joy = SDL_JoystickOpen(SDL_event.jdevice.which);
            tmp_joy_id = SDL_JoystickInstanceID(tmp_joy);
            tmp_joy_flag = 0;

            for(int i = 0; i < 8; i++)
            {
                if(tmp_joy_id == rc_joyID[i])
                {
                    tmp_joy_flag = 1;
                    break;
                }
            }

            if(SDL_event.jdevice.which >= 0 && tmp_joy_flag == 0)
            {
                for(int i = 0; i < 8; i++)
                {
                    if(rc_joystick[i] == NULL)
                    {
                        //cout << "Assigned " << i << endl;
                        rc_joystick[i] = tmp_joy;
                        rc_haptic[i] = SDL_HapticOpenFromJoystick(rc_joystick[i]);
                        SDL_HapticRumbleInit(rc_haptic[i]);
                        rc_joyID[i] = tmp_joy_id;
                        rc_numJoysticks++;
                        break;
                    }
                }
            }
            break;

#ifndef RC_MOBILE //This block handles touch events for non-mobile devices, Just in case it has a touch screen that SDL2 can get events for
        case SDL_FINGERDOWN:
            rc_touch = 1;
            rc_touchX = SDL_event.tfinger.x * win_w;
            rc_touchY = SDL_event.tfinger.y * win_h;
#ifdef RC_IOS
            rc_pressure = 1; //FIXME: On IOS pressure is always getting reported as 0 on finger down so I am just setting it to 1 until I figure this out
#else
            rc_pressure = SDL_event.tfinger.pressure;
#endif
            rc_setTouchFingerEvent(SDL_event.tfinger.fingerId, rc_touchX, rc_touchY, rc_pressure);
            break;
        case SDL_FINGERUP:
            rc_touch = 0;
            rc_mt_status = 0;
            rc_touchX = SDL_event.tfinger.x * win_w;
            rc_touchY = SDL_event.tfinger.y * win_h;
            rc_pressure = SDL_event.tfinger.pressure;
            rc_setTouchFingerEvent(SDL_event.tfinger.fingerId, -1, -1, 0);
            break;
        case SDL_FINGERMOTION:
            rc_touch = 1;
            rc_touchX = SDL_event.tfinger.x * win_w;
            rc_touchY = SDL_event.tfinger.y * win_h;
            rc_motionX = SDL_event.tfinger.dx * win_w;
            rc_motionY = SDL_event.tfinger.dy * win_h;
#ifdef RC_IOS
            rc_pressure = 1;
#else
            rc_pressure = SDL_event.tfinger.pressure;
#endif
            rc_setTouchFingerEvent(SDL_event.tfinger.fingerId, rc_touchX, rc_touchY, rc_pressure);
            break;
        case SDL_MULTIGESTURE:
            rc_touch = 2;
            rc_mt_status = 1;
            rc_mt_x = SDL_event.mgesture.x;
            rc_mt_y = SDL_event.mgesture.y;
            rc_mt_numFingers = SDL_event.mgesture.numFingers;
            rc_mt_dist = SDL_event.mgesture.dDist;
            rc_mt_theta = SDL_event.mgesture.dTheta;
#ifdef RC_IOS
            rc_pressure = 1;
#else
            rc_pressure = SDL_event.tfinger.pressure;
#endif
            break;
#endif

		case SDL_USEREVENT:
			irrevent.EventType = irr::EET_USER_EVENT;
			irrevent.UserEvent.UserData1 = reinterpret_cast<uintptr_t>(SDL_event.user.data1);
			irrevent.UserEvent.UserData2 = reinterpret_cast<uintptr_t>(SDL_event.user.data2);

			device->postEventFromUser(irrevent);
			break;

		default:
			break;
		} // end switch

	} // end while

	if(!Close)
    {
    	irrtheora::updateVideo();

        VideoDriver->setRenderTarget(rc_canvas[0].texture);
        irr::core::vector2d<s32> bb_position(0,0);
        irr::core::dimension2d<u32> bb_dimension(win_w, win_h);
        VideoDriver->setViewPort( irr::core::rect(bb_position, bb_dimension) );

        irr::core::vector2d screenSize( (irr::f32) rc_canvas[0].dimension.Width, (irr::f32) rc_canvas[0].dimension.Height );

        double frame_current_time = ((double)SDL_GetTicks())/1000.0d;

        for(int i = 0; i < rc_transition_actor.size();)
		{
			if((frame_current_time - rc_actor[i].transition_start_time) >= rc_actor[i].transition_time)
			{
				irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[i].mesh_node;
				node->setTransitionTime(0);
				node->setJointMode(irr::scene::EJUOR_NONE);
				rc_actor[i].transition = false;
				rc_actor[i].transition_time = 0;
				rc_actor[i].transition_start_time = 0;
				rc_transition_actor.erase(i);
			}
			else
			{
				irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[i].mesh_node;
				node->animateJoints();
				i++;
			}
		}


        VideoDriver->beginScene(true, true);

        rc_physics3D.DeltaTime = device->getTimer()->getTime() - rc_physics3D.TimeStamp;
		rc_physics3D.TimeStamp = device->getTimer()->getTime();
        rc_physics3D.world->stepSimulation(rc_physics3D.DeltaTime*0.001f, rc_physics3D.maxSubSteps, rc_physics3D.fixedTimeStep);

        for(int i = 0; i < rc_canvas.size(); i++)
        {
            if(rc_canvas[i].show3D)
            {
                VideoDriver->setRenderTarget(rc_canvas[i].texture, true, true, irr::video::SColor(255,120,120,120));

                if(rc_canvas[i].camera.camera)
                    SceneManager->setActiveCamera(rc_canvas[i].camera.camera);

                rc_canvas[i].camera.update();

                VideoDriver->setViewPort(irr::core::rect<irr::s32>(0,0,rc_canvas[i].viewport.dimension.Width,rc_canvas[i].viewport.dimension.Height));

                //irr::core::rect viewport(irr::core::position, rc_canvas[i].viewport.dimension);
                //VideoDriver->setViewPort(viewport);

                SceneManager->drawAll();

                vector3df p0(0, 0, 0);
				vector3df p1(10, 30, 0);
				vector3df p2(20, -30, 0);
				vector3df p3(30, 0, 0);
				//drawBezierCurve(VideoDriver, p0, p1, p2, p3, irr::video::SColor(255, 0, 255, 0), 100);

                VideoDriver->setRenderTarget(rc_canvas[0].texture);
            }
        }



		for(int cz = 0; cz < rc_canvas_zOrder.size(); cz++)
        {
            int canvas_id = rc_canvas_zOrder[cz];

            if(rc_canvas[canvas_id].texture && rc_canvas[canvas_id].visible)
            {
                irr::core::rect<s32> dest(rc_canvas[canvas_id].viewport.position, rc_canvas[canvas_id].viewport.dimension);
                irr::core::rect<s32> src(rc_canvas[canvas_id].offset, rc_canvas[canvas_id].viewport.dimension);

                irr::video::SColor color(rc_canvas[canvas_id].color_mod);
                //color.set(255,255,255,255);

                //std::cout << "draw canvas[" << canvas_id << "]" << std::endl;

                if(rc_canvas[canvas_id].type == RC_CANVAS_TYPE_SPRITE)
					drawSprites(canvas_id);

                draw2DImage2(VideoDriver, rc_canvas[canvas_id].texture, src, dest, irr::core::vector2d<irr::s32>(0, 0), 0, true, color, screenSize);

                //drawSprites(canvas_id);
                //draw2DImage2(VideoDriver, rc_canvas[canvas_id].sprite_layer, src, dest, irr::core::vector2d<irr::s32>(0, 0), 0, true, color, screenSize);
                //drawCanvasImage(rc_canvas[canvas_id].texture, dest.UpperLeftCorner.X, dest.UpperLeftCorner.Y,
                //                src.UpperLeftCorner.X, src.UpperLeftCorner.Y, src.getWidth(), src.getHeight(), dest.getWidth(), dest.getHeight());

                //VideoDriver->draw2DImage(rc_canvas[canvas_id].texture, dest, src, 0, &color, true);
            }
        }

		//env->drawAll();

		VideoDriver->setRenderTarget(0);
		//VideoDriver->beginScene(true, true);
		VideoDriver->draw2DImage(rc_canvas[0].texture, irr::core::vector2d(0,0));
		//device->getGUIEnvironment()->drawAll();
		VideoDriver->endScene();

		rc_setActiveCanvas(rc_active_canvas);
    }

    #ifdef RC_WEB
	   emscripten_sleep(0);
	#else
	   SDL_Delay(0);
	#endif // RC_WEB

    return (!Close);
}

#endif // RC_GFX_INCLUDED