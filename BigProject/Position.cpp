#include "Position.h"

Position::Position(int newX, int newY){
    x = newX;
    y = newY;
}

Position::Position(){
    x = 0;
    y = 0;
}

void Position::reset(){
    x = 0;
    y = 0;
}

Position& Position::operator+(Position& other){
    return *(new Position(this->x + other.x, this->y + other.y));
}

Position Position::copy(){
    return *(new Position(x, y));
}