#include <iostream>
#include <string>
#include <unordered_map>

int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> map;
    int maxLength = 0, start = 0;
    for (int end = 0; end < s.length(); end++) {
        if (map.find(s[end]) != map.end()) {
            start = std::max(start, map[s[end]] + 1);
        }
        map[s[end]] = end;
        maxLength = std::max(maxLength, end - start + 1);
    }
    return maxLength;
}

int main() {
    std::string s = "abcabcbb";
    std::cout << "Length of longest substring without repeating characters: " << lengthOfLongestSubstring(s) << std::endl;
    return 0;
}
