#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    /*std::cout << v.size() << ' ' << v.capacity() << std::endl;
    //std::cout << v[9] << std::endl;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    std::cout << v.size() << ' ' << v.capacity() << std::endl;
    std::cout << v[9] << std::endl;
    v.resize(4);
    v.pop_back();
    v.pop_back();
    v.pop_back();
    std::cout << v.size() << ' ' << v.capacity() << std::endl;
    std::cout << v[9] << std::endl;
    v.push_back(1);
    std::cout << v.size() << ' ' << v.capacity() << std::endl;*/
    std::cout << v.max_size() << std::endl;
    for (int i = 0; i<v.max_size()-2305843009210000000 ; ++i) {
        v.push_back(1);
    }
    return 0;
}