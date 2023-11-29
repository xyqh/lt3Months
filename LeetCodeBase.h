#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<iostream>
#include<limits.h>
#include<math.h>

using namespace std;

struct ListNode
{
    ListNode *next;
    int val;
    ListNode(int _val):
        val(_val),
        next(nullptr)
        {};
};

struct Node
{
    Node *left;
    Node *right;
    Node *next;
    Node *random;
    int val;
    Node(int _val):
        val(_val),
        left(nullptr),
        right(nullptr),
        next(nullptr),
        random(nullptr)
        {};
};

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int _val):
        val(_val),
        left(nullptr),
        right(nullptr)
        {};
    
    TreeNode(int _val, TreeNode *_left, TreeNode *_right):
        val(_val),
        left(_left),
        right(_right)
        {};
};

vector<int> serializeListNode(ListNode *node){
    vector<int> serialize;
    while(node){
        serialize.push_back(node->val);
        node = node->next;
    }
    return serialize;
}

ListNode* DeSerializeListNode(const vector<int>& lists){
    int n = lists.size();
    if(n == 0){
        return nullptr;
    }
    ListNode *dummyNode = new ListNode(0), *node = dummyNode;
    for(const int &val:lists){
        node->next = new ListNode(val);
        node = node->next;
    }
    return dummyNode->next;
}

vector<string> serializeTreeNode(TreeNode *root){
    queue<TreeNode*> que;
    vector<string> serialize;
    que.push(root);
    bool nextAllNullptr = false;
    while(!nextAllNullptr && !que.empty()){
        nextAllNullptr = true;
        int n = que.size();
        TreeNode *node = nullptr;
        for(int i = 0; i < n; ++i){
            node = que.front();
            que.pop();
            serialize.push_back(node ? to_string(node->val) : "null");
            que.push(node ? node->left : nullptr);
            que.push(node ? node->right : nullptr);
            if(node && (node->left || node->right)){
                nextAllNullptr = false;
            }
        }
    }

    return serialize;
}

TreeNode *createTreeNode(const string& str){
    if(str == "null") return nullptr;
    return new TreeNode(atoi(str.c_str()));
}

TreeNode *DeSerializeTreeNode(const vector<string>& nodes){
    int n = nodes.size(), i = 0;
    if(n < 1) return nullptr;
    string val = nodes[i++];
    TreeNode *node = createTreeNode(val);
    if(node == nullptr){
        return nullptr;
    }
    TreeNode *root = node;
    queue<TreeNode*> que;
    que.push(node);
    while(i < n){
        node = que.front();
        que.pop();
        TreeNode *left = nullptr, *right = nullptr;
        if(node){
            node->left = left = createTreeNode(nodes[i++]);
            node->right = right = createTreeNode(nodes[i++]);
        }
        que.push(left);
        que.push(right);
    }
    return root;
}