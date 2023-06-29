#include <bits/stdc++.h> 
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int>ind(v,0);
    vector<int>adj[v];

    for(auto x:edges){
        adj[x[0]].push_back(x[1]);
        ind[x[1]]++;
    }
    queue<int>q;
    for(int i=0;i<v;i++)
      if(ind[i]==0) 
        q.push(i);
    vector<int>res;
    while(!q.empty()){
        auto node=q.front();q.pop();
        res.push_back(node);
        for(auto x:adj[node]){
            ind[x]--;
            if(ind[x]==0) q.push(x);
        }
    }
   return res;
}