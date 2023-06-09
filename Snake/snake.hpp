#ifndef SNAKE_H
#define SNAKE_H

enum direction {UP = 0, DOWN, RIGHT, LEFT};

class Snake {
    int len = 1;
    int headrow = 1;
    int headcol = 1;
    int* x;
    int* y;
    direction dir = RIGHT;
public:
    Snake();
    int getlen() {return len;};
    int get_headrow() {return headrow;};
    int get_headcol() {return headcol;};
    int getx(int i) {return x[i];};
    int gety(int i) {return y[i];};
    int getdir() {return dir;};
    void input(char key);
    void addlen();
    void move(int& lastrow, int& lastcol);
};

#endif // SNAKE_H