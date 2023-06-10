// Problem Statement

/*
  Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
  There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
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

 ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
         ListNode*  curr=head;
         ListNode* tmp=head;
         int size=1;
        
          while(tmp->next) size++,tmp=tmp->next;
            tmp->next=head;
        
         k=k%size;
        if(k){
           for(auto i=0; i<size-k; i++) tmp = tmp->next; 
         }
        head=tmp->next;
        tmp->next=NULL;
        
        return head;
    }