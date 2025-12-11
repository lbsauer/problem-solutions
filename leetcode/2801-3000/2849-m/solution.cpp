// https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time
// 2025/08/01

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        const int dist = max(abs(fx - sx), abs(fy - sy));
        return dist == 0 ? t != 1 : dist <= t;
    }
};