
#include <bits/stdc++.h> 
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//Function to return a list containing elements of left view of the binary tree.
void left_view(vector<int>&ans,Node* root,int level){
     if(!root) return;
     if(ans.size()==level){
         ans.push_back(root->data);
     }
     if(root->left) left_view(ans,root->left,level+1);
     if(root->right) left_view(ans,root->right,level+1);
     
}
vector<int> leftView(Node *root)
{
   vector<int>ans;
   int l=0;
   left_view(ans,root,l);
   return ans;
}