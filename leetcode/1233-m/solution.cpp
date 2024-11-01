// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem
// 2024-10-24

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> res;

        for (int i = 0; i < folder.size();) {
            string& s = folder[i];

            do {
                ++i;
            } while (
                i < folder.size()                            &&
                s.size() < folder[i].size()                  &&
                equal(s.begin(), s.end(), folder[i].begin()) &&
                folder[i][s.size()] == '/'
            );

            res.push_back(s);
        }

        return res;
    }
};