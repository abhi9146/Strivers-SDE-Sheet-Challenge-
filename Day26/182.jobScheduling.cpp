
#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};


class Solution 
{
    public:
    static bool comp(Job a,Job b){
        return (a.profit>b.profit);
    }
    vector<int> JobScheduling(Job arr[], int n) { 
        sort(arr,arr+n,comp);
        int ans=0,cnt=0;
        int maxxi=0;
        for(int i=0;i<n;i++){
            maxxi=max(maxxi,arr[i].dead);
        }
        vector<int>vis(maxxi+1,-1);
        for(int i=0;i<n;i++){
            int j=arr[i].dead;
            while(j--){
               if(vis[j]==-1){
                   vis[j]=i;cnt++;
                   ans+=arr[i].profit;
                   break;
               }
            }
        }
        return {cnt,ans};  
    } 
};