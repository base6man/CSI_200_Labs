#include "mazeTile.h"
#include <SFML\Graphics.hpp>

MazeTile::MazeTile(){
    myColor = sf::Color::Magenta;
    setupShape();
}

MazeTile::MazeTile(sf::Color newColor){
    myColor = newColor;
    setupShape();
}

MazeTile::MazeTile(char colorChar){
    switch(colorChar){
        case '#': 
            myColor = sf::Color::Black;
            break;
        case '.':
            myColor = sf::Color::White;
            break;
        case 'S':
            myColor = sf::Color::Green;
            break;
        case 'E':
            myColor = sf::Color::Red;
            break;
        default:
            myColor = sf::Color::Magenta;
    }
    setupShape();
}

void MazeTile::setupShape(){
    myShape.setSize( sf::Vector2f(SIZE, SIZE) );
    myShape.setFillColor(myColor);
}

void MazeTile::draw(sf::RenderWindow* window, int x, int y){
    myShape.setPosition(SIZE*x, SIZE*y);
    (*window).draw( myShape );
}

std::string MazeTile::print(){
    if(myColor == sf::Color::Black){
        return "black";
    }
    if(myColor == sf::Color::White){
        return "white";
    }
    return "other";
}