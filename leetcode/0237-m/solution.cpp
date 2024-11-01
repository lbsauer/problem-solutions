// https://leetcode.com/problems/delete-node-in-a-linked-list
// 2024/05/04

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* aux = node->next;
        *node = *(node->next);
        delete aux;
    }
};