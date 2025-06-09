// https://leetcode.com/problems/decrease-elements-to-make-array-zigzag
// 2024/08/16

class Solution {
public:
    int diff(const vector<int>& nums, const int i) {
        if (i == 0) {
            return max(0, nums[i] - nums[i + 1] + 1);
        }

        if (i == nums.size() - 1) {
            return max(0, nums[i] - nums[i - 1] + 1);
        }

        return max(0, nums[i] - min(nums[i - 1], nums[i + 1]) + 1);
    }
    
    int movesToMakeZigzag(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        
        int odd = 0;
        int even = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (i & 1) {
                even += diff(nums, i);
            } else {
                odd += diff(nums, i);
            }
        }

        return min(odd, even);
    }
};