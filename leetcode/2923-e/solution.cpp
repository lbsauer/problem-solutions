// https://leetcode.com/problems/find-champion-i
// 2024-11-12

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        return distance(grid.begin(), find_if(grid.begin(), grid.end(), [&](const auto& row) {
            return accumulate(row.begin(), row.end(), 1) == grid.size();
        }));
    }
};