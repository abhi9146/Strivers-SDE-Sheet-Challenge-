
// Problem Statement

/*
 Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
*/

#include <bits/stdc++.h> 
using namespace std;

 double myPow(double x, int n) {
        double res = 1;
        while (n) {
            if (n % 2) res = n > 0 ? res * x : res / x;
            x = x * x;
            n /= 2;
        }
        return res;
    }