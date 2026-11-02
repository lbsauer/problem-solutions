// https://leetcode.com/problems/count-the-number-of-special-characters-ii
// 2026/05/27

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int first_upper[26]{}, last_lower[26]{};
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] <= 'Z') {
                if (first_upper[word[i] - 'A'] == 0) {
                    first_upper[word[i] - 'A'] = i + 1;
                }
            } else {
                last_lower[word[i] - 'a'] = i + 1;
            }
        }

        int count = 0;
        for (int i = 0; i < 26; ++i) {
            count += last_lower[i] != 0 && last_lower[i] < first_upper[i];
        }

        return count;
    }
};