#ifndef RC_AUDIO_H_INCLUDED
#define RC_AUDIO_H_INCLUDED

#include <vector>
#include "rc_os_defines.h"

#ifdef RC_ANDROID
#define RC_MOBILE
#endif

#ifdef RC_IOS
#define RC_MOBILE
#endif


#ifdef RC_ANDROID

#include <android/log.h>
//Using SDL and standard IO
#include <string>
#include <stdio.h>
#include <iostream>
#include "SDL.h"
#include "SDL_mixer.h"

#else

#ifdef RC_IOS

//Using SDL and standard IO
#include <string>
#include <stdio.h>
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

#else
//Using SDL and standard IO
#include <string>
#include <sstream>
#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#endif //RC_IOS

#endif // RC_ANDROID

using namespace std;

#ifdef RC_MOBILE
//Screen dimension constants
const int MAX_SOUNDS = 1024;
const int MAX_MUSIC = 1;
#else
//Screen dimension constants
const int MAX_SOUNDS = 1024;
const int MAX_MUSIC = 1;
#endif // RC_MOBILE

struct rc_sound_obj
{
	Mix_Chunk * sound;
	bool active = false;
};

std::vector<rc_sound_obj> rc_sound;

Mix_Music * rc_music;


bool rc_audio_init()
{
	if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        cout << "OpenAudio Error: " << Mix_GetError() << endl;
        return false;
    }
    return true;
}

void rc_audio_quit()
{
    for(int i = 0; i < rc_sound.size(); i++)
    {
        if(rc_sound[i].sound != NULL)
            Mix_FreeChunk(rc_sound[i].sound);
        rc_sound[i].sound = NULL;
    }
    if(rc_music != NULL)
        Mix_FreeMusic(rc_music);
    rc_music = NULL;
    Mix_Quit();
}

int rc_queryAudioSpec(double * freq, double * format, double * channels)
{
    //need to do something here
    int qa_freq = 0;
    Uint16 qa_format = 0;
    int qa_channels = 0;
    int result = Mix_QuerySpec(&qa_freq, &qa_format, &qa_channels);
    *freq = (double)qa_freq;
    *format = (double)qa_format;
    *channels = (double)qa_channels;
    return result;
}

int rc_loadSound(std::string fname)
{
    int id = -1;
    for(int i = 0; i < rc_sound.size(); i++)
	{
		if(!rc_sound[i].active)
		{
			id = i;
			break;
		}
	}

	if(id < 0)
	{
		rc_sound_obj obj;
		id = rc_sound.size();
		rc_sound.push_back(obj);
	}


    rc_sound[id].sound = Mix_LoadWAV(fname.c_str());
    if(rc_sound[id].sound == NULL)
    {
        std::cout << "Could not load sound: " << Mix_GetError() << std::endl;
        return -1;
    }

    rc_sound[id].active = true;

    return id;
}

int rc_createSound(double * abuf, Uint32 alen, Uint8 volume)
{
    int id = -1;
    for(int i = 0; i < rc_sound.size(); i++)
	{
		if(!rc_sound[i].active)
		{
			id = i;
			break;
		}
	}

	if(id < 0)
	{
		rc_sound_obj obj;
		id = rc_sound.size();
		rc_sound.push_back(obj);
	}
	rc_sound[id].sound = (Mix_Chunk*)SDL_malloc(sizeof(Mix_Chunk));
    rc_sound[id].sound->allocated = 1;
    rc_sound[id].sound->abuf = (Uint8*)SDL_malloc(sizeof(Uint8)*alen);

    for(int i = 0; i < alen; i++)
		rc_sound[id].sound->abuf[i] = (Uint8)abuf[i];

	rc_sound[id].sound->alen = alen;
	rc_sound[id].sound->volume = volume;

	rc_sound[id].active = true;
	return id;
}

void rc_loadMusic(std::string fname)
{
    if(rc_music != NULL)
    {
        Mix_FreeMusic(rc_music);
    }
    rc_music = Mix_LoadMUS(fname.c_str());
    if(rc_music == NULL)
    {
        std::cout << "Could not load music: " << Mix_GetError() << std::endl;
        return;
    }
}

