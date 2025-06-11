// https://leetcode.com/problems/count-complete-subarrays-in-an-array
// 2025/04/24

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (const int n : nums) {
            ++freq[n];
        }

        const int distinct_count = freq.size();
        freq.clear();

        int count = 0;
        for (int l = 0, r = 0, distinct = 0; r < nums.size(); ++r) {
            distinct += ++freq[nums[r]] == 1;

            while (distinct == distinct_count) {
                distinct -= --freq[nums[l++]] == 0;
                count += nums.size() - r;
            }
        }

        return count;
    }
};