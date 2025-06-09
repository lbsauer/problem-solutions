// https://leetcode.com/problems/most-beautiful-item-for-each-query
// 2024/11/11

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), [](const auto& lhs, const auto& rhs) { return lhs[0] < rhs[0]; });

        vector<reference_wrapper<int>> sorted(queries.size(), ref(queries.front()));
        transform(queries.begin(), queries.end(), sorted.begin(), [](int& q) { return ref(q); });

        sort(sorted.begin(), sorted.end(), [](const int& lhs, const int& rhs) { return lhs < rhs; });

        int max_beauty = 0;
        for (auto it = items.begin(); int& i : sorted) {
            for (; it != items.end() && it->front() <= i; ++it) {
                max_beauty = max(max_beauty, it->back());
            }

            i = max_beauty;
        }

        return queries;
    }
};