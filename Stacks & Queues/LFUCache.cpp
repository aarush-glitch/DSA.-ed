struct Node {
    int key, val, cnt;
    Node* next;
    Node* prev;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
        cnt = 1;
    }
};

struct List {
    int size;
    Node* head;
    Node* tail;
    List() {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size=0;
    }

    void addFront(Node* node) {
        Node* afterNode = head->next;
        node->next = afterNode;
        node->prev = head;
        head->next = node;
        afterNode->prev = node;
        size++;
    }

    void removeNode(Node* delNode) {
        Node* delprev = delNode->prev;
        Node* delnext = delNode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache {
public:
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int maxSizeCache, minFreq, curSize;
    
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq=0;
        curSize=0;
    }
    
    void updateFreqList(Node* node) {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt == minFreq && freqListMap[node->cnt]->size==0) {
            minFreq++;
        }
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt+1)!=freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt+1];
        }
        node->cnt+=1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    int get(int key) {
        if(keyNode.find(key)==keyNode.end())
            return -1;
        Node* node = keyNode[key];
        int val = node->val;
        updateFreqList(node);
        return val;
    }
    
    void put(int key, int value) {
        if(maxSizeCache==0) return;
        if(keyNode.find(key)!=keyNode.end()) {
            Node* node = keyNode[key];
            node->val = value;
            updateFreqList(node);
        }
        else {
            if(curSize==maxSizeCache) {
                List* list = freqListMap[minFreq];
                Node* node = list->tail->prev;
                keyNode.erase(node->key);
                freqListMap[minFreq]->removeNode(node);
                curSize--;
            }
            curSize++;
            minFreq=1;
            List* listFreq = new List();
            if(freqListMap.find(1)!=freqListMap.end()) {
                listFreq = freqListMap[1];
            }
            Node* newNode = new Node(key, value);
            listFreq->addFront(newNode);
            keyNode[key] = newNode;
            freqListMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
