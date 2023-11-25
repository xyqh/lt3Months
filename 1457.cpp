#include "LeetCodeBase.h"

int ans = 0;
int cnt = 0;

// 二叉树的路径指从根节点到叶子节点所经过的所有节点的集合
void dfs(TreeNode *node){
    cnt ^= (1 << node->val);
    if(!node->left && !node->right){
        // 最低位的1置0
        if((cnt & cnt - 1) == 0){
            ++ans;
        }
    }else{
        if(node->left) dfs(node->left);
        if(node->right) dfs(node->right);
    }
    cnt ^= (1 << node->val);
}

int pseudoPalindromicPaths (TreeNode* root) {
    dfs(root);
    return ans;
}

int main(){
    TreeNode *node1 = new TreeNode(3, new TreeNode(3), new TreeNode(1));
    TreeNode *node2 = new TreeNode(1, nullptr, new TreeNode(1));
    TreeNode *root = new TreeNode(2, node1, node2);
    pseudoPalindromicPaths(root);
    return 0;
}