
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        queue<pair<int,int>>q;
        vector<int>vis(n,0);
        
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            q.push({i,-1});
            vis[i]=1;
            
          while(!q.empty()){
            auto it=q.front();q.pop();
            
            int node=it.first;
            int par=it.second;
            
            for(auto x:adj[node]){
                if(!vis[x]){
                    vis[x]=1;
                    q.push({x,node});
                }
                else if(x!=par) return 1;
            }
         }
        }
        return 0;
    }
};