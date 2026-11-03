// https://leetcode.com/problems/angle-between-hands-of-a-clock
// 2026/08/22

class Solution {
public:
    double angleClock(int hour, int minutes) {
        const double m = minutes / 60.0;
        const double h = hour / 12.0 + m / 12.0;

        const double delta = abs(h - m) * 360.0;

        return min(delta, 360.0 - delta);
    }
};