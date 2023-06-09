#ifndef INCLUDE_H
#define INCLUDE_H
#include <stdio.h>

enum objecttype {NOT = 0, DIR, FIL, EXE};

struct Object{
    int type;
    int len;
    char* name;
    struct Object* next;
};
typedef struct Object Object;

void screensetup();
int gettype(FILE* fp);
int getname(FILE* fp, char* buf);
Object* new_object(int _type, int _len, char* buf, Object* PrevObj);
void gotoline(FILE* fp);
void output(Object* First);
void delete(Object* First);

#endif // INCLUDE_H