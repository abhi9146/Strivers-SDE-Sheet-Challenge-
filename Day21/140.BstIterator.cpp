#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        find_left(root);
    }

    bool hasNext(){
        if (st.empty())
            return false;
        return true;
    }

    int next() {
        TreeNode* top = st.top();
        st.pop();
        if (top->right)
            find_left(top->right);
            
        return top->val;
    }

    void find_left(TreeNode* root){
        TreeNode* p = root;
        while (p){
            st.push(p);
            p = p->left;
        }
    }
};
