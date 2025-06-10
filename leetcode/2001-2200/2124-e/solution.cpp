// https://leetcode.com/problems/check-if-all-as-appears-before-all-bs
// 2024/09/17

class Solution {
public:
    bool checkString(string s) {
        return find(find(s.begin(), s.end(), 'b'), s.end(), 'a') == s.end();
    }
};