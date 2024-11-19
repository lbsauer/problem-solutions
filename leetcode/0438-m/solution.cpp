// https://leetcode.com/problems/find-all-anagrams-in-a-string
// 2024-11-16

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};
        
        int count[26] = {0};
        for (int i = 0; i < p.size() - 1; ++i) {
            ++count[s[i] - 'a'];
            --count[p[i] - 'a'];
        }
        --count[p.back() - 'a'];

        vector<int> res;
        for (int i = p.size() -1; i < s.size(); ++i) {
            ++count[s[i] - 'a'];

            if (all_of(begin(count), end(count), [](int c) { return c == 0; })) {
                res.push_back(i + 1 - p.size());
            }

            --count[s[i + 1 - p.size()] - 'a'];
        }

        return res;
    }
};