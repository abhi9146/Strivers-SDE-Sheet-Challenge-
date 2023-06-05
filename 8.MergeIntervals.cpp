
// Problem Statement

/*
   Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
    int n=intervals.size();
    vector<vector<int>>res;
    
    sort(intervals.begin(),intervals.end());
    int st=intervals[0][0],en=intervals[0][1];

    for(int i=1;i<n;i++){
        if(intervals[i][0]<=en){
              en=max(intervals[i][1],en);
           }
           else{
             res.push_back({st,en});
             st=intervals[i][0];
             en=intervals[i][1];
           }
    }
    res.push_back({st,en});
    return res;
}