#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
using namespace sf;

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "Bubble.h"

int main() {
    srand(time(0));
    rand();
    
    // create a window
    RenderWindow window( VideoMode(640, 640), "A4" );
    
    vector<Bubble*> bubbles;
    for(int i = 0; i < 5; i++){
        Bubble* myBubble = new Bubble();
        bubbles.push_back(myBubble);
    }

    // create an event object once to store future events
    Event event;

    // while the window is open
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear();

        /////////////////////////////////////
        // BEGIN DRAWING HERE

        for(unsigned int i = 0; i < bubbles.size(); i++){
            bubbles.at(i)->updatePosition(640, 640);
            bubbles.at(i)->draw(&window);
        }

        //  END  DRAWING HERE
        /////////////////////////////////////


        // display the current contents of the window
        window.display();

        /////////////////////////////////////
        // BEGIN EVENT HANDLING HERE
        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
            
            
            if (event.type == event.MouseButtonPressed && Mouse::isButtonPressed(Mouse::Left))
            {
                cout << Mouse::getPosition(window).x << " " << Mouse::getPosition(window).y << endl;
                bubbles.push_back(new Bubble(Mouse::getPosition(window).x, Mouse::getPosition(window).y));
            }

            if(event.type == event.KeyPressed && event.key.scancode == sf::Keyboard::Scan::D){
                bubbles.pop_back();
            }
            if(event.type == event.KeyPressed && event.key.scancode == sf::Keyboard::Scan::Q){
                window.close();
            }
            if(event.type == event.KeyPressed && event.key.scancode == sf::Keyboard::Scan::Escape){
                window.close();
            }
        }
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////
    }

    return 0;
}
