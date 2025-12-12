// https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three
// 2025/11/22

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        return count_if(nums.begin(), nums.end(), [](int n) { return n % 3 != 0; });
    }
};