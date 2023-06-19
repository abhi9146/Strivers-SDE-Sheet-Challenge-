#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>>st;
    int ind=0;
    StockSpanner() {
        st.push({-1,INT_MAX});
    }
    
    int next(int price) {
      while(st.top().first !=-1 && price>=st.top().second) st.pop();
      int res= ind-st.top().first;        
      st.push({ind++,price});

      return res;
    }
};