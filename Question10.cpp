#include <iostream>
#include <string>

bool isAlphabetic(const std::string& s) {
    for (char c : s) {
        if (!isalpha(c)) return false;
    }
    return true;
}

int main() {
    std::string s = "HelloWorld";
    std::cout << "String \"" << s << "\" contains only alphabetic characters: " << std::boolalpha << isAlphabetic(s) << std::endl;
    return 0;
}
