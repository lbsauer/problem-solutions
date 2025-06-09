// https://leetcode.com/problems/climbing-stairs
// 2024/08/14

class Solution {
public:
    int climbStairs(int n) {
        int p = 0;
        int pp = 1;
        
        for (int i = 0; i < n; ++i) {
            swap(p, pp);
            pp += p;
        }

        return pp;
    }
};