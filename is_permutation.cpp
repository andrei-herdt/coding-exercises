#include <algorithm>
#include <iostream>
#include <string>

bool IsPermutation(std::string& string1, std::string& string2) {
    std::sort(std::begin(string1), std::end(string1));
    std::sort(std::begin(string2), std::end(string2));
    return string1 == string2;
}

int main() {
    std::string input1{"abcdefg"};
    std::string input2{"acbdefg"};
    std::cout << IsPermutation(input1, input2) << std::endl;
    input1 = "rbcdefg";
    input2 = "acbdefg";
    std::cout << IsPermutation(input1, input2) << std::endl;

    return 0;
}
