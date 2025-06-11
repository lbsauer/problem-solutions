// https://leetcode.com/problems/subarray-product-less-than-k
// 2025/04/28

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        
        int count = 0;
        for (int l = 0, r = 0, product = 1; r < nums.size(); ++r) {
            product *= nums[r];

            while (l <= r && product >= k) {
                product /= nums[l++];
            }

            count += r - l + 1;
        }

        return count;
    }
};