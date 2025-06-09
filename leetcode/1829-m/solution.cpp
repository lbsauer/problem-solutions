// https://leetcode.com/problems/maximum-xor-for-each-query
// 2024/11/07

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int mask = (1 << maximumBit) - 1, x = 0;
        
        for_each(nums.begin(), nums.end(), [&](int& n) { n = (x ^= n) ^ mask; });

        reverse(nums.begin(), nums.end());

        return nums;
    }
};