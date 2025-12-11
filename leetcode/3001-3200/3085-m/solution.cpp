// https://leetcode.com/problems/minimum-deletions-to-make-string-k-special
// 2025/06/20

class Solution {
public:
    int minimumDeletions(string word, int k) {
        int freq[26]{};
        for (const char c : word) {
            ++freq[c - 'a'];
        }

        int min_count = word.size();
        for (const int f : freq) {
            if (f == 0) continue;

            int count = 0;
            for (const int f2 : freq) {
                count += f <= f2 ? max(0, f2 - f - k) : f2;
            }

            min_count = min(min_count, count);
        }

        return min_count;
    }
};