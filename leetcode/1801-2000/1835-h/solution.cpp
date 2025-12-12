// https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and
// 2025/12/08

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        const int x = accumulate(arr2.begin(), arr2.end(), 0, bit_xor<int>{});
        return accumulate(arr1.begin(), arr1.end(), 0, [x](int acc, int n) { return acc ^ n & x; });
    }
};