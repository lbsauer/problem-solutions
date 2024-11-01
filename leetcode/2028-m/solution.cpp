// https://leetcode.com/problems/find-missing-observations
// 2024/09/05

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        const int target_sum = mean * (n + rolls.size());
        const int sum = accumulate(rolls.begin(), rolls.end(), 0);

        if (target_sum < (sum + n) || target_sum > (sum + 6 * n)) {
            return {};
        }

        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = min(6, (target_sum - sum) - (n - i - 1));
            sum += res[i];
        }

        return res;
    }
};