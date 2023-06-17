#include <bits/stdc++.h> 
using namespace std;

class Stack {
	queue<int>q1,q2;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
       return q1.size();
    }

    bool isEmpty() {
        return q1.size()==0;
    }

    void push(int element) {
        q2.push(element);
        while(!q1.empty()) {
            q2.push(q1.front());q1.pop();
        }
        swap(q1,q2);
    }

    int pop() {
       if(q1.size()>0){
           int tp=q1.front();
           q1.pop();
           return tp;
       }
       return -1;
    }

    int top() {
        if(q1.size()>0) return q1.front();
        return -1;
    }
};