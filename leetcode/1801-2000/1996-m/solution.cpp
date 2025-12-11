// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game
// 2025/08/01

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](const auto& lhs, const auto& rhs) {
            return lhs[0] == rhs[0] ? lhs[1] > rhs[1] : lhs[0] < rhs[0];
        });

        int count = 0, max_def = 0;
        for (int i = properties.size() - 1; i >= 0; --i) {
            count += properties[i][1] < max_def;
            max_def = max(max_def, properties[i][1]);
        }

        return count;
    }
};