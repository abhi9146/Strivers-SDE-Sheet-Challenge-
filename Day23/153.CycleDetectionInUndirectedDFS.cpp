#include<bits/stdc++.h>
using namespace std;

bool dfs(int ind,int par,vector<int>adj[],vector<int>&vis){
     vis[ind]=1;
     for(auto x:adj[ind]){
         if(!vis[x]){
             if(dfs(x,ind,adj,vis)) return 1; 
         }
         else{
             if(x!=par) return 1;
         }
     }
     return 0;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m){
    vector<int>vis(n+1,0);
    vector<int>adj[n+1];

    for(auto x:edges){
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,-1,adj,vis)) return "Yes";
        }
    }
    return "No";
}
