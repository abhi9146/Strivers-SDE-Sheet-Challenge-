// Problem Statement

/*
Given an array of integers A of size N and an integer B.

The College library has N books. The ith book has A[i] number of pages.

You have to allocate books to B number of students so that the maximum number of pages allocated to a student is minimum.

A book will be allocated to exactly one student.
Each student has to be allocated at least one book.
Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.
Calculate and return that minimum possible number
*/

#include<bits/stdc++.h>
using namespace std;


bool isPossible(int n, int m, vector<int>& arr, long long int mid) {
    int dayCount = 1;
    long long int timeCount = 0;

    for (int i = 0; i < m; i++) {
        if (timeCount + arr[i] <= mid) {
            timeCount += arr[i];
        } else {
            dayCount++;
            if (dayCount > n || arr[i] > mid) {
                return false;
            } else {
                timeCount = arr[i];
            }
        }
    }
    return true;
}

long long int ayushGivesNinjatest(int n, int m, vector<int>& time) {
    long long int s = 0;
    long long int sum = accumulate(time.begin(), time.end(), 0LL); // Calculate sum of time values

    long long int e = sum;
    long long int ans = -1;

    while (s <= e) {
        long long int mid = s + (e-s) / 2;
        if (isPossible(n, m, time, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

