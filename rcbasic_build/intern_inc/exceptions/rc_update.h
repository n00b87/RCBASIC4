rc_events();
rc_media_updateWindow_hw();
#ifdef RC_WEB
   emscripten_sleep(0);
#else
   SDL_Delay(0);
#endif // RC_WEB
