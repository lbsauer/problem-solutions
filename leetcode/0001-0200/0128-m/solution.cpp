// https://leetcode.com/problems/longest-consecutive-sequence
// 2024/08/15

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set{nums.begin(), nums.end()};

        int max_length = 0;
        for (const int i : set) {
            if (set.count(i - 1)) continue;

            int j = i + 1;
            while (set.count(j++));

            max_length = max(max_length, j - i - 1);
        }

        return max_length;
    }
};