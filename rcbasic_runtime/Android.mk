LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL
IRRLICHT_PATH := ../RCIrrlicht

SDL_MIXER_PATH := ../SDL_mixer
SDL_NET_PATH := ../SDL_net
THEORA_PATH := ../theora
IRR_THEORA_PATH := ../irrTheora

AN8_PATH := ../an8-parser

BOX2D_PATH := ../box2d-2.4.2
BULLET_PATH := ../bullet3
IRR_BULLET_PATH := ../irrBullet

VORBIS_LIBRARY_PATH := ../libvorbis64
THEORAPLAY_PATH := ../src/theoraplay

FREETYPE_PATH := ../freetype-2.9.1

LOCAL_CFLAGS := -I$(LOCAL_PATH)/$(THEORAPLAY_PATH) -DRC_ANDROID_BUILD

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include \
					$(LOCAL_PATH)/$(SDL_MIXER_PATH)/include \
					$(LOCAL_PATH)/$(SDL_NET_PATH)/include \
					$(LOCAL_PATH)/$(THEORA_PATH)/include \
					$(LOCAL_PATH)/$(VORBIS_LIBRARY_PATH)/include \
					$(LOCAL_PATH)/$(THEORAPLAY_PATH) \
					$(LOCAL_PATH)/$(IRR_THEORA_PATH) \
					$(LOCAL_PATH)/$(FREETYPE_PATH)/include \
					$(LOCAL_PATH)/$(AN8_PATH) \
					$(LOCAL_PATH)/$(BOX2D_PATH)/include \
					$(LOCAL_PATH)/$(BULLET_PATH)/src \
					$(LOCAL_PATH)/$(IRR_BULLET_PATH)/include
					

LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(IRRLICHT_PATH)/include

# Add your application source files here...
LOCAL_SRC_FILES := main.cpp \
				   CShader.cpp \
				   gui_freetype_font.cpp \
				   ProjectiveTextures.cpp \
				   theoraplay.c

# Add irrBullet source files
LOCAL_SRC_FILES += $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletBoxShape.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletBvhTriangleMeshShape.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletCapsuleShape.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletCollisionCallBackInformation.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletCollisionObjectAffectorAttract.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletCollisionObjectAffector.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletCollisionObjectAffectorDelete.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletCollisionObject.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletCollisionShape.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletcommon.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletConeShape.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletConvexHullShape.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBullet.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletCylinderShape.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletGhostObject.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletGImpactMeshShape.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletLiquidBody.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletMotionState.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletPhysicsDebug.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletRayCastVehicle.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletRigidBody.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletSoftBody.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletSphereShape.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletTriangleMeshShape.cpp \
				   $(LOCAL_PATH)/$(IRR_BULLET_PATH)/src/irrBulletWorld.cpp


# LOCAL_SHARED_LIBRARIES := SDL2 SDL2_mixer SDL2_net ogg_shared vorbis64 theora
LOCAL_SHARED_LIBRARIES := SDL2 SDL2_mixer SDL2_net SDL2_ttf ogg_shared vorbis64 theora
LOCAL_STATIC_LIBRARIES := Irrlicht Box2d Bullet freetype

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -lOpenSLES -llog -landroid

include $(BUILD_SHARED_LIBRARY)
