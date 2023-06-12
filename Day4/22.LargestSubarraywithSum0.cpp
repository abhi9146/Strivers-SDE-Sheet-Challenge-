
// Problem Statement

/*
 Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.
*/

#include <bits/stdc++.h> 
using namespace std;

int LongestSubsetWithZeroSum(vector < int > A) {
      unordered_map<int,int>um;
      int n=A.size();
        int len=0,sum=0;
        um[sum]=-1;
        
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(um.find(sum)!=um.end()){
                len=max(len,i-um[sum]);
            }
            else um[sum]=i;
        }
        return len;
}