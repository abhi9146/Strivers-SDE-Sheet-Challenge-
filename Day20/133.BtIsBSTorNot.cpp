

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
    bool fun(TreeNode* root,long lo,long hi){
        if(root==NULL) return true;
        if(root->val<=lo || root->val>=hi) return false;
        
        bool left=fun(root->left,lo,root->val);
        bool right=fun(root->right,root->val,hi);

        return (left && right);
    }

    bool isValidBST(TreeNode* root) {
        return fun(root,LONG_MIN,LONG_MAX);
    }
};