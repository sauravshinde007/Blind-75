// You are given an integer array coins representing coins of different denominations 
// and an integer amount representing a total amount of money.
// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any 
// combination of the coins, return 0.
// You may assume that you have an infinite number of each kind of coin.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//DP(Recursion + memoization)
//Top Down approach

//fn(ind, amount) = Total ways to make amount using 0 to ind indexes from coins
int fn(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp){
    //base case
    //here if the ind coin is divisible of amount then we can have 1 way or 0 ways
    if(ind == 0) return amount % coins[ind] == 0;

    //check if problem already solved
    if(dp[ind][amount] != -1) return dp[ind][amount];

    //Dont take the coin
    int notTake = fn(ind-1, amount, coins, dp);

    //Take the coin
    int take = 0 ;
    //here as we can take any no of coins hence we will not move to preceding index we will stay on ind
    if(amount >= coins[ind]) take = fn(ind, amount - coins[ind], coins, dp); 

    return dp[ind][amount] = take + notTake;
}

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return fn(n-1, amount, coins, dp);
}   

int main(){
    


    return 0;
}