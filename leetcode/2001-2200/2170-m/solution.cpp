// https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating
// 2025/08/01

class Solution {
    tuple<int, int, int> most_freq(const vector<int>& nums, unordered_map<int, int>& freq, bool odd) {
        int max1{}, max2{}, f1{}, f2{};
        for (int i = odd; i < nums.size(); i += 2) {
            const int f = ++freq[nums[i]];
            if (f > f1) {
                f2 = max1 == nums[i] ? f2 : f1;
                max2 = max1 == nums[i] ? max2 : max1;
                f1 = f;
                max1 = nums[i];
            } else if (f > f2) {
                f2 = f;
                max2 = nums[i];
            }
        }

        return {max1, f1, f2};
    }

public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        const auto [max_even, e_f1, e_f2] = most_freq(nums, freq, false);

        freq.clear();
        const auto [max_odd, o_f1, o_f2] = most_freq(nums, freq, true);

        return nums.size() - (max_even == max_odd ? max(e_f1 + o_f2, o_f1 + e_f2) : e_f1 + o_f1);
    }
};