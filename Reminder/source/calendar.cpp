#include "../header/calendar.hpp"
#include <ctime>
#include <algorithm>
#include <iostream>

Calendar::Calendar() {
    sf::RectangleShape line;
    line.setSize({350, 2});
    line.setFillColor(sf::Color::Black);
    for (int i = 0; i < 8; ++i) {
        line.setPosition(sf::Vector2f(0.f, 50.f * i));
        horizontal_lines[i] = line;
    }
    line.setSize({2, 350});
    line.setPosition({0, 0});
    vertical_lines[0] = line;
    line.setPosition({348, 0});
    vertical_lines[7] = line;
    line.setSize({2, 300});
    for (int i = 1; i < 7; ++i) {
        line.setPosition(sf::Vector2f(50.f * i, 50.f));
        vertical_lines[i] = line;
    }
}

void Calendar::setFont(sf::Font font) {
    text_font = font;
}

void Calendar::setHeader() {
    sf::Text weekday;
    weekday.setFont(text_font);
	weekday.setCharacterSize(20);
	weekday.setFillColor(sf::Color::Black);
    std::string weekday_names[7] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
    for (int i = 0; i < 7; ++i) {
        weekday.setString(weekday_names[i]);
        weekday.setPosition({9 + i * 50.f, 62.f});
        weekdays[i] = weekday;
    }
    tm *ptm = nullptr;
    time_t t = std::time(nullptr);
    ptm = std::localtime(&t);
    month = ptm->tm_mon;
    year = 1900 + ptm->tm_year;
    today = ptm->tm_mday;
    header_string.setFont(text_font);
	header_string.setCharacterSize(20);
	header_string.setFillColor(sf::Color::Black);
    header_string.setString(parse(-1, month, year));
    header_string.setPosition({175 - header_string.getLocalBounds().width / 2, 5 + header_string.getLocalBounds().height / 2});
}

std::string Calendar::parse(int d, int m, int y) {
    std::string str;
    if (d != -1) {
        switch (d) {
            case 1: str.append("01"); break;
            case 2: str.append("02"); break;
            case 3: str.append("03"); break;
            case 4: str.append("04"); break;
            case 5: str.append("05"); break;
            case 6: str.append("06"); break;
            case 7: str.append("07"); break;
            case 8: str.append("08"); break;
            case 9: str.append("09"); break;
            case 10: str.append("10"); break;
            case 11: str.append("11"); break;
            case 12: str.append("12"); break;
            case 13: str.append("13"); break;
            case 14: str.append("14"); break;
            case 15: str.append("15"); break;
            case 16: str.append("16"); break;
            case 17: str.append("17"); break;
            case 18: str.append("18"); break;
            case 19: str.append("19"); break;
            case 20: str.append("20"); break;
            case 21: str.append("21"); break;
            case 22: str.append("22"); break;
            case 23: str.append("23"); break;
            case 24: str.append("24"); break;
            case 25: str.append("25"); break;
            case 26: str.append("26"); break;
            case 27: str.append("27"); break;
            case 28: str.append("28"); break;
            case 29: str.append("29"); break;
            case 30: str.append("30"); break;
            case 31: str.append("31"); break;
        }
    }
    if (m == -1) {
        return str;
    }
    switch (m) {
        case 0: str.append("January"); break;
        case 1: str.append("February"); break;
        case 2: str.append("March"); break;
        case 3: str.append("April"); break;
        case 4: str.append("May"); break;
        case 5: str.append("June"); break;
        case 6: str.append("July"); break;
        case 7: str.append("August"); break;
        case 8: str.append("September"); break;
        case 9: str.append("October"); break;
        case 10: str.append("November"); break;
        case 11: str.append("December"); break;
    }
    if (y == -1) {
        return str;
    }
    str.append("\t");
    std::string year;
    for (int i = 0; i < 4; ++i) {
        char c;
        switch (y % 10) {
            case 0: c = '0'; break;
            case 1: c = '1'; break;
            case 2: c = '2'; break;
            case 3: c = '3'; break;
            case 4: c = '4'; break;
            case 5: c = '5'; break;
            case 6: c = '6'; break;
            case 7: c = '7'; break;
            case 8: c = '8'; break;
            case 9: c = '9'; break;
        }
        year += c;
        y /= 10;
    }
    std::reverse(year.begin(), year.end());
    str += year;
    return str;
}

void Calendar::setDates() {
    if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month ==  11) {
        number_of_days = 31;
    } else if (month == 1) {
        if (year % 4 == 0 || (year % 100 == 0 && year % 400 == 0)) {
            number_of_days = 29;
        } else {
            number_of_days = 28;
        }
    } else {
        number_of_days = 30;
    }
    month_days = new sf::Text[number_of_days];
    std::tm t = { 0, 0, 0, 1, month - 1, year - 1900 };
    std::mktime(&t);
    int first_weekday = t.tm_wday;
    int day = 0;
    for (int col = first_weekday + 1; col < 7; ++col) {
            month_days[day].setString(parse(day + 1, -1, -1));
            month_days[day].setFont(text_font);
            month_days[day].setCharacterSize(20);
            month_days[day].setFillColor(sf::Color::Black);
            month_days[day].setPosition({15.f + 50 * col, 115.f});
            day++;
    }
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 7; ++col) {
            if (day == number_of_days) {
                break;
            }
            month_days[day].setString(parse(day + 1, -1, -1));
            month_days[day].setFont(text_font);
            month_days[day].setCharacterSize(20);
            month_days[day].setFillColor(sf::Color::Black);
            month_days[day].setPosition({15.f + 50 * col, 165.f + 50 * row});
            day++;
        }
    }
    month_days[today-1].setFillColor(sf::Color::Red);
}

void Calendar::drawCalendar(sf::RenderWindow& window) {
    for (auto line : horizontal_lines) {
        window.draw(line);
    }
    for (auto line : vertical_lines) {
        window.draw(line);
    }
    for (auto day : weekdays) {
        window.draw(day);
    }
    window.draw(header_string);
    for (int i = 0; i < number_of_days; ++i) {
        window.draw(month_days[i]);
    }
}

Calendar::~Calendar() {
    delete[] month_days;
}