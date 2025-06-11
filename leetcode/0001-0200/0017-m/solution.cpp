// https://leetcode.com/problems/letter-combinations-of-a-phone-number
// 2025/05/21

class Solution {
    constexpr static string_view map[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(vector<string>& res, string& curr, const string& digits) {
        if (curr.size() == digits.size()) {
            res.push_back(curr);
            return;
        }

        for (const char c : map[digits[curr.size()] - '2']) {
            curr.push_back(c);
            backtrack(res, curr, digits);
            curr.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        string curr;
        vector<string> res;

        backtrack(res, curr, digits);

        return res;
    }
};