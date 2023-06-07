
// Problem Statement

/*
 Given an array of integers arr and an integer x. 
 Find the total number of subarrays having bitwise XOR of all elements equals to x.
*/

#include <bits/stdc++.h> 
using namespace std;

int subarraysXor(vector<int> &arr, int x){
    int cnt=0;
    unordered_map<int,int>um;
    um[0]=1;
    int xo=0;

    for(int i=0;i<arr.size();i++){
        xo^=arr[i];
        cnt+= ( um[xo ^x]);
        um[xo]++;
    }
    return cnt;
}