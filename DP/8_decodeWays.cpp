// 91. Decode Ways
// You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:
// "1" -> 'A'
// "2" -> 'B'
// ...
// "25" -> 'Y'
// "26" -> 'Z'

// However, while decoding the message, you realize that there are many different ways you can 
// decode the message because some codes are contained in other codes ("2" and "5" vs "25").

// For example, "11106" can be decoded into:

// "AAJF" with the grouping (1, 1, 10, 6)
// "KJF" with the grouping (11, 10, 6)
// The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
// Note: there may be strings that are impossible to decode.

// Given a string s containing only digits, return the number of ways to decode it. 
// If the entire string cannot be decoded in any valid way, return 0.

class Solution {
public:
    //Top Down Approach (Recursion + Memoization)
    int fn(int ind, string &s, vector<int> &dp){
        //base case
        if(ind <= 0){
            //check validity
            if(s[0] >= '1' && s[0] <= '9') return 1; //one way
            //if invalid
            else return 0;
        }

        //check problem already solved
        if(dp[ind] != -1) return dp[ind];

        int ways = 0;

        //take one char (ind)
        if(s[ind] >= '1' && s[ind] <= '9') ways += fn(ind-1, s, dp);

        //take two char (ind-1, ind)
        if((s[ind-1] == '1' && (s[ind] <= '9' && s[ind] >= '0')) || 
        (s[ind-1] == '2' && (s[ind] <= '6' && s[ind] >= '0'))) ways += fn(ind-2, s, dp);

        return dp[ind] = ways;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);

        return fn(n-1, s, dp);
    }
};