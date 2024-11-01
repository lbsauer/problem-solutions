// https://leetcode.com/problems/custom-sort-string
// 2024/07/22

class Solution {
public:
    string customSortString(string order, string s) {
        int idx[26];
        for (int i = 0; i < order.length(); ++i) {
            idx[order[i] - 'a'] = i;
        }

        sort(s.begin(), s.end(), [&](const char lhs, const char rhs) {
            return idx[lhs - 'a'] < idx[rhs - 'a'];
        });

        return s;
    }
};