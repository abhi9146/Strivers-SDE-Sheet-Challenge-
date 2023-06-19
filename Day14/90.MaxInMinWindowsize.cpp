#include <bits/stdc++.h> 
using namespace std;

vector<int> maxMinWindow(vector<int> arr, int n) {
     vector<int> left(n);
     vector<int> right(n);
     vector<int> ans(n,INT_MIN);

        stack<int> t;
        for(int i=0;i<n;i++){
            while(!t.empty()&&arr[t.top()]>=arr[i])t.pop();
            if(t.empty())left[i]=-1;
            else left[i]=t.top();
            t.push(i);
        }
        while(!t.empty())t.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!t.empty()&&arr[t.top()]>=arr[i])t.pop();
            if(t.empty())right[i]=n;
            else right[i]=t.top();
            t.push(i);
        }

        for(int i=0;i<n;i++)
        right[i]=right[i]-left[i]-1;

        for(int i=0;i<n;i++)
        ans[right[i]-1]=max(ans[right[i]-1],arr[i]);

        for(int i=n-2;i>=0;i--)
        {
            if(ans[i]<ans[i+1])
            ans[i]=ans[i+1];
        }
        return ans;
}