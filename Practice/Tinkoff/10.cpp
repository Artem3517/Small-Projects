#include <iostream>

int main() {
    int n;
    std::cin >> n;
    float min_x = 1000;
    float max_x = -1000;
    float x, y;
    for (int i = 0; i < n; i++) {
        std::cin >> x >> y;
        if (x < min_x) {
            min_x = x;
        }
        if (x > max_x) {
            max_x = x;
        }
    }
    std::cout << (max_x - min_x) / 2 << std::endl;
    return 0;
}