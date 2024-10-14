LOCAL_PATH := $(call my-dir)

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := Bullet-prebuilt
LOCAL_SRC_FILES := ../bullet3/build3/Android/obj/local/$(TARGET_ARCH_ABI)/libBullet.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := freetype-prebuilt
LOCAL_SRC_FILES := ../freetype/Android/libs/$(TARGET_ARCH_ABI)/libfreetype.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL
SDL_IMAGE_PATH := ../SDL2_image
SDL_MIXER_PATH := ../SDL2_mixer
SDL_NET_PATH := ../SDL2_net
THEORA_PATH := ../theora
IRR_PATH := ../RCIrrlicht
BULLET_PATH := ../bullet3
IRRBULLET_PATH := ../irrBullet
IRRTHEORA_PATH := ../irrTheora
FREETYPE_PATH := ../freetype
BOX2D_PATH := ../box2d-2.4.2
AN8_PATH := ../an8-parser

VORBIS_LIBRARY_PATH := ../libvorbis64
THEORAPLAY_PATH := ../src/theoraplay

ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
VORBIS_LIBRARY_PATH := ../libvorbisidec-1.2.1
THEORAPLAY_PATH := ../src/theoraplay_tremor
endif

LOCAL_CFLAGS := -I$(LOCAL_PATH)/$(THEORAPLAY_PATH) -I$(LOCAL_PATH)/$(IRR_PATH)/include -DRC_ANDROID_BUILD
LOCAL_CPP_FEATURES += exceptions

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include \
					$(LOCAL_PATH)/$(SDL_IMAGE_PATH) \
					$(LOCAL_PATH)/$(SDL_MIXER_PATH) \
					$(LOCAL_PATH)/$(SDL_NET_PATH) \
					$(LOCAL_PATH)/$(THEORA_PATH) \
					$(LOCAL_PATH)/$(VORBIS_LIBRARY_PATH)/include \
					$(LOCAL_PATH)/$(THEORAPLAY_PATH) \
					$(LOCAL_PATH)/$(IRR_PATH)/include \
					$(LOCAL_PATH)/$(BULLET_PATH)/src \
					$(LOCAL_PATH)/$(IRRBULLET_PATH)/include \
					$(LOCAL_PATH)/$(IRRTHEORA_PATH) \
					$(LOCAL_PATH)/$(FREETYPE_PATH)/include \
					$(LOCAL_PATH)/$(AN8_PATH) \
					$(LOCAL_PATH)/$(BOX2D_PATH)/include

# Add your application source files here...
LOCAL_SRC_FILES := main.cpp $(LOCAL_PATH)/$(THEORAPLAY_PATH)/theoraplay.c gui_freetype_font.cpp

