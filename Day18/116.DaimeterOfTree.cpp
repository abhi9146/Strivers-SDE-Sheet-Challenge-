
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
    
    int find(TreeNode* root,int& daimeter){
        if(root==NULL) return 0;
        int lh=find(root->left,daimeter);
        int rh=find(root->right,daimeter);
        
        daimeter=max(daimeter,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int daimeter=0;
        find(root,daimeter);
        return daimeter;
    }
};