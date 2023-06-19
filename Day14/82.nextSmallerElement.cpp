#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &nums, int n){
    stack<int>st;
    st.push(INT_MIN);
    for(int i=n-1;i>=0;i--){
        int curr=nums[i];
        while(st.top()>=nums[i]) st.pop();
        if(st.top()==INT_MIN) nums[i]=-1;
        else nums[i]=st.top();

        st.push(curr);
    }

    return nums;
}