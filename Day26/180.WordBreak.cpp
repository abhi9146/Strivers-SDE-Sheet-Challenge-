
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool fun(int ind,int n,string &s,map<string,int>&mp,vector<int>&dp){
        if(ind==n) return true;
        if(dp[ind]!=-1) return dp[ind];
        for(int i=ind;i<n;i++){
          if(mp.find(s.substr(ind,i-ind+1))!=mp.end() && fun(i+1,n,s,mp,dp)) 
              return dp[ind]= true;
        }
        return dp[ind]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        map<string,int>mp;
        for(auto x:wordDict) mp[x]++;
        
        vector<int>dp(n+1,-1);
        if(fun(0,n,s,mp,dp)) return true;
        return false;
    }
};