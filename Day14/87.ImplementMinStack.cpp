
#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
      vector<pair<int,int>>v;
      int mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        mini=min(mini,val);
        v.push_back({val,mini});
    }
    
    void pop() {
        v.pop_back();
        if(v.size() != 0) mini = v[v.size()-1].second;
        else mini = INT_MAX;
    }
    
    int top() {
        return v[v.size()-1].first;
    }
    
    int getMin() {
        return v[v.size()-1].second;
    }
};