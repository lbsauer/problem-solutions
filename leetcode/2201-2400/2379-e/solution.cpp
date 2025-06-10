// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks
// 2025/03/07

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int min_count = count(blocks.begin(), next(blocks.begin(), k), 'W');

        for (int i = k, count = min_count; i != blocks.size(); ++i) {
            count += blocks[i] == 'W';
            count -= blocks[i - k] == 'W';

            min_count = min(min_count, count);
        }

        return min_count;
    }
};