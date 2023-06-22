
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        
        while(--n){
            string curr="";
            for(int i=0;i<s.size();i++){
                int cnt=1;
                while ((i + 1 < s.size()) && (s[i] == s[i + 1])){
                    cnt++;    
                    i++;
               }
                curr+=to_string(cnt)+s[i];
            }
            s=curr;
        }
        return s;
    }
};