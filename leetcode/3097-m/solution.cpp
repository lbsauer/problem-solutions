// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii
// 2024/11/10

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int bits[32] = {0};

        int res = INT_MAX;
        int or_acc = 0;

        for (int l = 0, r = 0; r < nums.size() && res > 1; ++r) {
            or_acc |= nums[r];
            for (int i = 0, n = nums[r]; n != 0; ++i) {
                bits[i] += n & 1;
                n >>= 1;
            }

            for (; l <= r && or_acc >= k; ++l) {
                res = min(res, r - l + 1);

                for (int i = 0, n = nums[l]; n != 0; ++i) {
                    bits[i] -= n & 1;
                    n >>= 1;

                    or_acc &= ~(int{bits[i] == 0} << i);
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};