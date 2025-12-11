// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i
// 2025/09/21

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<bool> ban(n);
        for (const int b : banned) {
            if (b <= n) ban[b - 1] = true;
        }

        int sum = 0, count = 0;
        for (int i = 1; i <= n && sum < maxSum; ++i) {
            if (!ban[i - 1]) {
                sum += i;
                ++count;
            }
        }

        return count - (sum > maxSum);
    }
};