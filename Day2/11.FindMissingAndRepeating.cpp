
// Problem Statement

/*
   You are given a read only array of n integers from 1 to n.
   Each integer appears exactly once except A which appears twice and B which is missing.
   Return A and B.
*/

#include <bits/stdc++.h>
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n){
	vector<int>freq(n+1,0);
	for(auto x:arr) freq[x]++;

	pair<int,int>p;
	for(int i=1;i<=n;i++){
		if(freq[i]==0) p.first=i;
		else if(freq[i]>1) p.second=i;
	}
	return p;
}
