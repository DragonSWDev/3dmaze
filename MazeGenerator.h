#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H

/* This class is generating perfect maze by using Deep First Search alghoritm. You can find more informations about this here:
http://www.migapro.com/depth-first-search/
*/

#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class MazeGenerator
{
private:
    int mazeSize;
    
    int randNum(int min, int max);
    void generateRandomDirs(vector <int> &directions);
    void addPath(int r, int c, bool *mazeArray[]);
    
public:
    void generateMaze(int size, bool *mazeArray[]);
};

#endif // MAZEGENERATOR_H
