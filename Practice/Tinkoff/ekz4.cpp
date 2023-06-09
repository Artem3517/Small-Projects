#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int x, y, z;
    std::cin >> x >> y >> z;
    int count = 0;
    int max_a = x + (y * b + z * c) / a;
    int max_b = y + (x * a + z * c) / b;
    int max_c = z + (x * a + y * b) / c;
    for (int i = 0; i < max_a + 1; ++i) {
        for (int j = 0; j < max_b + 1; ++j) {
            for (int k = 0; k < max_c + 1; ++k) {
                if (i * a + j * b + k * c == x * a + y * b + z * c) {
                    count++;
                }
            }
        }
    }
    std::cout << count << std::endl;
    return 0;
}