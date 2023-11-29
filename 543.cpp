#include "LeetCodeBase.h"

int ans = 0;

int dfs(TreeNode *root){
    if(root == nullptr) return 0;
    int left = dfs(root->left);
    int right = dfs(root->right);
    ans = max(ans, left + right + 1);
    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    dfs(root);
    return max(0, ans - 1);
}