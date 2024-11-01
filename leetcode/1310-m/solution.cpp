// https://leetcode.com/problems/xor-queries-of-a-subarray
// 2024-09-13

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for (int i = 1; i < arr.size(); ++i) {
            arr[i] ^= arr[i - 1];
        }

        vector<int> res;
        res.reserve(queries.size());

        for (const vector<int>& q : queries) {
            res.push_back(q[0] == 0 ? arr[q[1]] : arr[q[0] - 1] ^ arr[q[1]]);
        }

        return res;
    }
};