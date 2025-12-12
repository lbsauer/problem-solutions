// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones
// 2025/11/22

class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};