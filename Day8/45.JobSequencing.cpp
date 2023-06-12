// Problem Statement

/*
Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.
*/

#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

 static bool comp(Job &a, Job &b){
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) { 
        sort(arr,arr+n,comp);
        int cnt=0,total=0;
        int maxxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxxi=max(maxxi,arr[i].dead);
        }
        
        vector<int>v(maxxi+1,-1);
        
        for(int i=0;i<n;i++){
            int id=arr[i].id;
            int dead=arr[i].dead-1;
            int pro=arr[i].profit;
            
            while(dead>=0 && v[dead]!=-1) dead--;
            if(dead>=0) {v[dead]=id;total+=pro;cnt++;}
        }
        
        return {cnt,total};
    } 