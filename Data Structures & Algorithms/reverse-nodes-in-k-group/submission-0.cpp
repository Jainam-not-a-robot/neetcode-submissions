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
    bool isPossible(ListNode* head, int k) {
        for (int i = 0; i < k; i++) {
            if (!head) return false;
            head = head->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* curr, int k) {
        ListNode* prev = nullptr;
        for (int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        ListNode* newHead = &dummy;
        ListNode* curr2 = newHead;
        ListNode* curr = head;
        while (true) {
            if (!isPossible(curr, k)) {
                curr2->next = curr;
                return newHead->next;
            }
            ListNode* newcurr = curr;
            for (int i = 0; i < k; i++) {
                newcurr = newcurr->next;
            }
            curr2->next = reverse(curr, k);
            curr = newcurr;
            for (int i = 0; i < k; i++) {
                curr2 = curr2->next;
            }
        }
        return nullptr;
    }
};
