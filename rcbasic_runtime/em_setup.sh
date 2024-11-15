#!/bin/bash

export PROG_LOCATION=/home/n00b/projects/rcbasic_alpha3/test_project
export OUT_HTML=/home/n00b/projects/rc_em/output/test.html

export EMSDK_PATH=/home/n00b/Programs/emsdk

export THEORA_LIB=/home/n00b/Projects/rc_em/libtheora-1.1.1/out/lib
export THEORA_INCLUDE=/home/n00b/Projects/rc_em/libtheora-1.1.1/out/include

export IRR_LIB=/home/n00b/Projects/RCIrrlicht/lib/emscripten
export IRR_INCLUDE=/home/n00b/Projects/RCIrrlicht/include

export BULLET_LINKER_LIBS="
-L/home/n00b/Projects/bullet3/em_build/src/Bullet3Collision 
-L/home/n00b/Projects/bullet3/em_build/src/Bullet3Common 
-L/home/n00b/Projects/bullet3/em_build/src/Bullet3Dynamics 
-L/home/n00b/Projects/bullet3/em_build/src/Bullet3Geometry 
-L/home/n00b/Projects/bullet3/em_build/src/Bullet3OpenCL 
-L/home/n00b/Projects/bullet3/em_build/src/Bullet3Serialize 
-L/home/n00b/Projects/bullet3/em_build/src/BulletCollision 
-L/home/n00b/Projects/bullet3/em_build/src/BulletDynamics 
-L/home/n00b/Projects/bullet3/em_build/src/BulletInverseDynamics 
-L/home/n00b/Projects/bullet3/em_build/src/BulletSoftBody 
-L/home/n00b/Projects/bullet3/em_build/src/LinearMath
"
export BULLET_INCLUDE=/home/n00b/Projects/bullet3/em_build/include
export BULLET_INCLUDE_LOCAL=/home/n00b/Projects/bullet3/em_build/include/bullet

export IRR_BULLET_SRC_DIR=/home/n00b/Projects/irrBullet/src

# export IRR_BULLET_SRC=

export IRR_BULLET_INCLUDE=/home/n00b/Projects/irrBullet/include

export IRR_THEORA_INCLUDE=/home/n00b/Projects/irrTheora

export AN8_INCLUDE=/home/n00b/Projects/an8-parser

export BOX2D_LIB=/home/n00b/Projects/box2d-2.4.2/box2d-2.4.2/em_build/bin
export BOX2D_INCLUDE=/home/n00b/Projects/box2d-2.4.2/box2d-2.4.2/include


em++ main.cpp \
	theoraplay.c \
	gui_freetype_font.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletBoxShape.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletBvhTriangleMeshShape.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletCapsuleShape.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletCollisionCallBackInformation.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletCollisionObjectAffectorAttract.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletCollisionObjectAffector.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletCollisionObjectAffectorDelete.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletCollisionObject.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletCollisionShape.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletcommon.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletConeShape.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletConvexHullShape.cpp \
	$IRR_BULLET_SRC_DIR/irrBullet.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletCylinderShape.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletGhostObject.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletGImpactMeshShape.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletLiquidBody.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletMotionState.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletPhysicsDebug.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletRayCastVehicle.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletRigidBody.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletSoftBody.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletSphereShape.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletTriangleMeshShape.cpp \
	$IRR_BULLET_SRC_DIR/irrBulletWorld.cpp \
	"-I$IRR_BULLET_INCLUDE" \
	"-L$THEORA_LIB" \
	"-I$THEORA_INCLUDE" \
	"-L$IRR_LIB" \
	"-I$IRR_INCLUDE" \
	"$IRR_LIB/libIrrlicht.a" \
	"-I$BULLET_INCLUDE" \
	"-I$BULLET_INCLUDE_LOCAL" \
	-L/home/n00b/Projects/bullet3/em_build/src/Bullet3Collision \
	-L/home/n00b/Projects/bullet3/em_build/src/Bullet3Common \
	-L/home/n00b/Projects/bullet3/em_build/src/Bullet3Dynamics \
	-L/home/n00b/Projects/bullet3/em_build/src/Bullet3Geometry \
	-L/home/n00b/Projects/bullet3/em_build/src/Bullet3OpenCL \
	-L/home/n00b/Projects/bullet3/em_build/src/Bullet3Serialize \
	-L/home/n00b/Projects/bullet3/em_build/src/BulletCollision \
	-L/home/n00b/Projects/bullet3/em_build/src/BulletDynamics \
	-L/home/n00b/Projects/bullet3/em_build/src/BulletInverseDynamics \
	-L/home/n00b/Projects/bullet3/em_build/src/BulletSoftBody \
	-L/home/n00b/Projects/bullet3/em_build/src/LinearMath \
	-lBullet3Collision -lBullet3Common -lBullet3Dynamics -lBullet3Geometry -lBulletCollision -lBulletDynamics -lBulletInverseDynamics -lBulletSoftBody -lLinearMath \
	"-I$IRR_THEORA_INCLUDE" \
	"-I$AN8_INCLUDE" \
	"-L$BOX2D_LIB" \
	"-I$BOX2D_INCLUDE" \
	-lbox2d \
	--use-port=freetype \
	-s FULL_ES2=1 \
	-s USE_SDL=2 -s USE_SDL_IMAGE=2 -s USE_SDL_MIXER=2 -s USE_SDL_NET=2 -s USE_OGG=1 -s USE_VORBIS=1 -ltheora -ltheoradec -o "$OUT_HTML" --preload-file $PROG_LOCATION@ -O3 -s ASYNCIFY -s SDL2_IMAGE_FORMATS='["bmp","png","xpm"]' --use-preload-plugins -s TOTAL_MEMORY=134217728 -s ALLOW_MEMORY_GROWTH=1 -s MAXIMUM_MEMORY=1073741824


#	--use-port=bullet \

#	-L/home/n00b/Projects/bullet3/em_build/src/Bullet3Collision \
#	-L/home/n00b/Projects/bullet3/em_build/src/Bullet3Common \
#	-L/home/n00b/Projects/bullet3/em_build/src/Bullet3Dynamics \
#	-L/home/n00b/Projects/bullet3/em_build/src/Bullet3Geometry \
#	-L/home/n00b/Projects/bullet3/em_build/src/Bullet3OpenCL \
#	-L/home/n00b/Projects/bullet3/em_build/src/Bullet3Serialize \
#	-L/home/n00b/Projects/bullet3/em_build/src/BulletCollision \
#	-L/home/n00b/Projects/bullet3/em_build/src/BulletDynamics \
#	-L/home/n00b/Projects/bullet3/em_build/src/BulletInverseDynamics \
#	-L/home/n00b/Projects/bullet3/em_build/src/BulletSoftBody \
#	-L/home/n00b/Projects/bullet3/em_build/src/LinearMath \
