// https://leetcode.com/problems/minimum-removals-to-balance-array
// 2026/02/05

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int longest = 0;
        for (int l = 0, r = 0; r < nums.size(); ++l) {
            const auto max_v = static_cast<long long>(k) * nums[l];
            while (r < nums.size() && nums[r] <= max_v) ++r;

            longest = max(longest, r - l);
        }

        return nums.size() - longest;
    }
};