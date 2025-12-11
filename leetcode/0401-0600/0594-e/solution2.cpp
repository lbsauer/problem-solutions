// https://leetcode.com/problems/longest-harmonious-subsequence
// 2025/12/11

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int longest = 0;
        for (int l = 0, r = 1; r < nums.size(); ++l) {
            while (r < nums.size() && nums[r] <= nums[l] + 1) ++r;
            
            if (nums[r - 1] == nums[l] + 1) longest = max(longest, r - l);
        }

        return longest;
    }
};