
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fun(int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
       if(n==0 && m==0) return grid[0][0];
       if(n<0 || m<0) return 500;

       if(dp[n][m] !=-1) return dp[n][m];
       
       int ans=grid[n][m];
       int left=fun(n-1,m,grid,dp);
       int up=fun(n,m-1,grid,dp);
       
       return dp[n][m]=ans+min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size() , m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
         
        return fun(n-1,m-1,grid,dp);
    }
};