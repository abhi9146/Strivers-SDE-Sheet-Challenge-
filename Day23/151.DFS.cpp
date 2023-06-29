#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs(int start, vector<int> adj[],int vis[],vector<int>&ans){
        ans.push_back(start);
        vis[start]=1;
        for(auto it:adj[start]){
            if(!vis[it]){
                dfs(it,adj,vis,ans);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        int vis[V]={0};
        vis[0]=1;
        dfs(0,adj,vis,ans);
        return ans;
    }
};