LOCAL_SRC_FILES += \
	$(BOX2D_PATH)/src/collision/b2_broad_phase.cpp \
	$(BOX2D_PATH)/src/collision/b2_chain_shape.cpp \
	$(BOX2D_PATH)/src/collision/b2_circle_shape.cpp \
	$(BOX2D_PATH)/src/collision/b2_collide_circle.cpp \
	$(BOX2D_PATH)/src/collision/b2_collide_edge.cpp \
	$(BOX2D_PATH)/src/collision/b2_collide_polygon.cpp \
	$(BOX2D_PATH)/src/collision/b2_collision.cpp \
	$(BOX2D_PATH)/src/collision/b2_distance.cpp \
	$(BOX2D_PATH)/src/collision/b2_dynamic_tree.cpp \
	$(BOX2D_PATH)/src/collision/b2_edge_shape.cpp \
	$(BOX2D_PATH)/src/collision/b2_polygon_shape.cpp \
	$(BOX2D_PATH)/src/collision/b2_time_of_impact.cpp \
	$(BOX2D_PATH)/src/common/b2_block_allocator.cpp \
	$(BOX2D_PATH)/src/common/b2_draw.cpp \
	$(BOX2D_PATH)/src/common/b2_math.cpp \
	$(BOX2D_PATH)/src/common/b2_settings.cpp \
	$(BOX2D_PATH)/src/common/b2_stack_allocator.cpp \
	$(BOX2D_PATH)/src/common/b2_timer.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_body.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_chain_circle_contact.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_chain_polygon_contact.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_circle_contact.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_contact.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_contact_manager.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_contact_solver.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_distance_joint.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_edge_circle_contact.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_edge_polygon_contact.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_fixture.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_friction_joint.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_gear_joint.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_island.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_joint.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_motor_joint.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_mouse_joint.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_polygon_circle_contact.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_polygon_contact.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_prismatic_joint.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_pulley_joint.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_revolute_joint.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_weld_joint.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_wheel_joint.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_world_callbacks.cpp \
	$(BOX2D_PATH)/src/dynamics/b2_world.cpp \
	$(BOX2D_PATH)/src/rope/b2_rope.cpp \
	$(IRRBULLET_PATH)/src/irrBulletBoxShape.cpp \
	$(IRRBULLET_PATH)/src/irrBulletBvhTriangleMeshShape.cpp \
	$(IRRBULLET_PATH)/src/irrBulletCapsuleShape.cpp \
	$(IRRBULLET_PATH)/src/irrBulletCollisionCallBackInformation.cpp \
	$(IRRBULLET_PATH)/src/irrBulletCollisionObjectAffectorAttract.cpp \
	$(IRRBULLET_PATH)/src/irrBulletCollisionObjectAffector.cpp \
	$(IRRBULLET_PATH)/src/irrBulletCollisionObjectAffectorDelete.cpp \
	$(IRRBULLET_PATH)/src/irrBulletCollisionObject.cpp \
	$(IRRBULLET_PATH)/src/irrBulletCollisionShape.cpp \
	$(IRRBULLET_PATH)/src/irrBulletcommon.cpp \
	$(IRRBULLET_PATH)/src/irrBulletConeShape.cpp \
	$(IRRBULLET_PATH)/src/irrBulletConvexHullShape.cpp \
	$(IRRBULLET_PATH)/src/irrBullet.cpp \
	$(IRRBULLET_PATH)/src/irrBulletCylinderShape.cpp \
	$(IRRBULLET_PATH)/src/irrBulletGhostObject.cpp \
	$(IRRBULLET_PATH)/src/irrBulletGImpactMeshShape.cpp \
	$(IRRBULLET_PATH)/src/irrBulletLiquidBody.cpp \
	$(IRRBULLET_PATH)/src/irrBulletMotionState.cpp \
	$(IRRBULLET_PATH)/src/irrBulletPhysicsDebug.cpp \
	$(IRRBULLET_PATH)/src/irrBulletRayCastVehicle.cpp \
	$(IRRBULLET_PATH)/src/irrBulletRigidBody.cpp \
	$(IRRBULLET_PATH)/src/irrBulletSoftBody.cpp \
	$(IRRBULLET_PATH)/src/irrBulletSphereShape.cpp \
	$(IRRBULLET_PATH)/src/irrBulletTriangleMeshShape.cpp \
	$(IRRBULLET_PATH)/src/irrBulletWorld.cpp




LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image SDL2_mixer SDL2_net Irrlicht freetype-prebuilt
LOCAL_STATIC_LIBRARIES := Bullet-prebuilt android_native_app_glue

RC_TH_LOCAL_SHARED_LIBRARIES := ogg_shared vorbis64 theora

ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
RC_TH_LOCAL_SHARED_LIBRARIES := ogg_shared tremor theora
LOCAL_CFLAGS += -DRC_USE_TREMOR -O2
endif

LOCAL_SHARED_LIBRARIES += $(RC_TH_LOCAL_SHARED_LIBRARIES)

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -lOpenSLES -llog -landroid 

include $(BUILD_SHARED_LIBRARY)
