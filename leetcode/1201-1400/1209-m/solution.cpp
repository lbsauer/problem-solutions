// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii
// 2025/08/24

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stack;
        for (const char c : s) {
            if (stack.empty() || stack.back().first != c) {
                stack.emplace_back(c, 1);
            } else if (++stack.back().second == k) {
                stack.pop_back();
            }
        }

        s.clear();
        for (const auto [c, n] : stack) {
            s.append(n, c);
        }

        return s;
    }
};