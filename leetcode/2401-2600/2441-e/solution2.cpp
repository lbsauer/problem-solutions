class Solution {
public:
    int findMaxK(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](auto lhs, auto rhs) -> bool {
            return abs(lhs) < abs(rhs);
        });

        for (int i = nums.size() - 1; i > 0; --i) {
            if (-nums[i] == nums[i - 1]) {
                return abs(nums[i]);
            }
        }

        return -1;
    }
};