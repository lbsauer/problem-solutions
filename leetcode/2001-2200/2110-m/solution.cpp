// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock
// 2025/12/14

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long count = prices.size();
        for (int l = 0, r = 1; r < prices.size(); l = r++) {
            while (r < prices.size() && prices[r] == prices[r - 1] - 1) {
                count += r++ - l;
            }
        }

        return count;
    }
};