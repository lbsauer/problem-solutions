// https://leetcode.com/problems/merge-intervals
// 2024/11/14

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& lhs, const auto& rhs) {
            return lhs[0] < rhs[0];
        });

        int l = 0;
        for (int r = 0; r < intervals.size(); ++r) {
            if (intervals[r][0] <= intervals[l][1]) {
                intervals[l][1] = max(intervals[l][1], intervals[r][1]);
            } else {
                swap(intervals[++l], intervals[r]);
            }
        }

        intervals.resize(l + 1);

        return intervals;
    }
};