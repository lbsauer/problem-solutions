// https://leetcode.com/problems/buy-two-chocolates
// 2024/05/05

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for (int i : prices) {
            min2 = std::min(min2, std::max(min1, i));
            min1 = std::min(min1, i);
        }

        return (min1 + min2 <= money) ? (money - min1 - min2) : money;
    }
};