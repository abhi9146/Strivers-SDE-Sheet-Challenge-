// Problem Statement

/*
  Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
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

  bool isPalindrome(ListNode* head) {
        
       if(head==NULL || head->next==NULL) return true;
        
       ListNode* slow=head;
       ListNode* fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse_list(slow->next);
        slow=slow->next;
        
        while(slow!=NULL){
           if(head->val!= slow->val) return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
    
    ListNode* reverse_list(ListNode* p){
        ListNode* prev=NULL;
        ListNode* next=NULL;
        
        while(p!=NULL){
            next=p->next;
            p->next=prev;
            prev=p;
            p=next;
        }
        return prev;
    }