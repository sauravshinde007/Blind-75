// Contains Duplicate : Check if a value appears atleast twice

// Problem Statement: Given an integer array nums, return true if any value appears at least twice in the array, 
// and return false if every element is distinct.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Method 1: Maintain Map and store value and at every iteration check if that curr element already exists
bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> mpp; //store value and freq
    for(int i : nums){
        if(mpp.count(i) > 0) return true;
        mpp[i]++;
    }
    
    return false;
}

int main(){



    return 0;
}