#include "LeetCodeBase.h"

int rootSum(TreeNode *node, long targetSum){
    if(node == nullptr) return 0;

    int ret = 0;
    targetSum -= node->val;
    if(targetSum == 0){
        ++ret;
    }

    ret += rootSum(node->left, targetSum);
    ret += rootSum(node->right, targetSum);
    return ret;
}

int pathSum(TreeNode* root, int targetSum) {
    if(root == nullptr) return 0;

    int ret = rootSum(root, targetSum);
    ret += pathSum(root->left, targetSum);
    ret += pathSum(root->right, targetSum);
    return ret;
}