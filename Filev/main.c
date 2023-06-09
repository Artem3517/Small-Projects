#include "include.h"
#include <stdio.h>
#include <ncurses.h>

int main() {
    screensetup();
    FILE* fp = fopen("output.txt", "r");
    Object* FirstObj = NULL;
    Object* NewObj = NULL;
    Object* PrevObj = NULL;
    char buf[100] = {};
    int type = 0;
    int len = 0;
    int count = 0;
    gotoline(fp);
    while (true) {
        type = gettype(fp);
        if (type == NOT) {
            break;
        }
        len = getname(fp, buf);
        NewObj = new_object(type, len, buf, PrevObj);
        if (count == 0) {
            FirstObj = NewObj;
        }
        if (count == 1) {
            FirstObj->next = NewObj;
        }
        PrevObj = NewObj;
        count++;
    }
    output(FirstObj);
    napms(5000);
    fclose(fp);
    endwin();
    delete(FirstObj);
    return 0;
}