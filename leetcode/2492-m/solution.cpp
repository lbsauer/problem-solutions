// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities
// 2024-11-12

class Solution {
    int find(vector<int>& sets, int x) {
        return sets[x] < 0 ? x : sets[x] = find(sets, sets[x]);
    }

    void unite(vector<int>& sets, int x, int y) {
        x = find(sets, x);
        y = find(sets, y);

        if (x == y) return;

        if (x > y) swap(x, y);

        sets[x] += sets[y];
        sets[y] = x;
    }

public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> sets(n, -1);
        for (const auto& r : roads) {
            unite(sets, r[0] - 1, r[1] - 1);
        }

        int set_zero = find(sets, 0);

        int score = INT_MAX;
        for (const auto& r : roads) {
            if (find(sets, r[0] - 1) != set_zero) continue;

            score = min(score, r[2]);
        }

        return score;
    }
};