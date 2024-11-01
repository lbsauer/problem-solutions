// https://leetcode.com/problems/maximize-happiness-of-selected-children
// 2024/05/08

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        std::sort(happiness.begin(), happiness.end(), [](int lhs, int rhs) {
            return lhs > rhs;
        });

        long long count = 0;
        for (int i = 0; i < k; ++i) {
            count += std::max(happiness[i] - i, 0);
        }

        return count;
    }
};