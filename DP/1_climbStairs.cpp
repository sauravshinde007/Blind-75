#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//dp[i] = total ways to climb i steps
//DP(recursion + memoization)
 int fn(int i, vector<int> &dp){
    //base case
    if(i == 0 || i == 1) return 1; //only one way

    //check if problem already solved
    if(dp[i] != -1) return dp[i];

    //go either one step or two steps
    return dp[i] = fn(i-1, dp) + fn(i-2, dp);
}

int climbStairs(int n) {
    vector<int> dp(-1, n);
    //top down approach
    return fn(n, dp);
}


int main(){
    cout<<climbStairs(2);


    return 0;
}