// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k
// 2026/02/22

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        const int mask = (1 << k) - 1;
        if (s.size() < mask + k) return false;

        int curr = 0;
        for (int i = 0; i < k - 1; ++i) {
            curr = (curr << 1) | (s[i] == '1');
        }

        vector<bool> seen(mask + 1);
        for (int i = k - 1; i < s.size(); ++i) {
            curr = ((curr << 1) & mask) | (s[i] == '1');
            seen[curr] = true;
        }

        return all_of(seen.begin(), seen.end(), [](bool b) { return b; });
    }
};