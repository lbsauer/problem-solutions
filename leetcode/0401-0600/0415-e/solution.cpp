// https://leetcode.com/problems/add-strings
// 2024/05/02

class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.length() < num2.length()) {
            num1.insert(0, num2.length() - num1.length(), '0');
        } else {
            num2.insert(0, num1.length() - num2.length(), '0');
        }

        bool carry = false;
        for (int i = num1.length() - 1; i >= 0; --i) {
            char c = (num1[i] + num2[i] + carry - 96);
            carry = c >= 10;
            num1[i] = (c % 10 + '0');
        }

        return carry ? '1' + num1 : num1;
    }
};