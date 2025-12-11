// https://leetcode.com/problems/finding-pairs-with-a-certain-sum
// 2025/07/07

class FindSumPairs {
    int max_val;
    vector<int> nums;
    vector<pair<int, int>> freq1;
    unordered_map<int, int> freq2;

    static constexpr auto comp = [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.first < rhs.first;
    };

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums(move(nums2)), max_val() {
        sort(nums1.begin(), nums1.end());
        for (int l = 0, r = 0; r < nums1.size(); l = r) {
            while (r < nums1.size() && nums1[l] == nums1[r]) ++r;

            freq1.emplace_back(nums1[l], r - l);
        }

        freq2.reserve(nums.size());
        for (const int n : nums) {
            ++freq2[n];
            max_val = max(max_val, n);
        }
    }
    
    void add(int index, int val) {
        const auto it = freq2.find(nums[index]);
        if (--it->second == 0) {
            freq2.erase(it);
        }

        nums[index] += val;
        ++freq2[nums[index]];
        max_val = max(max_val, nums[index]);
    }

    int count(int tot) {
        int total = 0;

        auto it = lower_bound(freq1.begin(), freq1.end(), make_pair(tot - max_val, 0), comp);
        for (; it != freq1.end() && it->first < tot; ++it) {
            const auto it2 = freq2.find(tot - it->first);
            if (it2 != freq2.end()) total += it->second * it2->second;
        }

        return total;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */