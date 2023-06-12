
// Problem Statement

/*
 You are given an m x n integer matrix matrix with the following two properties:
 Given an integer target, return true if target is in matrix or false otherwise.
 You must write a solution in O(log(m * n)) time complexity.
*/

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n=mat.size(), m = mat[0].size();
        int lo=0,hi=n*m-1;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
           int val=mat[mid/m][mid%m];
            //cout<<row<<" "<<col<<endl;
            if(val==target) return true;
            else if(val>target) hi=mid-1;
            else lo=mid+1;
        }
        return false;
}

