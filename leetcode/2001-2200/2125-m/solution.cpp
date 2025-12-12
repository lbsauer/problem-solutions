// https://leetcode.com/problems/number-of-laser-beams-in-a-bank
// 2025/10/27

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int beams = 0, prev = 0;
        for (const string& row : bank) {
            const int curr = count(row.begin(), row.end(), '1');
            if (curr == 0) continue;
            
            beams += prev * curr;
            prev = curr;
        }
        
        return beams;
    }
};