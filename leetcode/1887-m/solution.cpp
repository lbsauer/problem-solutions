// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal
// 2024-11-01

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>{});

        int count = 0;
        for (auto it = nums.begin(); it != nums.end();) {
            count += distance(nums.begin(), it);
            it = find_if(it + 1, nums.end(), [it](int n) { return n != *it; });
        }

        return count;
    }
};