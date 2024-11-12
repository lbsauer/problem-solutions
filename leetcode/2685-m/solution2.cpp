// https://leetcode.com/problems/count-the-number-of-complete-components
// 2024/08/05

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int64_t> adj(n);

        for (int i = 0; i < n; ++i) {
            adj[i] |= (1ll << i);
        }

        for (const vector<int>& e : edges) {
            adj[e[0]] |= (1ll << e[1]);
            adj[e[1]] |= (1ll << e[0]);
        }

        int total = 0;
        for (int i = 0; i < n; ++i) {
            if (adj[i] == 0) continue;

            bool b = true;
            for (int64_t j = 0, a = adj[i]; a != 0; ++j, a >>= 1) {
                if (!(a & 1) || i == j) continue;

                if (adj[i] != adj[j]) {
                    b = false;
                }

                adj[j] = 0;
            }

            total += b;
        }

        return total;
    }
};