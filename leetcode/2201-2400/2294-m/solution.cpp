// https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k
// 2025/06/18

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int count = 0;
        for (int l = 0, r = 1; l < nums.size(); l = r++, ++count) {
            while (r < nums.size() && nums[r] - nums[l] <= k) ++r;
        }

        return count;
    }
};