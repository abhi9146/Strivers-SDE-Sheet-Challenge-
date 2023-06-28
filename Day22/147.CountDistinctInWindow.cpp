#include <bits/stdc++.h> 
using namespace std;

vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    int n=arr.size();
    map<int,int>mp;
    vector<int>res;

    for(int i=0;i<n;i++){
        if(i<k) mp[arr[i]]++;
        else{
            res.push_back(mp.size());
            mp[arr[i-k]]--;
            if(mp[arr[i-k]]==0) mp.erase(arr[i-k]);
            mp[arr[i]]++;
        }
    }
    res.push_back(mp.size());
    return res;
}
