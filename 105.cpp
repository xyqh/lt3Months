    #include "LeetCodeBase.h"

    unordered_map<int, int> mp;

    TreeNode* buildTree(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir){
        int val = preorder[pl];
        TreeNode *root = new TreeNode(val);
        if(pl == pr) return root;
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0; i < n; ++i){
            mp[inorder[i]] = i;
        }

        return buildTree(preorder, 0, n - 1, inorder, 0, n - 1);
    }