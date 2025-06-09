// https://leetcode.com/problems/merge-nodes-in-between-zeros
// 2024/07/03

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* prev = head;

        uint64_t sum = 0;
        while (curr->next != nullptr) {
            if (curr->val != 0) {
                sum += curr->val;
            } else {
                prev->val = sum;
                prev->next = curr;
                prev = curr;
                sum = 0;
            }

            curr = curr->next;
        }

        prev->val = sum;
        prev->next = nullptr;

        return head;
    }
};