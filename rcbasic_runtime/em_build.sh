#!/bin/bash

BASEDIR=$(dirname $0)

cd $BASEDIR

export PROG_LOCATION=/home/n00b/projects/rcbasic_alpha3/test_project
export OUT_HTML=/home/n00b/projects/rc_em/output/test.html

export EMSDK_PATH=$BASEDIR/emsdk
export RCBASIC_SRC_PATH=$PWD/..

RC_EMSDK_VERSION=3.1.72

if [ ! -e $EMSDK_PATH ] 
then
git clone https://github.com/emscripten-core/emsdk.git
pushd $EMSDK_PATH
# I am selecting a version that I know works here since this might get broken by emscripten in the future
./emsdk install $RC_EMSDK_VERSION
popd
fi


pushd $EMSDK_PATH
# I am selecting a version that I know works here since this might get broken by emscripten in the future
./emsdk activate $RC_EMSDK_VERSION
source ./emsdk_env.sh
popd


emcc \
	-L$BASEDIR \
	--use-port=freetype \
	libIrrlicht.a \
	-lbox2d \
	-lBullet3Collision -lBullet3Common -lBullet3Dynamics -lBullet3Geometry -lBulletCollision -lBulletDynamics -lBulletInverseDynamics -lBulletSoftBody -lLinearMath \
	-s FULL_ES2=1 \
	-s USE_SDL=2 -s USE_SDL_IMAGE=2 -s USE_SDL_MIXER=2 -s USE_SDL_NET=2 -s USE_OGG=1 -s USE_VORBIS=1 -ltheora -ltheoradec -O3 -s ASYNCIFY -s SDL2_IMAGE_FORMATS='["bmp","png","xpm"]' --use-preload-plugins \
	gui_freetype_font.o \
	irrBulletBoxShape.o \
	irrBulletBvhTriangleMeshShape.o \
	irrBulletCapsuleShape.o \
	irrBulletCollisionCallBackInformation.o \
	irrBulletCollisionObjectAffectorAttract.o \
	irrBulletCollisionObjectAffectorDelete.o \
	irrBulletCollisionObjectAffector.o \
	irrBulletCollisionObject.o \
	irrBulletCollisionShape.o \
	irrBulletcommon.o \
	irrBulletConeShape.o \
	irrBulletConvexHullShape.o \
	irrBulletCylinderShape.o \
	irrBulletPhysicsDebug.o \
	irrBulletRayCastVehicle.o \
	irrBullet.o \
	irrBulletRigidBody.o \
	irrBulletLiquidBody.o \
	irrBulletSoftBody.o \
	irrBulletSphereShape.o \
	main.o \
	theoraplay.o \
	irrBulletGhostObject.o \
	irrBulletGImpactMeshShape.o \
	irrBulletMotionState.o \
	irrBulletTriangleMeshShape.o \
	irrBulletWorld.o \
	-o "$OUT_HTML" --preload-file $PROG_LOCATION@ --use-preload-plugins -s TOTAL_MEMORY=134217728 -s ALLOW_MEMORY_GROWTH=1 -s MAXIMUM_MEMORY=1073741824
