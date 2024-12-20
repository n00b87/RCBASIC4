#ifndef RC_WINDOWCLOSE_H_INCLUDED
#define RC_WINDOWCLOSE_H_INCLUDED

void rc_closeWindow_hw()
{
	irrtheora::stopVideo();
	irrtheora::deleteVideo();

	for(int i = 0; i < rc_font.size(); i++)
		rc_deleteFont(i);

	for(int i = 0; i < rc_tileset.size(); i++)
		rc_deleteTileSet(i);

	for(int i = 0; i < rc_tilemap.size(); i++)
		rc_deleteTileMap(i);

	for(int i = 0; i < rc_image.size(); i++)
		rc_deleteImage(i);

	for(int i = 0; i < rc_sprite.size(); i++)
		rc_deleteSprite(i);

	for(int i = 0; i < rc_joint.size(); i++)
		rc_deleteJoint(i);

	for(int i = 0; i < rc_actor.size(); i++)
		rc_deleteActor(i);

	for(int i = 0; i < rc_physics3D.constraints.size(); i++)
		rc_deleteConstraint(i);

	for(int i = 0; i < rc_canvas.size(); i++)
		rc_canvasClose(i);

	rc_clearScene();

	device->drop();
    device = NULL;
    VideoDriver = NULL;
    SceneManager = NULL;

    if(rc_window!=NULL)
        SDL_DestroyWindow(rc_window);
    rc_window = NULL;

    rc_canvas.clear();
    rc_canvas_zOrder.clear();
    rc_font.clear();
}

void rc_preUpdate()
{
	//3D World Update
	//rc_physics3D.DeltaTime = device->getTimer()->getTime() - rc_physics3D.TimeStamp;
	//rc_physics3D.TimeStamp = device->getTimer()->getTime();
	rc_physics3D.DeltaTime = SDL_GetTicks() - rc_physics3D.TimeStamp;
	rc_physics3D.TimeStamp = SDL_GetTicks();
	float fixed_timestep = rc_physics3D.fixedTimeStep < 0 ? rc_physics3D.DeltaTime*0.001f : rc_physics3D.fixedTimeStep;
	rc_physics3D.world->stepSimulation(rc_physics3D.DeltaTime*0.001f, rc_physics3D.maxSubSteps, fixed_timestep);

	for(int i = 0; i < rc_canvas.size(); i++)
	{
		if(rc_canvas[i].type != RC_CANVAS_TYPE_SPRITE)
			continue;

		Uint32 delta_time = SDL_GetTicks() - rc_canvas[i].physics2D.time_stamp;
		rc_canvas[i].physics2D.time_stamp = SDL_GetTicks();
		float step = rc_canvas[i].physics2D.timeStep < 0 ? (delta_time*0.001f) : rc_canvas[i].physics2D.timeStep;
		int32 velocityIterations = rc_canvas[i].physics2D.velocityIterations;
		int32 positionIterations = rc_canvas[i].physics2D.positionIterations;

		if(rc_canvas[i].physics2D.enabled)
			rc_canvas[i].physics2D.world->Step(step, velocityIterations, positionIterations);
	}

	hasPreUpdated = true;
}

