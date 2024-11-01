// https://leetcode.com/problems/k-th-nearest-obstacle-queries
// 2024/09/01

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> res;
        res.reserve(queries.size());

        priority_queue<int> pq;
        for (const vector<int>& q : queries) {
            pq.push(abs(q[0]) + abs(q[1]));

            if (pq.size() > k) pq.pop();

            res.push_back(pq.size() == k ? pq.top() : -1);
        }

        return res;
    }
};