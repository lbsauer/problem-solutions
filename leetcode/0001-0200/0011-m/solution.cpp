// https://leetcode.com/problems/container-with-most-water
// 2025/07/31

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        for (int l = 0, r = height.size() - 1; l < r; ++l) {
            while (l < r && height[r] < height[l]) {
                max_area = max(max_area, height[r] * (r-- - l));
            }

            max_area = max(max_area, height[l] * (r - l));
        }

        return max_area;
    }
};