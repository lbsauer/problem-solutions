// https://leetcode.com/problems/top-k-frequent-elements
// 2024-11-01

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        int max_count = 0;

        for (const int n : nums) {
            max_count = max(max_count, ++counts[n]);
        }

        vector<vector<int>> freq(max_count + 1);
        for (const auto [num, count] : counts) {
            freq[count].push_back(num);
        }

        vector<int> res(k);
        for_each(freq.rbegin(), freq.rend(), [&, it = res.begin()](const auto& v) mutable {
            it = copy(v.begin(), v.begin() + min(v.size(), size_t(distance(it, res.end()))), it);
        });

        return res;
    }
};