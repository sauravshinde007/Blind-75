// Given an integer array nums, return the length of the longest strictly increasing subsequence.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//DP(Recursion + memoization) (Bottom Up Approach) (0 to n-1)
//fn(ind, prev_ind) = max length of LIS from 0 to ind with previous ind of subseqn being prev_ind
int fn(int ind, int prev_ind, vector<int> &nums, vector<vector<int>> &dp){
    int n = nums.size();
    //base case (out of bounds then no max length)
    if(ind  == n) return 0; 

    //check if problem already solved
    if(dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];

    //Dont take curr index in the subseqn
    int len = fn(ind + 1, prev_ind, nums, dp); //length of the subseqn

    //Take the curr index
    if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
        len = max(len, 1 + fn(ind+1, ind, nums, dp));
    }

    return dp[ind][prev_ind + 1] = len;
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    //here as prev_ind is from -1 to n-1 so (n+1 size)
    vector<vector<int>> dp(n, vector<int>(n+1, -1));

    return fn(0, -1, nums, dp);
}

int main(){
    


    return 0;
}