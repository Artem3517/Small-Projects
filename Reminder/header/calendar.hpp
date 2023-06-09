#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Calendar {
    sf::Font text_font;
    int today;
    int month;
    int year;
    int number_of_days;
    sf::Text header_string;
    sf::Text weekdays[7];
    sf::Text* month_days;
    sf::RectangleShape horizontal_lines[8];
    sf::RectangleShape vertical_lines[8];
public:
    Calendar();
    void setFont(sf::Font font);
    void setHeader();
    void setDates();
    std::string parse(int d, int m, int y);
    void drawCalendar(sf::RenderWindow& window);
    ~Calendar();
};