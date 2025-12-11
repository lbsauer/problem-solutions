// https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make
// 2025/08/29

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());

        int sum = 1;
        for (const int c : coins) {
            if (sum < c) break;
            sum += c;
        }

        return sum;
    }
};