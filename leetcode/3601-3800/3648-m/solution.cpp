// https://leetcode.com/problems/minimum-sensors-to-cover-grid
// 2025/10/16

class Solution {
public:
    int minSensors(int n, int m, int k) {
        const int d = k * 2 + 1;
        return ((n + d - 1) / d) * ((m + d - 1) / d);
    }
};