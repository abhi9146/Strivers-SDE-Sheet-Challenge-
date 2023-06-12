// Problem Statement

/*
 Given a binary array nums, return the maximum number of consecutive 1's in the array.
*/

#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_len=0,len=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) len++;
            else{
               max_len=max(max_len,len);
               len=0;
            }
        }
        max_len=max(max_len,len);
        return max_len;
    }