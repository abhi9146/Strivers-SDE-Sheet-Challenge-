// Problem Statement

/*
 You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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

 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* ans=new ListNode(NULL);
        ListNode* res=ans;
        while(l1 && l2){
            int temp=l1->val+l2->val+carry;
            ans->next=new ListNode(temp%10);
            carry=temp/10;
            l1=l1->next;
            l2=l2->next;
            ans=ans->next;
        }
         while(l1){
            int temp=l1->val+carry;
            ans->next=new ListNode(temp%10);
            carry=temp/10;
            l1=l1->next;
            ans=ans->next;
        }
        while(l2){
            int temp=l2->val+carry;
            ans->next=new ListNode(temp%10);
            carry=temp/10;
            l2=l2->next;
            ans=ans->next;
        }
        if(carry) ans->next=new ListNode(carry);
        return res->next;
}