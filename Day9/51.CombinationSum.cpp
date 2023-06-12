
// Problem Statement

/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency of at least one of the chosen numbers is different.
*/

#include<bits/stdc++.h>
using namespace std;


void fun(vector<int>& candidates,int ind, int n,int target,vector<int>&tmp,vector<vector<int>>&res){
          if(ind==n){
              if(target==0) res.push_back(tmp);
              return;
          }
          fun(candidates,ind+1,n,target,tmp,res);
          if(target>=candidates[ind]){
             tmp.push_back(candidates[ind]);
             fun(candidates,ind,n,target-candidates[ind],tmp,res);
             tmp.pop_back();
          } 
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>tmp;
        int n=candidates.size();

        fun(candidates,0,n,target,tmp,res);
        return res;
    }