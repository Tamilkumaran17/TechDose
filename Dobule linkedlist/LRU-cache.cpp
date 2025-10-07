#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int val) : key(k), value(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:

    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    LRUCache(int cap) {

        this->capacity = cap;
        head = new Node(0,0);
        tail = new Node(0,0);

        head->next = tail;
        tail->prev = head;
    }

    void addNode_next_to_head(Node* node) {

        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void deleteNode(Node* node) {

        Node* pre = node->prev;
        Node* nxt = node->next;

        pre->next = nxt;
        nxt->prev = pre;
    }

    int get(int key) {

        if(mp.find(key) == mp.end())
         return -1;

        Node* node = mp[key];

        deleteNode(node);
        addNode_next_to_head(node);

        return node->value;
    }

    void put(int key, int value) {

        if(mp.find(key) != mp.end()) {

            Node* node = mp[key];
            node->value = value;
            deleteNode(node);
            addNode_next_to_head(node);

        } else {

            if(mp.size() >= capacity) {
                Node* del = tail->prev;
                deleteNode(del);
                mp.erase(del->key);
                delete del;
            }

            Node* node = new Node(key,value);
            addNode_next_to_head(node);
            mp[key] = node;
        }
    }

    void display() {
        
        Node* curr = head->next;
        cout << "Cache State: ";
        while(curr != tail) {
            cout << "(" << curr->key << "," << curr->value << ") ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    int cap;
    cout << "Enter LRU Cache capacity: ";
    cin >> cap;

    LRUCache cache(cap);

    while(true) {
        cout << "\nChoose operation:\n1. PUT key value\n2. GET key\n3. DISPLAY cache\n4. EXIT\n";
        int choice;
        cin >> choice;

        if(choice == 1) {
            int key, value;
            cin >> key >> value;
            cache.put(key, value);
            cout << "Inserted (" << key << "," << value << ")" << endl;
        } else if(choice == 2) {
            int key;
            cin >> key;
            int val = cache.get(key);
            if(val == -1) cout << "Key " << key << " not found" << endl;
            else cout << "Value: " << val << endl;
        } else if(choice == 3) {
            cache.display();
        } else if(choice == 4) {
            break;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
