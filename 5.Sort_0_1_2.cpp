// Problem Statement 

/*
   Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
   We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
   You must solve this problem without using the library's sort function.
*/

#include <bits/stdc++.h> 
using namespace std;

void sort012(int *arr, int n){
     int i=0,j=0,k=n-1;
     while(j<=k){
        if(arr[j]==0){
           swap(arr[j++],arr[i++]);
        }
        else if(arr[j]==1) j++;
        else{
           swap(arr[j],arr[k--]);
        }
     }
}