// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range
// 2025/12/06

class Solution {
public:
    int countOdds(int low, int high) {
        return (high - low) / 2 + ((low | high) & 1);
    }
};