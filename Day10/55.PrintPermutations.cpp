// Problem Statement

/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

*/

#include<bits/stdc++.h>
using namespace std;

void fun(int n,vector<int>&nums,vector<int>&tmp,vector<int>&vis,vector<vector<int>>&res){
        if(tmp.size()==n){
           res.push_back(tmp);
           return;
        } 
        
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                vis[i]=1;tmp.push_back(nums[i]);
                fun(n,nums,tmp,vis,res);
                vis[i]=0;tmp.pop_back();
            }
        }
    }

vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        vector<int>vis(n,0);
        vector<int>tmp;

        fun(n,nums,tmp,vis,res);
        return res;
    }