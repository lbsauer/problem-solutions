// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits
// 2026/02/24

class Solution {
    int popcount(int x) {
        return bitset<32>(x).count();
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](const int lhs, const int rhs) {
            return popcount(lhs) == popcount(rhs) ? lhs < rhs : popcount(lhs) < popcount(rhs);
        });

        return arr;
    }
};