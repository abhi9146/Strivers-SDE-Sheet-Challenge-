#include <bits/stdc++.h>
using namespace std;

class Queue {
    // Define the data members(if any) here.
    stack<int>s1,s2;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        while(!s1.empty()){
            s2.push(s1.top());s1.pop();
        }
         s1.push(val);
        while(!s2.empty()){
            s1.push(s2.top());s2.pop();
        }
    }

    int deQueue() {
        if(s1.size()>0){
           int tp=s1.top();
           s1.pop();
           return tp;
        } 
        return -1;
    }

    int peek() {
        if(s1.size()>0) return s1.top();
        return -1;
    }

    bool isEmpty() {
        return s1.size()==0;
    }
};