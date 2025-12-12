// https://leetcode.com/problems/matrix-cells-in-distance-order
// 2025/12/08

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> res(rows * cols);
        res[0] = {rCenter, cCenter};

        int max_col = cCenter, min_col = cCenter;
        for (int l = 0, r = 1; r < res.size(); ++l) {
            const int row = res[l][0], col = res[l][1];

            if (row >= rCenter && row + 1 < rows) res[r++] = {row + 1, col};
            if (row <= rCenter && row > 0)        res[r++] = {row - 1, col};

            if (col == max_col && col + 1 < cols) res[r++] = {row, ++max_col};
            if (col == min_col && col > 0)        res[r++] = {row, --min_col};
        }

        return res;
    }
};