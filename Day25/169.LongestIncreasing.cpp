
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fun(int ind,vector<int>&nums,int n,int last_ind,vector<vector<int>>&dp){
          if(ind==n) return 0;
        
          if(dp[ind][last_ind+1]!=-1) return dp[ind][last_ind+1];
          int non_take=fun(ind+1,nums,n,last_ind,dp);
 
          int take=0;
          if(last_ind==-1 || nums[last_ind]<nums[ind]){
             take = 1+fun(ind+1,nums,n,ind,dp);
          }

          return dp[ind][last_ind+1]=max(take,non_take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return fun(0,nums,n,-1,dp);
    }
};