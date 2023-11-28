#include "LeetCodeBase.h"

vector<int> inorderTraversal(TreeNode* root) {
    if(root == nullptr) return {};
    stack<TreeNode*> stk;
    vector<int> inorder;
    stk.push(root);
    TreeNode *node = stk.top();
    while(node->left){
        node = node->left;
        stk.push(node);
    }

    while(!stk.empty()){
        node = stk.top();
        stk.pop();
        inorder.push_back(node->val);
        if(node->right){
            node = node->right;
            stk.push(node);
            while(node->left){
                node = node->left;
                stk.push(node);
            }
        }
    }

    return inorder;
}