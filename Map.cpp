#include "Map.h"

Map::Map(int mazeSize)
{
    //Create dynamic 2D table and fill it with true (true means there is wall here)
    mapArray = new bool*[mazeSize];
    
    for(int i = 0; i < mazeSize; i++)
        mapArray[i] = new bool[mazeSize];
    
    for(int i = 0; i < mazeSize; i++)
        for(int j = 0; j < mazeSize; j++)
            mapArray[i][j] = true;
        
    size = mazeSize;
}

Map::~Map()
{
    //Delete array to release memory
    for(int i = 0; i < size; i++)
        delete [] mapArray[i];
    
    delete [] mapArray;
}

void Map::createMap(IVideoDriver *driver, ISceneManager *scenemgr)
{
    array <IMeshSceneNode*> nodes;
    
    mazeTexture = driver->getTexture("textures/wall.tga");
    
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
        {
            IMesh *cube = scenemgr->getGeometryCreator()->createCubeMesh(vector3df(30,30,30));
            
            IMeshSceneNode *wall = scenemgr->addMeshSceneNode(cube);
            
            if(mapArray[i][j])
                wall->setPosition(vector3df(j*30, 0, i*30));
            else
                wall->setPosition(vector3df(j*30, -30, i*30));
            
            wall->setMaterialTexture(0, mazeTexture);
                
            nodes.push_back(wall);
        }
        
    CMeshCombiner *combiner = new CMeshCombiner(0.8,40,ETPT_TILE);
    mapMesh = combiner->combineMeshes(driver, nodes);
    nodes.clear();
}

IMesh *Map::getMapMesh()
{
    return mapMesh;
}
