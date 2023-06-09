#include "../header/note.hpp"
#include <iostream>
#include <sstream>

Note::Note() {
    /*date.setOutlineThickness(2.f);
    date.setOutlineColor(sf::Color::Black);
    date.setFillColor(sf::Color::White);
    date.setSize({ 100, 100 });*/
    note.setOutlineThickness(2.f);
    note.setOutlineColor(sf::Color::Black);
    note.setFillColor(sf::Color::White);
    note.setSize({ 450, 100 });
    date_text.setFont(text_font);
    date_text.setCharacterSize(15);
    date_text.setFillColor(sf::Color::Blue);
    note_text.setFont(text_font);
    note_text.setCharacterSize(20);
    note_text.setFillColor(sf::Color::Black);
    input_file.open("../include/data.txt");
    output_file.open("../include/data.txt", std::ios::app);
}

void Note::setPosition(sf::Vector2f pos) {
    //date.setPosition(pos);
    note.setPosition({ pos.x, pos.y });
    note_text.setPosition({ 360, 40 });
    date_text.setPosition({ 360, 10 });
}

void Note::setFont(sf::Font font) {
    text_font  = font;
}

void Note::uploadNote() {
    input_file >> number;
    std::string date, text;
    input_file.seekg(3, std::ios::cur);
    getline(input_file, date, '\n');
    getline(input_file, text, '\n');
    note_text.setString(text);
    date_text.setString(date);
}

void Note::createNote(std::string text) {
    text.append(1, '|');
    note_text.setString(text);
}

void Note::drawNote(sf::RenderWindow& window) {
    //window.draw(date);
    window.draw(note);
    window.draw(date_text);
    window.draw(note_text);
}




/*
if (event.type == sf::Event::TextEntered) {
    if (event.text.unicode < 128) {
        std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
    }
}
*/