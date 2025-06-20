class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const auto end = unique(nums.begin(), nums.end());

        const auto comp = [](const int lhs, const int rhs) { return abs(lhs) < abs(rhs); };

        const int root = sqrt(nums.back());

        int longest = 0;
        for (auto it = nums.begin(); it != end && abs(*it) <= root; ++it) {
            if (*it <= 0) continue;

            auto nit = it;
            for (int i = *it, length = 1; i <= root; i *= i) {
                nit = lower_bound(next(nit), end, i * i, comp);
                if (nit == end || *nit != i * i) break;

                longest = max(longest, ++length);
                *nit = -*nit;
            }
        }

        return longest < 2 ? -1 : longest;
    }
};