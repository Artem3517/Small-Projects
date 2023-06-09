#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "menu.hpp"
#include "game.hpp"

class Window {
    bool isMenuActive, isGameActive;
    int window_width;
    int window_height;
    sf::Font text_font;
    sf::RenderWindow window;
    Menu menu;
    Game game;
public:
    Window(const int w, const int h);
    void drawMenu();
    void drawGame();
    void drawWindow();
};