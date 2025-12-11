// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array
// 2025/09/20

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = INT_MIN, second = INT_MAX;
        for (const int n : nums) {
            if (n >= first) {
                second = first;
                first = n;
            } else if (n > second) {
                second = n;
            }
        }

        return (first - 1) * (second - 1);
    }
};