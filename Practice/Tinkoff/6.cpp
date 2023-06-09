#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    int* students = new int[n];
    int odd = 0;
    int even = 0;
    int num = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> num;
        if (num % 2 == 0) {
            students[i] = 0;
            even++;
        } else {
            students[i] = 1;
            odd++;
        }
    }
    int pos1, pos2, wrong_odd, wrong_even;
    wrong_odd = wrong_even = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1 && students[i] == 1) {
            wrong_odd++;
            pos1 = i + 1; 
        }
        if (i % 2 == 0 && students[i] == 0) {
            wrong_even++;
            pos2 = i + 1;
        }
    }
    if (n % 2 == 0 && (odd != even || wrong_odd != 1 || wrong_even != 1)) {
            pos1 = pos2 = -1;
    } else if (n % 2 == 1 && (abs(odd - even) > 1 || wrong_odd != 1 || wrong_even != 1)) {
        pos1 = pos2 = -1;
    }
    if (pos1 > pos2) {
        std::swap(pos2, pos1);
    }
    std::cout << pos1 << ' ' << pos2 << std::endl;
    delete[] students;
    return 0;
}