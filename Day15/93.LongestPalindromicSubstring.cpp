
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int st=0,en=0,res=0;
    void lenFind(string s,int l,int r){
       while((l>=0 and r<s.size()) and (s[l]==s[r])){
         l--;r++;
       }
       if(res<(r-l-1)){
          st=l+1;en=r-1;
          res=(r-l-1);
       }
    }

    string longestPalindrome(string s) {
         for(int i=0;i<s.size()-1;i++){
           lenFind(s,i,i+1);
       }
       for(int i=0;i<s.size();i++){
           lenFind(s,i,i);
       }
      
       return s.substr(st,res);
    }
};