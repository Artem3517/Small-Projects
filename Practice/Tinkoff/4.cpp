
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void max_position(int num, int* pos, int* dif) {
    int temp = num;
    int digits = 0;
    while (temp > 0) {
        temp /= 10;
        digits++;
    }
    while (num / (int)std::pow(10, digits-1) == 9 && digits > 1) {
        num -= 9 * (int)std::pow(10, digits-1);
        digits--;
    }
    *pos = digits;
    *dif = 9 - (num / (int)std::pow(10, digits-1));
}

int replace(int num, int pos) {
    return (num / (int)std::pow(10, pos)) * (int)std::pow(10, pos) + 9 * (int)std::pow(10, pos-1) + num % (int)std::pow(10, pos-1);
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }
    std::sort(numbers.rbegin(), numbers.rend());
    int pos, dif, maxi, maxpos, maxdif;
    int sum = 0;
    for (int i = 0; i < k; i++) {
        maxi = maxpos = maxdif = 0;
        for (int j = 0; j < n; j++) {
            pos = dif = 0;
            max_position(numbers[j], &pos, &dif);
            if (pos > maxpos) {
                maxi = j;
                maxpos = pos;
                maxdif = dif;
            } else if (pos == maxpos && dif > maxdif) {
                maxi = j;
                maxdif = dif;
            }
        }
        numbers[maxi] = replace(numbers[maxi], maxpos);
        sum += maxdif * (int)std::pow(10, maxpos-1);
    }
    std::cout << sum << std::endl;
    return 0;
}