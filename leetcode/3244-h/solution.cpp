// https://leetcode.com/problems/shortest-distance-after-road-addition-queries-ii
// 2024-11-13

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> next(n);
        iota(next.begin(), next.end(), 1);

        vector<int> res(queries.size());

        for (auto it = res.begin(); const auto& q : queries) {
            int curr = next[q[0]];
            for (int prev = curr; curr < q[1]; prev = curr) {
                curr = next[curr];
                next[prev] = INT_MAX;
                --n;
            }

            next[q[0]] = curr;

            *it++ = n - 1;
        }

        return res;
    }
};