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
        if (!head) return nullptr;
        ListNode* curr = head;
        for (int i = 0; i < n; i++) curr = curr->next;
        ListNode* newhead = head;
        ListNode* prev = nullptr;
        while (curr) {
            prev = newhead;
            newhead = newhead->next;
            curr = curr->next;
        }
        if (prev) prev->next = newhead->next;
        else return head->next;
        return head;
    }
};
