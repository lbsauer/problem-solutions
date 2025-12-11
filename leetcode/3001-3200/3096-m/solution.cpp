// https://leetcode.com/problems/minimum-levels-to-gain-more-points
// 2025/09/20

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int bob = 0;
        for (const int p : possible) {
            bob += p == 1 ? 1 : -1;
        }

        int alice = 0;
        for (int i = 0; i < possible.size() - 1; ++i) {
            alice += possible[i] == 1 ? 1 : -1;
            bob   -= possible[i] == 1 ? 1 : -1;

            if (alice > bob) return i + 1;
        }

        return -1;
    }
};