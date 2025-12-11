// https://leetcode.com/problems/partition-array-into-k-distinct-groups
// 2025/10/15

class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;

        sort(nums.begin(), nums.end());

        const int group_size = nums.size() / k;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            while (j < nums.size() && nums[i] == nums[j]) ++j;

            if (j - i > group_size) return false;
        }

        return true;
    }
};