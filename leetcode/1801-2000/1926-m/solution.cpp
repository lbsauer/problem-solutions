// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze
// 2025/08/23

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        constexpr static pair<int, int> directions[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        const int m = maze.size(), n = maze[0].size();

        maze[entrance[0]][entrance[1]] = '+';

        deque<pair<int, int>> q{{entrance[0], entrance[1]}};
        for (int steps = 1; !q.empty(); ++steps) {
            for (int i = q.size(); i > 0; --i) {
                const auto [row, col] = q.front();
                q.pop_front();

                for (const auto [dr, dc] : directions) {
                    if (
                        row + dr < 0 || row + dr >= m ||
                        col + dc < 0 || col + dc >= n ||
                        maze[row + dr][col + dc] == '+'
                    ) {
                        continue;
                    }

                    if (
                        row + dr == 0 || row + dr == m - 1 ||
                        col + dc == 0 || col + dc == n - 1
                    ) {
                        return steps;
                    }

                    maze[row + dr][col + dc] = '+';
                    q.emplace_back(row + dr, col + dc);
                }
            }
        }

        return -1;
    }
};