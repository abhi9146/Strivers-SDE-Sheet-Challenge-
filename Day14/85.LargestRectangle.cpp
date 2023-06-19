
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> previous_smaller(vector<int>&arr,int n){
       stack<int>st;vector<int>res(n);
       st.push(-1);

       for(int i=0;i<n;i++){
          int curr=arr[i]; 
          while(st.top()!=-1 && curr<=arr[st.top()]) st.pop();
          res[i]=st.top();

          st.push(i);
        }
        return res;
    }

    vector<int> next_smaller(vector<int>&arr,int n){
        stack<int>st;
        vector<int>res(n);
        st.push(n);

        for(int i=n-1;i>=0;i--){
          int curr=arr[i]; 
          while(st.top()!=n && curr<=arr[st.top()]) st.pop();
          if(st.top()==n) res[i]=n;
          else res[i]=st.top();

          st.push(i);
        }
        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next=next_smaller(heights,n);
        vector<int>prev=previous_smaller(heights,n);
        
        int max_area=INT_MIN;
        for(int i=0;i<n;i++){
          int area=(next[i]-prev[i]-1)*heights[i];
          max_area=max(max_area,area);
        }
        
        return max_area;
    }
};