
class LRUCache {
public:
    // 1️⃣ Proper Node class INSIDE LRUCache
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int _key, int _val) {
            key = _key;
            val = _val;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int cap;
    unordered_map<int, Node*> mp;

    // 2️⃣ Constructor
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // 3️⃣ Add node right after head (MRU)
    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    // 4️⃣ Delete node from DLL
    void delNode(Node* delNode) {
        Node* beforeNode = delNode->prev;
        Node* afterNode = delNode->next;

        beforeNode->next = afterNode;
        afterNode->prev = beforeNode;
    }

    // 5️⃣ get operation
    int get(int key) {
        if (mp.find(key) != mp.end()) { // NOT emd()
            Node* temp = mp[key];
            int res = temp->val;

            mp.erase(key);        // remove old mapping
            delNode(temp);        // remove from current position
            addNode(temp);        // move to front (MRU)
            mp[key] = head->next; // update mapping

            return res;
        }
        return -1;
    }

    // 6️⃣ put operation
    void put(int key, int value) {
        // if key already exists, delete old node
        if (mp.find(key) != mp.end()) {
            Node* tempo = mp[key];
            mp.erase(key);
            delNode(tempo);
            // optionally: delete tempo;  (we rebuilt a new node below)
        }

        // if capacity full, remove LRU (node before tail)
        if ((int)mp.size() == cap) {
            Node* lru = tail->prev;
            mp.erase(lru->key);
            delNode(lru);
            // optionally: delete lru;
        }

        // insert new node as MRU
        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = head->next;
    }
};
