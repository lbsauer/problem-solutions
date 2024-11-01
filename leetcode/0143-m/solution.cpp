// https://leetcode.com/problems/reorder-list
// 2024/03/23

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
    void reorderList(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *aux = nullptr;
        ListNode *aux2 = nullptr;

        // find middle point
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = nullptr;

        // reverse second half
        while (slow != nullptr) {
            aux = slow->next;
            slow->next = aux2;
            aux2 = slow;
            slow = aux;
        }
        slow = aux2;

        // merge both halves
        fast = head;
        while (slow != nullptr) {
            aux = fast->next;
            aux2 = slow->next;

            fast->next = slow;
            slow->next = aux;

            slow = aux2;
            fast = aux;
        }
    }
};