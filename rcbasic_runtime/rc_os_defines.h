#ifndef RC_OS_DEFINES_H_INCLUDED
#define RC_OS_DEFINES_H_INCLUDED

#define RC_LINUX
#define RC_WEB
//#define RC_WINDOWS
//#define RC_ANDROID
//#define RC_MAC
//#define RC_IOS

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
#endif

//FOR DEBUG PURPOSES
#define RC_DRIVER_GLES2

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
