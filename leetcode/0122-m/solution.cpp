// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
// 2024/07/22

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = INT32_MAX;
        int profit = 0;
        int total = 0;

        for (int p : prices) {
            if ((p - cost) > profit) {
                profit = p - cost;
            } else {
                total += profit;
                profit = 0;
                cost = p;
            }
        }

        return total + profit;
    }
};