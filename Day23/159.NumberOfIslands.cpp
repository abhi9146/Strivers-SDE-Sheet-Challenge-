#include<bits/stdc++.h>
using namespace std;

int dx[8]={-1,1,0,0,-1,1,-1,1};
int dy[8]={0,0,-1,1,-1,1,1,-1};

void dfs(int i,int j,int n,int m,vector<vector<int>>&vis,int** arr){
  if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || arr[i][j]==0){
      return;
  }
  vis[i][j]=1;
  for(int ind=0;ind<8;ind++){
     int newi=i+dx[ind];
     int newj=j+dy[ind];

     dfs(newi,newj,n,m,vis,arr);
  }
}
int getTotalIslands(int** arr, int n, int m){
     vector<vector<int>>vis(n,vector<int>(m,0));
     int cnt=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(arr[i][j]==1 && vis[i][j]==0){
              cnt++;
              dfs(i,j,n,m,vis,arr);
           }
        }
     }
     return cnt;
}
