// https://leetcode.com/problems/coin-change
// 2024/08/29

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> count(amount + 1, INT_MAX);
        count[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (const int c : coins) {
                if (c > i || count[i - c] == INT_MAX) continue;

                count[i] = min(count[i], count[i - c] + 1);
            }
        }

        return count[amount] == INT_MAX ? -1 : count[amount];
    }
};