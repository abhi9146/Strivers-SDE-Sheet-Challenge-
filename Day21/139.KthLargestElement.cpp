#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
    public:
    void inorder(Node *root,vector<int> &v){
        if(root==NULL)
            return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    int kthLargest(Node *root, int k){
        vector<int> v;
        inorder(root,v);
        if(k>v.size())
            return -1;
        return v[v.size()-k];
    }
};