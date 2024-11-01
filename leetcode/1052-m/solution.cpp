// https://leetcode.com/problems/grumpy-bookstore-owner
// 2024/06/21

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int count = 0;
        for (int i = 0; i < customers.size(); ++i) {
            count += grumpy[i] ? 0 : customers[i];
        }

        int max_diff = 0;
        for (int i = 0; i < minutes; ++i) {
            max_diff += grumpy[i] ? customers[i] : 0;
        }

        int diff = max_diff;
        for (int i = minutes; i < customers.size(); ++i) {
            diff -= grumpy[i - minutes] ? customers[i - minutes] : 0;
            diff += grumpy[i] * customers[i];

            max_diff = std::max(max_diff, diff);
        }

        return count + max_diff;
    }
};