// https://leetcode.com/problems/dungeon-game
// 2025/05/13

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int m = dungeon.size(), n = dungeon.front().size();
        
        dungeon[m - 1][n - 1] = max(-dungeon[m - 1][n - 1], 0);
        
        for (int i = n - 2; i >= 0; --i) {
            dungeon[m - 1][i] = max(dungeon[m - 1][i + 1] - dungeon[m - 1][i], 0);
        }

        for (int i = m - 2; i >= 0; --i) {
            dungeon[i][n - 1] = max(dungeon[i + 1][n - 1] - dungeon[i][n - 1], 0);

            for (int j = n - 2; j >= 0; --j) {
                dungeon[i][j] = max(min(dungeon[i + 1][j], dungeon[i][j + 1]) - dungeon[i][j], 0);
            }
        }

        return dungeon[0][0] + 1;
    }
};