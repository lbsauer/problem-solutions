// https://leetcode.com/problems/maximum-distance-in-arrays
// 2024/08/17

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min = arrays.begin()->front();
        int max = arrays.begin()->back();

        int max_dist = 0;
        for (int i = 1; i < arrays.size(); ++i) {
            max_dist = std::max(max_dist, abs(arrays[i].back() - min));
            max_dist = std::max(max_dist, abs(arrays[i].front() - max));
            
            min = std::min(min, arrays[i].front());
            max = std::max(max, arrays[i].back());
        }

        return max_dist;
    }
};