// https://leetcode.com/problems/zero-array-transformation-i
// 2025/05/21

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> count(nums.size() + 1);
        for (const auto& q : queries) {
            ++count[q[0]];
            --count[q[1] + 1];
        }

        int curr = 0;
        for (int i = 0; i < nums.size(); ++i) {
            curr += count[i];
            
            if (curr < nums[i]) return false;
        }

        return true;
    }
};