// https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps
// 2025/08/03

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int max_fruits = 0;

        int l_dist = max(0, startPos - fruits[0][0]), r_dist = 0;
        for (int l = 0, r = 0, count = 0; r < fruits.size(); ++r) {
            count += fruits[r][1];

            if (fruits[r][0] > startPos) r_dist = fruits[r][0] - startPos;

            while (l < r && min(l_dist * 2 + r_dist, r_dist * 2 + l_dist) > k) {
                count -= fruits[l][1];
                l_dist = max(0, startPos - fruits[++l][0]);
            }

            if (r_dist <= k && l_dist <= k) max_fruits = max(max_fruits, count);
        }

        return max_fruits;
    }
};