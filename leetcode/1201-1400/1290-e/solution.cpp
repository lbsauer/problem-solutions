// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer
// 2025/07/15

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
    int getDecimalValue(ListNode* head) {
        int value = 0;
        while (head != nullptr) {
            value <<= 1;
            value |= head->val;
            head = head->next;
        }

        return value;
    }
};