// https://leetcode.com/problems/valid-triangle-number
// 2025/09/26

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int count = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int l = 0, r = i - 1; l < r; --r) {
                while (l < r && nums[l] + nums[r] <= nums[i]) ++l;

                count += r - l;
            }
        }

        return count;
    }
};