// Problem Statement 

/*
   Given an integer array nums, find the subarray with the largest sum, and return its sum.
*/

#include <bits/stdc++.h> 
#define ll long long 

long long maxSubarraySum(int arr[], int n){
    ll max_sum=0,cur_sum=0;

    for(int i=0;i<n;i++){
        cur_sum+=arr[i];
        if(cur_sum<0) cur_sum=0;
        if(cur_sum>max_sum) max_sum=cur_sum;
    }
    return max_sum;
}