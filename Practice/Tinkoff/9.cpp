#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> less;
    std::vector<int> great;
    int num = 0;
    int k = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> num;
        if (num <= 100) {
            less.push_back(num);
        } else {
            great.push_back(num);
            k++;
        }
    }
    if (k < 2) {
        std::sort(less.begin(), less.end());
    } else {
        std::sort(less.begin(), less.end());
        std::sort(great.begin(), great.end());
    }
    int summ = 0;
    if (k / 2 > 0) {
        for (int i = 0; i < n - k; i++) {
            summ += less[i];
        }
        for (int i = 0; i < k; i++) {
            summ += great[i];
        }
    } else {
        if (k % 2 == 0) {
            for (int i = 0; i < k / 2; i++) {
                summ += great[i];
            }
            for (int i = 0; i < n - k; i++) {
                summ += less[i];
            }
        } else {
            for (int i = 0; i < k / 2 + 1; i++) {
                summ += great[i];
            }
            for (int i = 0; i < n - k - 1; i++) {
                summ += less[i];
            }
        }
    }
    std::cout << summ << std::endl;
    return 0;
}