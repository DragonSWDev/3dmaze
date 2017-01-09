#include "Game.h"

Game::Game()
{
    //Set default variables
    width = 800;
    height = 600;
    vsync = false;
    fullscreen = false;
    fog = true;
    
    //Try to load configuration
    loadConfig();
    
    //If user set wrong size, correct it
    if(mazeSize > MAZE_MAXSIZE)
        mazeSize = MAZE_MAXSIZE;
    
    if(mazeSize < MAZE_MINSIZE)
        mazeSize = MAZE_MINSIZE;
}

void Game::loadConfig()
{
    vector <std::string> options;
    std::string option, value;
    bool isOption = true;
    
    ifstream fin("config.cfg");
    
    if(!fin.is_open())
    {
        cout << "Failed to load config file. Setting default variables." << endl;
        return;
    }
    
    while(!fin.eof())
    {
        std::string tmp;
        fin >> tmp;
        options.push_back(tmp);
    }
    
    fin.close();
    
    for(unsigned int i = 0; i < options.size(); i++)
    {
        for(unsigned int j = 0; j < options[i].size(); j++)
        {
            //'=' catched, so now we picking value, not option
            if(options[i][j] == '=')
            {
                isOption = false;
                continue;
            }
            
            if(isOption)
                option += options[i][j];
            
            if(!isOption)
                value += options[i][j];
        }
        
        //Save game options
        if(option.compare("width") == 0)
            width = atoi(value.c_str());
        
        if(option.compare("height") == 0)
            height = atoi(value.c_str());
        
        if(option.compare("mazeSize") == 0)
            mazeSize = atoi(value.c_str());
        
        if(option.compare("vsync") == 0)
        {
            if(value.compare("true") == 0)
                vsync = true;
            else if (value.compare("false") == 0)
                vsync = false;
        }
        
        if(option.compare("fullscreen") == 0)
        {
            if(value.compare("true") == 0)
                fullscreen = true;
            else if (value.compare("false") == 0)
                fullscreen = false;
        }
        
        if(option.compare("fog") == 0)
        {
            if(value.compare("true") == 0)
                fog = true;
            else if (value.compare("false") == 0)
                fog = false;
        }
        
        //Clear variables to use it in next loop step
        option="";
        value="";
        isOption = true;
    }
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


