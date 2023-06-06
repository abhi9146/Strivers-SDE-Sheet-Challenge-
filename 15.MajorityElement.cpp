
// Problem Statement

/*
 Given an array nums of size n, return the majority element.
 The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/

#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
        int cnt=0;
        int number=nums[0];

        for(auto x:nums){
          if(cnt==0) number=x;
          if(number ==x) cnt++;
          else cnt--;
        }
        return number;
    }