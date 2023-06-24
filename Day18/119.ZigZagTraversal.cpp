
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        
        queue<TreeNode*>q;bool fl=0;
        q.push(root);

        while(!q.empty()){
           vector<int>tmp;
           int len=q.size();

           for(int i=0;i<len;i++){
             auto node=q.front();q.pop();
             tmp.push_back(node->val);
             if(node->left) q.push(node->left);
             if(node->right) q.push(node->right);
           }
           if(!fl) {fl=!fl;ans.push_back(tmp);}
           else{
             reverse(tmp.begin(),tmp.end());
             ans.push_back(tmp);
             fl=!fl;
           }
        }
        return ans;
    }
};