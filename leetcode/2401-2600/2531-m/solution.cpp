// https://leetcode.com/problems/make-number-of-distinct-characters-equal
// 2026/01/31

class Solution {
public:
    bool isItPossible(string word1, string word2) {
        int freq1[26]{}, distinct1{};
        for (const char c : word1) {
            distinct1 += ++freq1[c - 'a'] == 1;
        }

        int freq2[26]{}, distinct2{};
        for (const char c : word2) {
            distinct2 += ++freq2[c - 'a'] == 1;
        }

        if (abs(distinct1 - distinct2) > 2) return false;

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (freq1[i] == 0 || freq2[j] == 0) continue;

                const int d1 = distinct1 - (freq1[i] == 1 && i != j) + (freq1[j] == 0 && i != j);
                const int d2 = distinct2 - (freq2[j] == 1 && i != j) + (freq2[i] == 0 && i != j);

                if (d1 == d2) return true;
            }
        }

        return false;
    }
};