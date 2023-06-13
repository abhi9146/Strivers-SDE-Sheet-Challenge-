
// Problem Statement

/*
Employable by enrolling today! 
Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.
*/

#include<bits/stdc++.h>
using namespace std;

bool isPossible(int node,int col,int n,vector<int>&color,bool graph[101][101]){
        for(int i=0;i<n;i++){
            if(node!=i && graph[i][node]==1 && color[i]==col) return false;
        }
        return true;
    }
    
    bool fun(int node,int m,int n,vector<int>&color,bool graph[101][101]){
        if(node==n) return true;
        
        for(int i=1;i<=m;i++){
            if(isPossible(node,i,n,color,graph)){
                color[node]=i;
                if(fun(node+1,m,n,color,graph)==true) return true;
                color[node]=0;
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int>color(n,0);
        
        if(fun(0,m,n,color,graph)==true) return true;
        return false;
    }