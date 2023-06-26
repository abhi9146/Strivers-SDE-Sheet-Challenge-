
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
    TreeNode* fun(vector<int>&nums,int st,int en){
       if(st>en) return NULL;
        int mid=(st+en)/2;
        
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=fun(nums,st,mid-1);
        root->right=fun(nums,mid+1,en);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int st=0,en=nums.size()-1;
        return fun(nums,st,en);
    }
};