
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fun(string w1, string w2,int i,int j,vector<vector<int>>&dp){
      if(j<0){
         return i+1;
      }
      if(i<0) return j+1;
      if(dp[i][j]!=-1) return dp[i][j];

      int ans=INT_MAX;
      if(w1[i]==w2[j]){
        ans=fun(w1,w2,i-1,j-1,dp);
      }
      int delet = 1+fun(w1,w2,i-1,j,dp);
      int update= 1+fun(w1,w2,i-1,j-1,dp);
      int insert= 1+fun(w1,w2,i,j-1,dp);


      return dp[i][j]=min({ans,delet,update,insert});
    }

    int minDistance(string w1, string w2) {
        if(w1.size()<=0) return w2.size();
        vector<vector<int>>dp(w1.size(),vector<int>(w2.size(),-1));
        return fun(w1,w2,w1.size()-1,w2.size()-1,dp);
    }
};