// https://leetcode.com/problems/maximum-product-of-word-lengths
// 2026/05/28

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> masks(words.size());
        for (int i = 0; i < words.size(); ++i) {
            for (const char c : words[i]) {
                masks[i] |= 1 << (c - 'a');
            }
        }

        size_t max_product = 0;
        for (int i = 0; i < masks.size(); ++i) {
            for (int j = i + 1; j < masks.size(); ++j) {
                if ((masks[i] & masks[j]) == 0) {
                    max_product = max(max_product, words[i].size() * words[j].size());
                }
            }
        }

        return max_product;
    }
};