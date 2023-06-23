#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class TreeNode {
    public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int getMaxWidth(TreeNode<int> *root)
{
   if(!root) return 0;
   int ans=0;
   queue<pair<TreeNode<int>*,int>>q;
   q.push({root,0});
   

   while(!q.empty()){
       int siz=q.size();
       int mini=q.front().second;
       int first,last;
       ans=max(ans,siz);
       for(int i=0;i<siz;i++){
           auto node=q.front().first;
           int cur=q.front().second-mini;q.pop();
           
           if(i==0) first=cur;
           if(i==siz-1) last=cur;

           if(node->left){
               q.push({node->left,2*cur+1});
           }
           if(node->right){
               q.push({node->right,2*cur+2});
           }
       }
       //ans=max(ans,last-first+1);
   }
    return ans;
}