// https://leetcode.com/problems/maximum-total-reward-using-operations-i
// 2024/08/19

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        const auto end = unique(rewardValues.begin(), rewardValues.end()) - 1;

        if (rewardValues.begin() == end) {
            return rewardValues.front();
        }

        vector<bool> seen(*end);

        auto it = rewardValues.begin();
        for (int i = 1; i < *end && !seen.back() && it != end; ++i) {
            if (!seen[i] && i < *it) continue;

            if (i == *it) {
                seen[i] = true;
                ++it;
            }

            for (auto nit = it; nit != end; ++nit) {
                if (i + *nit >= *end) break;

                seen[i + *nit] = true;
            }
        }

        return *end + distance(find(seen.rbegin(), seen.rend(), true), seen.rend()) - 1;
    }
};