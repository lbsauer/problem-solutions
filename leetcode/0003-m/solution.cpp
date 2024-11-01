// https://leetcode.com/problems/longest-substring-without-repeating-characters
// 2024/08/12

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> seen(128);

        int max_length = 0;
        for (int l = 0, r = 0; r < s.length(); ++r) {
            if (!seen[s[r]]) {
                max_length = max(max_length, r - l + 1);
            } else {
                while (seen[s[r]]) {
                    seen[s[l++]] = false;
                }
            }

            seen[s[r]] = true;
        }

        return max_length;
    }
};