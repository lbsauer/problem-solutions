// https://leetcode.com/problems/find-good-days-to-rob-the-bank
// 2024/10/31

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        if (time == 0) {
            vector<int> res(security.size());
            iota(res.begin(), res.end(), 0);
            return res;
        }

        if (time * 2 >= security.size()) return {};

        vector<int> decreasing(security.size());
        for (int i = 1; i < security.size() - time; ++i) {
            if (security[i] <= security[i - 1]) {
                decreasing[i] = decreasing[i - 1] + 1;
            }
        }

        vector<int> res;
        for (int i = security.size() - 2, increasing = 0; i >= time; --i) {
            if (security[i] <= security[i + 1]) {
                ++increasing;
            } else {
                increasing = 0;
            }

            if (increasing >= time && decreasing[i] >= time) {
                res.push_back(i);
            }
        }

        return res;
    }
};