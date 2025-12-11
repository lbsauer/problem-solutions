// https://leetcode.com/problems/sort-vowels-in-a-string
// 2025/09/12

class Solution {
    bool is_vowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o';
    }

public:
    string sortVowels(string s) {
        int freq[128]{};
        for (const char c : s) {
            freq[c] += is_vowel(c);
        }

        int pos = 0;
        for (char& c : s) {
            if (!is_vowel(c)) continue;

            while (freq[pos] == 0) ++pos;

            c = pos;
            --freq[pos];
        }

        return s;
    }
};