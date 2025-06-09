// https://leetcode.com/problems/max-consecutive-ones-iii
// 2020/08/28

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count_zero = 0;
        int max = 0;

        for (int l = 0, r = 0; r < nums.size(); ++r) {
            count_zero += nums[r] == 0;

            while (count_zero > k) {
                count_zero -= nums[l++] == 0;
            }

            max = std::max(max, r - l + 1);
        }

        return max;
    }
};