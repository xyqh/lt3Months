#include "LeetCodeBase.h"

ListNode *reverse(ListNode *preEnd, ListNode *curEnd){
    ListNode *pre = curEnd->next, *node = preEnd, *next = nullptr;
    while(true){
        next = node->next;
        node->next = pre;
        pre = node;
        node = next;
        if(node == curEnd){
            break;
        }
    }

    return preEnd->next;
}

ListNode *reverseKGroup(ListNode *head, int k){
    ListNode *dummyNode = new ListNode(0), *node = dummyNode, *endNode = head;
    dummyNode->next = head;

    int i = 0;
    while(endNode->next && i < k){
        endNode = endNode->next;
        if(++i == k){
            i = 0;
            node->next = reverse(node->next, endNode);
        }
    }

    return dummyNode->next;
}