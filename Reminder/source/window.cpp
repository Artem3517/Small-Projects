#include "../header/window.hpp"

#include <iostream>

Window::Window(int w, int h) {
    window_width = w; window_height = h;
    window.create(sf::VideoMode(window_width, window_height), "Reminder", sf::Style::Close | sf::Style::Titlebar);
    text_font.loadFromFile("../include/arialmt.ttf");
}

void Window::setup() {
    createButtons();
    createCalendar();
}

void Window::createButtons() {
    std::string button_names[4] = { "CREATE", "EDIT", "MARK", "DELETE" };
    sf::Vector2f button_size = sf::Vector2f(175, 75);
    sf::Color button_colors[4] = { sf::Color::Green, sf::Color::Blue, sf::Color::Yellow, sf::Color::Red };
    int j = 0;
    for (int i = 0; i < 4; i++) {
        buttons[i].setButtonSize(button_size);
        buttons[i].setButtonColor(button_colors[i]);
        buttons[i].setButtonText(button_names[i]);
        buttons[i].setButtonTextStyle(sf::Color::Black, 30, text_font);
        buttons[i].setPosition({175.f * (i % 2), 352.f + 75 * j});
        if (i == 1) j++;
    }
}

void Window::createCalendar() {
    calendar.setFont(text_font);
    calendar.setHeader();
    calendar.setDates();
}

void Window::createNotes(sf::Event event) {

}

void Window::draw() {
    notes.setPosition({350, 0});
    notes.setFont(text_font);
    //notes.uploadNote();
    std::string text;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }






            
            //if (sf::Mouse::getPosition().x > 350 && sf::Mouse::getPosition().x < 800) {
                //std::cout << 1;
                    //if (event.type == sf::Event::MouseButtonPressed) {
                        //if (event.mouseButton.button == sf::Mouse::Left) {
                        if (event.type == sf::Event::TextEntered) {
                            if (event.text.unicode == 8) {
                                text.pop_back();
                                notes.createNote(text);
                            }
                            if (event.text.unicode == 27) {
                                std::cout << 6;

                                break;
                            }
                            if (event.text.unicode < 127 && event.text.unicode > 31) {
                                text += static_cast<char>(event.text.unicode);
                                notes.createNote(text);
                            } else {
                                break;
                            }
                        }
                        //}
                    //}
                //}





            /*if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == 8) {
                    text.pop_back();
                    notes.createNote(text);
                }
                if (event.text.unicode == 27) {
                    std::cout << 6;

                    break;
                }
                if (event.text.unicode < 127 && event.text.unicode > 31) {
                    text += static_cast<char>(event.text.unicode);
                    notes.createNote(text);
                } else {
                    break;
                }
            }*/



        }
        window.clear(sf::Color::White);
        calendar.drawCalendar(window);
        for (int i = 0; i < 4; i++) {
            buttons[i].drawButton(window);
        }
        notes.drawNote(window);
        window.display();
    }
}