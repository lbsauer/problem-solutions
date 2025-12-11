// https://leetcode.com/problems/remove-k-digits
// 2025/08/13

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) return "0";

        string s;
        for (const char c : num) {
            while (k > 0 && !s.empty() && c < s.back()) {
                s.pop_back();
                --k;
            }

            s.push_back(c);
        }

        s.resize(s.size() - k);
        s.erase(0, s.find_first_not_of('0'));

        return s.empty() ? "0" : s;
    }
};