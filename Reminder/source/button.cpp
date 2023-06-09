#include "../header/button.hpp"
#include <iostream>


/*Button::Button(sf::Vector2f size, std::string text, sf::Color fillcolor, sf::Color textcolor, sf::Font font) {
    button_width = (int)size.x; button_height = (int)size.y; text_font = font;
    button_shape.setSize(size);
    button_shape.setFillColor(fillcolor);
    button_text.setFont(text_font);
    button_text.setString(text);
	button_text.setCharacterSize(20);
	button_text.setFillColor(textcolor);
}*/

void Button::setPosition(sf::Vector2f pos) {
		button_shape.setPosition(pos);
        button_left_x = pos.x; button_left_y = pos.y;
		float text_x = (button_left_x + button_width / 2) - (button_text.getLocalBounds().width / 2);
		float text_y = (button_left_y + button_height / 2.5) - (button_text.getLocalBounds().height / 2);
		button_text.setPosition({text_x, text_y});
}

bool Button::isMouseInside(int mouse_x, int mouse_y) {
		if ((mouse_x > button_left_x && mouse_x < button_left_x + button_width) && (mouse_y > button_left_y && mouse_y < button_left_y + button_height)) {
			return true;
		}
		return false;
}

void Button::setButtonSize(sf::Vector2f size) {
    button_width = (int)size.x; button_height = (int)size.y;
    button_shape.setSize(size);
}

void Button::setButtonColor(sf::Color color) {
    button_shape.setFillColor(color);
}

void Button::setButtonText(std::string text) {
    button_text.setString(text);
}

void Button::setButtonTextStyle(sf::Color color, int font_size, sf::Font font) {
    text_font = font;
    button_text.setFillColor(color);
    button_text.setCharacterSize(font_size);
    button_text.setFont(text_font);
}

void Button::drawButton(sf::RenderWindow& window) {
    window.draw(button_shape);
    window.draw(button_text);
}