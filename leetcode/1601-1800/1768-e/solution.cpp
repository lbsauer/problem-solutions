// https://leetcode.com/problems/merge-strings-alternately
// 2025/08/18

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged;
        for (const auto [c1, c2] : views::zip(word1, word2)) {
            merged.append({c1, c2});
        }

        if (word1.size() != word2.size()) {
            if (word1.size() < word2.size()) swap(word1, word2);
            merged.append(word1.substr(merged.size() / 2));
        }

        return merged;
    }
};