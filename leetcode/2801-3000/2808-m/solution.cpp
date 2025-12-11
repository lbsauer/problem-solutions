// https://leetcode.com/problems/minimum-seconds-to-equalize-a-circular-array
// 2025/08/22

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < nums.size(); ++i) {
            pos[nums[i]].push_back(i);
        }

        int min_time = INT_MAX;
        for (const auto& [_, v] : pos) {
            int max_gap = nums.size() - v.back() + v.front();
            for (int i = 1; i < v.size(); ++i) {
                max_gap = max(max_gap, v[i] - v[i - 1]);
            }

            min_time = min(min_time, max_gap / 2);
        }

        return min_time;
    }
};