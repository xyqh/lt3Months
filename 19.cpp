#include "LeetCodeBase.h"

ListNode* removeNthFromEnd(ListNode* head, int n){
    int i = 0;
    ListNode *fast = head, *dummyNode = new ListNode(0), *slow = dummyNode;
    dummyNode->next = head;
    while(++i < n){
        fast = fast->next;
    }

    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;

    return dummyNode->next;
}

int main(){
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;

    ListNode *node = removeNthFromEnd(node1, 3);
    return 0;
}