
// Problem Statement

/*
  There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
  Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
  The test cases are generated so that the answer will be less than or equal to 2 * 109.
*/

#include <bits/stdc++.h> 
using namespace std;

int count(int n,int m,vector<vector<int>>&dp){
	if(n==0 && m==0) return 1;
	if(n<0 || m<0) return 0;

    if(dp[n][m]!=-1) return dp[n][m];
	int left=count(n,m-1,dp);
	int right=count(n-1,m,dp);

	return dp[n][m]=left+right;
}
int uniquePaths(int m, int n) {
	vector<vector<int>>dp(m,vector<int>(n,-1));
	return count(m-1,n-1,dp);
}
