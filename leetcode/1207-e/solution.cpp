// https://leetcode.com/problems/unique-number-of-occurrences
// 2024/05/03

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        unordered_set<int> set;

        for (int i : arr) {
            ++map[i];
        }

        for (auto& i : map) {
            if (set.count(i.second)) return false;
            set.insert(i.second);
        }

        return true;
    }
};