#include "LeetCodeBase.h"

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2){
    ListNode *dummyNode = new ListNode(0);
    ListNode *node = dummyNode;
    while(list1 && list2){
        if(list2 < list1){
            node->next = list2;
            list2 = list2->next;
        }else{
            node->next = list1;
            list1 = list1->next;
        }
        node = node->next;
    }

    if(list1){
        node->next = list1;
    }
    if(list2){
        node->next = list2;
    }

    return dummyNode->next;
}