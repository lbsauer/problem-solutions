// https://leetcode.com/problems/maximum-matrix-sum
// 2026/01/06

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        
        int min_e = INT_MAX, neg = 0;
        for (const auto& row : matrix) {
            for (const int n : row) {
                neg += n < 0;
                sum += abs(n);
                min_e = min(min_e, abs(n));
            }
        }

        return sum - min_e * ((neg & 1) << 1);
    }
};