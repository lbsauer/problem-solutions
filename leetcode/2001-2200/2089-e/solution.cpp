// https://leetcode.com/problems/find-target-indices-after-sorting-array
// 2025/11/21

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less{}, equal{};
        for (const int n : nums) {
            less += n < target;
            equal += n == target;
        }

        vector<int> res(equal);
        iota(res.begin(), res.end(), less);

        return res;
    }
};