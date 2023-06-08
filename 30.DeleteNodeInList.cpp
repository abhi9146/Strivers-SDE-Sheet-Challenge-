
// Problem Statement

/*
 There is a singly-linked list head and we want to delete a node node in it.
 You are given the node to be deleted node. You will not be given access to the first node of head.
 All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.
*/


#include <bits/stdc++.h> 
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

void deleteNode(ListNode* node) {
    ListNode* temp=node;
    temp=temp->next;
    int data=temp->val;
    temp->val=node->val;
    node->val=data;
    
    node->next=temp->next;
    delete(temp);
}