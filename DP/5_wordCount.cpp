// Given a string s and a dictionary of strings wordDict, 
// return true if s can be segmented into a space-separated sequence of one or more dictionary words.
// Note that the same word in the dictionary may be reused multiple times in the segmentation.
  
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//DP (tabulation) (Bottom up approach)
bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        //1-D DP
        //dp[i] = can substr s[0 to i] can be segmented into wordDict
        vector<bool> dp(n+1, false);

        //0 to 0 substr is always true
        dp[0] = true;

        //Convert wordDict into set for O(1) lookup
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                //check if substring 0 to j can be segmented and
                // and substr j to i lies in words dictionary
                if(dp[j] && words.count(s.substr(j, i - j))){
                    dp[i] = true;
                    break; //no need to continue
                }
            }
    }

    return dp[n];
}

int main(){
    


    return 0;
}