#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    int people[n];
    for (int i = 0; i < n; i++) {
        std::cin >> people[i];
    }
    int gifts[n];
    for (int i = 0; i < n; i++) {
        gifts[i] = 0;
    }
    int change = 0;
    for (int i = 0; i < n; i++) {
        gifts[people[i] - 1]++;
        if (gifts[people[i] - 1] > 1) {
            change++;
        }
    }
    int pos, num;
    pos = num = -1;
    if (change == 1) {
        for(int i = 0; i < n; i++) {
            if (gifts[i] == 0) {
                num = i + 1;
            }
            if (gifts[i] == 2) {
                pos = i + 1;
            }
        }
    }
    std::cout << pos << ' ' << num << std::endl;
    return 0;
}