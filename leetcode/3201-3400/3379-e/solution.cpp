// https://leetcode.com/problems/transformed-array
// 2026/02/05

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        const int n = nums.size();

        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = nums[((nums[i] % n) + i + n) % n];
        }

        return result;
    }
};