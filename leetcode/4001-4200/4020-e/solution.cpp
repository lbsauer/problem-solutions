// https://leetcode.com/problems/elevator-requests-i
// 2026/08/16

class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int floor = 0, time = 0;
        for (const int r : requests) {
            time += abs(r - floor);
            floor = r;
        }

        return time;
    }
};