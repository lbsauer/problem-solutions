// https://leetcode.com/problems/sort-the-jumbled-numbers
// 2024/07/24

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> map(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            int mapped = mapping[nums[i] % 10];
            for (int j = 10, n = nums[i] / 10; n > 0; j *= 10) {
                mapped += mapping[n % 10] * j;
                n /= 10;
            }

            map[i] = make_pair(mapped, nums[i]);
        }

        stable_sort(map.begin(), map.end(), [&](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.first < rhs.first;
        });

        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = map[i].second;
        }

        return nums;
    }
};