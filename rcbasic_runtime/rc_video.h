#ifndef RC_VIDEO_H_INCLUDED
#define RC_VIDEO_H_INCLUDED

#include "rc_gfx_core.h"
#include <irrtheora.h>



void rc_loadVideo( std::string vid_file )
{
	irrtheora::loadVideo(vid_file);
}

void rc_playVideo( int v_loops )
{
	if(rc_active_canvas < 0 || rc_active_canvas >= rc_canvas.size())
	{
		std::cout << "PlayVideo Error: No Active Canvas available" << std::endl;
		return;
	}

	if(!rc_canvas[rc_active_canvas].texture)
	{
		std::cout << "PlayVideo Error: No Active Canvas available" << std::endl;
		return;
	}

	irrtheora::playVideo(v_loops, rc_canvas[rc_active_canvas].texture);
}

void rc_pauseVideo( )
{
	irrtheora::pauseVideo();
}

void rc_stopVideo( )
{
	irrtheora::stopVideo();
}

void rc_setVideoPosition(Uint32 pos)
{
	irrtheora::setVideoPosition(pos);
}

void rc_resumeVideo( )
{
	irrtheora::resumeVideo();
}

Uint32 rc_getVideoPosition( )
{
	return irrtheora::videoPosition();
}

void rc_deleteVideo( )
{
	irrtheora::deleteVideo();
}

bool rc_videoIsPlaying( )
{
	return irrtheora::videoIsPlaying();
}

bool rc_videoEnd( )
{
	return irrtheora::videoEnd();
}

void rc_getVideoStats( std::string vid_file,  double* vlen,  double* vfps,  double* frame_w,  double* frame_h )
{
	irrtheora::getVideoStats(vid_file, vlen, vfps, frame_w, frame_h);
}

void rc_setVideoDrawRect( double x, double y,  double w,  double h )
{
	irrtheora::setVideoDrawRect(x, y, w, h);
}

void rc_getVideoDrawRect( double* x,  double* y,  double* w,  double* h )
{
	irrtheora::getVideoDrawRect(x, y, w, h);
}

void rc_getVideoSize( double* w,  double* h )
{
	irrtheora::getVideoSize(w, h);
}

bool rc_videoExists( )
{
	return irrtheora::videoExists();
}


void rc_setVideoVolume( int vol )
{
	irrtheora::setVideoVolume(vol);
}

int rc_getVideoVolume( )
{
	return irrtheora::getVideoVolume();
}



#endif // RC_VIDEO_H_INCLUDED
