// https://leetcode.com/problems/print-words-vertically
// 2025/08/08

class Solution {
public:
    vector<string> printVertically(string s) {
        int words = 1, max_length = 0;
        for (int l = 0, r = 0; r < s.size(); ++r) {
            if (s[r] == ' ') {
                ++words;
                l = r + 1;
            } else {
                max_length = max(max_length, r - l + 1);
            }
        }

        vector<string> res(max_length, string(words, ' '));
        for (int l = 0, r = 0, w = 0; r < s.size(); ++r) {
            if (s[r] == ' ') {
                ++w;
                l = r + 1;
            } else {
                res[r - l][w] = s[r];
            }
        }

        for (string& str : res) {
            str.resize(str.find_last_not_of(' ') + 1);
        }

        return res;
    }
};