#include "LeetCodeBase.h"

int ans = INT_MIN;

int maxGain(TreeNode* root){
    if(root == nullptr) return 0;

    int ret = root->val;
    int left = max(maxGain(root->left), 0);
    int right = max(maxGain(root->right), 0);
    ans = max(ans, ret + left + right);

    return ret + max(left, right);
}

int maxPathSum(TreeNode *root){
    maxGain(root);
    return ans;
}