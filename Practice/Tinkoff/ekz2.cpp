#include <iostream>

int nod(int a, int b) {
    if (a < b) {
        std::swap(a, b);
    }

    while (b) {
        a %= b;
        std::swap(a, b);
    }

    return a;
}

int nok(int a, int b) {
    return a / nod(a, b) * b;
}

int main() {
    int number = 0;
    std::cin >> number;
    if (number % 2 == 0) {
        int term = number / 2;
        std::cout << term << ' ' << term << std::endl;
        return 0;
    }
    const int maxfirstterm = number / 2;
    int term1 = 1;
    int NOKs[maxfirstterm];
    while (term1 <= maxfirstterm) {
        NOKs[term1-1] = nok(term1, number - term1);
        term1++;
    }
    int minindex = 0;
    int minnok = number;
    for (int i = 0; i < maxfirstterm; ++i) {
        if (NOKs[i] < minnok) {
            minnok = NOKs[i];
            minindex = i;
        }
    }
    std::cout << 1 + minindex << ' ' << number - minindex - 1 << std::endl;
    return 0;
}