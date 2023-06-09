#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <string.h>
#define SQUARE(X) ((X)*(X))						// macros

static int t;									// t = 0

struct List { 									// typedef struct List { ... } User
	int id; 				
	char* name;
	struct List *ptr;
};
typedef struct List User;

enum {MON = 1, TUE, WED, THU, FRI, SAT, SUN};

void output(int day, char* string);				// in any function array must be put by its address
#endif // TEST_H
