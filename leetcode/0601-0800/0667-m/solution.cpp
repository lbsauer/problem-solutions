// https://leetcode.com/problems/beautiful-arrangement-ii
// 2025/08/08

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> v(n);

        for (int i = 0, j = 1; i < k; i += 2) {
            v[i] = j++;
        }
        
        for (int i = 1, j = n; i < k; i += 2) {
            v[i] = j--;
        }

        if (k % 2 == 0) {
            iota(v.rbegin(), next(v.rbegin(), n - k), k / 2 + 1);
        } else {
            iota(next(v.begin(), k), v.end(), k / 2 + 2);
        }

        return v;
    }
};