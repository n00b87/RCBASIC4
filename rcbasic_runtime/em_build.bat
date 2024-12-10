set BASEDIR=%~dp0

rem set PROG_LOCATION=C:\Users\Shadow\Desktop\rc_out\RCBasic_Package_64\examples\tile_demo
rem set OUT_HTML=C:\Users\Shadow\Desktop\test\tile_demo\test_tile_web\tile_demo.html

set PROG_LOCATION=%1
set OUT_HTML=%2

echo current file: %BASEDIR%


cd %BASEDIR%

set EMSDK_PATH=%BASEDIR%emsdk\

set RC_EMSDK_VERSION=3.1.72


if not exist "%EMSDK_PATH%emsdk.bat" (
echo hello world 
git clone https://github.com/emscripten-core/emsdk.git
pushd %EMSDK_PATH%
call .\emsdk.bat install %RC_EMSDK_VERSION%
popd
)


pushd %EMSDK_PATH%
call .\emsdk.bat activate %RC_EMSDK_VERSION%
call .\emsdk_env.bat
popd


emcc ^
	-L%BASEDIR% ^
	--use-port=freetype ^
	libIrrlicht.a ^
	-lbox2d ^
	-lBullet3Collision -lBullet3Common -lBullet3Dynamics -lBullet3Geometry -lBulletCollision -lBulletDynamics -lBulletInverseDynamics -lBulletSoftBody -lLinearMath ^
	-s FULL_ES2=1 ^
	-s USE_SDL=2 -s USE_SDL_IMAGE=2 -s USE_SDL_MIXER=2 -s USE_SDL_NET=2 -s USE_OGG=1 -s USE_VORBIS=1 -ltheora -ltheoradec -O3 -s ASYNCIFY --use-preload-plugins ^
	gui_freetype_font.o ^
	irrBulletBoxShape.o ^
	irrBulletBvhTriangleMeshShape.o ^
	irrBulletCapsuleShape.o ^
	irrBulletCollisionCallBackInformation.o ^
	irrBulletCollisionObjectAffectorAttract.o ^
	irrBulletCollisionObjectAffectorDelete.o ^
	irrBulletCollisionObjectAffector.o ^
	irrBulletCollisionObject.o ^
	irrBulletCollisionShape.o ^
	irrBulletcommon.o ^
	irrBulletConeShape.o ^
	irrBulletConvexHullShape.o ^
	irrBulletCylinderShape.o ^
	irrBulletPhysicsDebug.o ^
	irrBulletRayCastVehicle.o ^
	irrBullet.o ^
	irrBulletRigidBody.o ^
	irrBulletLiquidBody.o ^
	irrBulletSoftBody.o ^
	irrBulletSphereShape.o ^
	main.o ^
	theoraplay.o ^
	irrBulletGhostObject.o ^
	irrBulletGImpactMeshShape.o ^
	irrBulletMotionState.o ^
	irrBulletTriangleMeshShape.o ^
	irrBulletWorld.o ^
	-o "%OUT_HTML%" --preload-file %PROG_LOCATION%@ --use-preload-plugins -s TOTAL_MEMORY=134217728 -s ALLOW_MEMORY_GROWTH=1 -s MAXIMUM_MEMORY=1073741824

