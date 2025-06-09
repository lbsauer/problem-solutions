// https://leetcode.com/problems/count-the-number-of-complete-components
// 2024/11/12

class Solution {
    int find(vector<int>& sets, int x) {
        return sets[x] < 0 ? x : sets[x] = find(sets, sets[x]);
    }

    void unite(vector<int>& sets, vector<int>& count, int x, int y) {
        x = find(sets, x);
        y = find(sets, y);

        if (x == y) {
            ++count[x];
            return;
        }

        if (x > y) swap(x, y);

        count[x] += count[y] + 1;

        sets[x] += sets[y];
        sets[y] = x;
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> sets(n, -1), count(n);
        for (const auto& e : edges) {
            unite(sets, count, e[0], e[1]);
        }

        int complete = 0;
        for (int i = 0; i < n; ++i) {
            if (sets[i] >= 0) continue;

            complete += count[i] == (sets[i] * (sets[i] + 1)) / 2;
        }

        return complete;
    }
};