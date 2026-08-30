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
    ListNode* getmid(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* node, ListNode* prev) {
        while (node) {
            ListNode* next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode* left = head;
        ListNode* mid = getmid(head);
        ListNode* right = mid->next;
        mid->next = nullptr;
        right = reverse(right, nullptr);
        ListNode dummy = ListNode(0);
        ListNode* curr = &dummy;
        ListNode* curr2 = curr;
        while (right) {
            curr->next = left;
            left = left->next;
            curr->next->next = right;
            right = right->next;
            curr = curr->next->next;
        }
        if (left) curr->next = left;
        head = curr2->next;
    }
};
