// https://leetcode.com/problems/maximal-network-rank
// 2024/08/06

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<bitset<100>> adj(n);
        for (const vector<int>& r : roads) {
            adj[r[0]][r[1]] = true;
            adj[r[1]][r[0]] = true;
        }

        int max_rank = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;

                max_rank = max(max_rank, (int)(adj[i].count() + adj[j].count() - adj[i][j]));
            }
        }

        return max_rank;
    }
};