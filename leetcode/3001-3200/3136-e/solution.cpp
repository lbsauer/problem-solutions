// https://leetcode.com/problems/valid-word
// 2025/07/15

class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;

        int vowel{}, consonant{};
        for (const char c : word) {
            if (!isalpha(c) && !isdigit(c)) return false;

            if (
                c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'
            ) {
                ++vowel;
            } else {
                consonant += !isdigit(c);
            }
        }

        return vowel >= 1 && consonant >= 1;
    }
};