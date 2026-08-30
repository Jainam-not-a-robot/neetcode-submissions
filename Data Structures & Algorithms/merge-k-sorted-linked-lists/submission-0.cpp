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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) pq.push({lists[i]->val, lists[i]});
        }
        ListNode dummy = ListNode(0);
        ListNode* head = &dummy;
        ListNode* curr = head;
        while (!pq.empty()) {
            auto [val, node] = pq.top();
            pq.pop();
            curr->next = node;
            curr = curr->next;
            node = node->next;
            if (node) pq.push({node->val, node});
        }
        return head->next;
    }
};
