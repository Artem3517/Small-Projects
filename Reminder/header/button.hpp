#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Button {
    sf::Font text_font;
    int button_left_x;
    int button_left_y;
    int button_width;
    int button_height;
    sf::Text button_text;
    sf::RectangleShape button_shape;
public:
    Button() = default;
    //Button(sf::Vector2f size, std::string text, sf::Color fillcolor, sf::Color textcolor, sf::Font font);
    void setButtonSize(sf::Vector2f size);
    void setPosition(sf::Vector2f pos);
    void setButtonColor(sf::Color color);
    void setButtonText(std::string text);
    void setButtonTextStyle(sf::Color color, int font_size, sf::Font font);
    bool isMouseInside(int mouse_x, int mouse_y);
    void drawButton(sf::RenderWindow& window);
};