// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
// The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique 
// paths that the robot can take to reach the bottom-right corner.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Method 1: Recursion  + Memoization
    int fn(int i, int j, int m, int n, vector<vector<int>> &dp){
        //base case
        if(i == 0 && j == 0) return 1; //one path found

        //check for out of bounds
        if(i < 0 || j < 0 || i == m || j == n) return 0;

        //check if problem already solved
        if(dp[i][j] != -1 ) return dp[i][j];

        //either go up or left
        return dp[i][j] = fn(i-1, j, m, n, dp) + fn(i, j-1, m, n, dp);
    }

int uniqePaths(int m, int n){
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return fn(m-1, n-1, m, n, dp);
}

//Method 2: Tabulation (Bottom up appraoch)
int uniqePaths(int m, int n){
    //dp table
    vector<vector<int>> dp(m, vector<int>(n, 0));

    //base values for 0th row and 0th col only one way
    //right or down path
    for(int i=0; i<m; i++) dp[i][0] = 1;
    for(int j=0; j<n; j++) dp[0][j] = 1;

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];

}




int main(){
    


    return 0;
}