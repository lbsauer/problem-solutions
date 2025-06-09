// https://leetcode.com/problems/relative-ranks
// 2024/05/07

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        std::vector<std::string> res(score.size());
        std::vector<int> sorted(score.size());

        for (int i = 0; i < score.size(); ++i) {
            sorted[i] = i;
        }

        std::sort(sorted.begin(), sorted.end(), [&score](int lhs, int rhs) {
            return score[lhs] > score[rhs];
        });

        int i = 0;

        if (i < score.size()) {
            res[sorted[i++]] = "Gold Medal";
        }

        if (i < score.size()) {
            res[sorted[i++]] = "Silver Medal";
        }

        if (i < score.size()) {
            res[sorted[i++]] = "Bronze Medal";
        }

        for (int n = 4; i < score.size(); ++n) {
            res[sorted[i++]] = std::to_string(n);
        }

        return res;
    }
};