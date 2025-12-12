// https://leetcode.com/problems/count-covered-buildings
// 2025/12/11

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> min_row(n + 1, n), max_row(n + 1);
        vector<int> min_col(n + 1, n), max_col(n + 1);
        for (const auto& b : buildings) {
            min_row[b[0]] = min(min_row[b[0]], b[1]);
            max_row[b[0]] = max(max_row[b[0]], b[1]);
            min_col[b[1]] = min(min_col[b[1]], b[0]);
            max_col[b[1]] = max(max_col[b[1]], b[0]);
        }

        int count = 0;
        for (const auto& b : buildings) {
            count += (min_row[b[0]] < b[1]) & (b[1] < max_row[b[0]]) &
                     (min_col[b[1]] < b[0]) & (b[0] < max_col[b[1]]);
        }

        return count;
    }
};