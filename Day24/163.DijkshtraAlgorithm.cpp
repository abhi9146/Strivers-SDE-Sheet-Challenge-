
#include<bits/stdc++.h>
using namespace std;

class solve{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        vector<int>dist(n,1e9);
        dist[s]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,s});
        
        while(!pq.empty()){
            int node=pq.top().second;
            int dist_till=pq.top().first;pq.pop();
            
            for(auto x:adj[node]){
                int adjNode=x[0];
                int wt=x[1];
                
                if(wt+dist[node] <dist[adjNode]){
                    dist[adjNode]=wt+dist[node];
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};