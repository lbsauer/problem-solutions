// https://leetcode.com/problems/maximum-number-of-removable-characters
// 2024/08/16

class Solution {
public:
    bool is_subsequence(const string& s, const string& p, const vector<bool>& mask) {
        int count = 0;
        for (int i = 0, j = 0; i < s.size() && j < p.size(); ++i) {
            if (mask[i]) continue;

            count += s[i] == p[j];
            j += s[i] == p[j];
        }

        return count == p.size();
    }
    
    int maximumRemovals(string s, string p, vector<int>& removable) {
        vector<bool> mask(s.size());

        int l = 0;
        int r = removable.size() - 1;
        while (l <= r) {
            int middle = l + (r - l) / 2;

            for (int i = l; i <= middle; ++i) {
                mask[removable[i]] = true;
            }

            if (is_subsequence(s, p, mask)) {
                l = middle + 1;
            } else {
                for (int i = l; i <= middle; ++i) {
                    mask[removable[i]] = false;
                }

                r = middle - 1;
            }
        }

        return l;
    }
};