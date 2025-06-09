// https://leetcode.com/problems/word-subsets
// 2025/01/10

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int count[26], max_count[26] = {0};
        const auto count_freq = [&count, &max_count](const string& s) {
            fill(begin(count), end(count), 0);
            for_each(s.begin(), s.end(), [&](const char c) { ++count[c - 'a']; });
        };

        for (const string& w : words2) {
            count_freq(w);
            transform(begin(count), end(count), begin(max_count), begin(max_count),
                      [](const int lhs, const int rhs) { return max(lhs, rhs); });
        }

        vector<string> subsets;
        copy_if(words1.begin(), words1.end(), back_inserter(subsets), [&](const string& w) {
            count_freq(w);
            return equal(begin(count), end(count), begin(max_count), greater_equal<int>{});
        });

        return subsets;
    }
};