#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Button {
    int button_left_x;
    int button_left_y;
    int button_width;
    int button_height;
    sf::Text button_text;
    sf::Font text_font;
    sf::RectangleShape button_shape;
public:
    Button() = default;
    void setButtonSize(sf::Vector2f size);
    void setButtonPosition(sf::Vector2f pos);
    void setButtonColor(sf::Color color);
    void setButtonText(std::string text);
    void setButtonTextSize(int font_size);
    void setButtonTextFont(sf::Font font);
    void setButtonTextColor(sf::Color color);
    bool isMouseInside(sf::Vector2i mouse_pos);
    void drawButton(sf::RenderWindow& window);
};