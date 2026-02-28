// Given an array of distinct integers candidates and a target integer target, 
// return a list of all unique combinations of candidates where the chosen numbers sum to target. 
// You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. 
// Two combinations are unique if the frequency of at least one of the chosen numbers is different.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Bottom Up (Recursion)
    void fn(int ind, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &result){
        //base case
        if(ind == arr.size()){
            //whether target is 0
            if(target == 0) result.push_back(ds);
            return;
        }
        
        //pick curr element
        if(arr[ind] <= target){
            ds.push_back(arr[ind]);
            //we will stay at ind only as we can take element unlimited times
            fn(ind, target - arr[ind], arr, ds, result);
            
            //backtracking step
            ds.pop_back();
        }
        
        //not pick curr element
        fn(ind+1, target, arr, ds, result);
    }
    
    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        vector<int> ds;
        vector<vector<int>> result;
        
        fn(0, target, arr, ds, result);
        
        return result;
    }

int main(){
    


    return 0;
}

