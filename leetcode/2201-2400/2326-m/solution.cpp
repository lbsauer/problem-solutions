// https://leetcode.com/problems/spiral-matrix-iv
// 2024/03/29

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        std::vector<std::vector<int>> matrix(m, std::vector<int>(n, -1));

        ListNode *current = head;

        int l = 0;
        int r = n - 1;
        int t = 0;
        int b = m - 1;

        while (current != nullptr) {
            for (int i = l; i <= r && current != nullptr; ++i) {
                matrix[t][i] = current->val;
                current = current->next;
            }
            ++t;

            for (int i = t; i <= b && current != nullptr; ++i) {
                matrix[i][r] = current->val;
                current = current->next;
            }
            --r;

            for (int i = r; i >= l && current != nullptr; --i) {
                matrix[b][i] = current->val;
                current = current->next;
            }
            --b;

            for (int i = b; i >= t && current != nullptr; --i) {
                matrix[i][l] = current->val;
                current = current->next;
            }
            ++l;
        }

        return matrix;
    }
};