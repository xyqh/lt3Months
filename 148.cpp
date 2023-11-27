#include "LeetCodeBase.h"

ListNode *mergeSortList(ListNode *head, ListNode *tail){
    if(head == tail){
        return head;
    }

    ListNode *slow = head, *fast = head;
    while(fast && fast != tail){
        slow = slow->next;
        fast = fast->next;
        if(fast == tail){
            break;
        }
        if(fast){
            fast = fast->next;
        }
    }
    ListNode *l1 = mergeSortList(head, slow);
    ListNode *l2 = mergeSortList(slow->next, tail);
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

ListNode *sortList(ListNode *head){
    ListNode *node = head;
    while(node->next){
        node = node->next;
    }
    return mergeSortList(head, node);
}