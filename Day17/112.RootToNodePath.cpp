#include <bits/stdc++.h> 
using namespace std;

template <typename T = int>
class TreeNode
{
    public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

bool fun(TreeNode<int>*root , vector<int>&path,int x){
      if(!root) return false;
	  path.push_back(root->data);
	  if(root->data==x) return true;

	  if(fun(root->left,path,x) || fun(root->right,path,x)) return true;
	  path.pop_back();

	  return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x){
     vector<int>path;
	 if(fun(root,path,x)) return path;
	 //return -1;
	  
}
