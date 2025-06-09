// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i
// 2024/11/16

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res(nums.size() - k + 1, -1);

        for (auto it = nums.rbegin(), rit = res.rbegin(); rit != res.rend();) {
            const auto count = 1 + distance(it, adjacent_find(it, nums.rend(), [](int lhs, int rhs) {
                return lhs != rhs + 1;
            }));

            copy(it, it + min(count - k + 1, distance(rit, res.rend())), rit);

            advance(rit, min(count, distance(rit, res.rend())));
            advance(it, count);
        }

        return res;
    }
};