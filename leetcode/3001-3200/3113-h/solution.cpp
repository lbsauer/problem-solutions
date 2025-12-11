// https://leetcode.com/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum
// 2025/10/10

class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        stack<pair<int, int>, vector<pair<int, int>>> s;

        long long count = 0;
        for (const int n : nums) {
            while (!s.empty() && n > s.top().first) {
                s.pop();
            }

            if (s.empty() || n != s.top().first) {
                s.emplace(n, 0);
            }

            count += ++s.top().second;
        }

        return count;
    }
};