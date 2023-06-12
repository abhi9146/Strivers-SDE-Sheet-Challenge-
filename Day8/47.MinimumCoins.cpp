// Problem Statement

/*
Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then return -1.
*/

#include<bits/stdc++.h>
using namespace std;

int find(int coins[], int ind, int total, vector<vector<int>>&dp){
	    if(ind==0){
	        if((total%coins[0])==0) return (total/coins[0]);
	        return 1e9;
	    }
	    if(dp[ind][total]!=-1) return dp[ind][total];
	    int non_take=find(coins,ind-1,total,dp);
	    int take=1e9;
	    if(coins[ind]<=total) take=1+find(coins,ind,total-coins[ind],dp);
	    //cout<<take<<" "<<non_take<<endl;
	    return dp[ind][total]=min(take,non_take);
	}
	int minCoins(int coins[], int M, int V) {
	   // sort(coins,coins+M);
	   vector<vector<int>>dp(M+1,vector<int>(V+1,-1));
	    return find(coins,M-1,V,dp)==1e9?-1:find(coins,M-1,V,dp);
	} 