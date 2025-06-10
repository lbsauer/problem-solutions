// https://leetcode.com/problems/special-array-i
// 2025/02/04

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        const auto equal_parity = [](const int lhs, const int rhs) { return (lhs & 1) == (rhs & 1); };
        return adjacent_find(nums.begin(), nums.end(), equal_parity) == nums.end();
    }
};