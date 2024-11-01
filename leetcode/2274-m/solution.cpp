// https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors
// 2024/08/17

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());

        int max = std::max(special.front() - bottom, top - special.back());
        for (int i = 1; i < special.size(); ++i) {
            max = std::max(max, special[i] - special[i - 1] - 1);
        }

        return max;
    }
};