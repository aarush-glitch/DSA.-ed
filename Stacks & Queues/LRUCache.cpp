class Node {
public:
    int key, val;
    Node* next;
    Node* prev;

    Node() {
        next=nullptr;
        prev=nullptr;
    }

    Node(int key_, int val_): key(key_), val(val_) {
        next=nullptr;
        prev=nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> mpp;
    LRUCache(int capacity_) {
        capacity = capacity_;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    void deleteNode(Node* node) {
        Node* afterNode = node->next;
        Node* prevNode = node->prev;
        prevNode->next = afterNode;
        afterNode->prev = prevNode;
    }

    void insertAfterHead(Node* node) {
        Node* curHead = head->next;
        node->next = curHead;
        curHead->prev = node;
        node->prev = head;
        head->next = node;
    }

    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        Node* node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()) {
            Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else {
            if(mpp.size()==capacity) {
                Node* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
            Node* newNode = new Node(key, value);
            mpp[key] = newNode;
            insertAfterHead(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
