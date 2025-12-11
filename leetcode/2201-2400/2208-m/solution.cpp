// https://leetcode.com/problems/minimum-operations-to-halve-array-sum
// 2025/08/29

class Solution {
public:
    int halveArray(vector<int>& nums) {
        const long long sum = accumulate(nums.begin(), nums.end(), 0ll);

        priority_queue<double> pq(nums.begin(), nums.end());

        int count = 0;
        for (double curr = sum; curr * 2 > sum; ++count) {
            const double d = pq.top();
            pq.pop();

            curr -= d / 2;
            pq.push(d / 2);
        }

        return count;
    }
};