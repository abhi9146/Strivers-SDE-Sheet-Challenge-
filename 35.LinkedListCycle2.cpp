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


ListNode *detectCycle(ListNode *head) {
      if(!head or !head->next) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast and fast->next){
          slow=slow->next;
          fast=fast->next->next;
          if(slow==fast) break;
        }
        if(slow!=fast) return NULL;
        while(head!=fast){
          fast=fast->next;
          head=head->next;
        }
        return head;
    }