// https://leetcode.com/problems/sum-of-even-numbers-after-queries
// 2024/10/23

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = accumulate(nums.begin(), nums.end(), 0, [](const int acc, const int n) {
            return acc + (n % 2 == 0 ? n : 0);
        });

        vector<int> res(queries.size());
        for (int i = 0; const auto& q : queries) {
            sum -= nums[q[1]] % 2 == 0 ? nums[q[1]] : 0;
            nums[q[1]] += q[0];
            sum += nums[q[1]] % 2 == 0 ? nums[q[1]] : 0;

            res[i++] = sum;
        }

        return res;
    }
};