// https://leetcode.com/problems/number-of-good-ways-to-split-a-string
// 2024/08/16

class Solution {
public:
    int numSplits(string s) {
        int distinct_left = 1;
        int left[26] = {0};
        ++left[s[0] - 'a'];

        int distinct_right = 0;
        int right[26] = {0};
        for (int i = 1; i < s.size(); ++i) {
            distinct_right += right[s[i] - 'a'] == 0;
            ++right[s[i] - 'a'];
        }

        int count = distinct_left == distinct_right;
        for (int i = 1; i < s.size(); ++i) {
            --right[s[i] - 'a'];
            distinct_right -= right[s[i] - 'a'] == 0;

            ++left[s[i] - 'a'];
            distinct_left += left[s[i] - 'a'] == 1;

            count += distinct_left == distinct_right;
        }

        return count;
    }
};