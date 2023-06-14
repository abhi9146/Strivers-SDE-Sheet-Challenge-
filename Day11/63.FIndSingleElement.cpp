// Problem Statement

/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

*/

#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
        int lo=0,hi=nums.size()-2;

        while(lo<=hi){
            int mid=(lo+hi)>>1;
            if(nums[mid]==nums[mid^1]) lo=mid+1;
            else hi=mid-1;
        }
        return nums[lo];
    }