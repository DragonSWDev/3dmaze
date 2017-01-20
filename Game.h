#ifndef GAME_H
#define GAME_H

#define MAZE_MAXSIZE 40
#define MAZE_MINSIZE 13

#include <iostream>
#include <fstream>
#include <vector>

#include <irrlicht/irrlicht.h>

//Irrlicht and C++ namespaces
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

using namespace std;


class Game
{
private:
    int width, height, mazeSize;
    bool vsync, fog, fullscreen;
    IrrlichtDevice *device;
    IVideoDriver *driver;
    ISceneManager *scenemgr;
    
    void loadConfig();
    
public:
    Game();
    void startGame();
    
};

#endif // GAME_H
