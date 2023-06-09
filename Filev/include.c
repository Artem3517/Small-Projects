#include "include.h"
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

void screensetup() {
    initscr();
    cbreak();
    noecho();
    //nodelay(stdscr, TRUE);
    //keypad(stdscr, TRUE);
}

void gotoline(FILE* fp) {
    char c = 0;
    while (c != '\n') {
        fscanf(fp, "%c", &c);
    }
}

int gettype(FILE* fp) {
    char c = 0;
    fscanf(fp, "%c", &c);
    if (c == 'd') {
        return DIR;
    } else if (c == '-') {
        while (c != ' ') {
           fscanf(fp, "%c", &c); 
        }
        fseek(fp, -2, SEEK_CUR);
        fscanf(fp, "%c", &c);
        if (c == 'x') {
            return EXE;
        } else {
            return FIL;
        }
    } else {
        return NOT;
    }
}

Object* new_object(int _type, int _len, char* buf, Object* PrevObj) {
    Object* NewObj = (Object*)malloc(sizeof(Object));
    if (PrevObj != NULL) {
        PrevObj->next = NewObj;
    }
    NewObj->type = _type;
    NewObj->len = _len;
    NewObj->name = (char*)malloc(sizeof(char) * _len + 1);
    for (int i = 0; i < _len; i++) {
        NewObj->name[i] = buf[i];
    }
    NewObj->next = NULL;
    return NewObj;
}

int getname(FILE* fp, char* buf) {
    char c = 0;
    while (c != '\n') {
        fscanf(fp, "%c", &c);
    }
    while (c != ' ') {
        fseek(fp, -2, SEEK_CUR);
        fscanf(fp, "%c", &c);
    }
    int i = 0;
    while (c != '\n') {
        fscanf(fp, "%c", &c);
        buf[i] = c;
        i++;
    }
    return i;
}

void output(Object* Obj) {
    start_color();
    init_pair(DIR, COLOR_YELLOW, COLOR_BLACK);
    init_pair(FIL, COLOR_WHITE, COLOR_BLACK);
    init_pair(EXE, COLOR_GREEN, COLOR_BLACK);
    while (Obj != NULL) {
        switch (Obj->type) {
            case DIR: 
                attron(COLOR_PAIR(DIR));
                break;
            case FIL: 
                attron(COLOR_PAIR(FIL));
                break;
            case EXE: 
                attron(COLOR_PAIR(EXE));
                break;
            default:
                break;
        };
        for (int i = 0; i < Obj->len; i++) {
            printw("%c", Obj->name[i]);
        }
        wattroff(stdscr, COLOR_PAIR(Obj->type));
        Obj = Obj->next;
    }
    printw("> ");
    wrefresh(stdscr);
}

void delete(Object* First) {
    return;
}