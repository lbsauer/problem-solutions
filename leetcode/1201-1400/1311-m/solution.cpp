// https://leetcode.com/problems/get-watched-videos-by-your-friends
// 2024/11/07

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<bool> visited(friends.size());
        visited[id] = true;

        deque<int> q{id};
        while (!q.empty() && level-- > 0) {
            int size = q.size();

            while (size-- > 0) {
                for (const int v : friends[q.front()]) {
                    if (visited[v]) continue;

                    q.push_back(v);
                    visited[v] = true;
                }

                q.pop_front();
            }
        }

        unordered_map<string, int> freq;
        for_each(q.begin(), q.end(), [&](const int u) {
            for_each(watchedVideos[u].begin(), watchedVideos[u].end(), [&](const string& v) { ++freq[v]; });
        });

        // avoids having to hash strings for frequency comparison during sorting
        vector<const pair<const string, int>*> sorted(freq.size());
        transform(freq.begin(), freq.end(), sorted.begin(), [](const auto& p) { return &p; });

        sort(sorted.begin(), sorted.end(), [](const auto lhs, const auto rhs) {
            return lhs->second != rhs->second ? lhs->second < rhs->second : lhs->first < rhs->first;
        });

        vector<string> res(freq.size());
        transform(sorted.begin(), sorted.end(), res.begin(), [](const auto p) { return p->first; });

        return res;
    }
};