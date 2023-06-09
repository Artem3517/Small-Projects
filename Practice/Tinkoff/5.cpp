#include <iostream>
#include <cmath>

int get_digits(int num) {
    int n = 0;
    while (num > 0) {
        num /= 10;
        n += 1;
    }
    return n;
}

int main() {
    unsigned l, r;
    std::cin >> l >> r;
    unsigned step = 0;
    int digits = get_digits(l);
    for (int i = 0; i < digits; i++) {
        step += (int)std::pow(10, i);
    }
    int first = step;
    while (first < l) {
        first += step;
    }
    int count = 0;
    while (first <= r) {
        count++;
        first += step;
        if (first - 9 * step == 0) {
            step += (int)std::pow(10, digits);
            first = 0;
            digits++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}