// https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle
// 2025/08/26

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_diag = 0, max_area = 0;
        for (const auto& d : dimensions) {
            const int diag = d[0] * d[0] + d[1] * d[1];
            if (diag > max_diag) {
                max_diag = diag;
                max_area = d[0] * d[1];
            } else if (diag == max_diag) {
                max_area = max(max_area, d[0] * d[1]);
            }
        }

        return max_area;
    }
};