#include <ncurses.h>
#include "field.hpp"

Field::Field(int _rows, int _cols) {
    rows = _rows;
    cols = _cols;
    F = new int*[rows];
    for (int i = 0; i < rows; i++) {
        F[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == rows-1 || j == 0 || j == cols-1) {
                F[i][j] = 1;
            } else {
                F[i][j] = 0;
            }
        }
    }
}

void Field::setval(int row, int col, int val) {
    F[row][col] = val;
}

void Field::output() {
    wmove(stdscr, 0, 0);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            switch (F[i][j]) {
                case 0: printw(" ");
                        break;
                case 1: printw("#");
                        break;
                case 2: printw("*");
                        break;
                case 3: printw("o");
                        break;
                default: 
                        break;
            };
        }
        printw("\n");
    }
}

int Field::check(int headrow, int headcol) {
    if (F[headrow][headcol] == 1 || F[headrow][headcol] == 2) {
        return 1;
    } else if (F[headrow][headcol] == 3) {
        return 2;
    } else {
        return 0;
    }
}