// https://leetcode.com/problems/maximum-candies-allocated-to-k-children
// 2025/03/14

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        const long long total = accumulate(candies.begin(), candies.end(), 0ll);
        if (total < k) return 0;

        long long l = 1, r = total / k;
        while (l < r) {
            const long long m = midpoint(l, r + 1);
            const long long sum = accumulate(candies.begin(), candies.end(), 0ll,
                [m](long long acc, const int curr) { return acc += curr / m; });

            if (k > sum) {
                r = m - 1;
            } else {
                l = m;
            }
        }

        return l;
    }
};