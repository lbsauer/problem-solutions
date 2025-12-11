// https://leetcode.com/problems/truncate-sentence
// 2025/08/22

class Solution {
public:
    string truncateSentence(string s, int k) {
        int pos = 0;
        for (; k > 0 && pos < s.size(); ++pos) {
            k -= s[pos] == ' ';
        }

        return s.substr(0, pos - (pos != s.size()));
    }
};