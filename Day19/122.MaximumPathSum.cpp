

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
    int fun(TreeNode* root,int &max_sum){
      if(!root) return 0;

      int left,right,node=root->val;
       left=max(0,fun(root->left,max_sum));
       right=max(0,fun(root->right,max_sum));

      max_sum=max(max_sum,left+right+node);
      return max(left,right)+node;
    }
    int maxPathSum(TreeNode* root) {
        int max_sum=INT_MIN;
        
        fun(root,max_sum);
        return max_sum;
    }
};