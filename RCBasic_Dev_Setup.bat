cd ..

set DEV_BASE_DIR=%CD%

git clone --branch sdl2_device https://github.com/n00b87/RCIrrlicht.git

git clone --branch irrlicht_loader https://github.com/n00b87/an8-parser.git

git clone https://github.com/n00b87/RCDocs.git
git clone https://github.com/n00b87/IrrTheora.git
git clone https://github.com/n00b87/irrBullet.git

git clone --branch "VER-2-13-3" https://github.com/freetype/freetype.git

curl -Lo SDL2-devel-2.30.10-mingw.zip "https://github.com/libsdl-org/SDL/releases/download/release-2.30.10/SDL2-devel-2.30.10-mingw.zip"
tar -xf SDL2-devel-2.30.10-mingw.zip
rename SDL2-2.30.10 SDL2-dev

curl -Lo SDL2_image-devel-2.8.3-mingw.zip "https://github.com/libsdl-org/SDL_image/releases/download/release-2.8.3/SDL2_image-devel-2.8.3-mingw.zip"
tar -xf SDL2_image-devel-2.8.3-mingw.zip
rename SDL2_image-2.8.3 SDL2_image-dev

curl -Lo SDL2_mixer-devel-2.8.0-mingw.zip "https://github.com/libsdl-org/SDL_mixer/releases/download/release-2.8.0/SDL2_mixer-devel-2.8.0-mingw.zip"
tar -xf SDL2_mixer-devel-2.8.0-mingw.zip
rename SDL2_mixer-2.8.0 SDL2_mixer-dev

curl -Lo SDL2_net-devel-2.2.0-mingw.zip "https://github.com/libsdl-org/SDL_net/releases/download/release-2.2.0/SDL2_net-devel-2.2.0-mingw.zip"
tar -xf SDL2_net-devel-2.2.0-mingw.zip
rename SDL2_net-2.2.0 SDL2_net-dev

git clone --branch "v1.1.1" https://github.com/xiph/theora.git
git clone --branch "v1.1.1" https://github.com/xiph/theora.git theora64
git clone --branch "v1.3.7" https://github.com/xiph/vorbis.git
git clone --branch "v1.3.5" https://github.com/xiph/ogg.git

git clone --branch "v2.4.2" https://github.com/erincatto/box2d.git
git clone --branch "3.25" https://github.com/bulletphysics/bullet3.git

cd ogg

set TMP_PATH=%PATH%

set PATH=%MINGW32%\bin;%PATH%
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
set PATH=%TMP_PATH%

cd ..

set PATH=%MINGW64%\bin;%PATH%
mkdir build64
cd build64
cmake -G "MinGW Makefiles" ..
mingw32-make
set PATH=%TMP_PATH%

cd %DEV_BASE_DIR%

cd vorbis

set PATH=%MINGW32%\bin;%PATH%
mkdir build
cd build
cmake -G "MinGW Makefiles" .. -DOGG_INCLUDE_DIR=%DEV_BASE_DIR%\ogg\include -DOGG_LIBRARY=%DEV_BASE_DIR%\ogg\build\libogg.a
mingw32-make
set PATH=%TMP_PATH%

cd ..

set PATH=%MINGW64%\bin;%PATH%
mkdir build64
cd build64
cmake -G "MinGW Makefiles" .. -DOGG_INCLUDE_DIR=%DEV_BASE_DIR%\ogg\include -DOGG_LIBRARY=%DEV_BASE_DIR%\ogg\build64\libogg.a
mingw32-make
set PATH=%TMP_PATH%

cd %DEV_BASE_DIR%

set PATH=%MINGW32%\bin;%PATH%
cd theora\win32\xmingw32
set bash="C:\Program Files\Git\bin\sh.exe"
%bash% --login -i -c "export dev_dir=$PWD/../../.. && export C_INCLUDE_PATH=$dev_dir/ogg/include && export C_INCLUDE_PATH=$dev_dir/vorbis/include:$C_INCLUDE_PATH && export LIBRARY_PATH=$dev_dir/ogg/build:$LIBRARY_PATH && export LIBRARY_PATH=$dev_dir/vorbis/build/lib:$LIBRARY_PATH && mingw32-make libtheoradec.dll"
set PATH=%TMP_PATH%

cd %DEV_BASE_DIR%

set PATH=%MINGW64%\bin;%PATH%
cd theora64\win32\xmingw32
set bash="C:\Program Files\Git\bin\sh.exe"
%bash% --login -i -c "export dev_dir=$PWD/../../.. && export C_INCLUDE_PATH=$dev_dir/ogg/include && export C_INCLUDE_PATH=$dev_dir/vorbis/include:$C_INCLUDE_PATH && export LIBRARY_PATH=$dev_dir/ogg/build64:$LIBRARY_PATH && export LIBRARY_PATH=$dev_dir/vorbis/build64/lib:$LIBRARY_PATH && mingw32-make libtheoradec.dll"
set PATH=%TMP_PATH%

cd %DEV_BASE_DIR%


cd box2d

set PATH=%MINGW32%\bin;%PATH%
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
set PATH=%TMP_PATH%

cd ..

set PATH=%MINGW64%\bin;%PATH%
mkdir build64
cd build64
cmake -G "MinGW Makefiles" ..
mingw32-make
set PATH=%TMP_PATH%

cd %DEV_BASE_DIR%



cd bullet3

cd src
mklink /J bullet %CD%
cd ..

set PATH=%MINGW32%\bin;%PATH%
mkdir build
cd build
cmake -G "MinGW Makefiles" .. -DBUILD_OPENGL3_DEMOS=OFF -DBUILD_BULLET2_DEMOS=OFF -DBUILD_UNIT_TESTS=OFF -DUSE_GRAPHICAL_BENCHMARK=OFF
mingw32-make
set PATH=%TMP_PATH%

cd ..

set PATH=%MINGW64%\bin;%PATH%
mkdir build64
cd build64
cmake -G "MinGW Makefiles" .. -DBUILD_OPENGL3_DEMOS=OFF -DBUILD_BULLET2_DEMOS=OFF -DBUILD_UNIT_TESTS=OFF -DUSE_GRAPHICAL_BENCHMARK=OFF
mingw32-make
set PATH=%TMP_PATH%

cd %DEV_BASE_DIR%


cd freetype

cd include
mklink /J freetype2 %CD%
cd ..

set PATH=%MINGW32%\bin;%PATH%
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
set PATH=%TMP_PATH%

cd ..

set PATH=%MINGW64%\bin;%PATH%
mkdir build64
cd build64
cmake -G "MinGW Makefiles" ..
mingw32-make
set PATH=%TMP_PATH%

cd %DEV_BASE_DIR%


cd RCIrrlicht\include
del IrrCompileConfig.h
rename IrrCompileConfig_win.h IrrCompileConfig.h
cd %DEV_BASE_DIR%

cd RCIrrlicht\source\Irrlicht

set PATH=%CODEBLOCKS_DIR%;%PATH%

codeblocks --clean --target="Win32 - Release - accurate math - dll" Irrlicht-gcc.cbp
codeblocks --clean --target="Release64 - accurate math - dll" Irrlicht-gcc.cbp

codeblocks --build --target="Win32 - Release - accurate math - dll" Irrlicht-gcc.cbp
codeblocks --build --target="Release64 - accurate math - dll" Irrlicht-gcc.cbp

set PATH=%TMP_PATH%

cd %DEV_BASE_DIR%

echo ------------------------
echo Setup Complete