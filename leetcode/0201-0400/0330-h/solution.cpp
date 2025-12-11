// https://leetcode.com/problems/patching-array
// 2025/10/10

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int last = 0, patches = 0;
        for (int i = 0; i < nums.size() && last < n; ++i) {
            while (last < n && nums[i] > last + 1) {
                last += min(last + 1, n - last);
                ++patches;
            }

            last += min(nums[i], n - last);
        }

        while (last < n) {
            last += min(last + 1, n - last);
            ++patches;
        }

        return patches;
    }
};