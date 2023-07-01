
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int fun(int f,int eggs,vector<int>&dp){
        if(f==0 || f==1) return f;
        if(eggs==1) return f;
        
        if(dp[f]!=-1) return dp[f];
        
        int res=INT_MAX;
        for(int k=1;k<=f;k++){
            int tmp=1+max(fun(k-1,eggs-1,dp),fun(f-k,eggs,dp));
            res=min(res,tmp);
        }
        
        return dp[f]=res;
    }
    int eggDrop(int n, int k){
        vector<int>dp(k+1,-1);
        return fun(k,n,dp);
    }
};