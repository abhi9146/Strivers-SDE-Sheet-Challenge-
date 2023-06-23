
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
private:
    void fun(TreeNode* root,map<int,map<int,multiset<int>>>&mp,int xaxis,int level){
        if(!root) return;
        mp[xaxis][level].insert(root->val);

        if(root->left) fun(root->left,mp,xaxis-1,level+1);
        if(root->right) fun(root->right,mp,xaxis+1,level+1);
        
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        fun(root,mp,0,0);

        vector<vector<int>>res;
        for(auto x:mp){
           vector<int>col;
           for(auto it:x.second){
              col.insert(col.end(),it.second.begin(),it.second.end());
           }
           res.push_back(col);
        }
        return res;
    }
};