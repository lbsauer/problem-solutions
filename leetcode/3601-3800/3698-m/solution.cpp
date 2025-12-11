// https://leetcode.com/problems/split-array-with-minimum-difference
// 2025/10/15

class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long inc = 1, left = nums[0];
        for (; inc < nums.size() && nums[inc] > nums[inc - 1]; ++inc) {
            left += nums[inc];
        }
        
        long long dec = inc + 1, right = inc < nums.size() ? nums[inc] : 0;
        for (; dec < nums.size() && nums[dec] < nums[dec - 1]; ++dec) {
            right += nums[dec];
        }

        if (dec < nums.size()) return -1;

        const long long diff = abs(left - right);

        if (right != 0 && nums[inc] == nums[inc - 1]) return diff;

        return min(diff, abs((left - nums[inc - 1]) - (right + nums[inc - 1])));
    }
};