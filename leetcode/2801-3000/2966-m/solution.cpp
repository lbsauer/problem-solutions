// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference
// 2025/06/18

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        for (int i = 2; i < nums.size(); i += 3) {
            if (nums[i] - nums[i - 2] > k) return {};
        }
        
        vector<vector<int>> res(nums.size() / 3, vector<int>(3));
        for (int i = 0; i < res.size(); ++i) {
            for (int j = 0; j < 3; ++j) {
                res[i][j] = nums[i * 3 + j];
            }
        }

        return res;
    }
};