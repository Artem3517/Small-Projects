#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Game {
    sf::Texture texture;
    sf::Sprite background;
    int Field[12][10] = {};
public:
    Game();
    void setRandomFigure();
    bool gameProcess();
    void drawGame(sf::RenderWindow& window);
};