// https://leetcode.com/problems/remove-nodes-from-linked-list
// 2024/05/06

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
    void reverse(ListNode** node) {
        ListNode* curr = *node;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        *node = prev;
    }

    ListNode* find_larger(ListNode* node) {
        int num = node->val;
        node = node->next;
        // ListNode* temp;
        while (node != nullptr) {
            if (node->val >= num) return node;
            
            // temp = node;
            node = node->next;
            // delete temp;
        }

        return nullptr;
    }
    
    ListNode* removeNodes(ListNode* head) {
        reverse(&head);
        
        ListNode* curr = head;
        while (curr != nullptr) {
            curr->next = find_larger(curr);
            curr = curr->next;
        }

        reverse(&head);

        return head;
    }
};