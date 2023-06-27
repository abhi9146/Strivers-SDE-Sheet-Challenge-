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
     int cnt=0,val;
    int kthSmallest(TreeNode* root, int k) {
       if(root->left) kthSmallest(root->left,k);
       cnt++;
       if(k==cnt){
           val=root->val;return val;
       } 
        if(root->right) kthSmallest(root->right,k);

        return val;
    }
};