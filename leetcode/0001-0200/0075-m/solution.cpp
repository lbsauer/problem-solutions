// https://leetcode.com/problems/sort-colors
// 2025/12/06

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int l = 0, m = 0, r = nums.size() - 1; m <= r;) {
            if (nums[m] == 0) {
                swap(nums[m++], nums[l++]);
            } else if (nums[m++] == 2) {
                swap(nums[--m], nums[r--]);
            }
        }
    }
};