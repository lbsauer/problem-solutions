// https://leetcode.com/problems/binary-prefix-divisible-by-5
// 2025/11/24

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res(nums.size());
        for (int i = 0, x = 0; i < nums.size(); ++i) {
            x = (x * 2 + nums[i]) % 5;
            res[i] = x % 5 == 0;
        }

        return res;
    }
};