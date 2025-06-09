// https://leetcode.com/problems/isomorphic-strings
// 2024/04/02

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char map[128] = {0};
        bool mapped[128] = {false};

        for (int i = 0; i < s.length(); ++i) {
            if (map[s[i]] != 0) {
                if (map[s[i]] != t[i]) return false;
            } else {
                if (mapped[t[i]]) return false;
                map[s[i]] = t[i];
                mapped[t[i]] = true;
            }
        }

        return true;
    }
};