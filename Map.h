#ifndef MAP_H
#define MAP_H

#include <irrlicht/irrlicht.h>

/* This project using MeshCombiner created by Lonesome Ducky which You can find here:
   http://irrlicht.sourceforge.net/forum/viewtopic.php?t=39598 */
#include "MeshCombiner/CMeshCombiner.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Map
{
private:
   ITexture *mazeTexture;
   IMesh *mapMesh;
   bool **mapArray;
   int size;
    
public:
    Map(int mazeSize);
    ~Map();
    void createMap(IVideoDriver *driver, ISceneManager *scenemgr);
    IMesh *getMapMesh();
    
};

#endif // MAP_H
