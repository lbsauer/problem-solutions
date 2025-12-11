// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string
// 2025/10/16

class Solution {
public:
    string removeDuplicates(string s) {
        string t;
        for (const char c : s) {
            if (!t.empty() && t.back() == c) {
                t.pop_back();
            } else {
                t.push_back(c);
            }
        }

        return t;
    }
};