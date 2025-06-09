// https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections
// 2025/03/25

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        sort(rectangles.begin(), rectangles.end(), [](const auto& lhs, const auto& rhs) { return lhs[0] < rhs[0]; });

        int count = 0;
        int end = rectangles[0][2];

        for (int i = 1; i < rectangles.size() && count < 2; ++i) {
            count += rectangles[i][0] >= end;
            end = max(end, rectangles[i][2]);
        }

        if (count == 2) return true;

        sort(rectangles.begin(), rectangles.end(), [](const auto& lhs, const auto& rhs) { return lhs[1] < rhs[1]; });

        count = 0;
        end = rectangles[0][3];

        for (int i = 1; i < rectangles.size() && count < 2; ++i) {
            count += rectangles[i][1] >= end;
            end = max(end, rectangles[i][3]);
        }

        return count == 2;
    }
};