
// Problem Statement

/*
Given a matrix of integers A of size N x M in which each row is sorted.
Find and return the overall median of matrix A.
*/

#include<bits/stdc++.h>
using namespace std;

int countSmaller(vector<int>&row,int num){
    int lo=0,hi=row.size()-1;
    while(lo<=hi){
        int mid=(lo+hi)>>1;
        if(row[mid]>num) hi=mid-1;
        else lo=mid+1;
    }
    return lo;
}

int getMedian(vector<vector<int>> &matrix){
   int n=matrix.size(), m=matrix[0].size();

   int lo=1,hi=1e9;

   while(lo<=hi){
       int mid=(lo+hi)>>1;
       int cnt=0;
       for(int i=0;i<n;i++){
           cnt+=countSmaller(matrix[i],mid);
       }

       if(cnt<=((n*m)/2)) lo=mid+1;
       else hi=mid-1;
   }
   return lo;
}