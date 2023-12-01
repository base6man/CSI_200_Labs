#include <SFML\Graphics.hpp>
#include <cstdlib>
#include <iostream>

#include "Bubble.h"

Bubble::Bubble(float startX, float startY){
    setPosition(startX - radius, startY - radius);

    float maxSpeed = 0.1667;
    xDir = (float) rand() / RAND_MAX * (2*maxSpeed) - maxSpeed;
    yDir = (float) rand() / RAND_MAX * (2*maxSpeed) - maxSpeed;
    myShape.setRadius(radius);
    setRandomColor();
}

Bubble::Bubble(){
    float startX = (float) rand() / RAND_MAX * (300) + 100;
    float startY = (float) rand() / RAND_MAX * (300) + 100;
    setPosition(startX, startY);

    float maxSpeed = 0.1667;
    xDir = (float) rand() / RAND_MAX * (2*maxSpeed) - maxSpeed;
    yDir = (float) rand() / RAND_MAX * (2*maxSpeed) - maxSpeed;
    myShape.setRadius(radius);
    setRandomColor();
}

void Bubble::setRandomColor(){
    myShape.setFillColor(sf::Color(
        (float) rand() / RAND_MAX * 255, 
        (float) rand() / RAND_MAX * 255, 
        (float) rand() / RAND_MAX * 255));
}

void Bubble::setPosition(float x, float y){
    myShape.setPosition(x, y);
    xPos = x;
    yPos = y;
}

void Bubble::updatePosition(float width, float height){
    setPosition(xPos + xDir, yPos + yDir);

    if(xPos < 0 || xPos > width - 2*radius)  xDir = -xDir;
    if(yPos < 0 || yPos > height - 2*radius) yDir = -yDir;
}

void Bubble::draw(sf::RenderWindow* window){
    (*window).draw(myShape);
}