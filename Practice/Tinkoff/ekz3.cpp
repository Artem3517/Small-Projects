#include <iostream>

int main() {
    int count = 0;
    std::cin >> count;
    int numbers[count];
    for (int i = 0; i < count; ++i) {
        std::cin >> numbers[i];
    }
    int Xors[count];
    Xors[0] = 0; 
    if (count > 1) {
        Xors[1] = numbers[0]^numbers[1];
    }
    int maxxor = 0;
    int temp = 0;
    for (int i = 2; i < count; ++i) {
        maxxor = 0;
        for (int j = 0; j < i; ++j) {
            if ((numbers[i]^numbers[j]) > maxxor) {
                maxxor = (numbers[i]^numbers[j]);
            }
        }
        Xors[i] = maxxor;
    }
    for (int i : Xors) {
        std::cout << i << std::endl;
    }
    return 0;
}