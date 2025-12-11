// https://leetcode.com/problems/cells-with-odd-values-in-a-matrix
// 2025/10/15

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        long long row = 0, col = 0;
        for (const auto& i : indices) {
            row ^= 1ll << i[0];
            col ^= 1ll << i[1];
        }

        const int r = bitset<64>(row).count();
        const int c = bitset<64>(col).count();

        return r * (n - c) + c * (m - r);
    }
};