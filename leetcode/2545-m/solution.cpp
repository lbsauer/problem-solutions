// https://leetcode.com/problems/sort-the-students-by-their-kth-score
// 2024/07/22

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [k](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[k] > rhs[k];
        });

        return score;
    }
};