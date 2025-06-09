// https://leetcode.com/problems/walking-robot-simulation
// 2024/09/05

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        const int8_t x_dir[] = {0, 1, 0, -1};
        const int8_t y_dir[] = {1, 0, -1, 0};
        int8_t dir = 0;
        
        unordered_set<int64_t> set;
        for (const vector<int>& o : obstacles) {
            set.emplace((int64_t{o[0]} << 32) + o[1]);
        }

        int64_t x = 0, y = 0;

        int max_dist = 0;
        for (const int c : commands) {
            if (c == -1) {
                dir = (dir + 1) % 4;
                continue;
            }

            if (c == -2) {
                dir = (dir + 3) % 4;
                continue;
            }

            for (int8_t k = 0; k < c; ++k) {
                if (set.count((x + x_dir[dir] << 32) + y + y_dir[dir])) {
                    break;
                }

                x += x_dir[dir];
                y += y_dir[dir];
            }

            max_dist = max(max_dist, (int) (x * x + y * y));
        }

        return max_dist;
    }
};