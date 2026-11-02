// https://leetcode.com/problems/find-the-original-array-of-prefix-xor
// 2026/05/27

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> arr(pref.size());
        for (int i = 0, x = 0; i < pref.size(); ++i) {
            arr[i] = x ^ pref[i];
            x ^= arr[i];
        }

        return arr;
    }
};