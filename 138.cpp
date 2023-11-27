#include "LeetCodeBase.h"

Node *copyRandomList(Node *head){
    Node *dummyNode = new Node(0), *node = head;
    dummyNode->next = head;
    while(node){
        Node *next = node->next, *newNode = new Node(node->val);
        node->next = newNode;
        newNode->next = next;
        node = next;
    }

    node = dummyNode->next;
    while(node){
        if(node->random){
            node->next->random = node->random->next;
        }
        node = node->next->next;
    }

    node = dummyNode->next;
    Node *ans = node->next;
    while(node->next && ans->next){
        node->next = node->next->next;
        node = node->next;
        ans->next = ans->next->next;
    }

    return ans;
}