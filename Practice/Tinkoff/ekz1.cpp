#include <iostream>
#include <string>

int main() {
    int letters = 0;
    std::cin >> letters;
    std::cin.ignore();
    std::string words;
    std::string colors;
    std::getline(std::cin, words, '\n');
    std::getline(std::cin, colors, '\n');
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < letters - 1) {
        if (colors[i] == colors[i+1]) {
            if (words[j+1] != ' ') {
                ++count;
                while (words[j] != ' ' && j < words.length()) {
                    ++j;
                    ++i;
                }
            } else {
                ++j;
            }
        }
        ++i;
        ++j;
    }
    std::cout << count << std::endl;
    return 0;
}