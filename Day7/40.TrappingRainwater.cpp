// Problem Statement

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/

#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
        int water=0;
        int left=0,right=height.size()-1;
        int left_max=INT_MIN,right_max=INT_MIN;

        while(left<right){
          if(height[left]<=height[right]){
              if(height[left]>=left_max) left_max=height[left];
              else water +=left_max-height[left];

              left++;
          }
          else{
              if(height[right]>=right_max) right_max=height[right];
              else water +=right_max-height[right];

              right--;
          }
        }
        return water;
    }
