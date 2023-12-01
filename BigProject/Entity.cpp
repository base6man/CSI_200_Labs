#include "Entity.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <cassert>
using namespace std;

Entity::Entity(char newChar, Position newPosition, Entity listOfEntities[], Position newLevelEnd){
    myChar = newChar;
    position = newPosition;
    level = listOfEntities;
    endOfLevel = newLevelEnd;

    if(myChar == 'P' || myChar == 'Q' || myChar == 'R' || myChar == 'S' || myChar == 'T'){
        placesToGo[0] = *(new Position(0, 1));
        placesToGo[1] = *(new Position(-1, 1));
        placesToGo[2] = *(new Position(1, 1));
    }
    if(myChar == '~' || myChar == 'W' || myChar == 'X' || myChar == 'Y' || myChar == 'Z' || myChar == 'V'){
        placesToGo[0] = *(new Position(0, 1));
        placesToGo[1] = *(new Position(-1, 1));
        placesToGo[2] = *(new Position(1, 1));
        placesToGo[3] = *(new Position(1, 0));
        placesToGo[4] = *(new Position(-1, 0));
    }
}

Entity::Entity(){
    position = *(new Position());
    myChar = '-';
}

void Entity::update(){
    
    if(mirrorXMovement && (double)rand() / RAND_MAX > 0.5) {
        for(int i = 0; i < 8; i++){
            placesToGo[i].x = -placesToGo[i].x;
        }
    }
    if(mirrorYMovement && (double)rand() / RAND_MAX > 0.5) {
        for(auto i: placesToGo){
            i.y = -i.y;
        }
    }


    hasSwapped = false;
    oldPosition = position;
    for(auto i: placesToGo){
        if(level[positionToIndex(position + i)].displacementPriority() > this->displacementPriority() && isInLevel(position + i) && (i.x != 0 || i.y != 0)){
            this->position = this->position + i;
            break;
        }
    }
}

void Entity::swapEntities(){
    if(position.x == oldPosition.x && position.y == oldPosition.y){
        return;
    }
    if(hasSwapped){
        return;
    }
    if(level[positionToIndex(position)].displacementPriority() <= this->displacementPriority()){
        //cout << myChar << "    " << oldPosition.x  << " "  << oldPosition.y  << "    "  << position.x  << " "  << position.y  << "    " << (position.x == oldPosition.x && position.y == oldPosition.y) << "    " << hasSwapped << endl;
        position = oldPosition;
        return;
    }
    //cout << this->getChar();

    char yoTempChar = level[positionToIndex(position)].getChar();
    char myTempChar = this->getChar();

    Entity myNewEntity = *(new Entity(myTempChar, position, level, endOfLevel));
    Entity otherNewEntity = *(new Entity(yoTempChar, oldPosition, level, endOfLevel));

    myNewEntity.markAsSwapped();
    otherNewEntity.markAsSwapped();
    //cout << newIndex << endl;

    //cout << oldPosition.x  << " "  << oldPosition.y  << "    "  << position.x  << " "  << position.y  << "    " << endl;
    // position is set to oldPosition and oldPosition is set to default

 
    //cout << this->getChar() << myTempChar;
    level[positionToIndex(position)] = myNewEntity;
    level[positionToIndex(oldPosition)] = otherNewEntity;  // oldPosition and position both change values here
    
    //cout << oldPosition.x  << " "  << oldPosition.y  << "    "  << position.x  << " "  << position.y  << "    " << endl;
    //cout << this->getChar() << level[positionToIndex(position)].getChar() << level[positionToIndex(oldPosition)].getChar() << endl;
    
    //cout << endl;
    //assert(level[positionToIndex(position)].getChar() == this->getChar());
}

bool Entity::isInLevel(Position pos){
    return (int)pos.x >= 0 && (int)pos.y >= 0 && pos.x < endOfLevel.x && pos.y < endOfLevel.y;
}

int Entity::positionToIndex(Position myPosition){
    return myPosition.x + endOfLevel.x*myPosition.y;
}

Position Entity::indexToPosition(int myIndex){
    return *(new Position(myIndex % endOfLevel.x, myIndex / endOfLevel.x));
}

void Entity::printPosition() const{
    cout << position.x << " " << position.y << "    ";
}

int Entity::displacementPriority() const{
    if(myChar == '~' || myChar == 'W' || myChar == 'X' || myChar == 'Y' || myChar == 'Z' || myChar == 'V') return 1;
    if(myChar == '-') return 9;
    return 0;
}

char Entity::getChar() const{
    return myChar;
}

void Entity::markAsSwapped(){
    hasSwapped = true;
}