// https://leetcode.com/problems/count-pairs-that-form-a-complete-day-ii
// 2025/08/29

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long freq[24]{};
        for (const int h : hours) {
            ++freq[h % 24];
        }

        long long count = freq[0] * (freq[0] - 1) / 2 + freq[12] * (freq[12] - 1) / 2;
        for (int i = 1; i <= 11; ++i) {
            count += freq[i] * freq[24 - i];
        }

        return count;
    }
};