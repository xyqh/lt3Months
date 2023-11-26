#include "LeetCodeBase.h"

ListNode* reverseList(ListNode* head) {
    ListNode *pre = nullptr, *node = head;
    while(node){
        ListNode *next = node->next;
        node->next = pre;
        pre = node;
        node = next;
    }

    return pre;
}