// https://leetcode.com/problems/minimum-index-of-a-valid-split
// 2025/03/29

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dominant;
        for (int count = 0; const int n : nums) {
            if (count == 0) {
                dominant = n;
                ++count;
            } else {
                count += dominant == n ? 1 : -1;
            }
        }

        int left = 0, right = count(nums.begin(), nums.end(), dominant);
        for (int i = 0; i < nums.size(); ++i) {
            left  += nums[i] == dominant;
            right -= nums[i] == dominant;

            if (left * 2 > i + 1 && right * 2 > nums.size() - i - 1) return i;
        }

        return -1;
    }
};