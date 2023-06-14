
// Problem Statement

/*
Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the kth position of the final sorted array.
*/

#include<bits/stdc++.h>
using namespace std;

int kthElement(int arr1[], int arr2[], int n, int m, int k){
        if(n>m) kthElement(arr2,arr1,m,n,k);
        
        int lo=max(0,k-m),hi=min(n,k);
        
        while(lo<=hi){
            int cut1=(lo+hi)>>1;
            int cut2=k-cut1;
            
            int l1=cut1==0?INT_MIN:arr1[cut1-1];
            int l2=cut2==0?INT_MIN:arr2[cut2-1];
            
            int r1=cut1==n?INT_MAX:arr1[cut1];
            int r2=cut2==m?INT_MAX:arr2[cut2];
            
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }
            else if(l1>r2) hi=cut1-1;
            else lo=cut1+1;
        }
        return 0;
    }