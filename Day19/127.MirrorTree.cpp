

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

class Solution {
  public:
   
    void mirror(Node* node) {
        if(!node) return;
        if(node->left) mirror(node->left);
        if(node->right) mirror(node->right);
        
        Node* tmp=node->left;
        node->left=node->right;
        node->right=tmp;
    }
};