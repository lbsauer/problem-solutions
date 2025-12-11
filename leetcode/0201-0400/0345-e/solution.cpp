// https://leetcode.com/problems/reverse-vowels-of-a-string
// 2025/08/08

class Solution {
    bool is_vowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o';
    }

public:
    string reverseVowels(string s) {
        for (int l = 0, r = s.size() - 1; l < r; ++l) {
            if (!is_vowel(s[l])) continue;

            while (l < r && !is_vowel(s[r])) --r;   
            
            swap(s[l], s[r--]);
        }

        return s;
    }
};