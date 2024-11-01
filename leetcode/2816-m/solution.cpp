// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list
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
    
    ListNode* doubleIt(ListNode* head) {
        reverse(&head);

        bool carry = false;
        int sum;

        ListNode* curr = head;
        while (curr != nullptr) {
            sum = (curr->val << 1) + carry;
            carry = sum > 9;
            curr->val = sum % 10;

            curr = curr->next;
        }

        reverse(&head);

        if (carry) head = new ListNode(1, head);

        return head;
    }
};