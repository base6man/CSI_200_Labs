#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "Position.h"

class Entity{
    private:
        Position oldPosition;
        Position position;
        Position placesToGo[8];
        bool mirrorXMovement = true;
        bool mirrorYMovement = false;
        char myChar;
        Entity* level;
        Position endOfLevel;
        bool isInLevel(Position pos);
        int positionToIndex(Position myPosition);
        Position indexToPosition(int myIndex);
        bool hasSwapped = false;
    public:
        Entity();
        Entity(char newChar, Position newPosition, Entity listOfEntities[], Position newLevelEnd);
        void setup();
        char getChar() const;
        void changeChar(char newChar);
        void update();
        void swapEntities();
        void printPosition() const;
        int displacementPriority() const;
        void markAsSwapped();
};

#endif