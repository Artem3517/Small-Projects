#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Figure {
public:
    sf::RectangleShape cubes[4];
    Figure() = default;
    virtual void setPositionOne(int row, int col);
    virtual void setPositionTwo(int row, int col);
    virtual void setPositionThree(int row, int col);
    virtual void setPositionFour(int row, int col);
    void setColor(sf::Color color);
    void drawFigure(sf::RenderWindow& window);
};