// Problem Statement

/*
  Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
  Notice that the solution set must not contain duplicate triplets.
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>>res;
        int n=arr.size();
	     sort(arr.begin(),arr.end());
	for(int i=0;i<n-2;i++){
		int lo=i+1,hi=n-1;
		int target=0-arr[i];

        while(lo<hi){
			int mid=(lo+hi)/2;
			if((arr[lo]+arr[hi])==target){
				res.push_back({arr[i],arr[lo],arr[hi]});
				int j=lo,k=hi;
				lo++;hi--;
				while(lo<=hi && arr[lo]==arr[j]) lo++;
				while(hi>=lo && arr[hi]==arr[k]) hi--;
			}
			else if(arr[lo]+arr[hi] >target) hi--;
			else lo++;

			while( i<n-1 && arr[i]==arr[i+1]) i++;
		}
	}
	return res;
    }