#include<bits/stdc++.h>
using namespace std;

int findCelebrity(int n) {
 	stack<int>st;
	 for(int i=0;i<n;i++) st.push(i);

	 while(st.size()>1){
		 int a=st.top();st.pop();
		 int b=st.top();st.pop();

		 if(knows(a,b)) st.push(b);
		 else st.push(a);
	 }
	 int can=st.top();
	 for(int i=0;i<n;i++){
       if(can!=i && knows(can,i)) return -1;
	 }
	 for(int i=0;i<n;i++){
       if(can!=i && !knows(i,can)) return -1;
	 }
	 return can;
}