#include "LeetCodeBase.h"

TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr) return nullptr;
    TreeNode *newLeft = invertTree(root->right);
    TreeNode *newRight = invertTree(root->left);
    root->left = newLeft;
    root->right = newRight;
    return root;
}