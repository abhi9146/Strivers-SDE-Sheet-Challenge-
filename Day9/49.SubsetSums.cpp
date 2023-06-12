// Problem Statement

/*
Given a list arr of N integers, print sums of all subsets in it.
*/

#include<bits/stdc++.h>
using namespace std;

void fun(vector<int> arr,int ind, int n,vector<int>&res,int sum){
        if(ind==n){
            res.push_back(sum);
            return;
        }
        fun(arr,ind+1,n,res,sum);
        fun(arr,ind+1,n,res,sum+arr[ind]);
    }
    vector<int> subsetSums(vector<int> arr, int N){
        vector<int>res;
        fun(arr,0,N,res,0);
        return res;
    }