// https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars
// 2025/06/07

class Solution {
public:
    string clearStars(string s) {
        vector<int> pos[26]{};
        for (int i = 0, j; i < s.size(); ++i) {
            if (s[i] == '*') {
                for (j = 0; pos[j].empty(); ++j);
                s[pos[j].back()] = '*';
                pos[j].pop_back();
            } else {
                pos[s[i] - 'a'].push_back(i);
            }
        }

        s.resize(distance(s.begin(), remove(s.begin(), s.end(), '*')));

        return s;
    }
};