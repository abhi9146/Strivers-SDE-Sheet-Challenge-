#include <bits/stdc++.h> 
using namespace std;

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

int v=0;
int floorInBST(TreeNode<int> * root, int X){
    if(root->left) floorInBST(root->left,X);
    if(X>=root->val) v=root->val;
    if(root->right) floorInBST(root->right,X);

    return v;
}