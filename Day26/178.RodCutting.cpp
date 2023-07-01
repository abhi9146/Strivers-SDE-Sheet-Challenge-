
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fun(int st,int en,vector<int>&cuts,vector<vector<int>>&dp){
         if(st>en) return 0;
         if(dp[st][en]!=-1) return dp[st][en];

         int res=INT_MAX;
         for(int i=st;i<=en;i++){
            int cost=(cuts[en+1]-cuts[st-1]) + fun(st,i-1,cuts,dp) + fun(i+1,en,cuts,dp);
            res=min(res,cost);
         } 
         return dp[st][en]=res;
    }

    int minCost(int n, vector<int>& cuts) {
         int c = cuts.size();
         cuts.insert(cuts.begin(),0);
         cuts.push_back(n);

         sort(cuts.begin(),cuts.end());
         vector<vector<int>> dp(c+1,vector<int>(c+1,-1));

        return fun(1,c,cuts,dp);
    }
};