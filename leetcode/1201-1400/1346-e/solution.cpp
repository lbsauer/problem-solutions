// https://leetcode.com/problems/check-if-n-and-its-double-exist
// 2024/07/31

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;

        for (const int i : arr) {
            if (seen.count(2 * i) || (i % 2 == 0 && seen.count(i >> 1))) {
                return true;
            }

            seen.insert(i);
        }

        return false;
    }
};