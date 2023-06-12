// Problem Statement

/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
*/


// Problem Statement

#include <bits/stdc++.h> 
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int>m;
        while(headA){
            m[headA]++;
            headA=headA->next;
        }
        while(headB){
           if(m[headB]>0) return headB;
            headB=headB->next;
        }
        return NULL;
    }