void rc_deleteMusic()
{
    if(rc_music)
    {
        Mix_FreeMusic(rc_music);
        rc_music = NULL;
    }
}

void rc_playSound(int slot, int channel, int loops)
{
    if(rc_sound[slot].sound != NULL)
    {
        Mix_PlayChannel(channel, rc_sound[slot].sound, loops);
    }
}

void rc_playSoundTimed(int slot, int channel, int loops, int ms)
{
    if(rc_sound[slot].sound != NULL)
    {
        Mix_PlayChannelTimed(channel, rc_sound[slot].sound, loops, ms);
    }
}

void rc_playMusic(int loops)
{
    if(rc_music != NULL)
    {
        Mix_PlayMusic(rc_music, loops);
    }
}

int rc_musicIsPlaying()
{
    if(rc_music != NULL)
    {
        return Mix_PlayingMusic();
    }
    return 0;
}

void rc_pauseSound(int channel)
{
    if(Mix_Playing(channel))
    {
        Mix_Pause(channel);
    }
}

void rc_resumeSound(int channel)
{
    if(!Mix_Playing(channel))
    {
        Mix_Resume(channel);
    }
}

void rc_pauseMusic()
{
    if(Mix_PlayingMusic())
    {
        Mix_PauseMusic();
    }
}

void rc_resumeMusic()
{
    if(!Mix_PlayingMusic())
    {
        Mix_ResumeMusic();
    }
}

void rc_deleteSound(int slot)
{
    if(rc_sound[slot].sound != NULL)
    {
        Mix_FreeChunk(rc_sound[slot].sound);
        rc_sound[slot].sound = NULL;
    }
    rc_sound[slot].active = false;
}

void rc_fadeMusicIn(int time, int loops)
{
    Mix_FadeInMusic(rc_music, loops, time);
}

void rc_fadeMusicOut(int time)
{
    Mix_FadeOutMusic(time);
}

bool rc_musicExists()
{
    if(rc_music != NULL)
        return true;
    return false;
}

void rc_setMusicVolume(int volume)
{
    Mix_VolumeMusic(volume);
}

int rc_getMusicVolume()
{
    return Mix_VolumeMusic(-1);
}

void rc_setMusicPosition(double position)
{
    Mix_SetMusicPosition(position);
}

double rc_getMusicPosition()
{
    return Mix_SetMusicPosition(-1);
}

void rc_rewindMusic()
{
    Mix_RewindMusic();
}

void rc_setSoundChannels(int max_channels)
{
    Mix_AllocateChannels(max_channels);
}

int rc_getSoundChannels()
{
    return Mix_AllocateChannels(-1);
}

bool rc_soundIsEnabled()
{
    return (bool) Mix_Init(0);
}

bool rc_soundExists(int slot)
{
    return rc_sound[slot].active;
}

void rc_setChannelVolume(int channel, int volume)
{
    Mix_Volume(channel, volume);
}

int rc_getChannelVolume(int channel)
{
    return Mix_Volume(channel, -1);
}

void rc_setSoundVolume(int slot, int volume)
{
    Mix_VolumeChunk(rc_sound[slot].sound, volume);
}

int rc_getSoundVolume(int slot)
{
    return Mix_VolumeChunk(rc_sound[slot].sound, -1);
}

void rc_stopMusic()
{
    Mix_HaltMusic();
}

void rc_stopSound(int channel)
{
    Mix_HaltChannel(channel);
}

int rc_channelIsPlaying(int channel)
{
    return Mix_Playing(channel);
}

int rc_channelIsPaused(int channel)
{
    return Mix_Paused(channel);
}

int rc_setChannelDistance(int channel, Uint8 dist)
{
    return Mix_SetDistance(channel, dist);
}

int rc_setChannelPanning(int channel, Uint8 l, Uint8 r)
{
    return Mix_SetPanning(channel, l, r);
}


int rc_setChannelSpacePosition(int channel, double angle, double distance)
{
    return Mix_SetPosition(channel, (Sint16)angle, (Uint8) distance);
}


#endif // RC_AUDIO_H_INCLUDED
