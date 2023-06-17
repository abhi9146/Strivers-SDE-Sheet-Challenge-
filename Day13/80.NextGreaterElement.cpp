#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>um;
    
        int n=nums2.size();
        stack<int>st;
        st.push(INT_MAX);

        for(int i=n-1;i>=0;i--){
            int tp=nums2[i];
            while(st.top()<tp) st.pop();

            if(st.top()==INT_MAX) um[tp]=-1;
            else um[tp]=st.top();
            st.push(tp);
        }
        for(int i=0;i<nums1.size();i++){
            nums1[i]=um[nums1[i]];
        }
        return nums1;
    }
};