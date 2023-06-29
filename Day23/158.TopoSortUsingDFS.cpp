#include <bits/stdc++.h> 
using namespace std;

void dfs(int node,vector<int>adj[],stack<int>&st,vector<int>&vis){
    vis[node]=1;
    for(auto x:adj[node]){
        if(!vis[x]) dfs(x,adj,st,vis);
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int>adj[v];

    for(auto x:edges){
        adj[x[0]].push_back(x[1]);
    }
    stack<int>st;
    vector<int>vis(v,0),res;
    for(int i=0;i<v;i++){
        if(!vis[i]) dfs(i,adj,st,vis);
    }
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
   return res;
}