// https://leetcode.com/problems/convert-1d-array-into-2d-array
// 2024/09/01

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) return {};

        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < original.size(); ++i) {
            res[i / n][i % n] = original[i];
        }

        return res;
    }
};