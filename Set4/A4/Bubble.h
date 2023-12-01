#include <SFML\Graphics.hpp>

#ifndef BUBBLE_H
#define BUBBLE_H

class Bubble{
    private:
        sf::CircleShape myShape;
        float xDir, yDir;
        float xPos, yPos;
        int radius = 30;
        void setPosition(float x, float y);
        void setRandomColor();
    public:
        Bubble();
        Bubble(float startX, float startY);
        void draw(sf::RenderWindow* window);
        void updatePosition(float width, float height);
};

#endif