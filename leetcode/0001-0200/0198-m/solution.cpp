// https://leetcode.com/problems/house-robber
// 2025/06/03

class Solution {
public:
    int rob(vector<int>& nums) {        
        int back1 = 0, back2 = 0;
        for (const int n : nums) {
            back2 = max(back2 + n, back1);
            swap(back1, back2);
        }

        return back1;
    }
};