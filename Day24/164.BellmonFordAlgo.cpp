
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
   
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int>dist(V,1e8);
        dist[S]=0;
        
        for(int i=0;i<V-1;i++){
            for(auto x:edges){
                int u=x[0] , v=x[1] , wt=x[2];
                
                if(dist[u]!=1e8 && dist[u]+wt <dist[v]){
                    dist[v]=dist[u]+wt;
                }
                
            }
        }
        for(auto x:edges){
                int u=x[0] , v=x[1] , wt=x[2];
                
                if(dist[u]+wt <dist[v]){
                    return {-1};
                }
                
            }
        return dist;
    }
};