
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fun(int ind,vector<int>&nums,int target,vector<vector<int>>&dp){
        if(ind<=0) return target==0;
        if(target<0) return false;
        if(dp[ind][target]!=-1) return dp[ind][target];
        int non_take=fun(ind-1,nums,target,dp);
        int take=0;
        if(target>=nums[ind]) take=fun(ind-1,nums,target-nums[ind],dp);
   
        return dp[ind][target]=(take|non_take);
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto x:nums) sum+=x;

        if(sum%2) return false;
        
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        return fun(n-1,nums,sum/2,dp);
    }
};