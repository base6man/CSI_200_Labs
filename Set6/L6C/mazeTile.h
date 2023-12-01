#include <SFML\Graphics.hpp>

#ifndef MAZE_TILE_H
#define MAZE_TILE_H

class MazeTile{
    private:
        sf::Color myColor;
        sf::RectangleShape myShape;
        const int SIZE = 15;
        void setupShape();
    public:
        MazeTile();
        MazeTile(sf::Color myColor);
        MazeTile(char colorChar);
        void draw(sf::RenderWindow* window, int x, int y);
        std::string print();
};

#endif