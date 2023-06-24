
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
public:
    int isLeaf(Node *root){
        if(!root->left && !root->right) return 1;
        return 0;
    }
    void addLeftBoundry(Node* root,vector<int>&res){
       Node* curr=root->left;
       while(curr){
           if(!isLeaf(curr)) res.push_back(curr->data);
           if(curr->left) curr=curr->left;
           else curr=curr->right;
       }
    }
    void addLeaves(Node *root,vector<int>&res){
        
        if(isLeaf(root)) {res.push_back(root->data);return;}
        if(root->left) addLeaves(root->left,res);
        if(root->right) addLeaves(root->right,res);
    }
    void addRightBoundry(Node *root,vector<int>&res){
        Node *curr=root->right;
        vector<int>tmp;
        while(curr){
            if(isLeaf(curr)==0) tmp.push_back(curr->data);
            if(curr->right) curr=curr->right;
            else curr=curr->left;
        }
        for(int i=tmp.size()-1;i>=0;i--){
            res.push_back(tmp[i]);
        }
    }
    
    
    vector <int> boundary(Node *root){
       
       vector<int>res;
       if(!root) return res;
       if(!isLeaf(root)) res.push_back(root->data);
       
       addLeftBoundry(root,res);
       addLeaves(root,res);
       addRightBoundry(root,res);
       
       return res;
    }
};
