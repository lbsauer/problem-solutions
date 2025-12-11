// https://leetcode.com/problems/final-value-of-variable-after-performing-operations
// 2025/09/20

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (const string& op : operations) {
            x += op[1] == '+';
        }

        return x * 2 - operations.size();
    }
};