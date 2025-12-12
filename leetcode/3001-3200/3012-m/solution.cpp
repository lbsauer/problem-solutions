// https://leetcode.com/problems/minimize-length-of-array-using-operations
// 2025/11/05

class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int min_e = nums[0], freq = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < min_e) {
                min_e = nums[i];
                freq = 1;
            } else {
                freq += nums[i] == min_e;
            }
        }

        const auto it = find_if(nums.begin(), nums.end(), [min_e](const int n) { return n % min_e != 0; });

        return it == nums.end() ? (freq + 1) / 2 : 1;
    }
};