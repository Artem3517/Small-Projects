#include "../header/window.hpp"
#include <iostream>

Window::Window(const int w, const int h) {
    window_width = w; window_height = h;
    //isMenuActive = true; isGameActive = false;
    isGameActive = true;
    window.create(sf::VideoMode(window_width, window_height), "TeTris", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);
    text_font.loadFromFile("../../Reminder/include/arialmt.ttf");
    menu.setMenuFont(text_font);
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
            if (menu.exit_button.isMouseInside(mouse_pos)) {
                menu.exit_button.setButtonColor(sf::Color::Blue);
                if (event.type == sf::Event::MouseButtonPressed) {
                    isMenuActive = false;
                    window.close();
                }
            }
            mouse_pos = sf::Mouse::getPosition(window);
            if (!menu.exit_button.isMouseInside(mouse_pos)) { 
                menu.exit_button.setButtonColor(sf::Color::White);
            
            }


            /*if (menu.checkButtons(mouse_pos) == 1) {
                isMenuActive = false;
                isGameActive = true;
            }*/
            
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
                isGameActive = isMenuActive = false;
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left) {
                    game.moveSide(-10);
                } else if (event.key.code == sf::Keyboard::Right) {
                    game.moveSide(10);
                }
            }
        }
        window.clear(sf::Color::White);
        if (game.gameProcess()) {
            game.drawGame(window);
            window.display();
        }// else {
            //isGameActive = false;
            //isMenuActive = true;
        //}
    }
}

void Window::drawWindow() {
    while (isGameActive || isMenuActive) {
        if (isMenuActive) {
            drawMenu();
        }
        if (isGameActive) {
            drawGame();
        }
    }
}