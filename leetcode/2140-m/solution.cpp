// https://leetcode.com/problems/solving-questions-with-brainpower
// 2025/04/01

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> points(questions.size());
        points.back() = questions.back()[0];

        for (int i = questions.size() - 2; i >= 0; --i) {
            const long long next = questions[i][1] + i + 1 < questions.size() ? points[i + 1 + questions[i][1]] : 0;
            points[i] = max(points[i + 1], questions[i][0] + next);
        }

        return points.front();
    }
};