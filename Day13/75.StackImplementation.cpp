#include <bits/stdc++.h> 
using namespace std;

// Stack class.
class Stack {
    
public:
    int n,tp=-1;
    vector<int>arr;
    Stack(int capacity) {
        n=capacity;
        arr.resize(capacity);
    }

    void push(int num) {
        if(tp<(n-1)) arr[++tp]=num;
    }

    int pop() {
       if(tp>-1) return arr[tp--];
       return -1;
    }
    
    int top() {
        if(tp!=-1) return arr[tp];
        return -1;
    }
    
    int isEmpty() {
       if(tp==-1) return 1;
       return 0;
    }
    
    int isFull() {
        if(tp==n) return 1;
        return 0;
    }
    
};