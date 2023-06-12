
// Problem Statement

/*
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
*/

#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

static bool comp(Item &a, Item &b){
        double val1=double(a.value)/double(a.weight);
        double val2=double(b.value)/double(b.weight);
        
        return val1>val2;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n){
        sort(arr,arr+n,comp);
        
        double total=0;
        
        for(int i=0;i<n;i++){
            if(W>=arr[i].weight){
                W-=arr[i].weight;
                total+=arr[i].value;
            }
            else{
                total+= (double(arr[i].value)/double(arr[i].weight))*W;
                break;
            }
        }
        return total;
    }