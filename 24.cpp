#include "LeetCodeBase.h"

ListNode* swapPairs(ListNode* head){
    ListNode *dummyNode = new ListNode(0), *node = dummyNode;
    dummyNode->next = head;
    while(node->next){
        ListNode *next = node->next;
        ListNode *nextNext = next->next;
        if(nextNext){
            node->next = nextNext;
            next->next = nextNext->next;
            nextNext->next = next;
        }else{
            break;
        }
    }

    return dummyNode->next;
}