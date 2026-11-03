// https://leetcode.com/problems/remove-adjacent-almost-equal-characters
// 2026/08/16

class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int count = 0;
        for (int i = 1; i < word.size(); ++i) {
            if (abs(word[i] - word[i - 1]) <= 1) {
                ++count;
                ++i;
            }
        }

        return count;
    }
};