
#include<bits/stdc++.h>
using namespace std;

class Solution{
   bool dfs(int node,vector<int>adj[],vector<int>&col,vector<int>&vis,int c){
         col[node]=c;
         vis[node]=1;

         for(auto x:adj[node]){
           if(!vis[x]){
             if(dfs(x,adj,col,vis,!c)==0) return 0;
           }
           else{
             if(col[x]==col[node]) return 0;
           }
         }
         return 1;
   }

   public:
   bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];

        for(int i=0;i<n;i++){
           for(auto x:graph[i]){
             adj[i].push_back(x);
             adj[x].push_back(i);
           }
        }
       vector<int>vis(n,0),col(n,0);
       for(int i=0;i<n;i++){
         if(!vis[i]){
          if(dfs(i,adj,col,vis,0)==0) return 0;
         }
       }
       return 1;
   }
};