// https://leetcode.com/problems/unique-length-3-palindromic-subsequences
// 2025/11/20

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int min_pos[26]{}, max_pos[26]{};
        for (int i = 0; i < s.size(); ++i) {
            if (min_pos[s[i] - 'a'] == 0) {
                min_pos[s[i] - 'a'] = i + 1;
            }
            max_pos[s[i] - 'a'] = i;
        }

        int count = 0;
        for (int i = 0; i < 26; ++i) {
            int mask = 0;
            for (int j = min_pos[i]; j < max_pos[i]; ++j) {
                mask |= 1 << (s[j] - 'a');
            }

            count += bitset<32>(mask).count();
        }

        return count;
    }
};