// https://leetcode.com/problems/add-two-numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = (l1->val + l2->val) / 10;
        
        ListNode* res = new ListNode((l1->val + l2->val) % 10);
        ListNode* current = res;

        l1 = l1->next;
        l2 = l2->next;

        while (l1 && l2) {
            current->next = new ListNode((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val + carry) / 10;

            current = current->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        current->next = l1 ? l1 : l2;

        while (current->next && carry) {
            carry = (current->next->val + 1) / 10;
            current->next->val = (current->next->val + 1) % 10;
            current = current->next;
        }

        if (carry) current->next = new ListNode(1);

        return res;
    }
};