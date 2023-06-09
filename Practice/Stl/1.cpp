#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <algorithm>

int main() {
    std::vector <int> vec;
    for (int i = 1; i < 10; i++) {
        vec.push_back(i);
    }
    std::vector <int>::iterator it = vec.begin();
    int total = 0;
    while (it != vec.end()) {
        total += *it;
        it++;
    }
    std::cout << total << std::endl;
    std::vector <int> arr = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
    std::vector <int> results;
    results.resize(9);
    std::transform(vec.begin(), vec.begin() + 10, arr.begin(), results.begin(), std::plus<int>());
    std::cout << arr.size() << std::endl;
    for (int i = 0; i < results.size(); i++) {
        std::cout << results[i] << ' ';
    }
    std::cout << std::endl;
    if (arr != results) {
        std::cout << 'x' << std::endl;
    }
    std::vector<int> v(5, 1);
    v.resize(7, 2);
    std::cout << v[1] << ' ' << v[6] << std::endl;;
    unsigned size = v.max_size();
    //v.assign(v.max_size(), 0);
    /*for( int i = 0; i < 10; i++ ) {
        std::cout << "Element " << i << " is " << v.at(i) << std::endl;
    }*/
    return 0;
}