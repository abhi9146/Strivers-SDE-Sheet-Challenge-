// Problem Statement

/*
 Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
 You must write an algorithm that runs in O(n) time.
*/

#include <bits/stdc++.h> 
using namespace std;

int longestConsecutive(vector<int>& nums) {
       unordered_set<int>us(nums.begin(),nums.end());
       int longest_streak=0;
       
       for(auto x:nums){
         if(!us.count(x-1)){
           int len=0;
           while(us.count(x)){
             x++;len++;
           }
           longest_streak=max(longest_streak,len);
         }
       }
       return longest_streak;
    }