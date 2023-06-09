#include "snake.hpp"
#include <ncurses.h>

Snake::Snake() {
    x = new int[len];
    y = new int[len];
    x[0] = headrow;
    y[0] = headcol;
}

void Snake::addlen() {
    len++;
    int* _x = new int[len];
    int* _y = new int[len];
    for (int i = len - 1; i > 0; i--) {
        _x[i] = x[i-1];
        _y[i] = y[i-1];
    }
    _x[0] = headrow;
    _y[0] = headcol;
    delete [] x;
    delete [] y;
    x = _x;
    y = _y;
}

void Snake::input(char key) {
    if (key == 'w') {
        dir = UP;;
    }
    if (key == 's') {
        dir = DOWN;
    }
    if (key == 'd') {
        dir = RIGHT;
    }
    if (key == 'a') {
        dir = LEFT;
    }
}

void Snake::move(int& lastrow, int& lastcol) {
    switch (dir) {
        case UP:
            headrow--;
            break;
        case DOWN:
            headrow++;
            break;
        case RIGHT:
            headcol++;
            break;
        case LEFT:
            headcol--;
            break;
        default:
            break;
    }
    lastrow = x[len-1];
    lastcol = y[len-1];
    for (int i = len-1; i > 0; i--) {
        x[i] = x[i-1];
        y[i] = y[i-1];
    }
    x[0] = headrow;
    y[0] = headcol;
}