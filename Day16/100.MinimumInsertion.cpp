

#include <bits/stdc++.h> 
using namespace std;

int minCharsforPalindrome(string s) {
	int n=s.size();
	int cnt=0;

	int i=0,j=n-1,last=j;
	while(i<j){
		if(s[i]==s[j]){
			i++;j--;
		}
		else{
			cnt++;i=0;last--;
			j=last;
		}
	}
	return cnt;
}
