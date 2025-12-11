// https://leetcode.com/problems/find-and-replace-pattern
// 2025/08/23

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (const string& word : words) {
            char w[26]{}, p[26]{};
            for (int i = 0; i < pattern.size(); ++i) {
                w[word[i] - 'a'] = pattern[i];
                p[pattern[i] - 'a'] = word[i];
            }

            bool match = true;
            for (int i = 0; i < pattern.size() && match; ++i) {
                match = w[word[i] - 'a'] == pattern[i] && p[pattern[i] - 'a'] == word[i];
            }

            if (match) res.push_back(word);
        }

        return res;
    }
};