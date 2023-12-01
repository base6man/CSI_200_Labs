/**
 * @file main.cpp
 * @author Keaton Mitchell
 * @brief Draws a maze from a file
 * @version 0.1
 * @date 2023-10-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "mazeTile.h"

int main() {
    // create a window
    string mazeName;
    cout << "Which maze would you like to draw?" << endl;
    cin >> mazeName;

    fstream inputFile("mazePack/" + mazeName);
    int mazeLength, mazeHeight;
    inputFile >> mazeHeight >> mazeLength;


    //MazeTile *mazeTiles[mazeLength][mazeHeight];
    vector<MazeTile*> mazeTiles;

    int index1 = 0, index2 = 0;
    while(!inputFile.eof()){
        char nextChar;
        inputFile >> nextChar;
        
        MazeTile* newMazeTile = new MazeTile(nextChar);
        mazeTiles.push_back(newMazeTile);

        index1++;
        if(index1 >= mazeLength){
            index1 = 0;
            index2++;
        }
    }

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING

    // perform any file processing once before draw loop begins

    //  END  ANY FILE LOADING
    /////////////////////////////////////

    // create an event object once to store future events
    Event event;
    RenderWindow window( VideoMode(mazeLength * 15, mazeHeight * 15), "SFML Test" );

    // while the window is open
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear();

        /////////////////////////////////////
        // BEGIN DRAWING HERE

        for(int i = 0; i < mazeLength; i++){
            for(int j = 0; j < mazeHeight; j++){
                mazeTiles.at(j*mazeLength+i)->draw(&window, i, j);
            }
        }

        // place any draw commands here to display in the window

        //  END  DRAWING HERE
        /////////////////////////////////////


        // display the current contents of the window
        window.display();

        /////////////////////////////////////
        // BEGIN EVENT HANDLING HERE
        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
            // check addition event types to handle additional events
        }
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////
    }

    return 0;
}
