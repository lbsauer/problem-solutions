// https://leetcode.com/problems/longest-square-streak-in-an-array
// 2025/06/12

class Solution {
    int square_streak_n(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (const int n : nums) {
            count[n] = 1;
        }

        const int root = sqrt(k);

        int longest = 0;
        for (auto& [n, c] : count) {
            if (n > root || c == 0) continue;

            auto it = count.find(n * n);
            while (it != count.end() && it->second > 0) {
                c += it->second;
                it->second = 0;

                if (it->first <= root) {
                    it = count.find(it->first * it->first);
                }
            }

            longest = max(longest, c);
        }

        return longest < 2 ? -1 : longest;
    }

    int square_streak_k(vector<int>& nums, int k) {
        vector<bool> seen(k + 1);
        for (const int n : nums) {
            seen[n] = true;
        }

        int longest = 0;
        for (int i = 2, root = sqrt(k); i <= root; ++i) {
            for (int j = i, length = seen[i]; j <= root && seen[j * j]; j *= j) {
                longest = max(longest, ++length);
                seen[j * j] = false;
            }
        }

        return longest < 2 ? -1 : longest;
    }

public:
    int longestSquareStreak(vector<int>& nums) {
        const int max = *max_element(nums.begin(), nums.end());
        return max <= nums.size() ? square_streak_k(nums, max) : square_streak_n(nums, max);
    }
};