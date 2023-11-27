#include "LeetCodeBase.h"

struct DoubleListNode{
    int val;
    int key;
    DoubleListNode *pre;
    DoubleListNode *next;
    DoubleListNode(int _key, int _val) : key(_key), val(_val), pre(nullptr), next(nullptr){};
};

class LRUCache{
    int _capacity;
    DoubleListNode *_head, *_tail;
    unordered_map<int, DoubleListNode*> _cache;

    void moveToFront(DoubleListNode* node){
        if(_head == node){
            return;
        }
        RemoveNode(node);
        insertToFront(node);
    }

    void insertToFront(DoubleListNode *node){
        if(_cache.size() == 1){
            _head = node;
            _tail = node;
            return;
        }

        node->pre = nullptr;
        node->next = _head;
        _head->pre = node;
        _head = node;        
    }

    void RemoveNode(DoubleListNode* node){
        DoubleListNode *pre = node->pre;
        DoubleListNode *next = node->next;
        if(pre){
            pre->next = next;
        }
        if(next){
            next->pre = pre;
        }

        if(node == _tail){
            _tail = pre;
        }
    }

    void RemoveLast(){
        RemoveNode(_tail);
    }
public:
    LRUCache(int capacity){
        _capacity = capacity;
        _head = nullptr, _tail = nullptr;
        _cache.clear();
    }

    int get(int key){
        if(_cache.count(key)){
            auto node = _cache[key];
            moveToFront(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value){
        if(_cache.count(key)){
            auto node = _cache[key];
            node->val = value;
            moveToFront(node);
            return;
        }
        if(_cache.size() == _capacity){
            _cache.erase(_tail->key);
            RemoveLast();
        }
        DoubleListNode *node = new DoubleListNode(key, value);
        _cache[key] = node;
        moveToFront(node);
    }
};

int main(){
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);
    cache.put(3, 3);
    cache.get(2);
    cache.put(4, 4);
    cache.get(1);
    cache.get(3);
    cache.get(4);

    return 0;
}