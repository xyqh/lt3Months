#include "LeetCodeBase.h"

// 空间o(1)，时间o(n)
bool isPalindrome(ListNode* head) {
    ListNode *slow = head, *fast = head->next;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode *node = slow->next, *pre = nullptr;
    while(node){
        ListNode *next = node->next;
        node->next = pre;
        pre = node;
        node = next;
    }

    ListNode *slowEnd = slow;
    slow = head, node = pre;
    bool ans = true;
    while(ans && node != nullptr){
        if(slow->val != node->val){
            ans = false;
        }
        slow = slow->next;
        node = node->next;
    }
    node = pre, pre = nullptr;
    while(node){
        ListNode *next = node->next;
        node->next = pre;
        pre = node;
        node = next;
    }
    slowEnd->next = pre;

    return ans;
}