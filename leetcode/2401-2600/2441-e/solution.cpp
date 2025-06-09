// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative
// 2024/05/01

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        std::unordered_set<int> set;
        int max = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (set.count(-nums[i])) {
                max = std::max(max, abs(nums[i]));
            } else {
                set.insert(nums[i]);
            }
        }

        return max;
    }
};