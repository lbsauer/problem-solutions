// https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end
// 2025/11/13

class Solution {
public:
    int maxOperations(string s) {
        int count = 0, ones = s[0] == '1';
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '1') {
                ++ones;
            } else if (s[i - 1] == '1') {
                count += ones;
            }
        }

        return count;
    }
};