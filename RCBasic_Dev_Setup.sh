sudo apt update

sudo apt install git
sudo apt install make
sudo apt install g++
sudo apt install geany
sudo apt install spice-webdavd spice-client-gtk
sudo apt install codeblocks
sudo apt install python3
sudo apt install openjdk-21-jdk

cd ..

git clone --branch "v2.4.2" https://github.com/erincatto/box2d.git
git clone --branch "3.21" https://github.com/bulletphysics/bullet3.git

sudo apt install libsdl2-dev
sudo apt install libsdl2-image-dev
sudo apt install libsdl2-mixer-dev
sudo apt install libsdl2-net-dev

sudo apt install libogg-dev
sudo apt install libvorbis-dev
sudo apt install libtheora-dev

git clone git@github.com:n00b87/RCBASIC4.git
git clone git@github.com:n00b87/an8-parser.git --branch irrlicht_loader
git clone git@github.com:n00b87/IrrTheora.git
git clone git@github.com:n00b87/RCBasic-Studio.git
git clone git@github.com:n00b87/RCIrrlicht.git --branch sdl2_device
git clone git@github.com:n00b87/RCIrrlicht.git RCIrrlicht_em --branch ogles2_sdl2 
git clone git@github.com:n00b87/irrBullet.git
git clone git@github.com:n00b87/RCDocs.git

git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk install 3.1.72
./emsdk activate 3.1.72
