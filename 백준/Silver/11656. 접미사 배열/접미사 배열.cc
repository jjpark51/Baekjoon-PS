#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main() {
    std::string word = "";
    getline(std::cin, word);

    std::vector<std::string> v;

    for (int i = 0; i < word.size(); i++) {
        v.push_back(word.substr(i));
    }

    std::sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }

    return 0;
}