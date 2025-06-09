// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes
// 2024/07/26

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> seen(n);
        for (const auto& e : edges) {
            seen[e[1]] = true;
        }

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (!seen[i]) res.push_back(i);
        }

        return res;
    }
};