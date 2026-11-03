// https://leetcode.com/problems/ipo
// 2026/08/16

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> projects(profits.size());
        for (int i = 0; i < projects.size(); ++i) {
            projects[i] = {capital[i], profits[i]};
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> pq;
        pq.push(0);

        for (int idx = 0; k > 0 && !pq.empty(); --k) {
            while (idx < projects.size() && projects[idx].first <= w) {
                pq.push(projects[idx++].second);
            }

            w += pq.top();
            pq.pop();
        }

        return w;
    }
};