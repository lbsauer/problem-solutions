// https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or
// 2025/07/29

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int closest[32]{};
        for (int i = nums.size() - 1; i >= 0; --i) {
            int dist = 1;
            for (int j = 0; j < 32; ++j) {
                closest[j] = (nums[i] & (1 << j)) ? i : closest[j];
                dist = max(dist, closest[j] - i + 1);
            }

            nums[i] = dist;
        }

        return nums;
    }
};