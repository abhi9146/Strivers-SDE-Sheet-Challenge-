
#include<bits/stdc++.h>
using namespace std;

class Solution{
	
	public:
	int fun(int ind,int arr[],int n,int prev_ind,vector<vector<int>>&dp){
	    if(ind==n){
	        return 0;
	    }
	    
	    if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
	    
	    int non_take=fun(ind+1,arr,n,prev_ind,dp);
	    int take=-1;
	    
	    if(prev_ind==-1 || arr[prev_ind]<arr[ind]){
	        take=arr[ind]+fun(ind+1,arr,n,ind,dp);
	    }
	    
	    return dp[ind][prev_ind+1]=max(take,non_take);
	}
	int maxSumIS(int arr[], int n)  {  
	    vector<vector<int>>dp(n,vector<int>(n+1,-1));
	    return fun(0,arr,n,-1,dp);
	}  
};