#include "LeetCodeBase.h"

struct DoubleListNode{
    int val;
    DoubleListNode *pre;
    DoubleListNode *next;
    DoubleListNode(int _val) : val(_val), pre(nullptr), next(nullptr){};
};

class LRUCache{
    int _capacity;
    DoubleListNode *_head, *_tail;
    unordered_map<int, DoubleListNode*> _cache;

    void moveToFront(DoubleListNode* node){
        if(_head == node){
            return;
        }
        if(_cache.size() == 1){
            _head = node;
            _tail = node;
            return;
        }

        DoubleListNode *pre = node->pre;
        DoubleListNode *next = node->next;
        if(pre){
            pre->next = node->pre;
        }
        if(next){
            next->pre = pre;
        }else{
            // 没有下一个的那一定是最后一个
            _tail = pre;
        }

        node->pre = nullptr;
        node->next = _head;
        _head->pre = node;
        _head = node;
    }

    void RemoveLast(){
        DoubleListNode *pre = _tail->next;
        pre->next = nullptr;
        _tail = pre;
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
            RemoveLast();
        }
        DoubleListNode *node = new DoubleListNode(value);
        _cache[key] = node;
        moveToFront(node);
    }
};