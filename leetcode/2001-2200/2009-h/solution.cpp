// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous
// 2024/07/20

class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const vector<int>::iterator new_end = unique(nums.begin(), nums.end());

        for (vector<int>::iterator it = nums.begin(); it != new_end; ++it) {
            *it = distance(it, lower_bound(it, new_end, *it + nums.size()));
        }

        return nums.size() - *max_element(nums.begin(), new_end);
    }
};