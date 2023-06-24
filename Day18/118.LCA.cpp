


#include <bits/stdc++.h> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q) return root;
        
        TreeNode* lh=lowestCommonAncestor(root->left,p,q);
        TreeNode* rh=lowestCommonAncestor(root->right,p,q);
        
        if(!lh) return rh;
        if(!rh) return lh;
        return root;
    }
};