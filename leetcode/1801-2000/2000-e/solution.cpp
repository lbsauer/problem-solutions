// https://leetcode.com/problems/reverse-prefix-of-word
// 2024/05/01

class Solution {
public:
    string reversePrefix(string word, char ch) {
        std::reverse(word.begin(), word.begin() + word.find_first_of(ch) + 1);
        return word;
    }
};