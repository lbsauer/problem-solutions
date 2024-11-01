// https://leetcode.com/problems/average-waiting-time
// 2024/08/07

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double avg = 0;
        int last = 0;

        for (int i = 0; i < customers.size(); ++i) {
            last = max(last, customers[i][0]) + customers[i][1];
            avg += last - customers[i][0];
        }

        return avg / customers.size();
    }
};