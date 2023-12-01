#include "LeetCodeBase.h"

unordered_map<int, int> mp;

TreeNode* buildTree(vector<int>& preorder, int& idx, vector<int>& inorder, int il, int ir){
    if(idx >= preorder.size() || il > ir) return nullptr;
    int val = preorder[idx++];
    TreeNode *root = new TreeNode(val);
    if(il < ir){
        int m = mp[val];
        root->left = buildTree(preorder, idx, inorder, il, m - 1);
        root->right = buildTree(preorder, idx, inorder, m + 1, ir);
    }
    
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = inorder.size(), i = 0;
    for(int i = 0; i < n; ++i){
        mp[inorder[i]] = i;
    }

    return buildTree(preorder, i, inorder, 0, n - 1);
}