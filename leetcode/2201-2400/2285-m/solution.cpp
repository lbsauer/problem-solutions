// https://leetcode.com/problems/maximum-total-importance-of-roads
// 2024/07/27

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n);
        for (const auto& r : roads) {
            ++degree[r[0]];
            ++degree[r[1]];
        }

        sort(degree.begin(), degree.end(), greater<int>{});

        long long res = 0;
        for_each(degree.begin(), degree.end(), [&](long long d) { res += d * n--; });

        return res;
    }
};