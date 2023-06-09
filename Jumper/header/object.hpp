#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Object {
    sf::Sprite object;
    sf::Texture texture;
    int speed_x = 10;
    int speed_y = 10;
public:
    Object() = default;
    void setTexture(sf::Texture t);
    void setObjectPosition(sf::Vector2f pos);
    sf::Vector2f getObjectPosition();
    void drawObject(sf::RenderWindow& window);
};