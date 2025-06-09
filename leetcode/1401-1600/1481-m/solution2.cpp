// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals
// 2025/03/10

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());

        priority_queue<int, vector<int>, greater<int>> freq;
        for (vector<int>::iterator it = arr.begin(), nit; it != arr.end(); it = nit) {
            nit = find_if(next(it), arr.end(), [&](const int n) { return n != *it; });
            freq.emplace(distance(it, nit));
        }

        int res = freq.size();
        while (k > 0) {
            k -= freq.top();
            freq.pop();
            res -= k >= 0;
        }

        return res;
    }
};