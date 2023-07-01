
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool check(string str,int lo,int hi){
        while(lo<hi){
            if(str[lo]!=str[hi]) return false;
            lo++;hi--;
        }
        return true;
    }
    int fun(int ind,string str,int n,vector<int>&dp){
        if(ind==n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int res=INT_MAX;
        
        for(int i=ind;i<n;i++){
            if(check(str,ind,i)){
                res=min(res,1+fun(i+1,str,n,dp));
            }
        }
        return dp[ind]=res;
    }
    
    int palindromicPartition(string str){
        int n=str.size();
        vector<int>dp(n,-1);
        return fun(0,str,n,dp)-1;
    }
};