#include "MazeGenerator.h"

//Generate random num in range and return it
int MazeGenerator::randNum(int min, int max)
{
    return rand()%(max-min+1)+min;
}

void MazeGenerator::generateRandomDirs(vector<int>& directions)
{
    for(int i = 1; i <= 4; i++)
        directions.push_back(i);
    
    random_shuffle(directions.begin(), directions.end());
}

void MazeGenerator::addPath(int r, int c, bool *mazeArray[])
{
    vector <int> randDirs;
    
    generateRandomDirs(randDirs);
    
    for(int i = 0; i < randDirs.size(); i++)
    {
        switch(randDirs[i])
        {
            //Go up
            case 1:
                if (r - 2 <= 0)
                 continue;
                
             if (mazeArray[r - 2][c]) {
                 mazeArray[r - 2][c] = false;
                 mazeArray[r-  1][c] = false;
                 addPath(r - 2, c, mazeArray);
             }
             break;
             
             //Go down
            case 2:
                if (c + 2 >= mazeSize - 1)
                    continue;
                
                if (mazeArray[r][c + 2]) 
                {
                    mazeArray[r][c + 2] = false;
                    mazeArray[r][c + 1] = false;
                    addPath(r, c + 2, mazeArray);
                }
            break;
             
            //Go right
            case 3:
                if (r + 2 >= mazeSize - 1)
                    continue;
             
                if (mazeArray[r + 2][c]) 
                {
                    mazeArray[r + 2][c] = false;
                    mazeArray[r + 1][c] = false;
                    addPath(r + 2, c, mazeArray);
                }
                break;
             
            //Go left
            case 4:
                if (c - 2 <= 0)
                    continue;
             
                if (mazeArray[r][c - 2]) 
                {
                    mazeArray[r][c - 2] = false;
                    mazeArray[r][c - 1] = false;
                    addPath(r, c - 2, mazeArray);
                }
            break;
        }
    }
}

void MazeGenerator::generateMaze(int size, bool *mazeArray[])
{
    mazeSize = size;
    
    //Generate and set first point (it will start from it)
    int r = randNum(0, size-1);
    
    while(r % 2 == 0)
    {
       r = randNum(0, size-1); 
    }
    
    int c = randNum(0, size-1);
    
    while(c % 2 == 0)
    {
        c = randNum(0, size-1);
    }
    
    //False is empty field (no wall)
    mazeArray[r][c] = false;
    
    //Generate rest
    addPath(r, c, mazeArray);
}
