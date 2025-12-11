// https://leetcode.com/problems/summary-ranges
// 2025/08/29

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        for (int l = 0, r = 1; l < nums.size(); l = r++) {
            while (r < nums.size() && nums[r] == nums[r - 1] + 1) ++r;

            if (r == l + 1) {
                res.push_back(to_string(nums[l]));
            } else {
                res.push_back(to_string(nums[l]) + "->" + to_string(nums[r - 1]));
            }
        }

        return res;
    }
};