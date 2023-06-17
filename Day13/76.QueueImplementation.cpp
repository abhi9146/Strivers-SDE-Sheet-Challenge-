#include <bits/stdc++.h> 
using namespace std;

class Queue {
public:
    int fr=0,rear=0;
    vector<int>arr;
    Queue() {
        arr.resize(5000);
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return (fr==rear);
    }

    void enqueue(int data) {
        arr[rear++]=data;
    }

    int dequeue() {
       if(rear!=fr) return arr[fr++];
       return -1;
    }

    int front() {
       if(rear!=fr) return arr[fr];
       return -1;
    }
};