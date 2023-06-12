// Problem Statement

/*
 Given the head of a singly linked list, return the middle node of the linked list.
 If there are two middle nodes, return the second middle node.
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

 ListNode* middleNode(ListNode* head) {
        ListNode* sl=head;
        ListNode* ft=head;
        
        while(ft and ft->next){
            sl=sl->next;
            ft=ft->next->next;
        }
        return sl;
    }