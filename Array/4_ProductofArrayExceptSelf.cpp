// Given an integer array nums, return an array answer such that 
// answer[i] is equal to the product of all the elements of nums except nums[i].

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);

    vector<int> leftProduct(n); //stores left product of all elements to its left excluding self
    vector<int> rightProduct(n); //stores right product of all elements to its right excluding self

    //calculate left product
    leftProduct[0] = 1;
    for(int i=1; i<n; i++){
        leftProduct[i] = nums[i-1] * leftProduct[i-1];
    }

    rightProduct[n-1] = 1;
    for(int i=n-2; i>=0; i--){
        rightProduct[i] = nums[i+1] * rightProduct[i+1];
    }

    for(int i=0; i<n; i++){
        result[i] = leftProduct[i] * rightProduct[i];
    }

    return result;
}

int main(){

    vector<int> nums = {1, 2, 3, 4};


    return 0;
}