// https://leetcode.com/problems/apply-operations-to-make-string-empty
// 2024/05/03

class Solution {
public:
    string lastNonEmptyString(string s) {
        std::vector<int> count(26);
        int max = 0;
        int max_count = 0;
        for (char c : s) {
            if (++count[c - 'a'] == max) {
                ++max_count;
            } else if (count[c - 'a'] > max) {
                max = count[c - 'a'];
                max_count = 1;
            }
        }

        std::string res(max_count, ' ');
        for (int i = s.length() - 1; i >= 0 && max_count > 0; --i) {
            if (count[s[i] - 'a']-- != max) continue;
            res[--max_count] = s[i];
        }

        return res;
    }
};