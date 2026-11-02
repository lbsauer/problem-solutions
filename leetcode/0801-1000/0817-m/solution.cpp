// https://leetcode.com/problems/linked-list-components
// 2026/01/31

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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());

        int count = 0;
        for (bool last = false; head != nullptr; head = head->next) {
            const bool curr = set.contains(head->val);
            count += curr && !last;
            last = curr;
        }

        return count;
    }
};