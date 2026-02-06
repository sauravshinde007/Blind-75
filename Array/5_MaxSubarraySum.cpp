// Kadane's Algorithm : Maximum Subarray Sum in an Array
// Problem Statement: Given an integer array nums, find the subarray with the largest sum and 
// return the sum of the elements present in that subarray.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int result = nums[0];
        int maxEnd = nums[0]; //represents sum till the prev of curr element

        for(int i=1; i<n; i++){
            int currentSum = maxEnd + nums[i];
            result = max(result, currentSum);

            //If currentSum is less than curr then no point in 
            // extending this (start over from curr element)
            if(currentSum < nums[i]) maxEnd = nums[i];
            else maxEnd += nums[i];
        }

    return result;
}

int main(){



    return 0;
}