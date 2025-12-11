// https://leetcode.com/problems/find-all-k-distant-indices-in-an-array
// 2025/06/23

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> indices;
        for (int i = 0, j = 0; i < nums.size() && j < nums.size(); ++i) {
            while (j < nums.size() && nums[j] != key) ++j;

            if (abs(j - i) <= k && j < nums.size()) indices.push_back(i);

            j += i - j == k;
        }

        return indices;
    }
};