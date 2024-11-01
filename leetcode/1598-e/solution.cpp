// https://leetcode.com/problems/crawler-log-folder
// 2024/07/10

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;

        for (string& s : logs) {
            if (s == "./") continue;
            
            if (s == "../") {
                count = max(count - 1, 0);
            } else {
                ++count;
            }
        }

        return count;
    }
};