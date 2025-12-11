// https://leetcode.com/problems/find-closest-person
// 2025/09/04

class Solution {
public:
    int findClosest(int x, int y, int z) {
        x = abs(x - z);
        y = abs(y - z);

        return x < y ? 1 : (x == y ? 0 : 2);
    }
};