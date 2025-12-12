// https://leetcode.com/problems/maximum-points-inside-the-square
// 2025/11/21

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int dist[26];
        fill(begin(dist), end(dist), INT_MAX);

        int min_dist = INT_MAX;
        for (int i = 0; i < s.size(); ++i) {
            const int d = max(abs(points[i][0]), abs(points[i][1]));
            min_dist = min(min_dist, max(dist[s[i] - 'a'], d));
            dist[s[i] - 'a'] = min(dist[s[i] - 'a'], d);
        }

        return count_if(begin(dist), end(dist), [&](const int d) { return d < min_dist; });
    }
};