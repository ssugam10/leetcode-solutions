#include <unordered_map>
using namespace std;

class node {
public:
    int key;
    int val;
    node *prev;
    node *next;

    node(int key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    unordered_map<int, node*> mp;
    node *head;
    node *tail;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        mp.clear();
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node *newnode) {
        newnode->next = head->next;
        newnode->prev = head;
        head->next->prev = newnode;
        head->next = newnode;
    }

    void deletenode(node *delnode) {
        node *delPrev = delnode->prev;
        node *delNext = delnode->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        node *delnode = mp[key];
        deletenode(delnode);
        addnode(delnode);

        return delnode->val;
    }

    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            node *newNode = new node(key, value);
            mp[key] = newNode;
            addnode(newNode);

            if (mp.size() > capacity) {
                node *delNode = tail->prev;
                mp.erase(delNode->key);
                deletenode(delNode);
                delete delNode;
            }
        } else {
            node *existingNode = mp[key];
            deletenode(existingNode);
            existingNode->val = value;
            addnode(existingNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key, value);
 */
