// Problem Statement

/*
 Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
*/

#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
        int j=0,n=nums.size();
        if(n<2) return 1;
        for(int i=1;i<n;i++){
          if(nums[j]!=nums[i]){
            nums[++j]=nums[i];
          }
        }
        return j+1;
    }