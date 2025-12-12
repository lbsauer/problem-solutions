// https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations
// 2025/12/10

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        long long fat = 1;
        for (int i = 1; i < complexity.size(); ++i) {
            if (complexity[i] <= complexity[0]) return 0;
            fat = (fat * i) % 1'000'000'007;
        }

        return fat;
    }
};