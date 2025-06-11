// https://leetcode.com/problems/rabbits-in-forest
// 2025/04/23

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        for (const int a : answers) {
            ++freq[a];
        }

        int count = 0;
        for (const auto [n, f] : freq) {
            count += (f + n) / (n + 1) * (n + 1);
        }

        return count;
    }
};