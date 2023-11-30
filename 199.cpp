#include "LeetCodeBase.h"

vector<int> rightSideView(TreeNode* root) {
    if(root == nullptr) return {};
    vector<int> ans;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        int n = que.size();
        TreeNode *node = nullptr;
        for(int i = 0; i < n; ++i){
            node = que.front();
            que.pop();
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
        ans.push_back(node->val);
    }

    return ans;
}