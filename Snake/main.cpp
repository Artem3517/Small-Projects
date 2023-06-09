#include <iostream>
#include <ncurses.h>
#include <ctime>
#include "field.hpp"
#include "snake.hpp"

void screensetup() {
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    srand(time(0));
}

int main() {
    int rows = 15;
    int cols = 35;
    Field Field(rows, cols);
    Snake Snake;
    int frow = rows / 2;
    int fcol = cols / 2;
    screensetup();
    bool game = true;
    int score = 0;
    int dir = 0;
    char key = 0;
    int lastrow = 0;
    int lastcol = 0;
    int headrow = 0;
    int headcol = 0;
    while (game) {
        for (int i = 0; i < Snake.getlen(); i++) {
           Field.setval(Snake.getx(i), Snake.gety(i), 2);
        }
        Field.setval(frow, fcol, 3);
        Field.output();
        key = getch();
        Snake.input(key);
        Snake.move(lastrow, lastcol);
        Field.setval(lastrow, lastcol, 0);
        headrow = Snake.get_headrow();
        headcol = Snake.get_headcol();
        switch (Field.check(headrow, headcol)) {
            case 1:
                game = false;
                break;
            case 2:
                Snake.addlen();
                frow = rand() % (rows - 2) + 1;
                fcol = rand() % (cols - 2) + 1;
                Field.setval(frow, fcol, 3);
                score += 10;
                break;
            default:
                break;
        }
        printw("Score: %d\n", score);
        wrefresh(stdscr);
        napms(150);
    }
    napms(2000);
    endwin();
    return 0;
}
