/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* curr = head;
        while (curr) {
            Node* node = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = node;
            curr = curr->next->next;
        }
        curr = head;
        while (curr) {
            curr->next->random = curr->random ? curr->random->next : nullptr;
            curr = curr->next->next; 
        }
        Node* newhead = head->next;
        curr = head;
        Node* curr2 = newhead;
        while (curr->next->next) {
            Node* currnext = curr->next->next;
            Node* newnext = curr2->next->next;
            curr->next = currnext;
            curr2->next = newnext;
            curr = curr->next;
            curr2 = curr2->next;
        }
        return newhead;
    }
};
