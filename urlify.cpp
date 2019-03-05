#include <algorithm>
#include <iostream>
#include <string>

void URLify(std::string& string1) {
    for (size_t i = 0; i < string1.size(); ++i) {
        if (string1[i] == ' ') {
            string1[i] = '@';
            string1.insert(++i, "20");
            string1.pop_back();
            string1.pop_back();
        }
    }
}

int main() {
    std::string input1{"Mr John Smith    "};
    URLify(input1);
    std::cout << input1 << std::endl;

    return 0;
}
