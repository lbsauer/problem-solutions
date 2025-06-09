// https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character
// 2024/08/16

class Solution {
public:
    int f(const string& s) {
        return count(s.begin(), s.end(), *min_element(s.begin(), s.end()));
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int w_freq[10] = {0};
        for (string& w : words) {
            ++w_freq[f(w) - 1];
        }

        int total = accumulate(begin(w_freq), end(w_freq), 0);
        for (int i = 0; i < 10; ++i) {
            total -= w_freq[i];
            w_freq[i] = total;
        }

        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            res[i] = w_freq[f(queries[i]) - 1];
        }

        return res;
    }
};