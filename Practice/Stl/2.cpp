#include <iostream>
#include <algorithm>

void func(int x) {
    std::cout << x << ' ';
}

class A {
    int x;
public:
    A() = default;
    A(int _x) : x(_x) {};
    int get() const { return x; };
};

int nums() {
    static int count = 0;
    ++count;
    return count;
}

int main() {
    int arr[5] = { 1, 2, 3, 4, 5 };
    std::for_each (arr, arr + 5, func);
    std::cout << std::endl;
    int obj[3];
    std::generate(obj, obj+3, nums);
    for (auto i : obj) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    if (std::equal(arr, arr + 5, obj)) {
        std::cout << "true" << std::endl;
    }
    return 0;
}