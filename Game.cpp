#include "Game.h"

Game::Game()
{
    //Load config false, so set default variables
    if(!loadConfig())
    {
        width = 800;
        height = 600;
        vsync = false;
        fullscreen = false;
        fog = true;
    }
}

bool Game::loadConfig()
{
    //Implement this later, now return false
    return false;
}

void Game::startGame()
{
    //Create Irrlicht device and get pointer to driver and scene manager
    device = createDevice(EDT_OPENGL, dimension2d<u32>(width, height), 32, fullscreen, false, vsync, 0);
    
    driver = device->getVideoDriver();
    scenemgr = device->getSceneManager();
    
    device->setWindowCaption(L"3D Maze");
    
    //Main loop
    while(device->run())
    {
        driver->beginScene(true, true, SColor(255,0,0,0));
        
        scenemgr->drawAll();
        
        driver->endScene();
    }
    
    device->drop();
}


