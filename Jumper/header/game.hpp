#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <vector>

#include "object.hpp"

class Game {
    //sf::Texture texture;
    //sf::Sprite background;
    Object ball;
    std::vector <Object> platforms;
public:
    Game();
    void setRandomPlatform(Object& platform);
    void moveSide(int speed);
    bool gameProcess();
    void drawGame(sf::RenderWindow& window);
};