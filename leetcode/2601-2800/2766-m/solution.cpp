// https://leetcode.com/problems/relocate-marbles
// 2026/02/19

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int> set(nums.begin(), nums.end());
        for (int i = 0; i < moveFrom.size(); ++i) {
            set.erase(moveFrom[i]);
            set.insert(moveTo[i]);
        }

        vector<int> res(set.begin(), set.end());
        sort(res.begin(), res.end());

        return res;
    }
};