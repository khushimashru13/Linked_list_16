class AllOne {
    struct Node {
        int count;
        unordered_set<string> keys;
        Node* prev;
        Node* next;

        Node(int c) {
            count = c;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    unordered_map<string, Node*> mp;

    void insertAfter(Node* prevNode, Node* newNode) {
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        prevNode->next->prev = newNode;
        prevNode->next = newNode;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);

        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {
        if (mp.find(key) == mp.end()) {
            // New key -> count 1
            if (head->next == tail || head->next->count != 1) {
                insertAfter(head, new Node(1));
            }

            head->next->keys.insert(key);
            mp[key] = head->next;
        }
        else {
            Node* curr = mp[key];
            Node* nextNode = curr->next;

            // Create count + 1 bucket if needed
            if (nextNode == tail || nextNode->count != curr->count + 1) {
                nextNode = new Node(curr->count + 1);
                insertAfter(curr, nextNode);
            }

            nextNode->keys.insert(key);
            mp[key] = nextNode;

            curr->keys.erase(key);

            if (curr->keys.empty())
                removeNode(curr);
        }
    }

    void dec(string key) {
        Node* curr = mp[key];

        if (curr->count == 1) {
            // Remove key completely
            curr->keys.erase(key);
            mp.erase(key);

            if (curr->keys.empty())
                removeNode(curr);
        }
        else {
            Node* prevNode = curr->prev;

            // Create count - 1 bucket if needed
            if (prevNode == head || prevNode->count != curr->count - 1) {
                prevNode = new Node(curr->count - 1);
                insertAfter(curr->prev, prevNode);
            }

            prevNode->keys.insert(key);
            mp[key] = prevNode;

            curr->keys.erase(key);

            if (curr->keys.empty())
                removeNode(curr);
        }
    }

    string getMaxKey() {
        if (tail->prev == head)
            return "";

        return *(tail->prev->keys.begin());
    }

    string getMinKey() {
        if (head->next == tail)
            return "";

        return *(head->next->keys.begin());
    }
};