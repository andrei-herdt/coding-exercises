#include <algorithm>
#include <iostream>
#include <string>

bool IsUnique(std::string& string) {
    std::sort(std::begin(string), std::end(string));
    auto last = std::unique(std::begin(string), std::end(string));
    return last == std::end(string);
}

int main() {
    std::string input1{"abcdefg"};
    std::string input2{"accdefg"};
    std::cout << IsUnique(input1) << std::endl;
    std::cout << IsUnique(input2) << std::endl;

    return 0;
}
