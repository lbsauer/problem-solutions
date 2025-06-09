// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i
// 2024/12/16

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        constexpr static auto comp = [](const int& lhs, const int& rhs) -> bool {
            return lhs == rhs ? &lhs > &rhs : lhs > rhs;
        };
        
        vector<reference_wrapper<int>> heap(nums.begin(), nums.end());
        make_heap(heap.begin(), heap.end(), comp);

        while (k-- > 0) {
            heap.front() *= multiplier;
            pop_heap(heap.begin(), heap.end(), comp);
            push_heap(heap.begin(), heap.end(), comp);
        }

        return nums;
    }
};