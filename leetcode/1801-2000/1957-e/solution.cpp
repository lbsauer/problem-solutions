// https://leetcode.com/problems/delete-characters-to-make-fancy-string
// 2025/07/21

class Solution {
public:
    string makeFancyString(string s) {
        int l = 1;
        for (int r = 1, count = 1; r < s.size(); ++r) {
            count = s[r] == s[r - 1] ? count + 1 : 1;
            if (count < 3) s[l++] = s[r];
        }

        s.resize(l);

        return s;
    }
};