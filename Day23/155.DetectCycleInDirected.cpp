#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int topoSort(int V, vector<int> adj[]) {
	    int cnt=0;vector<int>indeg(V,0);
	   for(int i=0;i<V;i++){
	       for(auto x:adj[i]){
	        indeg[x]++;
	    }
	   }
	   queue<int>q;
	   for(int i=0;i<V;i++){
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
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
         return topoSort(V,adj);
    }
};