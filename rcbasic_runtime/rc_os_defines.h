#ifndef RC_OS_DEFINES_H_INCLUDED
#define RC_OS_DEFINES_H_INCLUDED

//USED FOR TESTING ONLY
#define RC_TESTING

//I am checking Android first since I think it also defines __linux__

#if defined(__ANDROID__)
	#define RC_ANDROID
#elif defined(__linux__)
	#define RC_LINUX
#elif defined(__EMSCRIPTEN__)
	#define RC_WEB
#elif defined(_WIN32) || defined(_WIN64)
	#define RC_WINDOWS
#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
	 #include <TargetConditionals.h>
    #if defined(TARGET_IPHONE_SIMULATOR) || defined(TARGET_OS_IPHONE)
		#define RC_IOS
    #else
		#define RC_MAC
	#endif // TARGET_IPHONE_SIMULATOR
#endif // defined

#ifdef RC_WEB
#define RC_LINUX
#define RC_DRIVER_GLES2
#endif

#ifdef RC_ANDROID
#define RC_MOBILE
#define RC_DRIVER_GLES2
#endif

#ifdef RC_IOS
#define RC_MOBILE
#define RC_DRIVER_GLES2
#endif

//FOR TESTING PURPOSES
#ifdef RC_TESTING
//#define RC_DRIVER_GLES2
#endif // RC_TESTING

#define RC_PI 3.14159265359

inline double rc_util_radians(double degrees)
{
    return degrees * (RC_PI/180);
}

inline double rc_util_degrees(double radians)
{
    return radians * (180/RC_PI);
}

#endif // RC_OS_DEFINES_H_INCLUDED
