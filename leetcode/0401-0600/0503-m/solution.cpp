// https://leetcode.com/problems/next-greater-element-ii
// 2025/08/13

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        
        stack<int, vector<int>> s;
        for (int i = 0, n = nums.size(); i < n * 2; ++i) {
            while (!s.empty() && nums[s.top()] < nums[i % n]) {
                res[s.top()] = nums[i % n];
                s.pop();
            }

            s.push(i % n);
        }

        return res;
    }
};