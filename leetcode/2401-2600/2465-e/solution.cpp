// https://leetcode.com/problems/number-of-distinct-averages
// 2025/07/07

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_set<int> set;
        for (int l = 0, r = nums.size() - 1; l < r; ++l, --r) {
            set.insert(nums[l] + nums[r]);
        }

        return set.size();
    }
};