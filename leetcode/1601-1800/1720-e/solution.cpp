// https://leetcode.com/problems/decode-xored-array
// 2025/06/13

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        for (int& n : encoded) {
            first ^= n;
            n ^= first;
        }

        encoded.push_back(first);

        return encoded;
    }
};