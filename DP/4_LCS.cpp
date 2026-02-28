// Given two strings str1 and str2, give length of the longest common subsequence of the two strings.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Method 1 : Recursion + memoization
//fn(ind1, ind2) = len of LCS from text1(0 to ind1) & text2(0 to ind2)
int fn(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp){
    //base case (if any of the text out of bounds then no LCS possible)
    if(ind1 < 0 || ind2 < 0) return 0;

    //check if problem already solved
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    //if match found (move both index)
    if(text1[ind1] == text2[ind2]) return dp[ind1][ind2] =  1 + fn(ind1-1, ind2-1, text1, text2, dp);

    //if match not found (move either index and see which is max)
    return dp[ind1][ind2] = max(fn(ind1-1, ind2, text1, text2, dp), fn(ind1, ind2-1, text1, text2, dp));
}

int longestCommonSubsequence1(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return fn(n-1, m-1, text1, text2, dp);
}

//Method 2: Tabulation (Bottom up approach)
int longestCommonSubsequence2(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();

    //dp[i][j] = max LCS from text1(0 to i-1) & text2(0 to j-1)
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            //match found
            if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            //match not found
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
}



int main(){
    
    string text1 = "catsdogsandandcat";
    string text2 = "catsandog";

    cout<<longestCommonSubsequence2(text1, text2);

    return 0;
}