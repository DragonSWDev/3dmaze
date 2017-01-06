# 3D Maze
This is the simple 3D game written in C++ with Irrlicht Engine. You have to solve randomly generated maze. Game is currently unfinished.

### Installation guide

#### 1. Install Irrlicht engine and CMake

#### 2. Get source code

    git clone https://github.com/BlackDragonK99/sfml-snake && cd sfml-snake
    
#### 3. Configure and build
**Unix-like (Linux, BSD etc.)**

    mkdir build && cd build
    cmake ..
    make
    
If You have Irrlicht installed in custom location, You can specify include and lib files by adding this to CMakeLists.txt:

    include_directories(/mydir/include)
    link_directories(/mydir/lib)
    
**Windows**

There is cmake for Windows, but it is recommended to use Visual Studio. Download and install VS, create new project, set up Irrlicht, import 3D Maze source code to the created project and compile it. You can find instructions about using Irrlicht with Visual Studio here:
http://irrlicht.sourceforge.net/docu/example001.html
    
#### 4. Copy compiled binary (3dmaze) to the desired directory and put directory font with content next to binary
You have to put wall.tga file next to the binary.

### Manual
You can specify options by creating config.cfg file.

#### Configuration options
**width=800** - window/screen width

**height=600** - window/screen height

**vsync=true** - enable or disable vsync

**fog=true** - enable or disable fog

**fullscreen=false** - run in windowed or full screen mode

**mazeSize=20** - specify maze size - min is 8, max is 128
