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
    int n = lists.size();
    if(n < 1) return nullptr;
    return mergeLists(lists, 0, n - 1);
}

int main(){
    ListNode *node1 = new ListNode(1);
    node1->next = new ListNode(4);
    node1->next->next = new ListNode(5);
    
    ListNode *node2 = new ListNode(1);
    node2->next = new ListNode(3);
    node2->next->next = new ListNode(4);

    ListNode *node3 = new ListNode(2);
    node3->next = new ListNode(6);

    vector<ListNode*> lists = {node1, node2, node3};
    ListNode *node = mergeKLists(lists);
    return 0;
}