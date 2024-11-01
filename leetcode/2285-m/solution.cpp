// https://leetcode.com/problems/maximum-total-importance-of-roads
// 2024/07/27

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> count(n);
        for (const auto& r : roads) {
            ++count[r[0]];
            ++count[r[1]];
        }

        sort(count.begin(), count.end(), greater<int>{});

        long long res = 0;
        auto it = count.begin();
        while (n > 0) {
            res += (long long)*it++ * n--;
        }

        return res;
    }
};