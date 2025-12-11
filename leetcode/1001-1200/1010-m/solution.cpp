// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60
// 2025/08/29

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int freq[60]{};
        
        int count = 0;
        for (const int t : time) {
            count += freq[(60 - (t % 60)) % 60];
            ++freq[t % 60];
        }

        return count;
    }
};