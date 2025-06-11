// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words
// 2025/05/25

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int count[26][26]{};
        for (const string& w : words) {
            ++count[w[0] - 'a'][w[1] - 'a'];
        }

        int diff = 0, equal = 0;
        for (int i = 0; i < 26; ++i) {
            equal += count[i][i] & ~(equal & 1);

            for (int j = i + 1; j < 26; ++j) {
                diff += min(count[i][j], count[j][i]);
            }
        }

        return diff * 4 + equal * 2;
    }
};