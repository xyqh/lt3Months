#include "LeetCodeBase.h"

int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> stk;
    TreeNode* node = root;
    while(node){
        stk.push(node);
        node = node->left;
    }

    while(!stk.empty()){
        node = stk.top();
        stk.pop();
        if(--k == 0){
            return node->val;
        }

        node = node->right;
        while(node){
            stk.push(node);
            node = node->left;
        }
    }

    return -1;
}