// https://leetcode.com/problems/lexicographical-numbers
// 2025/06/08

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> nums(n);
        for (int x = 1, i = 0; i < n; ++x) {
            while (x <= n) {
                nums[i++] = x;
                x *= 10;
            }

            x /= 10;
            while (x % 10 == 9) {
                x /= 10;
            }
        }

        return nums;
    }
};