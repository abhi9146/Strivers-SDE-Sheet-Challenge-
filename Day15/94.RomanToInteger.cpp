
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int convert(char ch){
      switch(ch) {
          case 'I':
            return 1; 
          case 'V':
            return 5; 
          case 'X':
            return 10; 
          case 'L':
            return 50; 
          case 'C':
            return 100; 
          case 'D':
            return 500; 
          case 'M':
            return 1000;
        }
        return 0;
    }
    int romanToInt(string s){
        int n=n=s.size();
        int total=convert(s[n-1]);  
    
        for(int i=n-2;i>=0;i--){
             if(convert(s[i+1])>convert(s[i])){
                total-=convert(s[i]);
             }
             else total+=convert(s[i]);
           //cout<<total<<" ";
        }
        return total;
    }
};