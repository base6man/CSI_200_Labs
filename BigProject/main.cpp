// #include <SFML/Graphics.hpp>
// using namespace sf;

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <ctime>
#include "Entity.h"
using namespace std;

int main() {
    srand(time(0));
    rand();

    ifstream levelSize("level.txt");
    string firstLineOfLevel;
    levelSize >> firstLineOfLevel;
    const int WIDTH = firstLineOfLevel.size();

    int numLinesInLevel = 1;
    string nextLineOfLevel;
    while(!levelSize.eof()){
        numLinesInLevel++;
        levelSize >> nextLineOfLevel;
    }
    const int HEIGHT = numLinesInLevel;

    const Position END_OF_LEVEL = *(new Position(WIDTH, HEIGHT));
    Position placeInLevel = *(new Position(0, 0));

    Entity level[WIDTH * HEIGHT];
    
    ifstream levelFile("level.txt");
    if(levelFile.fail()){
        cerr << "Could not open level" << endl;
        return -1;
    }
    
    char nextChar;
    while(placeInLevel.x + END_OF_LEVEL.x*placeInLevel.y < END_OF_LEVEL.x*END_OF_LEVEL.y){
        levelFile >> nextChar;

        Entity* newEntity = new Entity(nextChar, placeInLevel, level, END_OF_LEVEL);

        level[placeInLevel.x + END_OF_LEVEL.x*placeInLevel.y] = *newEntity;
        delete newEntity;

        placeInLevel.x++;
        if(placeInLevel.x >= END_OF_LEVEL.x){
            placeInLevel.x = 0;
            placeInLevel.y++;
        }

    }

    cout << "Loaded level!" << endl;

    for(int i = 0; i < 20; i++){
        cout << endl;

        placeInLevel.reset();
        for(int i = 0; i < END_OF_LEVEL.y; i++){
            for(int j = 0; j < END_OF_LEVEL.x; j++){
                cout << level[placeInLevel.x + END_OF_LEVEL.x*placeInLevel.y].getChar();
                placeInLevel.x++;
            }
            placeInLevel.x = 0;
            placeInLevel.y++;
            cout << endl;
        }
        _sleep(300);

        for(int i = 0; i < END_OF_LEVEL.x*END_OF_LEVEL.y; i++){
            level[i].update();
        }
        for(int i = 0; i < END_OF_LEVEL.x*END_OF_LEVEL.y; i++){
            level[i].swapEntities();
        }
  
    }


    cout << endl;
    placeInLevel.reset();
    for(int i = 0; i < END_OF_LEVEL.y; i++){
        for(int j = 0; j < END_OF_LEVEL.x; j++){
            cout << level[placeInLevel.x + END_OF_LEVEL.x*placeInLevel.y].getChar();
            placeInLevel.x++;
        }
        placeInLevel.x = 0;
        placeInLevel.y++;
        cout << endl;
    }

    for(int i = 0; i < END_OF_LEVEL.x*END_OF_LEVEL.y; i++){
        level[i].printPosition();
    }

    
    return 0;
}
