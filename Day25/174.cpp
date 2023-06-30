
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
   int  fun(int i,int j,int arr[],vector<vector<int>>&dp){
       if(i==j) return 0;
       
       if(dp[i][j]!=-1) return dp[i][j];
       
       int res=INT_MAX;
       for(int k=i;k<j;k++){
           int steps = arr[i-1]*arr[k]*arr[j] + fun(i,k,arr,dp) + fun(k+1,j,arr,dp);
           res=min(res,steps);
       }
       
       return dp[i][j]=res;
   }
    int matrixMultiplication(int n, int arr[]){
       vector<vector<int>>dp(n,vector<int>(n,-1));
       return fun(1,n-1,arr,dp);
    }
};