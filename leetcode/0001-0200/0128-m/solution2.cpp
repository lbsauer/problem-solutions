class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const auto end = unique(nums.begin(), nums.end());

        int max_length = 0;
        for (auto it = nums.begin(), it2 = nums.begin(); it != end; it = it2) {
            while (++it2 != end) {
                if (*it2 - *(it2 - 1) != 1) break;
            }

            max_length = max(max_length, (int) distance(it, it2));
        }

        return max_length;
    }
};