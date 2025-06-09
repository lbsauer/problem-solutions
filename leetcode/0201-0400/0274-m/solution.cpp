// https://leetcode.com/problems/h-index
// 2024/08/21

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int h = 0;
        for (auto it = citations.rbegin(); it != citations.rend(); ++it) {
            if (*it < distance(citations.rbegin(), it) + 1) break;

            h = distance(citations.rbegin(), it) + 1;
        }

        return h;
    }
};