// https://leetcode.com/problems/alice-and-bob-playing-flower-game
// 2025/08/29

class Solution {
public:
    long long flowerGame(int n, int m) {
        return static_cast<long long>(n) * m / 2;
    }
};