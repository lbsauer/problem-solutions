// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i
// 2025/07/15

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int alt = 1, odd = nums[0] & 1;
        for (int i = 1; i < nums.size(); ++i) {
            odd += nums[i] & 1;
            alt += (nums[i] & 1) != (nums[i - 1] & 1);
        }

        return max({alt, odd, static_cast<int>(nums.size()) - odd});
    }
};