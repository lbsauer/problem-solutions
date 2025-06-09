// https://leetcode.com/problems/remove-nth-node-from-end-of-list
// 2024/03/24

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr) return nullptr;
        if (head->next->next == nullptr) {
            if (n == 2) return head->next;
            head->next = nullptr;
            return head;
        }
        
        ListNode *current = head;
        ListNode *to_remove = head;

        for (int i = 0; i < n; ++i) {
            current = current->next;
        }
        if (current == nullptr) return head->next;

        while (current->next != nullptr) {
            current = current->next;
            to_remove = to_remove->next;
        }

        to_remove->next = to_remove->next->next;

        return head; 
    }
};