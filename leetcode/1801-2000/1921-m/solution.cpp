// https://leetcode.com/problems/eliminate-maximum-number-of-monsters
// 2025/09/20

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> arrival(dist.size());
        for (int i = 0; i < dist.size(); ++i) {
            arrival[i] = (dist[i] + speed[i] - 1) / speed[i];
        }

        sort(arrival.begin(), arrival.end());

        int count = 0;
        for (int i = 0; i < arrival.size() && count == i; ++i) {
            count += arrival[i] > i;
        }

        return count;
    }
};