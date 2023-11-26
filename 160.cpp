#include "LeetCodeBase.h"

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *nodeA = headA, *nodeB = headB;
    while(nodeA != nodeB){
        nodeA = nodeA ? nodeA->next : headB;
        nodeB = nodeB ? nodeB->next : headA;
    }
    return nodeA;
}