// https://leetcode.com/problems/longest-chunked-palindrome-decomposition
// 2025/10/09

class Solution {
public:
    int longestDecomposition(string text) {
        int k = 0;

        string pre, suf;
        for (int l = 0, r = text.size() - 1; l <= r; ++l, --r) {
            pre.push_back(text[l]);
            suf.push_back(text[r]);

            if (equal(pre.begin(), pre.end(), suf.rbegin())) {
                k += 1 + (l != r);
                pre.clear();
                suf.clear();
            }
        }

        return k + !pre.empty();
    }
};