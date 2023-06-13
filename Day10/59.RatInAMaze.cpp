

// Problem Statement

/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.
*/

#include<bits/stdc++.h>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void fun(int i,int j,vector<vector<int>>&mat, int n,string &tmp,vector<string>&res,vector<vector<int>>&vis){
    if(i<0 || j<0 || i>=n || j>=n) return;
    if(mat[i][j]==0 || vis[i][j]==1) return ;
    
    if(i==n-1 && j==n-1)  {res.push_back(tmp);return;}
    
    vis[i][j]=1;
    for(int ind=0;ind<4;ind++){
        int newi=dx[ind]+i;
        int newj=dy[ind]+j;
        
        
        if(dx[ind]==0){
            if(dy[ind]==-1) tmp+='L';
            else tmp+='R';
        }
        else{
            if(dx[ind]==-1) tmp+='U';
            else tmp+='D';
        }
        fun(newi,newj,mat,n,tmp,res,vis);
        tmp.pop_back();
    }
        vis[i][j]=0;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string>res;
    string tmp="";
    
    vector<vector<int>>vis(n,vector<int>(n,0));
    
    fun(0,0,m,n,tmp,res,vis);
    //for(auto x:res) cout<<x<<" ";
    return res;
}