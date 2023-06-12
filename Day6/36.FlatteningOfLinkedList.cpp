// Problem Statement

/*
  Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
*/


#include <bits/stdc++.h> 
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

 Node* merge(Node *l1 , Node *l2){
    if(!l1) return l2;
    if(!l2) return l1;
    
    if(l1->data <= l2->data){
        l1->bottom=merge(l1->bottom,l2);
        return l1;
    }
    else{
        l2->bottom=merge(l1,l2->bottom);
        return l2;
    }
}
/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root){
    if(root==NULL || root->next==NULL) return root;
    flatten(root->next);
    root=merge(root,root->next);
    return root;
}