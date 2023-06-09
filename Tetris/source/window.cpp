#include "../header/window.hpp"
#include <iostream>

Window::Window(const int w, const int h) {
    window_width = w; window_height = h;
    isMenuActive = true; isGameActive = false;
    window.create(sf::VideoMode(window_width, window_height), "TeTris", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);
    text_font.loadFromFile("../include/Courier-New.ttf");
    menu.setMenuButtons(text_font);
}

void Window::drawMenu() {
    while (isMenuActive && window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                isGameActive = isMenuActive = false;
                window.close();
            } 
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
            //exit button
            if (menu.exit_button.isMouseInside(mouse_pos)) {
                menu.exit_button.setButtonTextColor(sf::Color::Green);
                if (event.type == sf::Event::MouseButtonPressed) {
                    isMenuActive = false;
                    isGameActive = false;
                    window.close();
                }
            }
            if (!menu.exit_button.isMouseInside(mouse_pos)) { 
                menu.exit_button.setButtonTextColor(sf::Color::White);
            }
            //game button
            if (menu.game_button.isMouseInside(mouse_pos)) {
                menu.game_button.setButtonTextColor(sf::Color::Green);
                if (event.type == sf::Event::MouseButtonPressed) {
                    isMenuActive = false;
                    isGameActive = true;
                }
            }
            if (!menu.game_button.isMouseInside(mouse_pos)) { 
                menu.game_button.setButtonTextColor(sf::Color::White);
            }
        }
        window.clear(sf::Color::Black);
        menu.drawMenu(window);
        window.display();
    }
}

void Window::drawGame() {
    while (isGameActive && window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                isGameActive = false;
                isMenuActive = false;
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        game.drawGame(window);
        window.display();
    }
}

void Window::drawWindow() {
    while (isGameActive || isMenuActive) {
        if (isMenuActive) drawMenu();
        if (isGameActive) drawGame();
    }
}