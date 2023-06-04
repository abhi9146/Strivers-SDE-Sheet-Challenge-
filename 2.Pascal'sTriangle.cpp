// Problem Statement 

/*
   Given an integer numRows, return the first numRows of Pascal's triangle.
   In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

   Input: numRows = 5
   Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<long long int>> printPascal(int n) {
     vector<vector<ll>>res;
    res.push_back({1});
     for(int i=1;i<n;i++){
          vector<ll>curr(i+1,1);
          for(int j=1;j<i;j++){
             curr[j]=res[i-1][j]+res[i-1][j-1];
          }
          res.push_back(curr);
     }
     return res;

}
