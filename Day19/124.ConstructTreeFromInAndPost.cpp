
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
    TreeNode* create(vector<int>& inorder,int instart,int inend, vector<int>& postorder,int poststart,int postend,unordered_map<int,int>&ma){
        
        if(instart>inend || poststart > postend) return NULL;
        TreeNode* root=new TreeNode(postorder[postend]);
        
        int loc=ma[postorder[postend]];
        int left=loc-instart;
        
        root->left=create(inorder,instart,loc-1,postorder,poststart,poststart+left-1,ma);
        root->right=create(inorder,loc+1,inend,postorder,poststart+left,postend-1,ma);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>ma;
        for(int i=0;i<inorder.size();i++) ma[inorder[i]]=i;
        
        return create(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,ma);
       
    }
};