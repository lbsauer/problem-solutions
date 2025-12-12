// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers
// 2025/11/14

class Solution {
public:
    int minPartitions(string n) {
        return *max_element(n.begin(), n.end()) - '0';
    }
};