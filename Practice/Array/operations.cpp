#include "operations.h"
#include <iostream>
#include <ctime>

int* input(int n) {
    srand(time(NULL));
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    return arr;
}

void output(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }
    putchar('\n');
}
