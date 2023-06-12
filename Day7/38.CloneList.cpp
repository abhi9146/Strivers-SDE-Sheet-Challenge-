// Problem Statement

/*
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* helper(Node* head,unordered_map<Node*,Node* >& mp){
        if(head==NULL) return NULL;
        Node* newnode=new Node(head->val);
        mp[head]=newnode;
        newnode->next=helper(head->next,mp);

        //
        if(head->random){
            newnode->random=mp[head->random];
        }
        return newnode;
    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node* > mp;
        return helper(head,mp);
    }