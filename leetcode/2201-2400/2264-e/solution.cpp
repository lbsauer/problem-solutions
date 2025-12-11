// https://leetcode.com/problems/largest-3-same-digit-number-in-string
// 2025/08/14

class Solution {
public:
    string largestGoodInteger(string num) {
        char largest = 0;
        for (int i = 2; i < num.size(); ++i) {
            if (num[i] == num[i - 1] && num[i] == num[i - 2]) {
                largest = max(largest, num[i]);
            }
        }

        return largest == 0 ? "" : string(3, largest);
    }
};