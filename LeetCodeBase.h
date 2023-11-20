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