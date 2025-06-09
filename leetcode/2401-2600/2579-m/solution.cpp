// https://leetcode.com/problems/count-total-number-of-colored-cells
// 2025/03/05

class Solution {
public:
    long long coloredCells(int n) {
        return 1 + n * (n - 1ll) / 2 * 4;
    }
};