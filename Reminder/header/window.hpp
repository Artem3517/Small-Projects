#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <vector>
#include <list>

#include "../header/button.hpp"
#include "../header/calendar.hpp"
#include "../header/note.hpp"

class Window {
    int window_width;
    int window_height;
    sf::Font text_font;
    sf::RenderWindow window;
    Button buttons[4];
    Calendar calendar;
    Note notes;
public:
    Window(int w, int h);
    void setup();
    void createButtons();
    void createCalendar();
    void createNotes(sf::Event event);
    void draw();
};