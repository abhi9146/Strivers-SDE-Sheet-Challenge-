
// Problem Statement

/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.
*/

#include<bits/stdc++.h>
using namespace std;

void fun(vector<int>&c,int ind,int n,int target,vector<int>&tmp,vector<vector<int>>&res){
            if(target==0){
               res.push_back(tmp);
            } 

        for(int i=ind;i<n;i++){
            if(i!=ind && c[i]==c[i-1]) continue;

            if(c[i]>target) break;
            tmp.push_back(c[i]);
            fun(c,i+1,n,target-c[i],tmp,res);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(),c.end());
        int n=c.size();
        vector<vector<int>>res;
        vector<int>tmp;

        fun(c,0,n,target,tmp,res);
        return res;
    }