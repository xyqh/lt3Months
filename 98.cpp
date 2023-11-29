#include "LeetCodeBase.h"

bool isValidBST(TreeNode* root) {
    if(root == nullptr) return true;
    stack<TreeNode*> stk;
    TreeNode *node = root;
    while(node){
        stk.push(node);
        node = node->left;
    }

    int pre = -1;
    bool checkFirst = false;
    while(!stk.empty()){
        node = stk.top();
        stk.pop();
        if(!checkFirst){
            checkFirst = true;
            pre = node->val;
        }else{
            if(pre >= node->val){
                return false;
            }
            pre = node->val;
        }

        node = node->right;
        while(node){
            stk.push(node);
            node = node->left;
        }
    }

    return true;
}