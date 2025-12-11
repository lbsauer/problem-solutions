// https://leetcode.com/problems/student-attendance-record-i
// 2025/08/18

class Solution {
public:
    bool checkRecord(string s) {
        return count(s.begin(), s.end(), 'A') < 2 && s.find("LLL") == string::npos;
    }
};