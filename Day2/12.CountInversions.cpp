
// Problem Statement

/*
 Count the total number of inversions present in the array
*/

#include <bits/stdc++.h>
using namespace std; 
#define ll long long

long long merge(vector<ll>&temp,ll left,ll mid,ll right,long long *arr){
    ll inv_count=0, i = left, j = mid, k = left;

    while((i <= mid-1) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while(i <= mid - 1)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(i = left ; i <= right ; i++)
        arr[i] = temp[i];
    
    return inv_count;
}

long long mergeSort(vector<ll>&temp,ll left,ll right,long long *arr){
    ll mid,inv_count = 0;
    if(right > left){
        mid = (left + right)/2;

        inv_count += mergeSort(temp,left,mid,arr);
        inv_count += mergeSort(temp,mid+1,right,arr);

        inv_count += merge(temp,left,mid+1,right,arr);
    }
    return inv_count;
}

long long getInversions(long long *arr, int n){
    vector<ll>temp(n);
   return mergeSort(temp,0,n-1,arr);
}