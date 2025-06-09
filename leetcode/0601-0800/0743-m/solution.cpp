// https://leetcode.com/problems/network-delay-time
// 2024/08/27

class Solution {
public:
    struct Edge {
        int v, w;

        Edge(int v, int w) : v(v), w(w) {}

        bool operator<(const Edge& other) const {
            return w > other.w;
        }
    };

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<Edge>> graph(n);
        for (const vector<int>& t : times) {
            graph[t[0] - 1].emplace_back(t[1] - 1, t[2]);
        }

        priority_queue<Edge> pq;
        pq.emplace(--k, 0);

        vector<int> time(n, INT_MAX);
        time[k] = 0;

        vector<bool> visited(n);
        
        while (!pq.empty()) {
            const Edge curr = pq.top();
            pq.pop();

            if (visited[curr.v]) continue;

            visited[curr.v] = true;

            for (const Edge& e : graph[curr.v]) {
                if (visited[e.v]) continue;

                int new_time = curr.w + e.w;

                if (new_time < time[e.v]) {
                    time[e.v] = new_time;
                    pq.emplace(e.v, new_time);
                }
            }
        }

        if (find(visited.begin(), visited.end(), false) != visited.end()) {
            return -1;
        }

        return *max_element(time.begin(), time.end());
    }
};