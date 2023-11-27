#include "LeetCodeBase.h"

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
    ListNode *dummyNode = new ListNode(0), *node = dummyNode;
    int add = 0;
    while(l1 && l2){
        int sum = l1->val + l2->val + add;
        add = sum / 10;
        sum %= 10;
        node->next = new ListNode(sum);
        node = node->next;
        l1 = l1->next;
        l2 = l2->next;
    }

    while(l1){
        int sum = l1->val + add;
        add = sum / 10;
        sum %= 10;
        node->next = new ListNode(sum);
        node = node->next;
        l1 = l1->next;
    }
    while(l2){
        int sum = l2->val + add;
        add = sum / 10;
        sum %= 10;
        node->next = new ListNode(sum);
        node = node->next;
        l2 = l2->next;
    }

    if(add){
        node->next = new ListNode(add);
    }

    return dummyNode->next;
}