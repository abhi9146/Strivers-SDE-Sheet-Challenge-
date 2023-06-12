
// Problem Statement

/*
 There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?
*/
#include<bits/stdc++.h>
using namespace std;

 int maxMeetings(int start[], int end[], int n){
       vector<pair<int,int>>vp;
       for(int i=0;i<n;i++) vp.push_back({end[i],start[i]});
       sort(vp.begin(),vp.end());
       
       int ans=1,prev=vp[0].first;
       for(int i=1;i<n;i++){
           if(vp[i].second>prev){
               ans++;
               prev=vp[i].first;
           }
       }
       return ans;
    }