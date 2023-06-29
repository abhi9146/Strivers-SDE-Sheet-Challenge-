#include<bits/stdc++.h>
using namespace std;

int topoSort(int V, vector<int> adj[]) {
	    int cnt=0;vector<int>indeg(V+1,0);
	   for(int i=1;i<=V;i++){
	       for(auto x:adj[i]){
	        indeg[x]++;
	    }
	   }
	   queue<int>q;
	   for(int i=1;i<=V;i++){
	       if(indeg[i]==0) q.push(i);
	   }
	   
	   while(!q.empty()){
	       auto x=q.front();q.pop();
	        cnt++;
	       
	       for(auto it:adj[x]){
	           indeg[it]--;
	           if(indeg[it]==0) q.push(it);
	       }
	   }
	   return cnt!=V;
	}
bool detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<int>adj[n+1];

    for(auto x:edges){
        adj[x.first].push_back(x.second);
    }

    return topoSort(n,adj);
}