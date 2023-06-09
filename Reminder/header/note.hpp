#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <fstream>

class Note {
    int number;
    sf::RectangleShape note;
    //sf::RectangleShape date;
    sf::Font text_font;
    sf::Text date_text;
    sf::Text note_text;
    std::ifstream input_file;
    std::ofstream output_file;
public:
    Note();
    void setFont(sf::Font font);
    void createNote(std::string text);
    void uploadNote();
    void setPosition(sf::Vector2f pos);
    void drawNote(sf::RenderWindow& window);
};