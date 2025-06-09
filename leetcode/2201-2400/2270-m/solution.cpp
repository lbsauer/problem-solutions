// https://leetcode.com/problems/number-of-ways-to-split-array
// 2025/01/03

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long l = 0, r = accumulate(nums.begin(), nums.end(), 0ll);
        return count_if(nums.begin(), prev(nums.end()), [&](const int n) { return (l += n) >= (r -= n); });
    }
};