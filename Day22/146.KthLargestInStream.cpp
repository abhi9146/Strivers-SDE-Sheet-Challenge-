#include<bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    priority_queue <int, vector<int>, greater<int>> pq;
    int lim;
    KthLargest(int k, vector<int>& nums) {
      lim=k;
        for(auto x:nums){
          pq.push(x);
          if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>lim) pq.pop();
        return pq.top();
    }
};
