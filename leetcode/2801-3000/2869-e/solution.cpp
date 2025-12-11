// https://leetcode.com/problems/minimum-operations-to-collect-elements
// 2025/09/26

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long mask = 0, target = (1ll << k) - 1;

        int count = 0;
        for (int i = nums.size() - 1; (mask & target) != target; --i) {
            mask |= 1ll << (nums[i] - 1);
            ++count;
        }

        return count;
    }
};