// https://leetcode.com/problems/shortest-distance-after-road-addition-queries-ii
// 2024/11/13

class Solution {
    struct Node {
        int val = 0;
        Node* next;
    };

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<Node> nodes(n);
        for (int i = 1; i < n; ++i) {
            nodes[i].val = i;
            nodes[i - 1].next = &nodes[i];
        }

        vector<int> res(queries.size());

        for (auto it = res.begin(); const auto& q : queries) {
            if (nodes[q[0]].val != INT_MAX) {
                Node* curr = nodes[q[0]].next;

                while (curr->val < q[1]) {
                    curr->val = INT_MAX;
                    curr = curr->next;
                    --n;
                }

                nodes[q[0]].next = curr;
            }

            *it++ = n - 1;
        }

        return res;
    }
};