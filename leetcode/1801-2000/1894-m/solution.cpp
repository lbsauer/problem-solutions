// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk
// 2024/09/01

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int total = k % accumulate(chalk.begin(), chalk.end(), uint64_t{});

        int pos = 0;
        for (; pos < chalk.size(); ++pos) {
            if (total < chalk[pos]) break;

            total -= chalk[pos];
        }

        return pos;
    }
};