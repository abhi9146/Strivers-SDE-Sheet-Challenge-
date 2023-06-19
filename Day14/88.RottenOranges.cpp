#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<vector<int>>q;
        int fresh=0;
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(grid[i][j]==2) {vis[i][j]=1;q.push({i,j,0});}
            else if(grid[i][j]==1) fresh++;
          }
        }
         
        int max_time=0;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        //cout<<q.size();
        while(!q.empty()){
          auto it=q.front();q.pop();
          int i=it[0],j=it[1],ti=it[2];
            
          max_time=max(max_time,ti);
          for(int ind=0;ind<4;ind++){
            int newi=dx[ind]+i;
            int newj=dy[ind]+j;

            if(newi>=0 && newj>=0 && newi<n && newj<m && grid[newi][newj]==1 && vis[newi][newj]==0){
              fresh--;
              q.push({newi,newj,ti+1});
              vis[newi][newj]=1;
            }
          }
        }
        
        if(fresh!=0) return -1;
        return max_time;
    }
};