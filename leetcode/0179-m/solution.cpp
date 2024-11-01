// https://leetcode.com/problems/largest-number
// 2024-09-18

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> sorted(nums.size());
        
        transform(nums.begin(), nums.end(), sorted.begin(), [](const int n) {
            return to_string(n);
        });

        sort(sorted.begin(), sorted.end(), [](const string& lhs, const string& rhs) {
            return lhs + rhs > rhs + lhs;
        });

        return sorted.front() == "0" ? "0" : accumulate(sorted.begin(), sorted.end(), string());
    }
};