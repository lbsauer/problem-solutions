// https://leetcode.com/problems/generate-parentheses
// 2025/05/14

class Solution {
    void solve(vector<string>& res, string& s, int left, int right) {
        if (right == 0) {
            res.push_back(s);
            return;
        }
        
        if (left > 0) {
            s.push_back('(');
            solve(res, s, left - 1, right);
            s.pop_back();
        }

        if (right > left) {
            s.push_back(')');
            solve(res, s, left, right - 1);
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;

        string s;
        s.reserve(2 * n);

        solve(res, s, n, n);

        return res;
    }
};