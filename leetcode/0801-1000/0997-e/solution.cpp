// https://leetcode.com/problems/find-the-town-judge
// 2025/06/09

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trust_count(n);
        for (const auto& t : trust) {
            --trust_count[t[0] - 1];
            ++trust_count[t[1] - 1];
        }

        for (int i = 0; i < n; ++i) {
            if (trust_count[i] == n - 1) return i + 1;
        }

        return -1;
    }
};