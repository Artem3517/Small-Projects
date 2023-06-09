#include "../header/menu.hpp"
#include <iostream>

Menu::Menu() {
    background.loadFromFile("../include/menu.png");
    screen.setTexture(background);
    screen.setPosition(0, 0);
    game_button.setButtonColor(sf::Color::White);
    game_button.setButtonSize(sf::Vector2f(300, 100));
    game_button.setButtonText("New game");
    game_button.setPosition(sf::Vector2f(100, 180));
    exit_button.setButtonColor(sf::Color::White);
    exit_button.setButtonSize(sf::Vector2f(300, 100));
    exit_button.setButtonText("Exit game");
    exit_button.setPosition(sf::Vector2f(100, 300));
}

void Menu::setMenuFont(sf::Font text_font) {
    game_button.setButtonTextStyle(sf::Color::Black, 40, text_font);
    exit_button.setButtonTextStyle(sf::Color::Black, 40, text_font);
}

/*int Menu::checkButtons(sf::Vector2i mouse_pos) {
    if (exit_button.isMouseInside(mouse_pos.x, mouse_pos.y)) {
        return 2;
    } else if (game_button.isMouseInside(mouse_pos.x, mouse_pos.y)) {
        return 1;
    } else {
        return 0;
    }
}*/

void Menu::drawMenu(sf::RenderWindow& window) {
    window.draw(screen);
    game_button.drawButton(window);
    exit_button.drawButton(window);
}