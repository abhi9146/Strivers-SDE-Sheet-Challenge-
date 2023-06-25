


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
    bool check(TreeNode* ls,TreeNode* rs){
       if(!ls and !rs) return true;
       if(!ls or !rs) return false;
       if(ls->val !=rs->val) return false;

       return check(ls->left,rs->right) and check(ls->right,rs->left);
       
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return check(root->left,root->right); 
    }
};