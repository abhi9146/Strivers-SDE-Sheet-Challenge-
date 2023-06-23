#include <bits/stdc++.h> 
using namespace std;

class BinaryTreeNode
{
public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};


vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>>res;
    vector<int>pre,post,ino;
   
   if(!root) return res;
    stack<pair<BinaryTreeNode<int>*,int>>st;
    st.push({root,1});

    while(!st.empty()){
        auto it=st.top();st.pop();
        if(it.second==1) {
            pre.push_back(it.first->data);
            st.push({it.first,it.second+1});
            if(it.first->left) st.push({it.first->left,1});
        }
        else if(it.second==2){
            ino.push_back(it.first->data);
            st.push({it.first,it.second+1});
            if(it.first->right) st.push({it.first->right,1});
        }
        else{
            post.push_back(it.first->data);
        }
    }
    res.push_back(ino);
    res.push_back(pre);
    res.push_back(post);
    return res;
}






