// Problem Statement

/*
 Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
*/


#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        int n=nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
          long long t3=target-nums[i];
          for(int j=i+1;j<n;j++){
            int left=j+1,right=n-1;
            long long new_target=t3-nums[j];
            
             while(left<right){
               int two_sum=nums[left]+nums[right];
                 if(two_sum==new_target){
                   res.push_back({nums[i],nums[j],nums[left],nums[right]});
                    
                   int num3=nums[left],num4=nums[right];
                   while(left<right and nums[left]==num3) left++;
                   while(left<right and nums[right]==num4) right--;
                 }
                 else if(two_sum<new_target) left++;
                 else right--;
             }
            while(j+1<n and nums[j]==nums[j+1]) j++;
          }
          while(i+1<n and nums[i]==nums[i+1]) i++;
        }
        return res;
    }