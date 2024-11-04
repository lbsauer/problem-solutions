// https://leetcode.com/problems/string-compression-iii
// 2024-11-03

class Solution {
public:
    string compressedString(string word) {
        string res;
        
        for (auto it = word.begin(); it != word.end();) {
            auto it2 = find_if(it + 1, word.end(), [it](char c) { return c != *it; });

            for (int count = distance(it, it2); count > 0; count -= 9) {
                res += min(count, 9) + '0';
                res += *it;
            }

            it = it2;
        }

        return res;
    }
};