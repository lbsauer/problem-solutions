// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array
// 2024/10/30

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> sub{nums.front()}, heights(nums.size());
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > sub.back()) {
                sub.push_back(nums[i]);
            } else {
                *lower_bound(sub.begin(), sub.end(), nums[i]) = nums[i];
            }

            heights[i] = sub.size() - 1;
        }

        sub.clear();
        sub.push_back(nums.back());

        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] > sub.back()) {
                sub.push_back(nums[i]);
            } else {
                *lower_bound(sub.begin(), sub.end(), nums[i]) = nums[i];
            }

            if (heights[i] > 0 && sub.size() > 1) heights[i] += sub.size();
        }

        return nums.size() - *max_element(heights.begin() + 1, heights.end() - 1);
    }
};