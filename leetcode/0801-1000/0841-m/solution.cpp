// https://leetcode.com/problems/keys-and-rooms
// 2024/07/27

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size());
        visited[0] = true;
        
        forward_list<int> stack;
        stack.push_front(0);

        while (!stack.empty()) {
            const int v = stack.front();
            stack.pop_front();

            for (const int u : rooms[v]) {
                if (visited[u]) continue;

                stack.push_front(u);
                visited[u] = true;
            }
        }
        
        return find(visited.begin(), visited.end(), false) == visited.end();
    }
};