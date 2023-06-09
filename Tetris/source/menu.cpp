#include "../header/menu.hpp"
#include <iostream>

Menu::Menu() {
    //background
    background.loadFromFile("../include/menu.png");
    screen.setTexture(background);
    screen.setPosition(0, 0);
}

void Menu::setMenuButtons(sf::Font text_font) {
    //game button
    game_button.setButtonText("New game");
    game_button.setButtonTextFont(text_font);
    game_button.setButtonTextSize(40);
    game_button.setButtonTextColor(sf::Color::White);
    game_button.setButtonPosition(sf::Vector2f(150, 180));
    game_button.setButtonSize(sf::Vector2f(200, 60));
    game_button.setButtonColor(sf::Color::Black);
    //exit button
    exit_button.setButtonText("Exit game");
    exit_button.setButtonTextFont(text_font);
    exit_button.setButtonTextSize(40);
    exit_button.setButtonTextColor(sf::Color::White);
    exit_button.setButtonSize(sf::Vector2f(200, 60));
    exit_button.setButtonPosition(sf::Vector2f(150, 280));
    exit_button.setButtonColor(sf::Color::Black);
}

void Menu::drawMenu(sf::RenderWindow& window) {
    window.draw(screen);
    game_button.drawButton(window);
    exit_button.drawButton(window);
}