bool rc_update()
{
	if(rc_window_vsync)
	{
		int frame_delay = 1000/rc_vsync_refresh_rate;
		while( (SDL_GetTicks()-rc_vsync_timer) < frame_delay ){}
		rc_vsync_timer = SDL_GetTicks();
	}

    if(!device->run())
        return false;

    int win_w = 0, win_h = 0;
    double w_scale = 1, h_scale = 1;

    if(rc_window)
    {
        SDL_GetWindowSize(rc_window, &win_w, &win_h);
        //std::cout << "size = " << win_w << ", " << win_h << std::endl;
    }

    w_scale = ( (double)win_w / (double)rc_window_size.Width );
    h_scale = ( (double)win_h / (double)rc_window_size.Height );

    rc_window_mouse_scale_x = ( (double)rc_window_size.Width / (double)win_w );
    rc_window_mouse_scale_y = ( (double)rc_window_size.Height / (double)win_h );

    rc_window_zone_scale_x = w_scale;
    rc_window_zone_scale_y = h_scale;

    SEvent irrevent;
	SDL_Event SDL_event;
	bool Close = false;

	rc_inkey_val = 0;

	rc_mwheelx = 0;
	rc_mwheely = 0;

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

			//device->postEventFromUser(irrevent);
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
        irr::core::dimension2d<u32> bb_dimension = rc_canvas[0].texture->getSize();
        irr::core::dimension2d<u32> win_dimension(win_w, win_h);
        VideoDriver->setViewPort( irr::core::rect<irr::s32>(bb_position, bb_dimension) );

        irr::core::vector2d<irr::f32> screenSize( (irr::f32) rc_canvas[0].dimension.Width, (irr::f32) rc_canvas[0].dimension.Height );
        //irr::core::vector2d<irr::f32> screenSize( (irr::f32) win_h, (irr::f32) win_w );

        Uint32 current_time_ms = SDL_GetTicks();
        double frame_current_time = ((double)current_time_ms)/1000.0;

        for(int i = 0; i < rc_transition_actor.size();)
		{
			int t_actor = rc_transition_actor[i];

			if((frame_current_time - rc_actor[t_actor].transition_start_time) >= rc_actor[t_actor].transition_time)
			{
				irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[t_actor].mesh_node;
				node->setTransitionTime(0);
				node->setJointMode(irr::scene::EJUOR_NONE);
				rc_actor[t_actor].transition = false;
				rc_actor[t_actor].transition_time = 0;
				rc_actor[t_actor].transition_start_time = 0;
				rc_transition_actor.erase(t_actor);

				rc_actor[t_actor].animation[0].start_frame = (int)rc_actor[t_actor].transition_frame;
				rc_actor[t_actor].animation[0].end_frame = (int)rc_actor[t_actor].transition_frame;
				rc_actor[t_actor].animation[0].fps = 0;
				rc_actor[t_actor].current_animation_loop = 0;
				rc_actor[t_actor].isPlaying = true;
				rc_actor[t_actor].current_animation = 0;
			}
			else
			{
				//std::cout << "Animate dammit" << std::endl;
				irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[t_actor].mesh_node;
				node->animateJoints();
				i++;
			}
		}


        VideoDriver->beginScene(true, true);

        if(!hasPreUpdated)
        {
        	//rc_physics3D.DeltaTime = device->getTimer()->getTime() - rc_physics3D.TimeStamp;
			//rc_physics3D.TimeStamp = device->getTimer()->getTime();
			rc_physics3D.DeltaTime = SDL_GetTicks() - rc_physics3D.TimeStamp;
			rc_physics3D.TimeStamp = SDL_GetTicks();
			float fixed_timestep = rc_physics3D.fixedTimeStep < 0 ? rc_physics3D.DeltaTime*0.001f : rc_physics3D.fixedTimeStep;
			rc_physics3D.world->stepSimulation(rc_physics3D.DeltaTime*0.001f, rc_physics3D.maxSubSteps, fixed_timestep);
        }

        for(int i = 0; i < rc_canvas.size(); i++)
        {
            if(rc_canvas[i].show3D)
            {
                VideoDriver->setRenderTarget(rc_canvas[i].texture, true, true, irr::video::SColor(255,120,120,120));

                if(rc_canvas[i].camera.camera)
                    SceneManager->setActiveCamera(rc_canvas[i].camera.camera);

                rc_canvas[i].camera.update();

                VideoDriver->setViewPort(irr::core::rect<irr::s32>(0,0,rc_canvas[i].texture->getSize().Width,rc_canvas[i].texture->getSize().Height));

                //irr::core::rect viewport(irr::core::position, rc_canvas[i].viewport.dimension);
                //VideoDriver->setViewPort(viewport);
                irr::video::SColor current_color = rc_active_color;
                irr::video::SMaterial m;
				m.Lighting=false;
				VideoDriver->setMaterial(m);
				VideoDriver->setTransform(video::ETS_WORLD, core::matrix4());
                for(int i = 0; i < rc_prim3d_operation.size(); i++)
				{
					switch(rc_prim3d_operation[i].prim_type)
					{
						case PRIM3D_LINE:
							rc_active_color = rc_prim3d_operation[i].color;
							prim3d_drawLine3D(rc_prim3d_operation[i].x[0], rc_prim3d_operation[i].y[0], rc_prim3d_operation[i].z[0],
											  rc_prim3d_operation[i].x[1], rc_prim3d_operation[i].y[1], rc_prim3d_operation[i].z[1]);
							break;
						case PRIM3D_BOX:
							rc_active_color = rc_prim3d_operation[i].color;
							prim3d_drawBox3D(rc_prim3d_operation[i].x[0], rc_prim3d_operation[i].y[0], rc_prim3d_operation[i].z[0],
											 rc_prim3d_operation[i].x[1], rc_prim3d_operation[i].y[1], rc_prim3d_operation[i].z[1]);
							break;
						case PRIM3D_TRIANGLE:
							rc_active_color = rc_prim3d_operation[i].color;
							prim3d_drawTriangle3D(rc_prim3d_operation[i].x[0], rc_prim3d_operation[i].y[0], rc_prim3d_operation[i].z[0],
												  rc_prim3d_operation[i].x[1], rc_prim3d_operation[i].y[1], rc_prim3d_operation[i].z[1],
												  rc_prim3d_operation[i].x[2], rc_prim3d_operation[i].y[2], rc_prim3d_operation[i].z[2]);
							break;
					}
				}
				rc_active_color = current_color;
				rc_setDriverMaterial();

                SceneManager->drawAll();
                //VideoDriver->draw2DRectangle(irr::video::SColor(255,0,255,0), irr::core::rect<irr::s32>(10,40,100,500));

                //vector3df p0(0, 0, 0);
				//vector3df p1(10, 30, 0);
				//vector3df p2(20, -30, 0);
				//vector3df p3(30, 0, 0);
				//drawBezierCurve(VideoDriver, p0, p1, p2, p3, irr::video::SColor(255, 0, 255, 0), 100);

                VideoDriver->setRenderTarget(rc_canvas[0].texture);
            }
        }

        rc_prim3d_operation.clear();

		for(int cz = 0; cz < rc_canvas_zOrder.size(); cz++)
        {
            int canvas_id = rc_canvas_zOrder[cz];

            if(rc_canvas[canvas_id].texture && rc_canvas[canvas_id].visible)
            {
                irr::core::rect<s32> dest(rc_canvas[canvas_id].viewport.position, rc_canvas[canvas_id].viewport.dimension);
                irr::core::rect<s32> src(rc_canvas[canvas_id].offset, rc_canvas[canvas_id].viewport.dimension);

                irr::video::SColor color(rc_canvas[canvas_id].color_mod);
                //color.set(255,255,255,255);

                //std::cout << "draw canvas[" << canvas_id << "] (" << rc_canvas[canvas_id].offset.X << ", " <<  rc_canvas[canvas_id].offset.Y << ") (" << rc_canvas[canvas_id].viewport.dimension.Width << ", " << rc_canvas[canvas_id].viewport.dimension.Height << ")" << std::endl;

                #if defined(RC_DRIVER_GLES2)
                if(rc_canvas[canvas_id].type == RC_CANVAS_TYPE_3D)
                {
                	src = irr::core::rect<s32>( irr::core::vector2d<s32>(0, 0), rc_canvas[canvas_id].texture->getSize() );
                	dest = irr::core::rect<s32>( irr::core::vector2d<s32>(dest.UpperLeftCorner.X, dest.UpperLeftCorner.Y + dest.getHeight()), irr::core::dimension2d<s32>(dest.getWidth(), -1*dest.getHeight()) );
                }
                else if(rc_canvas[canvas_id].type == RC_CANVAS_TYPE_2D)
				{
					irr::core::dimension2d<irr::u32> cv_dim = rc_canvas[canvas_id].viewport.dimension;
					irr::core::position2d<irr::s32> cv_pos = rc_canvas[canvas_id].viewport.position;
					irr::core::vector2d<irr::s32> cv_offset(rc_canvas[canvas_id].offset.X, rc_canvas[canvas_id].texture->getSize().Height - rc_canvas[canvas_id].offset.Y - cv_dim.Height);
					src = irr::core::rect<s32>( cv_offset, cv_dim );
					dest = irr::core::rect<s32>( irr::core::vector2d<s32>(cv_pos.X, cv_pos.Y + cv_dim.Height), irr::core::dimension2d<s32>(cv_dim.Width, -1*cv_dim.Height) );
				}
				else if(rc_canvas[canvas_id].type == RC_CANVAS_TYPE_SPRITE)
				{

					src = irr::core::rect<s32>( irr::core::vector2d<s32>(0, 0), rc_canvas[canvas_id].texture->getSize() );
                	dest = irr::core::rect<s32>( irr::core::vector2d<s32>(dest.UpperLeftCorner.X, dest.UpperLeftCorner.Y + dest.getHeight()), irr::core::dimension2d<s32>(dest.getWidth(), -1*dest.getHeight()) );
					drawSprites(canvas_id);
				}
                //dest = irr::core::rect<s32>( irr::core::vector2d<s32>(dest.UpperLeftCorner.X, dest.UpperLeftCorner.Y + dest.getHeight()), irr::core::dimension2d<s32>(dest.getWidth(), -1*dest.getHeight()) );
                draw2DImage2(VideoDriver, rc_canvas[canvas_id].texture, src, dest, irr::core::position2d<irr::s32>(0, 0), 0, true, color, screenSize);
                #else
                if(rc_canvas[canvas_id].type == RC_CANVAS_TYPE_SPRITE)
				{

					src = irr::core::rect<s32>( irr::core::vector2d<s32>(0, 0), rc_canvas[canvas_id].viewport.dimension); //sprite layers will just offset the sprites in drawSprites()
					drawSprites(canvas_id);
				}

                draw2DImage2(VideoDriver, rc_canvas[canvas_id].texture, src, dest, irr::core::position2d<irr::s32>(0, 0), 0, true, color, screenSize);
                #endif // defined

                //drawSprites(canvas_id);
                //draw2DImage2(VideoDriver, rc_canvas[canvas_id].sprite_layer, src, dest, irr::core::vector2d<irr::s32>(0, 0), 0, true, color, screenSize);
                //drawCanvasImage(rc_canvas[canvas_id].texture, dest.UpperLeftCorner.X, dest.UpperLeftCorner.Y,
                //                src.UpperLeftCorner.X, src.UpperLeftCorner.Y, src.getWidth(), src.getHeight(), dest.getWidth(), dest.getHeight());

                //VideoDriver->draw2DImage(rc_canvas[canvas_id].texture, dest, src, 0, &color, true);
            }
        }

		//env->drawAll();
		//VideoDriver->draw2DRectangle(irr::video::SColor(255,255,0,0), irr::core::rect<irr::s32>(0,0,100,500));

		VideoDriver->setRenderTarget(0);
		//VideoDriver->beginScene(true, true);
		//VideoDriver->draw2DImage(rc_canvas[0].texture, irr::core::vector2d<irr::s32>(0,0));

		//debug
		//std::cout << "scale:: " << rc_window_size.Width << ", " << win_w << ", " << rc_canvas[0].texture->getSize().Width << std::endl;
		//irr::core::rect<s32> src( irr::core::vector2d<s32>(0,0), rc_canvas[0].texture->getSize() );
		#ifdef RC_DRIVER_GLES2
		irr::core::rect<s32> src( irr::core::vector2d<s32>(0,0), rc_canvas[0].texture->getSize()  );
		irr::core::rect<s32> dest( irr::core::vector2d<s32>(0,0), irr::core::dimension2d<s32>(win_w*w_scale, win_h*h_scale) );
		#else
		irr::core::rect<s32> src( irr::core::vector2d<s32>(0,0), rc_window_size  );
		irr::core::rect<s32> dest;

		if(rc_windowIsFullscreen())
			dest = irr::core::rect<s32>( irr::core::vector2d<s32>(0,0), irr::core::dimension2d<s32>(win_w, win_h) );
		else
			dest = irr::core::rect<s32>( irr::core::vector2d<s32>(0,rc_canvas[0].texture->getSize().Height - rc_window_size.Height), irr::core::dimension2d<s32>(win_w, win_h) );
		#endif // RC_DRIVER_GLES2

		//irr::video::SColor color(0);
		VideoDriver->draw2DImage(rc_canvas[0].texture, dest, src);
		//draw2DImage2(VideoDriver, rc_canvas[0].texture, src, dest, irr::core::position2d<irr::s32>(0, 0), 0, false, color, screenSize);
		//irr::core::rect<irr::s32> src( irr::core::vector2d<irr::s32>(0, 0), rc_canvas[0].texture->getSize() );
		//irr::core::rect<irr::s32> dest( irr::core::vector2d<irr::s32>(0, 0), irr::core::dimension2d<irr::s32>( );
		//draw2DImage2(VideoDriver, rc_canvas[canvas_id].texture, src, dest, irr::core::position2d<irr::s32>(0, 0), 0, true, color, screenSize);

		//VideoDriver->draw2DImage(rc_image[0].image, irr::core::rect<irr::s32>(0,0,100,100), irr::core::rect<irr::s32>(0,0,100,100));
		//VideoDriver->draw2DRectangle(irr::video::SColor(255,255,0,0), irr::core::rect<irr::s32>(0,0,100,100));
		//end debug

		//device->getGUIEnvironment()->drawAll();
		VideoDriver->endScene();

		rc_setActiveCanvas(rc_active_canvas);
    }

    hasPreUpdated = false; //Will be set to true if PreUpdate() is called

    #ifdef RC_WEB
	   emscripten_sleep(0);
	#else
	   SDL_Delay(0);
	#endif // RC_WEB

    return (!Close);
}

#endif // RC_WINDOWCLOSE_H_INCLUDED
