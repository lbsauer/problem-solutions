// https://leetcode.com/problems/monotone-increasing-digits
// 2024/03/29

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        std::string s = std::to_string(n);

        for (int i = s.length() - 2; i >= 0; --i) {
            if (s[i] <= s[i + 1]) continue;

            std::fill(s.begin() + i + 1, s.end(), '9');
            --s[i];
        }

        return std::stoi(s);
    }
};