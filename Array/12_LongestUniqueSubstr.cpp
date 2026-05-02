#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// You are given a string s. You have to find the length of the longest substring 
// with all distinct characters. 

int longestUniqueSubstr(string &s) {
        int n = s.size();
        
        //base case
        if(n <= 1) return n;
        
        //to keep track of visited characters in a window
        vector<bool> visited(1000, false);
        
        int maxLen = 1; //represnts max len substr with distinct char
        int left = 0, right = 0; //left and right pointers for window
        
        
        while(right < n){
            //check if curr char is visited or not
            
            //visited
            while(visited[s[right]]){
                //un visit left pointer unitl right pointer
                visited[s[left]] = false; 
                left++;
            }
            
            //mark current char visited
            visited[s[right]] = true;
            
            //keep track of maximum length
            maxLen = max(maxLen, right - left + 1);
            
            right++;
        }
        
        return maxLen;
    }