

#include <bits/stdc++.h> 
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root){
        vector<int>res;
        if(!root) return res;
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        
        q.push({root,0});
        
        while(!q.empty()){
            auto node=q.front().first;
            auto line=q.front().second;q.pop();
            
            if(mp.find(line)==mp.end()) mp[line]=node->data;
            if(node->left) q.push({node->left,line-1});
            if(node->right) q.push({node->right,line+1});
        }
        
        for(auto x:mp){
            res.push_back(x.second);
        }
        return res;
    }

};