#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "button.hpp"

class Menu {
    sf::Texture background;
    sf::Sprite screen;
public:
    Button game_button;
    Button exit_button;
    Menu();
    void setMenuFont(sf::Font text_font);
    int checkButtons(sf::Vector2i mouse_pos);
    void drawMenu(sf::RenderWindow& window);
};