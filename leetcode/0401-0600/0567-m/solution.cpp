// https://leetcode.com/problems/permutation-in-string
// 2024/10/05

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;
        
        int count1[26] = {0};
        for (const char c : s1) {
            ++count1[c - 'a'];
        }

        int count2[26] = {0};
        for (int i = 0; i < s1.size(); ++i) {
            ++count2[s2[i] - 'a'];
        }

        for (int i = s1.size(); i < s2.size(); ++i) {
            if (equal(begin(count1), end(count1), begin(count2))) {
                return true;
            }

            --count2[s2[i - s1.size()] - 'a'];
            ++count2[s2[i] - 'a'];
        }

        return equal(begin(count1), end(count1), begin(count2));
    }
};