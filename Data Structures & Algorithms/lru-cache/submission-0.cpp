class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }

    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int capacity;
    unordered_map<int, Node*> mp;
    void removeNode(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    void insertFront(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        removeNode(node);
        insertFront(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            Node* node = new Node(key, value);
            insertFront(node);
            mp[key] = node;
            if (mp.size() > capacity) {
                Node* lru = tail->prev;
                removeNode(lru);
                mp.erase(lru->key);
                delete(lru);
            }
        }
        else {
            Node* node = mp[key];
            removeNode(node);
            node->val = value;
            insertFront(node);
        }
    }
};
