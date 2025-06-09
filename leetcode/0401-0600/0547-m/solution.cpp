// https://leetcode.com/problems/number-of-provinces
// 2024/07/27

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size());
        int count = 0;
        
        for (int i = 0; i < isConnected.size(); ++i) {
            if (visited[i]) continue;
            
            visited[i] = true;

            forward_list<int> stack;
            stack.push_front(i);

            while (!stack.empty()) {
                const int v = stack.front();
                stack.pop_front();

                for (int j = 0; j < isConnected.size(); ++j) {
                    if (visited[j] || isConnected[v][j] == 0) continue;

                    stack.push_front(j);
                    visited[j] = true;
                }
            }

            ++count;
        }

        return count;
    }
};