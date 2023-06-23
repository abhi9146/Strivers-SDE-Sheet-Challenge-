
#include <bits/stdc++.h> 
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int>res;
        if(!root) return res;
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
       // fun(root,mp,0);
        
        while(!q.empty()){
            auto node=q.front().first;
            auto line=q.front().second; q.pop();
            
            mp[line]=node->data;
            if(node->left) q.push({node->left,line-1});
            if(node->right) q.push({node->right,line+1});
        }
        
        for(auto it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};