// https://leetcode.com/problems/fruit-into-baskets
// 2025/08/03

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int max_fruits = 0;
        
        int have[2]{}, count[2]{};
        for (int l = 0, r = 0; r < fruits.size(); ++r) {
            if (fruits[r] != have[0] && fruits[r] != have[1]) {
                while (count[0] > 0 && count[1] > 0) {
                    --count[fruits[l++] == have[1]];
                }

                have[count[1] == 0] = fruits[r];
            }

            ++count[fruits[r] == have[1]];

            max_fruits = max(max_fruits, count[0] + count[1]);
        }

        return max_fruits;
    }
};