// https://leetcode.com/problems/remove-element
// 2025/06/09

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
    }
};