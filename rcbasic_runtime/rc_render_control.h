#ifndef RC_RENDER_CONTROL_H_INCLUDED
#define RC_RENDER_CONTROL_H_INCLUDED

#include <irrlicht.h>
#include "rc_gfx_core.h"
#include "rc_post_fx.h"



void rc_pipeline_Begin()
{
    manual_render_control = true;

    VideoDriver->beginScene(true, true);

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
}

void rc_pipeline_End()
{
    int win_w = 0, win_h = 0;
    double w_scale = 1, h_scale = 1;

    if(rc_window)
    {
        SDL_GetWindowSize(rc_window, &win_w, &win_h);
    }


    if(manual_render_control)
    {
        #ifdef RC_DRIVER_GLES2
        w_scale = ( (double)win_w / (double)rc_window_size.Width );
        h_scale = ( (double)win_h / (double)rc_window_size.Height );

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

        VideoDriver->draw2DImage(rc_canvas[0].texture, dest, src);

        VideoDriver->endScene();

        rc_setActiveCanvas(rc_active_canvas);

        #ifdef RC_WEB
           emscripten_sleep(0);
        #else
           SDL_Delay(0);
        #endif // RC_WEB
    }

    manual_render_control = false;
}



void rc_pipeline_Render()
{
    if(!manual_render_control)
        return;

    //std::cout << "db 1" << std::endl;

    if(rc_active_canvas < 0 || rc_active_canvas >= rc_canvas.size())
        return;

    //std::cout << "db 2: " << (rc_canvas[rc_active_canvas].texture == NULL ? "NULL" : "OK") << std::endl;

    if(!rc_canvas[rc_active_canvas].texture)
        return;

    //std::cout << "Render" << std::endl;

    //VideoDriver->setRenderTarget(rc_canvas[0].texture);
    irr::core::vector2d<s32> bb_position(0,0);
    irr::core::dimension2d<u32> bb_dimension = rc_canvas[0].texture->getSize();

    VideoDriver->setViewPort( irr::core::rect<irr::s32>(bb_position, bb_dimension) );


    if(rc_canvas[rc_active_canvas].show3D)
    {
        if(rc_canvas[rc_active_canvas].post_effect.is_active)
        {
            if(rc_canvas[rc_active_canvas].post_effect.type == RC_POST_PROCESS_MINERAL)
            {
                IPostProcessGlass* post_process = (IPostProcessGlass*) rc_canvas[rc_active_canvas].post_effect.object;
                VideoDriver->setRenderTarget(post_process->rt0, true, true);
            }
            else if(rc_canvas[rc_active_canvas].post_effect.type == RC_POST_PROCESS_BLOOM)
            {
                IPostProcessBloom* post_process = (IPostProcessBloom*) rc_canvas[rc_active_canvas].post_effect.object;
                VideoDriver->setRenderTarget(post_process->rt0, true, true);
            }
            else if(rc_canvas[rc_active_canvas].post_effect.type == RC_POST_PROCESS_BLUR)
            {
                IPostProcessBlur* post_process = (IPostProcessBlur*) rc_canvas[rc_active_canvas].post_effect.object;
                VideoDriver->setRenderTarget(post_process->rt0, true, true);
            }
            else if(rc_canvas[rc_active_canvas].post_effect.type == RC_POST_PROCESS_COLORIZE)
            {
                IPostProcessColor* post_process = (IPostProcessColor*) rc_canvas[rc_active_canvas].post_effect.object;
                VideoDriver->setRenderTarget(post_process->rt0, true, true);
            }
            else if(rc_canvas[rc_active_canvas].post_effect.type == RC_POST_PROCESS_INVERT)
            {
                IPostProcessInvert* post_process = (IPostProcessInvert*) rc_canvas[rc_active_canvas].post_effect.object;
                VideoDriver->setRenderTarget(post_process->rt0, true, true, irr::video::SColor(0,0,0,0));
            }
            else if(rc_canvas[rc_active_canvas].post_effect.type == RC_POST_PROCESS_RADIAL_BLUR)
            {
                IPostProcessRadialBlur* post_process = (IPostProcessRadialBlur*) rc_canvas[rc_active_canvas].post_effect.object;
                VideoDriver->setRenderTarget(post_process->rt0, true, true);
            }
            else
            {
                VideoDriver->setRenderTarget(rc_canvas[rc_active_canvas].texture, true, true, rc_clear_color);
            }
        }
        else
        {
            VideoDriver->setRenderTarget(rc_canvas[rc_active_canvas].texture, false, false);
        }

        if(rc_canvas[rc_active_canvas].camera.camera)
            SceneManager->setActiveCamera(rc_canvas[rc_active_canvas].camera.camera);

        rc_canvas[rc_active_canvas].camera.update();

        VideoDriver->setViewPort(irr::core::rect<irr::s32>(0,0,rc_canvas[rc_active_canvas].texture->getSize().Width,rc_canvas[rc_active_canvas].texture->getSize().Height));

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

        if(rc_canvas[rc_active_canvas].post_effect.type == RC_POST_PROCESS_MOTION_BLUR && rc_canvas[rc_active_canvas].post_effect.is_active)
        {
            //render motion blur
            IPostProcessMotionBlur* post_process = (IPostProcessMotionBlur*) rc_canvas[rc_active_canvas].post_effect.object;
            post_process->render();
        }
        else
        {
            //std::cout << "draw all" << std::endl;
            SceneManager->drawAll();
        }

        for(int p_actor = 0; p_actor < rc_projector_actors.size(); p_actor++)
        {
            int actor_id = rc_projector_actors[p_actor];

            if(actor_id < 0 || actor_id >= rc_actor.size())
                continue;

            if(!rc_actor[actor_id].mesh_node)
                continue;

            if(rc_actor[actor_id].mesh_node->isVisible())
            {
                CProjectiveTextures* pt_node = (CProjectiveTextures*)rc_actor[actor_id].mesh_node;
                pt_node->render();
            }
        }

        //render post effects
        if(rc_canvas[rc_active_canvas].post_effect.is_active)
        {
            rc_renderPostEffect(rc_active_canvas);
        }

    }


    int canvas_id = rc_active_canvas;

    if(rc_canvas[canvas_id].texture && rc_canvas[canvas_id].visible)
    {
        irr::core::rect<s32> dest(rc_canvas[canvas_id].viewport.position, rc_canvas[canvas_id].viewport.dimension);
        irr::core::rect<s32> src(rc_canvas[canvas_id].offset, rc_canvas[canvas_id].viewport.dimension);

        irr::video::SColor color(rc_canvas[canvas_id].color_mod);

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

        #else
        if(rc_canvas[canvas_id].type == RC_CANVAS_TYPE_SPRITE)
        {

            src = irr::core::rect<s32>( irr::core::vector2d<s32>(0, 0), rc_canvas[canvas_id].viewport.dimension); //sprite layers will just offset the sprites in drawSprites()
            drawSprites(canvas_id);
        }

        #endif // defined

    }

}

#endif // RC_RENDER_CONTROL_H_INCLUDED
