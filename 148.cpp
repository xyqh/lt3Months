#include "LeetCodeBase.h"

ListNode *sortList(ListNode *head){
    if(head == nullptr) return nullptr;
    vector<ListNode*> list;
    while(head){
        list.push_back(head);
        head = head->next;
    }

    sort(list.begin(), list.end(), [](ListNode *a, ListNode *b){
        return a->val < b->val;
    });
    ListNode *newHead = new ListNode(0), *node = newHead;
    for(ListNode *n:list){
        n->next = nullptr;
        node->next = n;
        node = node->next;
    }
    return newHead->next;
}

int main(){
    ListNode *node1 = new ListNode(4);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(1);
    ListNode *node4 = new ListNode(3);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    ListNode *node = sortList(node1);
    return 0;
}