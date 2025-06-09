// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero
// 2024/05/09

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int max = *std::max_element(candidates.begin(), candidates.end());
        
        int bit = 0;
        while (max != 0) {
            max >>= 1;
            ++bit;
        }

        for (int i = 0; i < bit; ++i) {
            int count = 0;
            for (int j = 0; j < candidates.size(); ++j) {
                count += candidates[j] >> i & 1;
            }

            max = std::max(max, count);
        }
        
        return max;
    }
};