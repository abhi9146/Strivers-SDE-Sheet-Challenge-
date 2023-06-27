#include <bits/stdc++.h> 
using namespace std;

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };


int findCeil(BinaryTreeNode<int> *root, int x){
    int val=-1;
    while(root){
       if(root->data==x ) return root->data;
    if(root->data>x) {
        val=root->data;
        root=root->left;
    }
    else{
        root=root->right;
    }
     
    }
    
    return val;
}