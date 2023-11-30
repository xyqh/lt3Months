    #include "LeetCodeBase.h"
    
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* pre = nullptr, *cur = nullptr;
        while(!stk.empty()){
            cur = stk.top();
            stk.pop();
            if(pre != nullptr){
                pre->right = cur;
            }
            if(cur->right) stk.push(cur->right);
            if(cur->left) stk.push(cur->left);
            cur->left = nullptr;
            pre = cur;
        }
    }