// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k
// 2025/06/21

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> groups((s.size() + k - 1) / k);
        for (int i = 0, j = 0; j < groups.size(); i += k, ++j) {
            groups[j] = s.substr(i, k);
        }

        groups.back().resize(k, fill);

        return groups;
    }
};