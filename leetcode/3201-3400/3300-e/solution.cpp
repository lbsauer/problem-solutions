// https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum
// 2026/05/28

class Solution {
public:
    int minElement(vector<int>& nums) {
        int min_e = INT_MAX;
        for (int n : nums) {
            int sum = 0;
            while (n > 0) {
                sum += n % 10;
                n /= 10;
            }

            min_e = min(min_e, sum);
        }

        return min_e;
    }
};