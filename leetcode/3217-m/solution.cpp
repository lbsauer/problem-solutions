// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array
// 2024/09/06

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> set{nums.begin(), nums.end()};

        ListNode** curr = &head;
        while (*curr != nullptr) {
            if (set.count((*curr)->val)) {
                // ListNode* del = *curr;
                *curr = (*curr)->next;
                // delete(del);
            } else {
                curr = &(*curr)->next;
            }
        }

        return head;
    }
};