#include "LeetCodeBase.h"

TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r){
    if(r < l) return nullptr;
    if(l == r) return new TreeNode(nums[l]);
    int m = l + (r - l >> 1);
    TreeNode *node = new TreeNode(nums[m]);
    node->left = sortedArrayToBST(nums, l, m - 1);
    node->right = sortedArrayToBST(nums, m + 1, r);
    return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}