// https://leetcode.com/problems/count-days-without-meetings
// 2025/03/23

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](const auto& lhs, const auto& rhs) { return lhs[0] < rhs[0]; });

        for (int end = 0; const auto& m : meetings) {
            if (m[0] > end) {
                days -= (m[1] - m[0] + 1);
                end = m[1];
            } else if (end < m[1]) {
                days -= (m[1] - end);
                end = m[1];
            }
        }

        return days;
    }
};