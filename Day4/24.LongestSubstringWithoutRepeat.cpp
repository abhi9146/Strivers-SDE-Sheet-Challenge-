
// Problem Statement

/*
 Given a string s, find the length of the longest substring
 without repeating characters.
*/

#include <bits/stdc++.h> 
using namespace std;

int uniqueSubstrings(string s){
    unordered_map<char,int>um;
    int n=s.size();

    int i=0,j=0,len=0,max_len=0;
    while(j<n){
        um[s[j]]++;
        while( i<=j && um[s[j]]>1){
            um[s[i]]--;i++;
        }
        len=(j-i);
        max_len=max(max_len,len);
        j++;
    }
    return max_len+1;
}
 