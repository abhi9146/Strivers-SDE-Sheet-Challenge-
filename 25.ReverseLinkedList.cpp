
// Problem Statement

/*
 Given the head of a singly linked list, reverse the list, and return the reversed list
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
 
ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev=head;
        ListNode* tmp;
        while(head->next){
          tmp=head->next;
          if(prev==head) head->next=NULL;
          else head->next=prev;
          prev=head;
          head=tmp;
        }
        head->next=prev;
        return head;
    }