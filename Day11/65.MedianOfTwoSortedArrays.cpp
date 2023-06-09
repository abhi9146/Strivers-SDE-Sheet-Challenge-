
// Problem Statement

/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
*/

#include<bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size())  return findMedianSortedArrays(nums2,nums1);

        int n=nums1.size() , m= nums2.size();
        int lo=0,hi=n;

        while(lo<=hi){
            int cut1=(lo+hi)>>1;
            int cut2=(n+m+1)/2 - cut1;

            int l1= cut1==0 ? INT_MIN : nums1[cut1-1];
            int l2= cut2==0 ? INT_MIN : nums2[cut2-1];

            int r1= cut1==n ? INT_MAX : nums1[cut1];
            int r2= cut2==m ? INT_MAX : nums2[cut2];

            if(l1<=r2 && l2<=r1){
                if((n+m)%2==0){
                    double res=(max(l1,l2)+min(r1,r2))/2.0;
                    return res;
                }
                else{
                    return max(l1,l2);
                }
            }
            else if(l1>r2) hi=cut1-1;
            else lo=cut1+1;
        }
        return 0.0;
    }