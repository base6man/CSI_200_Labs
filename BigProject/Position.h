#ifndef POSITION_H
#define POSITION_H

struct Position{
    int x;
    int y;
    Position();
    Position& operator+(Position& other);
    Position(int newX, int newY);
    void reset();
    Position copy();
};

#endif