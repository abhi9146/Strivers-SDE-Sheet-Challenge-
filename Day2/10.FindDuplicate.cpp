
// Problem Statement

/*
  Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
  There is only one repeated number in nums, return this repeated number.
  You must solve the problem without modifying the array nums and uses only constant extra space.
 
*/

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr, int n){
	 map<int,int>mp;
	 for(auto x:arr) {
		 mp[x]++;
		 if(mp[x]>1) return x;
	 }
}