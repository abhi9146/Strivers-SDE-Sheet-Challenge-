
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int fun(int ind,int wt[],int val[],int w,vector<vector<int>>&dp){
        if(ind==0){
            if(w>=wt[0]) return val[0];
            return 0;
        }
        if(dp[ind][w]!=-1) return dp[ind][w];
        
        int non_take=fun(ind-1,wt,val,w,dp);
        int take=0;
        if(w>=wt[ind]){
            take=val[ind]+fun(ind-1,wt,val,w-wt[ind],dp);
        }
        
        return dp[ind][w]=max(take,non_take);
    }
    int knapSack(int w, int wt[], int val[], int n) { 
       vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
       
       return fun(n-1,wt,val,w,dp);
    }
};