
#include<bits/stdc++.h>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void fun(vector<vector<int>>&grid,int i,int j,int ne,int old){
     int n=grid.size() , m=grid[0].size();
     if(i<0 || j<0 || i>=n || j>=m) return;
     if(grid[i][j]!=old || grid[i][j]==ne) return;

     grid[i][j]=ne;

     for(int ind=0;ind<4;ind++){
         int newi=dx[ind]+i;
         int newj=dy[ind]+j;

         fun(grid,newi,newj,ne,old);
     }

}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor){
    vector<vector<int>>grid=image;
    int old=grid[x][y];
    fun(grid,x,y,newColor,old);

    return grid;
}