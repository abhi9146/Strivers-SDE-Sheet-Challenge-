
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
          int size=q.size();
          for(int i=0;i<size;i++){
             auto it=q.front();q.pop();
          if(!it) s+="#,";
          else{
             q.push(it->left);
             q.push(it->right);
             s+=(to_string(it->val)+',');
          }
          }
        }
       // cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;

        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
           auto node=q.front();q.pop();

           getline(s,str,',');
           if(str=="#"){
               node->left=NULL;
           }
           else{
               node->left=new TreeNode(stoi(str));
               q.push(node->left);
           }

           getline(s,str,',');
           if(str=="#"){
               node->right=NULL;
           }
           else{
               node->right=new TreeNode(stoi(str));
               q.push(node->right);
           }
        }
        return root;
    }
};
