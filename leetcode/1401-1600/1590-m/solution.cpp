// https://leetcode.com/problems/make-sum-divisible-by-p
// 2025/11/29

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int mod = 0;
        for (const int n : nums) {
            mod = (mod + n) % p;
        }

        if (mod == 0) return 0;

        unordered_map<int, int> pos{{0, -1}};

        int res = nums.size();
        for (int i = 0, x = 0; i < nums.size(); ++i) {
            x = (x + nums[i]) % p;

            const auto it = pos.find((x - mod + p) % p);
            if (it != pos.end()) {
                res = min(res, i - it->second);
            }

            pos[x] = i;
        }

        return res == nums.size() ? -1 : res;
    }
};