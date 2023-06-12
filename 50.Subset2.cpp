// Problem Statement

/*
Given an integer array nums that may contain duplicates, return all possible 
subsets(the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

#include<bits/stdc++.h>
using namespace std;

void find(int ind,vector<int>&nums,vector<vector<int>>&ans,vector<int>&ds){
        ans.push_back(ds);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            find(i+1,nums,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        find(0,nums,ans,ds);
        return ans;
    }