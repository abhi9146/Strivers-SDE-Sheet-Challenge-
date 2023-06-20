
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        s+=' ';
        int n=s.size();
        string ans="",tmp="";
        
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(tmp!=""){
                  if(ans!="") ans=tmp+' '+ans;
                  else ans=tmp;
                }
                tmp="";
            }
            else{
                tmp+=s[i];
            }
        }
        return ans;
    }
};