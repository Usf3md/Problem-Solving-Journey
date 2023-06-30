#include <bits/stdc++.h>

using namespace std;

struct lNode
{
    int key;
    int val;
    lNode *next;
    lNode *prev;
    lNode() : key(0), val(0), next(nullptr), prev(nullptr) {}
    lNode(int key, int x) : key(key), val(x), next(nullptr), prev(nullptr) {}
    lNode(int key, int x, lNode *next, lNode *prev) : key(key), val(x), next(next), prev(prev) {}
};

class LRUCache
{
public:
    int capacity;
    map<int, lNode *> m;
    lNode *head = new lNode();
    lNode *tail = new lNode();
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (m.count(key))
        {
            lNode *node = m[key];
            node->prev->next = node->next;
            node->next->prev = node->prev;
            tail->prev->next = node;
            node->prev = tail->prev;
            tail->prev = node;
            node->next = tail;
            return node->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (m.count(key))
        {
            m[key]->val = value;
            this->get(key);
        }
        else if (m.size() < capacity)
        {
            lNode *newNode = new lNode(key, value);
            m[key] = newNode;
            tail->prev->next = newNode;
            newNode->next = tail;
            newNode->prev = tail->prev;
            tail->prev = newNode;
        }
        else
        {
            lNode *leastNode = head->next;
            leastNode->next->prev = leastNode->prev;
            leastNode->prev->next = leastNode->next;
            leastNode->next = nullptr;
            leastNode->prev = nullptr;
            m.erase(leastNode->key);
            delete leastNode;
            lNode *newNode = new lNode(key, value);
            m[key] = newNode;
            tail->prev->next = newNode;
            newNode->next = tail;
            newNode->prev = tail->prev;
            tail->prev = newNode;
        }
    }
    void print()
    {
        lNode *ptr = head;
        while (ptr)
        {
            std::cout << ptr->key << ":" << ptr->val << ' ';
            ptr = ptr->next;
        }
        std::cout << endl;
        ptr = tail;
    }
};

int main()
{
    LRUCache cache(2);
    cache.put(2, 1);
    cache.print();
    cache.put(1, 1);
    cache.print();
    cache.put(2, 3);
    cache.print();
    cache.put(4, 1);
    cache.print();
    std::cout << cache.get(1) << endl;
    cache.print();
    std::cout << cache.get(2) << endl;
    cache.print();
    return 0;
}