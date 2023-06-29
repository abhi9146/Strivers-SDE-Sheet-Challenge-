
#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    int dfsreverse(int it,vector<int>adj[],vector<int>&vis){
         vis[it]=1;
         for(auto x:adj[it]){
             if(!vis[x]) dfsreverse(x,adj,vis);
         }
    }
    
	void reverse(int n,vector<vector<int>>&adj,vector<int>adjList[],vector<int>&vis){
	    for(int i=0;i<n;i++){
	        vis[i]=0;
	        for(auto x:adj[i]){
	            adjList[x].push_back(i);
	        }
	    }
	}
	
	void dfs(int i,vector<vector<int>>&adj,vector<int>&vis,stack<int>&st){
	        vis[i]=1;
	        for(auto x:adj[i]){
	            if(!vis[x]){
	            dfs(x,adj,vis,st);
	        }
	       }
	       st.push(i);
	       return;
	}
	public:
    int kosaraju(int V, vector<vector<int>>& v){
       vector<int>vis(V,0);
       stack<int>st;
       for(int i=0;i<V;i++){
           if(!vis[i]) dfs(i,v,vis,st);
       }
       
      // Reverse the edges 
       vector<int>adjList[V];
       reverse(V,v,adjList,vis);
       
       int cnt=0;
       while(!st.empty()){
           auto it=st.top();st.pop();
           
           if(!vis[it]){
               cnt++;
               dfsreverse(it,adjList,vis);
           }
       }
       return cnt;
    }
};