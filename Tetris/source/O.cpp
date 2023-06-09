#include "../header/O.hpp" 

void O::setPositionOne(int row, int col) {
    cubes[0].setPosition(sf::Vector2f(col * 50, row * 50));
    cubes[1].setPosition(sf::Vector2f((col + 1) * 50, row * 50));
    cubes[2].setPosition(sf::Vector2f(col * 50, (row + 1) * 50));
    cubes[3].setPosition(sf::Vector2f((col + 1) * 50, (row + 1) * 50));
}