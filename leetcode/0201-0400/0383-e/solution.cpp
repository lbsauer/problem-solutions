// https://leetcode.com/problems/ransom-note
// 2024/08/25

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (magazine.size() < ransomNote.size()) return false;
        
        int count[26] = {0};
        for (const char c : magazine) {
            ++count[c - 'a'];
        }

        for (const char c : ransomNote) {
            if (count[c - 'a'] == 0) return false;

            --count[c - 'a'];
        }

        return true;
    }
};