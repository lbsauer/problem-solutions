// https://leetcode.com/problems/consecutive-characters
// 2025/10/15

class Solution {
public:
    int maxPower(string s) {
        int max_power = 1;
        for (int i = 1, count = 1; i < s.size(); ++i) {
            count = s[i] == s[i - 1] ? count + 1 : 1;
            max_power = max(max_power, count);
        }

        return max_power;
    }
};