// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses
// 2024/05/05

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        std::unordered_set<int> set;
        
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') ++count;
            if (s[i] == ')') --count;

            if (count < 0) {
                set.insert(i);
                count = 0;
            }
        }

        for (int i = s.length() - 1; count > 0; --i) {
            if (s[i] != '(') continue;

            set.insert(i);
            --count;
        }

        std::string res(s.length() - set.size(), ' ');
        for (int i = 0, j = 0; i < s.length(); ++i) {
            if (set.count(i)) continue;

            res[j++] = s[i];
        }

        return res;
    }
};