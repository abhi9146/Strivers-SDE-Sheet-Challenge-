
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fun(int ind,vector<int>&coins,int total,vector<vector<int>>&dp){
        if(ind==0){
          if(total%coins[0]==0) return total/coins[0];
          return 1e9;
        }

        if(dp[ind][total]!=-1) return dp[ind][total];

        int non_take = fun(ind-1,coins,total,dp);
        int take=1e9;
        if(total>=coins[ind]){
           take=1+fun(ind,coins,total-coins[ind],dp);
        }

        return dp[ind][total]=min(take,non_take);
    }

    int coinChange(vector<int>& coins, int total) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(total+1,-1));
      
        int res= fun(n-1,coins,total,dp);
        return res==1e9?-1:res;
    }
};