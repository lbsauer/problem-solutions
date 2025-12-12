// https://leetcode.com/problems/minimum-average-difference
// 2025/12/07

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        const int n = nums.size();
        
        long long pre = 0, suf = accumulate(nums.begin(), nums.end(), 0ll);

        long long min_dif = suf, min_idx = 0;
        for (int i = 0; i < n - 1; ++i) {
            pre += nums[i];
            suf -= nums[i];

            const int d = abs(pre / (i + 1) - suf / (n - i - 1));
            if (d < min_dif) {
                min_dif = d;
                min_idx = i;
            }
        }

        return (pre + suf) / n < min_dif ? n - 1 : min_idx;
    }
};