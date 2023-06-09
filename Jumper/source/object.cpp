#include "../header/object.hpp"
#include <iostream>

void Object::setTexture(sf::Texture t) {
    texture = t;
    object.setTexture(texture);
}

void Object::setObjectPosition(sf::Vector2f pos) {
    object.setPosition(pos.x, pos.y);
}

sf::Vector2f Object::getObjectPosition() {
    return object.getPosition();
}

void Object::drawObject(sf::RenderWindow& window) {
    window.draw(object);
}