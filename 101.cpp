#include "LeetCodeBase.h"

bool isSymmetric(TreeNode *left, TreeNode *right){
    if(left && right){
        return left->val == right->val && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }else if(!left && !right){
        return true;
    }
    return false;
}

bool isSymmetric(TreeNode* root) {
    if(root == nullptr) return true;
    return isSymmetric(root->left, root->right);
}