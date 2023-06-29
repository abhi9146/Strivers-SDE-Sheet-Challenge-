
#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1,1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
	public:
    int spanningTree(int n, vector<vector<int>> adj[]){
        DisjointSet ds(n);
           vector<pair<int,pair<int,int>>> vp;
        
        for(int i=0;i<n;i++){
            for(auto x:adj[i]){
                vp.push_back({x[1],{x[0],i}});
            }
        }
        
        sort(vp.begin(),vp.end());
        int sum=0;
        
        for(auto it:vp){
            int u=it.second.first , v=it.second.second;
            int wt=it.first;
            
            int par_u=ds.findUPar(u) , par_v=ds.findUPar(v);
            
            if(par_u!=par_v){
                sum+=wt;
                ds.unionBySize(u,v);
            }
        }
        return sum;
    }
};