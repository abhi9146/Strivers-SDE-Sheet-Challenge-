
// Problem Statement

/*
Given a string s, partition s such that every 
substring of the partition is a palindrome
. Return all possible palindrome partitioning of s.
*/

#include<bits/stdc++.h>
using namespace std;

bool check(string &s,int st,int en){
        while(st<=en){
            if(s[st++]!=s[en--]) return 0;
        }
        return 1;
    }

    void fun(string &s,int st,int n,vector<vector<string>>&res,vector<string>&tmp){
        if(st==n){
            res.push_back(tmp);
            return;
        }
        for(int i=st;i<n;i++){
            if(check(s,st,i)){
               tmp.push_back(s.substr(st,i-st+1));
               fun(s,i+1,n,res,tmp);
               tmp.pop_back();
            } 
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>tmp;
        int en=s.size();

        fun(s,0,en,res,tmp);
        return res;
    }