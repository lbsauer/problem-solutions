// https://leetcode.com/problems/sliding-puzzle
// 2025/05/17

class Solution {
    int pack(const vector<vector<int>>& v) {
        int pack = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                pack <<= 3;
                pack |= v[i][j];
            }
        }

        return pack;
    }

    pair<int, int> unpack(vector<vector<int>>& v, int pack) {
        pair<int, int> pos;
        for (int i = 1; i >= 0; --i) {
            for (int j = 2; j >= 0; --j) {
                if ((pack & 7) == 0) pos = {i, j};

                v[i][j] = pack & 7;
                pack >>= 3;
            }
        }

        return pos;
    }

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        constexpr static pair<int, int> directions[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        const static int target = pack({{1, 2, 3}, {4, 5, 0}});
        if (pack(board) == target) return 0;
        
        unordered_set<int> seen;

        int depth = 0;

        deque<int> q{pack(board)};
        while (!q.empty() && !seen.contains(target)) {
            for (int count = q.size(); count > 0; --count) {
                const int curr = q.front();
                q.pop_front();

                const auto [row, col] = unpack(board, curr);

                for (const auto [dr, dc] : directions) {
                    if (row + dr < 0 || row + dr >= 2 || col + dc < 0 || col + dc >= 3) continue;

                    swap(board[row][col], board[row + dr][col + dc]);

                    const int next = pack(board);
                    if (!seen.contains(next)) {
                        seen.insert(next);
                        q.push_back(next);
                    }

                    swap(board[row][col], board[row + dr][col + dc]);
                }
            }

            ++depth;
        }

        return seen.contains(target) ? depth : -1;
    }
};