#include "LeetCodeBase.h"

ListNode *reverse(ListNode *start, ListNode *curEnd){
    ListNode *pre = curEnd->next, *node = start, *next = nullptr;
    while(true){
        next = node->next;
        node->next = pre;
        pre = node;
        node = next;
        if(pre == curEnd){
            break;
        }
    }

    return pre;
}

ListNode *reverseKGroup(ListNode *head, int k){
    ListNode *dummyNode = new ListNode(0), *node = dummyNode, *endNode = dummyNode;
    dummyNode->next = head;

    int i = 0;
    while(endNode->next && i < k){
        endNode = endNode->next;
        if(++i == k){
            i = 0;
            ListNode *preEnd = node->next;
            node->next = reverse(preEnd, endNode);
            node = preEnd;
            endNode = preEnd;
        }
    }

    return dummyNode->next;
}

int main(){
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    ListNode *node = reverseKGroup(node1, 2);
    return 0;
}