// https://leetcode.com/problems/design-graph-with-shortest-path-calculator
// 2025/04/24

class Graph {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<vector<pair<int, int>>> graph;
    vector<int> dist;

public:
    Graph(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        dist.resize(n);

        for (const auto& e : edges) {
            graph[e[0]].emplace_back(e[1], e[2]);
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        while (!pq.empty()) pq.pop();
        pq.emplace(0, node1);

        fill(dist.begin(), dist.end(), INT_MAX);
        dist[node1] = 0;

        while (!pq.empty() && pq.top().second != node2) {
            const auto [w, v] = pq.top();
            pq.pop();

            if (w > dist[v]) continue;

            for (const auto [nv, nw] : graph[v]) {
                if (w + nw < dist[nv]) {
                    dist[nv] = w + nw;
                    pq.emplace(w + nw, nv);
                }
            }
        }

        return dist[node2] == INT_MAX ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */