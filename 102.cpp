#include "LeetCodeBase.h"

vector<vector<int>> levelOrder(TreeNode* root) {
    if(root == nullptr) return {};
    vector<vector<int>> ans;
    queue<TreeNode*> que;
    que.push(root);
    TreeNode *node = nullptr;
    while(!que.empty()){
        int n = que.size();
        vector<int> tmp;
        for(int i = 0; i < n; ++i){
            node = que.front();
            que.pop();
            tmp.push_back(node->val);
            if(node->left){
                que.push(node->left);
            }
            if(node->right){
                que.push(node->right);
            }
        }
        ans.push_back(tmp);
    }

    return ans;
}