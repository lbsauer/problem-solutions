// https://leetcode.com/problems/validate-binary-tree-nodes
// 2024/11/08

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> visited(n);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                if (visited[leftChild[i]]) return false;

                visited[leftChild[i]] = true;
            }

            if (rightChild[i] != -1) {
                if (visited[rightChild[i]]) return false;

                visited[rightChild[i]] = true;
            }
        }

        int root = distance(visited.begin(), find(visited.begin(), visited.end(), false));

        if (root == n) return false;

        visited.assign(n, false);
        visited[root] = true;

        deque<int> stack{root};
        while (!stack.empty()) {
            const int v = stack.back();
            stack.pop_back();

            if (leftChild[v] != -1) {
                if (visited[leftChild[v]]) return false;

                visited[leftChild[v]] = true;
                stack.push_back(leftChild[v]);
            }

            if (rightChild[v] != -1) {
                if (visited[rightChild[v]]) return false;

                visited[rightChild[v]] = true;
                stack.push_back(rightChild[v]);
            }
        }

        return find(visited.begin(), visited.end(), false) == visited.end();
    }
};