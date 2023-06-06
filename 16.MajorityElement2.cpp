
// Problem Statement

/*
   Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
*/


#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementII(vector<int> &arr){
    unordered_map<int,int>m;
    int n=arr.size();
	 for(int i=0;i<n;i++){ 
		 m[arr[i]]++;
	}
    vector<int>res;
    for(auto x:m) if(x.second>(n/3) ) res.push_back(x.first);
    return res;
}