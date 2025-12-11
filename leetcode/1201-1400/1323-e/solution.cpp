// https://leetcode.com/problems/maximum-69-number
// 2025/08/15

class Solution {
public:
    int maximum69Number (int num) {
        int six = -1;
        for (int i = 0, n = num; n != 0; n /= 10, ++i) {
            if (n % 10 == 6) six = i;
        }

        return six == -1 ? num : num + 3 * pow(10, six);
    }
};