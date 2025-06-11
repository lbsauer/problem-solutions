// https://leetcode.com/problems/coin-change-ii
// 2025/05/13

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint32_t> count(amount + 1);
        count[0] = 1;

        for (int c : coins) {
            for (int i = c; i <= amount; ++i) {
                count[i] += count[i - c];
            }
        }

        return count[amount];
    }
};