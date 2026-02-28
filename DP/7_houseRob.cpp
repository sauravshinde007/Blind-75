#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Method 1: Recursion  + memoizaton (Botttom up apporach)
int fn(int ind, vector<int> &nums, vector<int> &dp){
    //base case
        if(ind <= 0){
            return nums[0];
        }

        //check if problem already solved
        if(dp[ind] != -1) return dp[ind];

        //rob curr house
        int robHouse = fn(ind-2, nums, dp) + nums[ind];

        //skip curr house
        int skipHouse = fn(ind-1, nums, dp);

        return dp[ind] = max(robHouse, skipHouse);
    }

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return fn(n-1, nums, dp);
}

//Method 2: Tabulation
int rob2(vector<int> &nums){
    int n = nums.size();

    vector<int> dp(n+1, 0); //one extra for out of bound

    //base value
    dp[1] = nums[0]; //if only one house

    for(int i=2; i<=n; i++){
        //rob cuurent house and skip adjacent
        int robHouse = nums[i-1] + dp[i-2];
        
        //skip current house and move to adjacnent
        int skipHouse = dp[i-1];

        dp[i] = max(robHouse, skipHouse);
    }

    return dp[n];
}