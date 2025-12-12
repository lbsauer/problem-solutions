// https://leetcode.com/problems/max-chunks-to-make-sorted
// 2025/11/30

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int max_e = 0, chunks = 0;
        for (int i = 0; i < arr.size(); ++i) {
            max_e = max(max_e, arr[i]);
            chunks += max_e == i;
        }

        return chunks;
    }
};