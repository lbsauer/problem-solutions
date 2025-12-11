// https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number
// 2025/10/15

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        return num % 3 == 0 ? vector<long long>{num / 3 - 1, num / 3, num / 3 + 1} : vector<long long>{};
    }
};