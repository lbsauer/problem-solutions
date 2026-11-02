// https://leetcode.com/problems/shortest-distance-to-a-character
// 2026/01/31

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> dist(s.size());

        int prev = -s.size();
        for (int i = 0; i < s.size(); ++i) {
            prev = s[i] == c ? i : prev;
            dist[i] = i - prev;
        }

        for (int i = prev - 1; i >= 0; --i) {
            prev = s[i] == c ? i : prev;
            dist[i] = min(dist[i], prev - i);
        }

        return dist;
    }
};