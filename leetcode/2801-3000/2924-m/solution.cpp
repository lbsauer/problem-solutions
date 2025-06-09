// https://leetcode.com/problems/find-champion-ii
// 2024/11/12

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> degree(n);
        for (const auto& e : edges) {
            ++degree[e[1]];
        }

        auto it = find(degree.begin(), degree.end(), 0);

        return find(it + 1, degree.end(), 0) != degree.end() ? -1 : distance(degree.begin(), it);
    }
};