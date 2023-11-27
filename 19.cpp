#include "LeetCodeBase.h"

ListNode* removeNthFromEnd(ListNode* head, int n){
    int i = 0;
    ListNode *fast = head, *dummyNode = new ListNode(0), *slow = dummyNode;
    dummyNode->next = head;
    while(++i < n){
        fast = fast->next;
        ++i;
    }

    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;

    return dummyNode->next;
}