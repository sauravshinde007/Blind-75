// Kadane's Algorithm : Maximum Subarray Sum in an Array
// Problem Statement: Given an integer array nums, find the subarray with the largest sum and 
// return the sum of the elements present in that subarray.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int maxi = nums[0];
        int prevSum = nums[0]; //sum till previous element

        //Kadane's Algorithm
        for(int i=1; i<n; i++){
            int currSum = prevSum + nums[i];

            //if currSum is less that the curr element then no point in extending the subarray
            if(currSum < nums[i]) prevSum = nums[i]; //start new subarray
            else prevSum += nums[i]; //extend subarray

            maxi = max(maxi, prevSum);
        }

        return maxi;
}

int main(){



    return 0;
}