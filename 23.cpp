#include "LeetCodeBase.h"

ListNode *mergeLists(vector<ListNode*>& lists, int l, int r){
    if(l == r){
        return lists[l];
    }

    int m = l + (r - l >> 1);
    ListNode *l1 = mergeLists(lists, l, m);
    ListNode *l2 = mergeLists(lists, m + 1, r);
    ListNode *newHead = new ListNode(0), *node = newHead;
    while(l1 && l2){
        if(l2->val < l1->val){
            node->next = l2;
            l2 = l2->next;
        }else{
            node->next = l1;
            l1 = l1->next;
        }
        node = node->next;
    }
    if(l1){
        node->next = l1;
    }
    if(l2){
        node->next = l2;
    }
    
    return newHead->next;
}

ListNode *mergeKLists(vector<ListNode*>& lists){
    return mergeLists(lists, 0, lists.size() - 1);
}