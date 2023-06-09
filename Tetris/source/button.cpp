#include "../header/button.hpp"

void Button::setButtonPosition(sf::Vector2f pos) {
		button_shape.setPosition(pos);
        button_left_x = button_shape.getPosition().x;
        button_left_y = button_shape.getPosition().y;
        float text_x = (button_left_x + button_width / 2) - (button_text.getGlobalBounds().width / 2);
        float text_y = (button_left_y + button_height / 2.5) - (button_text.getGlobalBounds().height / 2);
        button_text.setPosition(sf::Vector2f(text_x, text_y));
}

bool Button::isMouseInside(sf::Vector2i mouse_pos) {
	if ((mouse_pos.x > button_left_x && mouse_pos.x < button_left_x + button_width) && (mouse_pos.y > button_left_y && mouse_pos.y < button_left_y + button_height)) {
        return true;
	}
	return false;
}

void Button::setButtonSize(sf::Vector2f size) {
    button_width = (int)size.x; button_height = (int)size.y;
    button_shape.setSize(size);
    button_left_x = button_shape.getPosition().x;
    button_left_y = button_shape.getPosition().y;
    float text_x = (button_left_x + button_width / 2) - (button_text.getGlobalBounds().width / 2);
    float text_y = (button_left_y + button_height / 2.5) - (button_text.getGlobalBounds().height / 2);
    button_text.setPosition(sf::Vector2f(text_x, text_y));
}

void Button::setButtonColor(sf::Color color) {
    button_shape.setFillColor(color);
}

void Button::setButtonText(std::string text) {
    button_text.setString(text);
}

void Button::setButtonTextSize(int font_size) {
    button_text.setCharacterSize(font_size);
}
void Button::setButtonTextFont(sf::Font font) {
    text_font = font;
    button_text.setFont(text_font);
}

void Button::setButtonTextColor(sf::Color color) {
    button_text.setFillColor(color);
}

void Button::drawButton(sf::RenderWindow& window) {
    window.draw(button_shape);
    window.draw(button_text);
}