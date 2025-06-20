// https://leetcode.com/problems/minimum-number-of-operations-to-make-arrays-similar
// 2025/06/19

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        constexpr static auto comp = [](const int lhs, const int rhs) {
            return (lhs & 1) != (rhs & 1) ? (lhs & 1) < (rhs & 1) : lhs < rhs;
        };

        sort(nums.begin(), nums.end(), comp);
        sort(target.begin(), target.end(), comp);

        long long count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            count += max((nums[i] - target[i]) / 2, 0);
        }

        return count;
    }
};