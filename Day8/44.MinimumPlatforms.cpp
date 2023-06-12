// Problem Statement

/*
Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.
*/
#include<bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n){
         vector<pair<int,int>>vp;
         for(int i=0;i<n;i++){
             vp.push_back({arr[i],1});
             vp.push_back({dep[i],2});
         } 
         
         sort(vp.begin(),vp.end());
         int cnt=0,res=0;
         for(auto x:vp){
             //cout<<x.second<<" "<<cnt<<endl;
             if(x.second==1){
                 cnt++;
                 res=max(res,cnt);
             }
             else cnt--;
         }
         return res;
    }