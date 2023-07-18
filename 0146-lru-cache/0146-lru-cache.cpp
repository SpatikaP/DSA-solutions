class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
    };

    unordered_map<int, Node*> hashMap;
    Node* MRU;
    Node* LRU;
    int capacity;

    void addNode(Node* newNode) {
        Node* temp = MRU->next;
        MRU->next = newNode;
        newNode->prev = MRU;
        newNode->next = temp;
        temp->prev = newNode;
    }

    void deleteNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        hashMap = unordered_map<int, Node*>();
        MRU = new Node(-1, -1);
        LRU = new Node(-1, -1);
        MRU->next = LRU;
        LRU->prev = MRU;
    }

    int get(int key) {
        if (hashMap.find(key) == hashMap.end())
            return -1;
        
        put(key, hashMap[key]->val);
        return hashMap[key]->val;
    }

    void put(int key, int value) {
        if (hashMap.find(key) != hashMap.end()) {
            Node* node = hashMap[key];
            deleteNode(node);
            node->val = value;
            addNode(node);
            hashMap[key] = MRU->next;
        } else {
            if (hashMap.size() == capacity) {
                Node* prev = LRU->prev;
                deleteNode(prev);
                hashMap.erase(prev->key);
                delete prev;
            }
            Node* newNode = new Node(key, value);
            addNode(newNode);
            hashMap[key] = MRU->next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */