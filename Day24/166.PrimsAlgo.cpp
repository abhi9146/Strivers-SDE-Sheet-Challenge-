
#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        int sum=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(V,0);
        pq.push({0,0});
        
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(vis[node]) continue;
            vis[node]=1;
            
            sum+=wt;
            for(auto x:adj[node]){
                int adjNode=x[0] , adjwt=x[1];
                if(!vis[adjNode]){
                  pq.push({adjwt,adjNode});
                }
            }
        }
        return sum;
    }
};