#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int>pq1;
    priority_queue<int,vector<int>,greater<int>>pq2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
      if(pq1.size()<=0){
        pq1.push(num);
        return;
      }
        if(pq1.size()==pq2.size()){
          if(pq2.top()<num){
            pq1.push(pq2.top());pq2.pop();
            pq2.push(num);
          }
          else pq1.push(num);
        }
        else{
          if(pq1.top()>num){
            pq2.push(pq1.top());pq1.pop();
            pq1.push(num);
          }
          else{
            pq2.push(num);
          }
        }
    }
    
    double findMedian() {
      //  cout<<pq1.top()<<" "<<pq2.top()<<endl;
        if(pq1.size()==pq2.size()) return double((pq1.top()+pq2.top())/2.0);
        return double(pq1.top());
    }
};