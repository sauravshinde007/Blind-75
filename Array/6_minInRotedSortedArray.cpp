// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums of unique elements, return the minimum element of this array.

// You must write an algorithm that runs in O(log n) time.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findMin(vector<int>& nums) {
       int n = nums.size();
       int left = 0;
       int right = n-1;
       int first_minIdx = -1;

       while(left <= right){
            int mid = (left + right)/2;
            //check if condition true
            if(nums[mid] <= nums[n-1]){
                //go to left
                right = mid - 1;
                first_minIdx = mid;
            }else{
                //go to right
                left = mid + 1;
            }
       }

       return nums[first_minIdx]; 
    }

int main(){



    return 0;
}