#include "../header/figure.hpp"

void Figure::setColor(sf::Color color) {
    for (size_t i = 0; i < 4; ++i) {
        cubes[i].setFillColor(color);
    }
}

void Figure::drawFigure(sf::RenderWindow& window) {
    for (size_t i = 0; i < 4; ++i) {
        window.draw(cubes[i]);
    }
}