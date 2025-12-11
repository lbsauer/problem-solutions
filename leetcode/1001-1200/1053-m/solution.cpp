// https://leetcode.com/problems/previous-permutation-with-one-swap
// 2025/10/10

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int i = arr.size() - 2;
        while (i >= 0 && arr[i] <= arr[i + 1]) --i;

        if (i < 0) return arr;

        int j = arr.size() - 1;
        while (arr[j] >= arr[i] || arr[j] == arr[j - 1]) --j;

        swap(arr[i], arr[j]);

        return arr;
    }
};