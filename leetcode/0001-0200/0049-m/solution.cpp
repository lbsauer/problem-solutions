// https://leetcode.com/problems/group-anagrams
// 2024/11/01

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> map;
        vector<vector<string>> res;

        for (const string& s : strs) {
            string copy(s);
            sort(copy.begin(), copy.end());

            if (auto it = map.find(copy); it != map.end()) {
                res[it->second].push_back(s);
            } else {
                map[copy] = map.size();
                res.push_back({s});
            }
        }

        return res;
    }
};