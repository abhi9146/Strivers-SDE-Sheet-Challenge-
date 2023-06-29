
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n+1];

        for(int i=0;i<n;i++){
           for(auto x:graph[i]){
             adj[i].push_back(x);
             adj[x].push_back(i);
           }
        }

        queue<int>q;
        vector<int>vis(n,0),col(n);
        for(int i=0;i<n;i++){
           if(!vis[i]){
             q.push(i);
             col[i]=1;
             vis[i]=1;

             while(!q.empty()){
               auto node=q.front();
               q.pop();

               for(auto it:adj[node]){
                  if(!vis[it]){
                    vis[it]=1;
                    col[it]=!col[node];
                    q.push(it);
                  }
                  else{
                    if(col[it]==col[node]) return 0;
                  }
               }
             }
           }
        }
        //for(auto x:col) cout<<x<<" ";
        return 1;
    }
};