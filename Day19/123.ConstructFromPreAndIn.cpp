
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
    TreeNode* fun(int preSt,int preEn,vector<int>& preorder,int inSt,int inEn, vector<int>& inorder,map<int,int>mp){
      if(preSt>preEn || inSt>inEn) return NULL;
      int node=preorder[preSt];
      TreeNode* root = new TreeNode(node);
         
      int ind=mp[node];
      int left=ind-inSt;

      root->left=fun(preSt+1,preSt+left,preorder,inSt,ind-1,inorder,mp);
      root->right=fun(preSt+left+1,preEn,preorder,ind+1,inEn,inorder,mp);

         return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       int n=inorder.size();
      
       map<int,int>mp;
       for(int i=0;i<n;i++){
         mp[inorder[i]]=i;
       }

       return fun(0,n-1,preorder,0,n-1,inorder,mp);
    }
};